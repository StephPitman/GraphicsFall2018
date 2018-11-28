/**
 * File: World.hpp
 */

#include "World.hpp"

World::World() {
	objnum = 3; // number of object
	list[0] = (Shape*) malloc( sizeof(Shape*) * objnum);  // array to hold object pointers

	//cube object
	list[0] = new Cube();

	//Pyramid, replace the following by your pyramid
	list[1] = new Pyramid();

	//house, replace the following by your house
	list[2] = new House();

}

World::~World(){
	for (int i = 0; i<objnum; i++)
	   delete list[i];

	free(list);
}

void World::draw() {
	for (int i = 0; i<objnum; i++)
	   list[i]->draw();
}

void World::reset() {
	for (int i = 0; i<objnum; i++)
	   list[i]->reset();
}

