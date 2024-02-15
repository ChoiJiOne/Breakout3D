#include <SDL.h>

#include "Assertion.h"
#include "SDLManager.h"

/**
 * @brief OpenGL의 버전입니다.
 *
 * @note 이 값은 4.6으로 고정되어 있습니다.
 */
#define FIX_OPENGL_MAJOR_VERSION 4 // OpenGL 주(4) 버전입니다.
#define FIX_OPENGL_MINOR_VERSION 6 // OpenGL 부(6) 버전입니다.

SDLManager& SDLManager::Get()
{
	static SDLManager instance;
	return instance;
}

void SDLManager::Startup()
{
	CHECK(!bIsStartup_);

	SDL_FAILED(SDL_Init(SDL_INIT_EVERYTHING));

	SDL_FAILED(SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG));
	SDL_FAILED(SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE));
	SDL_FAILED(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, FIX_OPENGL_MAJOR_VERSION));
	SDL_FAILED(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, FIX_OPENGL_MINOR_VERSION));
	SDL_FAILED(SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8));
	SDL_FAILED(SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8));
	SDL_FAILED(SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8));
	SDL_FAILED(SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8));
	SDL_FAILED(SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24));
	SDL_FAILED(SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8));
	SDL_FAILED(SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1));
	SDL_FAILED(SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1));
	SDL_FAILED(SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 16));

	SDL_Window* window = SDL_CreateWindow("Breakout3D", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 800, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	CHECK(window != nullptr);

	mainWindow_ = window;
	bIsStartup_ = true;
}

void SDLManager::Shutdown()
{
	CHECK(bIsStartup_);

	if (mainWindow_)
	{
		SDL_Window* window = reinterpret_cast<SDL_Window*>(mainWindow_);
		SDL_DestroyWindow(window);
		
		mainWindow_ = nullptr;
	}

	SDL_Quit();

	bIsStartup_ = false;
}