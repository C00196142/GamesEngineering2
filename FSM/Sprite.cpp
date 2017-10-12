#include "Sprite.h"

Sprite::Sprite(SDL_Renderer* renderer)
{
	texture = IMG_LoadTexture(renderer, "png/spritesheet.png");

	frameRect.x = 0;
	frameRect.y = 0;
	frameRect.w = 360;
	frameRect.h = 500;

	spriteRect.x = 0;
	spriteRect.y = 0;
	spriteRect.w = 128;
	spriteRect.h = 176;
}


Sprite::~Sprite()
{
}

void Sprite::Jump()
{
	fsm.jumping();
}

void Sprite::Climb()
{
	fsm.climbing();
}

void Sprite::Render(SDL_Renderer* renderer)
{
	fsm.Update(frameRect);
	SDL_RenderCopy(renderer, texture, &frameRect, &spriteRect);
}