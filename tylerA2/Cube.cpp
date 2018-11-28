#include "Cube.hpp"

Cube::Cube() {
// your definition of cube vertices and faces
	vertex[0][0] = -0.5;	// front bottom left | x
	vertex[0][1] = -0.5;	// front bottom left | y
	vertex[0][2] = 0.5;		// front bottom left | z

	vertex[1][0] = -0.5;	// front top left | x
	vertex[1][1] = 0.5;		// front top left | y
	vertex[1][2] = 0.5;		// front top left | z

	vertex[2][0] = 0.5;		// front top right | x
	vertex[2][1] = 0.5;		// front top right | y
	vertex[2][2] = 0.5;		// front top right | z

	vertex[3][0] = 0.5;		// front bottom right | x
	vertex[3][1] = -0.5;	// front bottom right | y
	vertex[3][2] = 0.5;		// front bottom right | z

	vertex[4][0] = -0.5;	// back bottom left | x
	vertex[4][1] = -0.5;	// back bottom left | y
	vertex[4][2] = -0.5;	// back bottom left | z

	vertex[5][0] = -0.5;	// back top left | x
	vertex[5][1] = 0.5;		// back top left | y
	vertex[5][2] = -0.5;	// back top left | z

	vertex[6][0] = 0.5;		// back top right | x
	vertex[6][1] = 0.5;		// back top right | y
	vertex[6][2] = -0.5;	// back top right | z

	vertex[7][0] = 0.5;		// back bottom right | x
	vertex[7][1] = -0.5;	// back bottom right | y
	vertex[7][2] = -0.5;	// back bottom right | z

	// face[x][y]	x = face, y = vertex

	face[0][0] = 0;		// front | front bottom left
	face[0][1] = 1;		// front | front top left
	face[0][2] = 2;		// front | front top right
	face[0][3] = 3;		// front | front bottom right

	face[1][0] = 4;		// back | back bottom left
	face[1][1] = 5;		// back | back top left
	face[1][2] = 6;		// back | back top right
	face[1][3] = 7;		// back | back bottom right

	face[2][0] = 0;		// left | front bottom left
	face[2][1] = 4;		// left | back bottom left
	face[2][2] = 5;		// left | back top left
	face[2][3] = 1;		// left | front top left

	face[3][0] = 3;		// right | front bottom right
	face[3][1] = 7;		// right | back bottom right
	face[3][2] = 6;		// right | back top right
	face[3][3] = 2;		// right | front top right

	face[4][0] = 0;		// bottom | front bottom left
	face[4][1] = 4;		// bottom | back bottom left
	face[4][2] = 7;		// bottom | back bottom right
	face[4][3] = 3;		// bottom | front bottom right

	face[5][0] = 1;		// top | front top left
	face[5][1] = 5;		// top | back top left
	face[5][2] = 6;		// top | back top right
	face[5][3] = 2;		// top | front top right

	r = 1.0;
	g = 0;
	b = 0;
}

void Cube::draw_face(int i) {
// your drawing of face i

	glBegin(GL_LINE_LOOP);
		glVertex3fv(vertex[face[i][0]]);	// first coord
		glVertex3fv(vertex[face[i][1]]);	// second coord
		glVertex3fv(vertex[face[i][2]]);	// third coord
		glVertex3fv(vertex[face[i][3]]);	// fourth coord
	glEnd();
}

void Cube::drawMC() {
	// replace the following by your cube drawing
	glColor3f(r, g, b);
	//glutWireCube(1);
	for (int i = 0; i < 6; i++) {
		draw_face(i);
	}
}

void Cube::draw() {
	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	drawMC();
	glPopMatrix();
}
