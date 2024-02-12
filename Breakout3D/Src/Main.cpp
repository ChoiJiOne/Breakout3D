#include <cstdint>
#include <windows.h>

#include <SDL.h>

int32_t WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR pCmdLine, _In_ int32_t nCmdShow)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window = SDL_CreateWindow("Breakout3D", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 800, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

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
	}

	SDL_DestroyWindow(window);
	window = nullptr;

	SDL_Quit();
	return 0;
}