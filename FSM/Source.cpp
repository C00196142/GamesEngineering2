#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <list>
#include <thread>

#include "Sprite.h"
#include "Animation.h"

using namespace std;

int main(int argc, char* argv[])
{
	bool gameRunning = true;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window;
	window = SDL_CreateWindow("FSM", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	Sprite Player(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	Animation fsm;

	while (gameRunning)
	{
		SDL_Event event;

		while (SDL_PollEvent(&event));
		{
			if (event.type == SDL_QUIT)
			{
				gameRunning = false;
			}
			switch (event.type)
			{
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_UP)
				{
					Player.Climb();
				}

				else if (event.key.keysym.sym == SDLK_RIGHT)
				{
					Player.Jump();
				}

			}
		}
		SDL_RenderClear(renderer);
		Player.Render(renderer);
		SDL_RenderPresent(renderer);

	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	return 0;
}

