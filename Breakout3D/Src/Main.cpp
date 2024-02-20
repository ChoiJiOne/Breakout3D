#include <cstdint>
#include <windows.h>
#include <vector>

#include <glad/glad.h>
#include <SDL.h>

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

StaticMesh* sphere = nullptr;
StaticMesh* cube = nullptr;

SkyboxPass* skyboxPass = nullptr;
Shader* shadowPass = nullptr;
Shader* lightPass = nullptr;
Shader* visualLightPass = nullptr;

Texture2D* texture = nullptr;
Skybox* skybox = nullptr;

Vec3f viewPosition = Vec3f(10.0f, 10.0f, 10.0f);
Vec3f lightPosition = Vec3f(0.0f, 3.0f, 0.0f);
Vec4f lightColor = Vec4f(1.0f, 1.0f, 1.0f, 1.0f);

void Load()
{
	std::vector<Vertex> vertices;
	std::vector<uint32_t> indices;

	GeometryGenerator::CreateSphere(1.0f, 40, vertices, indices);
	sphere = ResourceManager::Get().CreateResource<StaticMesh>("Sphere");
	sphere->Initialize(vertices, indices);

	GeometryGenerator::CreateCube(Vec3f(10.0f, 1.0f, 10.0f), vertices, indices);
	cube = ResourceManager::Get().CreateResource<StaticMesh>("Cube");
	cube->Initialize(vertices, indices);

	lightPass = ResourceManager::Get().CreateResource<Shader>("Shader");
	lightPass->Initialize("Shader/Shader.vert", "Shader/Shader.frag");

	skyboxPass = ResourceManager::Get().CreateResource<SkyboxPass>("SkyboxPass");
	skyboxPass->Initialize();

	shadowPass = ResourceManager::Get().CreateResource<Shader>("ShadowPass");
	shadowPass->Initialize("Shader/ShadowPass.vert", "Shader/ShadowPass.frag");

	visualLightPass = ResourceManager::Get().CreateResource<Shader>("VisualLight");
	visualLightPass->Initialize("Shader/VisualLight.vert", "Shader/VisualLight.frag");

	texture = ResourceManager::Get().CreateResource<Texture2D>("Texture");
	texture->Initialize("Resource/earth.png");

	skybox = ResourceManager::Get().CreateResource<Skybox>("Skybox");
	skybox->Initialize(
		"Resource/Skybox/Space_Right.png", "Resource/Skybox/Space_Left.png",
		"Resource/Skybox/Space_Top.png", "Resource/Skybox/Space_Bottom.png",
		"Resource/Skybox/Space_Front.png", "Resource/Skybox/Space_Back.png"
	);
}

