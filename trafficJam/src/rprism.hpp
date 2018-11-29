/*
 * rprism.hpp
 *
 *  Created on: Nov 24, 2018
 *      Author: Stephanie
 */

#ifndef RPRISM_HPP_
#define RPRISM_HPP_

#include "Shape.hpp"

class rprism:public Shape{
protected:
	GLfloat vertex[8][3];
	GLint face[6][4];
	GLint length; //length of vehicle in units
	GLuint textureID; //red car is unique
	GLint direction; // Horizontal =0 ;

public:
	rprism(GLint len,GLint dir);
	~rprism();
	GLint getLenght();
	void setLenght(GLint len);
	void setTexture(GLuint text);
	GLint getDirection();
	void setDirection(GLint direct);
	void draw();
};



#endif /* RPRISM_HPP_ */
