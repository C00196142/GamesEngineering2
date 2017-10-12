#include "Animation.h"


//IDLE
void Idle::jumping(Animation* a)
{
	a->setCurrent(new Jumping);
	delete this;
}

void Idle::climbing(Animation* a)
{
	a->setCurrent(new Climbing);
	delete this;
}

void Idle::Animate(SDL_Rect& rect, Animation* a)
{
	rect.y = 1000;
}

//JUMPING
void Jumping::idle(Animation* a)
{
	a->setCurrent(new Idle);
	delete this;
}

void Jumping::Animate(SDL_Rect& rect, Animation* a)
{
	rect.y = 500;

	if (rect.x < 2880)
	{
		rect.x += 360;
	}
	else
	{
		rect.x = 0;
		idle(a);
	}
}


//CLIMBING
void Climbing::idle(Animation* a)
{
	a->setCurrent(new Idle);
	delete this;
}

void Climbing::Animate(SDL_Rect& rect, Animation* a)
{
	rect.y = 0;

	if (rect.x < 2880)
	{
		rect.x += 360;
	}
	else
	{
		rect.x = 0;
		idle(a);
	}
}

