#ifndef VEHICLE_HPP_
#define VEHICLE_HPP_

#include <GL/glut.h>
#include <stdio.h>
#include "Shape.hpp"

class Vehicle: public Shape {
protected:
	GLfloat vertex[8][3];	//[v]->[x][y][z]
	GLint face[6][4];		//[face][vertex index]
	GLfloat r, g, b;
	GLint direction;	// Horizontal = 0, Vertical = 0
	GLint id;

public:
	Vehicle(GLint size, GLint id, GLint dir);
	Vehicle() = delete;
	~Vehicle();
	GLint getID();
	void draw();
	void drawMC();

private:
	void draw_face(int);
};

#endif /* VEHICLE_HPP_ */
