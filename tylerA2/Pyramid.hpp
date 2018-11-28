#ifndef CPYRAMID_H
#define CPYRAMID_H

#include <GL/glut.h>
#include "Shape.hpp"

class Pyramid: public Shape {
protected:
	GLfloat vertex[5][3];	//[v]->[x][y][z]
	GLint face[5][4];		//[face][vertex index]
	GLfloat r, g, b;

public:
	Pyramid();
	void draw();
	void drawMC();

private:
	void draw_face(int);
};

#endif
