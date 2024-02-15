#include <cstdint>
#include <windows.h>
#include <vector>

#include <glad/glad.h>
#include <SDL.h>

#include "CrashModule.h"
#include "FileModule.h"
#include "MathModule.h"

#include "Assertion.h"
#include "Shader.h"
#include "RenderManager.h"
#include "ResourceManager.h"
#include "SDLManager.h"

struct Vertex
{
	Vector3f position;
	Vector4f color;
};

int32_t WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR pCmdLine, _In_ int32_t nCmdShow)
{
	CHECK(CrashModule::RegisterExceptionFilter());

	SDLManager::Get().Startup();
	RenderManager::Get().Startup();
	ResourceManager::Get().Startup();

	Shader* shader = ResourceManager::Get().CreateResource<Shader>("Shader");
	shader->Initialize("Shader/Shader.vert", "Shader/Shader.frag");

	std::vector<Vertex> vertices = 
	{
		{ Vector3f(-0.5f, -0.5f, 0.0f), Vector4f(1.0f, 0.0f, 0.0f, 1.0f) },
		{ Vector3f(+0.5f, -0.5f, 0.0f), Vector4f(0.0f, 1.0f, 0.0f, 1.0f) },
		{ Vector3f(+0.0f, +0.5f, 0.0f), Vector4f(0.0f, 0.0f, 1.0f, 1.0f) },
	};

	uint32_t vao;
	uint32_t vbo;

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, static_cast<uint32_t>(vertices.size()) * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(Vertex, position)));
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(Vertex, color)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);

	RenderManager::Get().SetMultisampleMode(false);

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

		shader->Bind();
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, vertices.size());
		glBindVertexArray(0);
		shader->Unbind();

		RenderManager::Get().EndFrame();
	}

	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
	
	ResourceManager::Get().Shutdown();
	RenderManager::Get().Shutdown();
	SDLManager::Get().Shutdown();

	CrashModule::UnregisterExceptionFilter();
	return 0;
}