int32_t WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR pCmdLine, _In_ int32_t nCmdShow)
{
	CHECK(CrashModule::RegisterExceptionFilter());

	SDLManager::Get().Startup();
	RenderManager::Get().Startup();
	ResourceManager::Get().Startup();

	RenderManager::Get().SetDepthMode(true);
	RenderManager::Get().SetAlphaBlendMode(true);
	RenderManager::Get().SetMultisampleMode(true);
	
	Load();

	const uint32_t SHADOW_WIDTH = 1024;
	const uint32_t SHADOW_HEIGHT = 1024;
	
	uint32_t depthMapFBO;
	glGenFramebuffers(1, &depthMapFBO);

	uint32_t depthMap;
	glGenTextures(1, &depthMap);
	glBindTexture(GL_TEXTURE_2D, depthMap);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMap, 0);
	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	SDL_Event e;
	bool bIsDone = false;
	while (!bIsDone)
	{
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT:
				bIsDone = true;
				break;
			}
		}

		RenderManager::Get().BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);

		Mat4x4f lightView = MathModule::CreateLookAt(lightPosition, Vec3f(0.0f, 0.0f, 0.0f), Vec3f(0.0f, 0.0f, 1.0f));
		Mat4x4f lightProjection = MathModule::CreateOrtho(-10.0f, 10.0f, -10.0f, 10.0f, 1.0f, 7.5f);
		
		{ // 1. ±íÀÌ ¾À ±×¸®±â
			RenderManager::Get().SetViewport(0, 0, SHADOW_WIDTH, SHADOW_HEIGHT);
			glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
			glClear(GL_DEPTH_BUFFER_BIT);
			
			shadowPass->Bind();
			shadowPass->SetUniform("view", lightView);
			shadowPass->SetUniform("projection", lightProjection);

			sphere->Bind();

			shadowPass->SetUniform("world", MathModule::CreateTranslation(-2.0f, 1.0f, 0.0f));
			glDrawElements(GL_TRIANGLES, sphere->GetIndexCount(), GL_UNSIGNED_INT, 0);

			shadowPass->SetUniform("world", MathModule::CreateTranslation(+2.0f, 1.0f, 0.0f));
			glDrawElements(GL_TRIANGLES, sphere->GetIndexCount(), GL_UNSIGNED_INT, 0);

			sphere->Unbind();

			cube->Bind();
			shadowPass->SetUniform("world", MathModule::CreateTranslation(Vec3f(0.0f, -0.5f, 0.0f)));
			glDrawElements(GL_TRIANGLES, cube->GetIndexCount(), GL_UNSIGNED_INT, 0);
			cube->Unbind();
			
			shadowPass->Unbind();
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
		}

		Mat4x4f view = MathModule::CreateLookAt(viewPosition, Vec3f(0.0f, 0.0f, 0.0f), Vec3f(0.0f, 1.0f, 0.0f));
		Mat4x4f projection = MathModule::CreatePerspective(MathModule::ToRadian(45.0f), static_cast<float>(1000) / static_cast<float>(800), 0.1f, 100.0f);
		
		{ // 2. ¾À ±×¸®±â
			RenderManager::Get().SetWindowViewport();

			lightPass->Bind();
			lightPass->SetUniform("view", view);
			lightPass->SetUniform("projection", projection);			
			lightPass->SetUniform("lightView", lightView);
			lightPass->SetUniform("lightProjection", lightProjection);
			lightPass->SetUniform("lightPosition", lightPosition);
			lightPass->SetUniform("lightColor", lightColor.x, lightColor.y, lightColor.z);
			lightPass->SetUniform("viewPosition", viewPosition);
			
			texture->Active(0);

			glActiveTexture(GL_TEXTURE0 + 1);
			glBindTexture(GL_TEXTURE_2D, depthMap);

			sphere->Bind();

			lightPass->SetUniform("world", MathModule::CreateTranslation(-2.0f, 1.0f, 0.0f));
			glDrawElements(GL_TRIANGLES, sphere->GetIndexCount(), GL_UNSIGNED_INT, 0);

			lightPass->SetUniform("world", MathModule::CreateTranslation(+2.0f, 1.0f, 0.0f));
			glDrawElements(GL_TRIANGLES, sphere->GetIndexCount(), GL_UNSIGNED_INT, 0);

			sphere->Unbind();

			cube->Bind();
			lightPass->SetUniform("world", MathModule::CreateTranslation(Vec3f(0.0f, -0.5f, 0.0f)));
			glDrawElements(GL_TRIANGLES, cube->GetIndexCount(), GL_UNSIGNED_INT, 0);
			cube->Unbind();

			lightPass->Unbind();
		}

		Mat4x4f world = MathModule::CreateScale(Vec3f(0.2f, 0.2f, 0.2f)) * MathModule::CreateTranslation(lightPosition);

		{ // 3. ¶óÀÌÆ® ±×¸®±â
			visualLightPass->Bind();
			visualLightPass->SetUniform("world", world);
			visualLightPass->SetUniform("view", view);
			visualLightPass->SetUniform("projection", projection);
			visualLightPass->SetUniform("lightColor", lightColor);
			sphere->Bind();
			glDrawElements(GL_TRIANGLES, sphere->GetIndexCount(), GL_UNSIGNED_INT, 0);
			sphere->Unbind();
			visualLightPass->Unbind();
		}

		RenderManager::Get().EndFrame();
	}

	ResourceManager::Get().Shutdown();
	RenderManager::Get().Shutdown();
	SDLManager::Get().Shutdown();

	CrashModule::UnregisterExceptionFilter();
	return 0;
}