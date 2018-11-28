#include "House.hpp"

House::House() {
// your definition of cube vertices and faces
	base = new Cube();
	roof = new Pyramid();
	roof->translate(0.0, 1.0, 0.0);
}

void House::draw() {
	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	base->draw();
	roof->draw();
	glPopMatrix();
}
