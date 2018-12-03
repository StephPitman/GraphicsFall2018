/*
 * board.hpp
 *
 *  Created on: Nov 24, 2018
 *      Author: Stephanie
 */

#ifndef BOARD_HPP_
#define BOARD_HPP_

#include <GL/glut.h>
#include <stdio.h>
#include "Vehicle.hpp"
#include "World.hpp"
#include "Camera.hpp"

class Board:public Shape{
protected:
	GLfloat vertex[36][3]; // [vertex index][x,y,z]
	GLint face[36][4]; // [face index][v1,v2,v3,v4]
	GLfloat cube_face_norm_mc[36][3];  // normal for each face in MC
	GLint matrix[8][8];
public:
	Board();
	~Board();
	bool isBackface(int faceindex);
	void setLevel(GLint mat[6][6]);
	void drawFace(GLint f, GLint l); // l is to draw an outline
	void draw();
};


#endif /* BOARD_HPP_ */
