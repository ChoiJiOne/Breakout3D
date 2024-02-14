#include <cstdint>
#include <windows.h>
#include <vector>

#include <glad/glad.h>
#include <SDL.h>

#include "Assertion.h"
#include "Shader.h"
#include "Vector.h"

struct Vertex
{
	Vector3f position;
	Vector4f color;
};

int32_t WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR pCmdLine, _In_ int32_t nCmdShow)
{
	SDL_FAILED(SDL_Init(SDL_INIT_EVERYTHING));
	SDL_FAILED(SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG));
	SDL_FAILED(SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE));
	SDL_FAILED(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4));
	SDL_FAILED(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6));
	SDL_FAILED(SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8));
	SDL_FAILED(SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8));
	SDL_FAILED(SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8));
	SDL_FAILED(SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8));
	SDL_FAILED(SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24));
	SDL_FAILED(SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8));
	SDL_FAILED(SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1));

	SDL_Window* window = SDL_CreateWindow("Breakout3D", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 800, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	SDL_ASSERT(window != nullptr, "failed to create window");

	SDL_GLContext context = SDL_GL_CreateContext(window);
	SDL_ASSERT(context != nullptr, "failed to create opengl context");

	SDL_FAILED(SDL_GL_MakeCurrent(window, context));
	CHECK(gladLoadGLLoader((GLADloadproc)(SDL_GL_GetProcAddress)));

	Shader shader;
	shader.Initialize("Shader/Shader.vert", "Shader/Shader.frag");

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

	SDL_Event e;
	bool bIsDone = false;
	while (!bIsDone)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				bIsDone = true;
			}
		}

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shader.Bind();
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, vertices.size());
		glBindVertexArray(0);
		shader.Unbind();

		SDL_GL_SwapWindow(window);
	}

	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);

	shader.Release();

	SDL_GL_DeleteContext(context);
	context = nullptr;

	SDL_DestroyWindow(window);
	window = nullptr;

	SDL_Quit();
	return 0;
}