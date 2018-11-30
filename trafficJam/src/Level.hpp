/*
 * level.hpp
 *
 *  Created on: Nov 24, 2018
 *      Author: Stephanie
 */

#ifndef LEVEL_HPP_
#define LEVEL_HPP_

#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

class Level{
protected:
	GLint levelMatrix[6][6];
public:
	Level();
	Level(GLint lvl[6][6]);
	~Level();
	void setLevel(GLint lvl[6][6]);
};



#endif /* LEVEL_HPP_ */
