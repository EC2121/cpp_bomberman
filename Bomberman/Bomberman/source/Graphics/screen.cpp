#include "screen.h"
#include "SDL.h"
#include <iostream>
namespace Graphics {


	Screen::Screen(const int in_width, const int in_height)
		: Screen()
	{

		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER) != 0)
		{
			error_type = SET_SDL_INIT_ERROR;
			std::cout << error_type << SDL_GetError();
			return;
		}
		window = SDL_CreateWindow("SDL is active!", 0, 100, in_width, in_height, 0);
		if (window == nullptr)
		{
			error_type = SET_SDL_WINDOW_INIT_ERROR;
			std::cout << error_type << SDL_GetError();
		}
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (!renderer)
		{
			error_type = SET_SDL_RENDERER_INIT_ERROR;
			std::cout << error_type << SDL_GetError();
		}
	}

	Screen::~Screen()
	{
		if (renderer)
		{
			SDL_DestroyRenderer(renderer);
		}
		if (window)
		{
			SDL_DestroyWindow(window);
		}
		if (SDL_WasInit(0))
		{
			SDL_Quit();
		}

	}




}