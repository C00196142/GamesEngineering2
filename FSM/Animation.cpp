#include "Animation.h"



Animation::Animation()
{
	current = new Idle();
}


Animation::~Animation()
{
}

void Animation::idle()
{
	current->idle(this);
}

void Animation::jumping()
{
	current->jumping(this);
}

void Animation::climbing()
{
	current->climbing(this);
}

void Animation::Update(SDL_Rect & rect)
{
	current->Animate(rect, this);
}