/*
 * HBF
 */
#ifndef CWORLD_HPP
#define CWORLD_HPP
#include <iostream>
#include <list>
#include <vector>
#include "Board.hpp"

class World {

public:
	GLint counter;
	Shape *list[5];
	World();
	~World();
	void drawWorld();  // draw all objects in the world
	void resetWorld(); //resets all objects
};

#endif
