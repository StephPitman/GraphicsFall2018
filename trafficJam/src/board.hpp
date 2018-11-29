/*
 * board.hpp
 *
 *  Created on: Nov 24, 2018
 *      Author: Stephanie
 */

#ifndef BOARD_HPP_
#define BOARD_HPP_

#include "Shape.hpp"

class board:public Shape{
protected:
	GLfloat vertex[16][3];
	GLint face[13][4];
	GLint matrix[8][8];
public:
	board();
	~board();
	void setMatrix(GLint mat[8][8]);
	GLint* getMatrix();
	void drawFace(GLint f);
	void draw();
};


#endif /* BOARD_HPP_ */
