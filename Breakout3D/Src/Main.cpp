#include <cstdint>
#include <windows.h>
#include <vector>

#include <glad/glad.h>
#include <SDL.h>

#include "CrashModule.h"
#include "FileModule.h"
#include "MathModule.h"

#include "Assertion.h"
#include "RenderManager.h"
#include "ResourceManager.h"
#include "SDLManager.h"
#include "Shader.h"
#include "Texture2D.h"

struct Vertex
{
	Vector3f position;
	Vector2f uv;
};

int32_t WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR pCmdLine, _In_ int32_t nCmdShow)
{
	CHECK(CrashModule::RegisterExceptionFilter());

	SDLManager::Get().Startup();
	RenderManager::Get().Startup();
	ResourceManager::Get().Startup();

	RenderManager::Get().SetDepthMode(true);
	RenderManager::Get().SetAlphaBlendMode(true);
	RenderManager::Get().SetMultisampleMode(true);

	Shader* shader = ResourceManager::Get().CreateResource<Shader>("Shader");
	shader->Initialize("Shader/Shader.vert", "Shader/Shader.frag");

	Texture2D* texture = ResourceManager::Get().CreateResource<Texture2D>("Texture");
	texture->Initialize("Resource/awesomeface.png");

	std::vector<Vertex> vertices = 
	{
		{ Vector3f(-0.5f, -0.5f, 0.0f), Vector2f(0.0f, 0.0f) },
		{ Vector3f(+0.5f, -0.5f, 0.0f), Vector2f(1.0f, 0.0f) },
		{ Vector3f(+0.5f, +0.5f, 0.0f), Vector2f(1.0f, 1.0f) },
		{ Vector3f(-0.5f, +0.5f, 0.0f), Vector2f(0.0f, 1.0f) },
	};
	
	std::vector<uint32_t> indices =
	{
		0, 1, 2,
		0, 2, 3,
	};

	uint32_t vao;
	uint32_t vbo;
	uint32_t ebo;

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, static_cast<uint32_t>(vertices.size()) * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<uint32_t>(indices.size()) * sizeof(uint32_t), indices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(Vertex, position)));
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(Vertex, uv)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);

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

		RenderManager::Get().BeginFrame(1.0f, 0.0f, 0.0f, 1.0f);

		texture->Active(0);

		shader->Bind();
		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		shader->Unbind();

		RenderManager::Get().EndFrame();
	}

	glDeleteBuffers(1, &ebo);
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
	
	ResourceManager::Get().Shutdown();
	RenderManager::Get().Shutdown();
	SDLManager::Get().Shutdown();

	CrashModule::UnregisterExceptionFilter();
	return 0;
}