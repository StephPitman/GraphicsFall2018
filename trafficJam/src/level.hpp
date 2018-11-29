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

class level{
protected:
	GLint boardMatrix[6][6];
public:
	level();
	~level();
};



#endif /* LEVEL_HPP_ */
