#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "State.h"

class Animation
{
	class State* current;
public:
	
	Animation();
	~Animation();

	void setCurrent(State* s)
	{
		current = s;
	}
	void idle();
	void jumping();
	void climbing();

	void Update(SDL_Rect&);
};

class State
{
public:

	virtual void idle(Animation* a)
	{
		std::cout << "State::Idling" << std::endl;
	}

	virtual void jumping(Animation* a)
	{
		std::cout << "State::Jumping" << std::endl;
	}

	virtual void climbing(Animation* a)
	{
		std::cout << "State::Climbing" << std::endl;
	}

	virtual void Animate(SDL_Rect&, Animation*) = 0;

};

class Idle : public State
{
public:
	Idle() {};
	~Idle() {};

	void jumping(Animation* a);
	void climbing(Animation* a);
	virtual void Animate(SDL_Rect&, Animation*);
};


class Jumping : public State
{
public:
	Jumping() {};
	~Jumping() {};

	void idle(Animation* a);
	virtual void Animate(SDL_Rect&, Animation*);
};


class Climbing : public State
{
public:
	Climbing() {};
	~Climbing() {};

	void idle(Animation* a);
	virtual void Animate(SDL_Rect&, Animation*);
};

