#include <SDL.h>
#include <SDL_image.h>
#include "Animation.h"
#pragma once

class Sprite
{
public:
	Sprite(SDL_Renderer*);
	~Sprite();
	void Render(SDL_Renderer*);
	void Jump();
	void Climb();

private:
	Animation fsm;

	SDL_Rect spriteRect;
	SDL_Rect frameRect;
	SDL_Texture * texture;
};

