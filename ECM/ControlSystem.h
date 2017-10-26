#pragma once

#include <vector>
#include <iostream>
#include "Entity.h"

class ControlSystem
{
	std::vector<Entity> entities;

public:
	ControlSystem() {};
	~ControlSystem() {};

	void addEntity(Entity e) {/* TBI */ }
	void update()
	{
		std::cout << "ControlSystem Update" << std::endl;
		/* Loop through Entities with */
		/* AIComponents and Update */
		/* TBI */
	}
};
