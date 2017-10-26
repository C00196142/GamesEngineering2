#pragma once

#include <vector>
#include <iostream>
#include "Entity.h"

class AISystem
{
	std::vector<Entity> entities;

public:
	AISystem() {};
	~AISystem() {};

	void addEntity(Entity e) 
	{
		/* TBI */ 
	}
	void update()
	{
		std::cout << "AISystem Update" << std::endl;
		/* Loop through Entities with */
		/* AIComponents and Update */
		/* TBI */
	}
};
