#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <list>
#include <thread>

#include "Entity.h"

#include "HealthComponent.h"
#include "PositionComponent.h"
#include "ControlComponent.h"

#include "RenderSystem.h"
#include "AISystem.h"
#include "ControlSystem.h"

using namespace std;

int main(int argc, char* argv[])
{
	bool gameRunning = true;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window;
	window = SDL_CreateWindow("ECM", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	Entity player;

	HealthComponent hc; 
	PositionComponent pc;
	ControlComponent cc;
	player.addComponent(hc); 
	player.addComponent(pc);
	player.addComponent(cc);

	ControlSystem cs;
	RenderSystem rs;
	AISystem ais;
	cs.addEntity(player); 
	rs.addEntity(player);
	ais.addEntity(player);



	while (gameRunning)
	{
		SDL_Event event;
		cs.update();
		rs.update();
		ais.update();

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

				}

			}
		}
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);

	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	return 0;
}