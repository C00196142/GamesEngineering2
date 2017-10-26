#pragma once

#include <vector>
#include <iostream>
#include "Entity.h"

class RenderSystem
{
	std::vector<Entity> entities;

public:
	RenderSystem() {};
	~RenderSystem() {};

	void addEntity(Entity e) 
	{
		/* TBI */ 
	}
	void update()
	{
		std::cout << "RenderSystem Update" << std::endl;
		/* Loop through Entities with */
		/* AIComponents and Update */
		/* TBI */
	}
};