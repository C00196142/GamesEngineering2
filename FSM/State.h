#pragma once
#include "Animation.h"
#include <iostream>

//class State
//{
//public:
//
//	virtual void idle(Animation* a)
//	{
//		std::cout << "State::Idling" << std::endl;
//	}
//
//	virtual void jumping(Animation* a)
//	{
//		std::cout << "State::Jumping" << std::endl;
//	}
//
//	virtual void climbing(Animation* a)
//	{
//		std::cout << "State::Climbing" << std::endl;
//	}
//
//	virtual void Animate(SDL_Rect&, Animation*) = 0;
//
//};
//
//class Idle : public State
//{
//public:
//	Idle();
//	~Idle();
//
//	void jumping(Animation* a);
//	void climbing(Animation* a);
//	virtual void Animate(SDL_Rect&, Animation*);
//};
//
//
//class Jumping : public State
//{
//public:
//	Jumping() {};
//	~Jumping() {};
//
//	void idle(Animation* a);
//};
//
//
//class Climbing : public State
//{
//public:
//	Climbing() {};
//	~Climbing() {};
//
//	void idle(Animation* a)
//	{
//		std::cout << "Going from Climbing to Idling" << std::endl;
//		a->setCurrent(new Idle());
//		delete this;
//	}
//};
