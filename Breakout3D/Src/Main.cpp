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

	std::vector<Vertex> vertices;
	std::vector<uint32_t> indices;
	GeometryGenerator::CreateSphere(1.0f, 40, vertices, indices);
	
	Shader* shader = ResourceManager::Get().CreateResource<Shader>("Shader");
	shader->Initialize("Shader/Shader.vert", "Shader/Shader.geom", "Shader/Shader.frag");

	Texture2D* texture = ResourceManager::Get().CreateResource<Texture2D>("Texture");
	texture->Initialize("Resource/earth.png");

	StaticMesh* mesh = ResourceManager::Get().CreateResource<StaticMesh>("StaticMesh");
	mesh->Initialize(vertices, indices);

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

		texture->Active(0);

		shader->Bind();

		static float time = 0.0f;
		time += 0.01f;
		shader->SetUniform("time", time);
		
		shader->SetUniform("world", Matrix4x4f::Identity());
		shader->SetUniform("view", MathModule::CreateLookAt(
			Vector3f(3.0f, 3.0f, 3.0f),
			Vector3f(0.0f, 0.0f, 0.0f),
			Vector3f(0.0f, 1.0f, 0.0f)
		));
		shader->SetUniform("projection", MathModule::CreatePerspective(
			MathModule::ToRadian(45.0f),
			static_cast<float>(1000) / static_cast<float>(800),
			0.1f,
			100.0f
		));

		mesh->Bind();
		glDrawElements(GL_TRIANGLES, mesh->GetIndexCount(), GL_UNSIGNED_INT, 0);
		mesh->Unbind();
		shader->Unbind();

		RenderManager::Get().EndFrame();
	}
		
	ResourceManager::Get().Shutdown();
	RenderManager::Get().Shutdown();
	SDLManager::Get().Shutdown();

	CrashModule::UnregisterExceptionFilter();
	return 0;
}