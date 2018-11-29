
#include "World.hpp"

#include "Board.hpp"

extern GLint selected;

extern GLint isAll;

World::World() {
	counter = 1;
	list[0] = new Board();

	/*counter = 5;
	list[0] = new Cube();
	list[0]->scaleChange(-0.2);

	list[1] = new Pyramid();
	list[1]->scaleChange(-0.2);
	list[1]->translate(-2.5, 0, 0);

	list[2] = new House();
	list[2]->scaleChange(-0.2);
	list[2]->translate(2.5, 0, 0);*/


//	 Mesh* mymesh = new Mesh();
//	 //mymesh->readMesh("BUCK.3VN");
//	mymesh->readMesh("BARN.3VN");
//	list[2] = mymesh;

}

World::~World(){
	for (int i=0; i < counter; i++)
		delete list[i];
}


void World::drawWorld() {
		for (int i=0; i<3; i++)
		list[i]->draw();
}

void World::resetWorld(){
	list[0]->reset();
	list[1]->reset();
	list[2]->reset();
}

