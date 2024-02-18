#include <cstdint>
#include <windows.h>
#include <vector>

#include <glad/glad.h>
#include <SDL.h>
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_opengl3.h>

#include "CrashModule.h"
#include "FileModule.h"
#include "MathModule.h"

#include "Assertion.h"
#include "GeometryGenerator.h"
#include "RenderManager.h"
#include "ResourceManager.h"
#include "SDLManager.h"
#include "Shader.h"
#include "Skybox.h"
#include "SkyboxPass.h"
#include "StaticMesh.h"
#include "Texture2D.h"
#include "Vertex.h"

int32_t WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR pCmdLine, _In_ int32_t nCmdShow)
{
	CHECK(CrashModule::RegisterExceptionFilter());

	SDLManager::Get().Startup();
	RenderManager::Get().Startup();
	ResourceManager::Get().Startup();

	RenderManager::Get().SetDepthMode(true);
	RenderManager::Get().SetAlphaBlendMode(true);
	RenderManager::Get().SetMultisampleMode(true);

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.IniFilename = nullptr;

	ImGui::StyleColorsDark();

	SDL_Window* window = reinterpret_cast<SDL_Window*>(SDLManager::Get().GetMainWindow());

	ImGui_ImplSDL2_InitForOpenGL(window, SDL_GL_GetCurrentContext());
	ImGui_ImplOpenGL3_Init("#version 460 core");

	std::vector<Vertex> vertices;
	std::vector<uint32_t> indices;
	GeometryGenerator::CreateSphere(1.0f, 40, vertices, indices);
	
	Shader* lightPass = ResourceManager::Get().CreateResource<Shader>("Shader");
	lightPass->Initialize("Shader/Shader.vert", "Shader/Shader.frag");

	SkyboxPass* skyboxPass = ResourceManager::Get().CreateResource<SkyboxPass>("SkyboxPass");
	skyboxPass->Initialize();

	Shader* visualLightPass = ResourceManager::Get().CreateResource<Shader>("VisualLight");
	visualLightPass->Initialize("Shader/VisualLight.vert", "Shader/VisualLight.frag");

	Texture2D* texture = ResourceManager::Get().CreateResource<Texture2D>("Texture");
	texture->Initialize("Resource/earth.png");

	Skybox* skybox = ResourceManager::Get().CreateResource<Skybox>("Skybox");
	skybox->Initialize(
		"Resource/Skybox/Space_Right.png",
		"Resource/Skybox/Space_Left.png",
		"Resource/Skybox/Space_Top.png",
		"Resource/Skybox/Space_Bottom.png",
		"Resource/Skybox/Space_Front.png",
		"Resource/Skybox/Space_Back.png"
	);

	StaticMesh* mesh = ResourceManager::Get().CreateResource<StaticMesh>("StaticMesh");
	mesh->Initialize(vertices, indices);

	Vec3f viewPosition = Vec3f(5.0f, 5.0f, 5.0f);
	Vec3f lightPosition = Vec3f(0.0f, 3.0f, 0.0f);
	Vec4f lightColor = Vec4f(1.0f, 1.0f, 1.0f, 1.0f);

	SDL_Event e;
	bool bIsDone = false;
	while (!bIsDone)
	{
		while (SDL_PollEvent(&e))
		{
			ImGui_ImplSDL2_ProcessEvent(&e);
			switch (e.type)
			{
			case SDL_QUIT:
				bIsDone = true;
				break;
			}
		}

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplSDL2_NewFrame();
		ImGui::NewFrame();

		{
			ImGui::Begin("Light Position");
			ImGui::SliderFloat("x", &lightPosition.x, -10.0f, 10.0f);
			ImGui::SliderFloat("z", &lightPosition.z, -10.0f, 10.0f);
			ImGui::End();
		}

		RenderManager::Get().BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);

		Mat4x4f world = MathModule::CreateScale(Vec3f(0.3f, 0.3f, 0.3f)) * MathModule::CreateTranslation(lightPosition);
		Mat4x4f view = MathModule::CreateLookAt(viewPosition, Vec3f(0.0f, 0.0f, 0.0f), Vec3f(0.0f, 1.0f, 0.0f));
		Mat4x4f projection = MathModule::CreatePerspective(MathModule::ToRadian(45.0f), static_cast<float>(1000) / static_cast<float>(800), 0.1f, 100.0f);

		{
			skyboxPass->Draw(view, projection, skybox);
			
			texture->Active(0);
			lightPass->Bind();
			lightPass->SetUniform("world", Mat4x4f::Identity());
			lightPass->SetUniform("view", view);
			lightPass->SetUniform("projection", projection);
			lightPass->SetUniform("lightPosition", lightPosition);
			lightPass->SetUniform("viewPosition", viewPosition);
			mesh->Bind();
			glDrawElements(GL_TRIANGLES, mesh->GetIndexCount(), GL_UNSIGNED_INT, 0);
			mesh->Unbind();
			lightPass->Unbind();

			visualLightPass->Bind();
			visualLightPass->SetUniform("world", world);
			visualLightPass->SetUniform("view", view);
			visualLightPass->SetUniform("projection", projection);
			visualLightPass->SetUniform("lightColor", lightColor);
			mesh->Bind();
			glDrawElements(GL_TRIANGLES, mesh->GetIndexCount(), GL_UNSIGNED_INT, 0);
			mesh->Unbind();
			visualLightPass->Unbind();
		}

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		RenderManager::Get().EndFrame();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

	ResourceManager::Get().Shutdown();
	RenderManager::Get().Shutdown();
	SDLManager::Get().Shutdown();

	CrashModule::UnregisterExceptionFilter();
	return 0;
}