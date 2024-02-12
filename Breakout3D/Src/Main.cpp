#include <cstdint>
#include <windows.h>

#include <SDL.h>

int32_t WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR pCmdLine, _In_ int32_t nCmdShow)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Quit();
	return 0;
}