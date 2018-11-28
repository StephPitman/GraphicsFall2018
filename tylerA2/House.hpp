#ifndef CHOUSE_H
#define CHOUSE_H

#include <GL/glut.h>
#include "Cube.hpp"
#include "Pyramid.hpp"

class House: public Shape {
protected:
	Cube* base;
	Pyramid* roof;

public:
	House();
	void draw();
};

#endif
