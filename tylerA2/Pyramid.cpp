#include "Pyramid.hpp"

Pyramid::Pyramid() {
// your definition of cube vertices and faces
	vertex[0][0] = -0.5;	// front left | x
	vertex[0][1] = -0.5;	// front left | y
	vertex[0][2] = 0.5;		// front left | z

	vertex[1][0] = -0.5;	// back left | x
	vertex[1][1] = -0.5;	// back left | y
	vertex[1][2] = -0.5;	// back left | z

	vertex[2][0] = 0.5;		// back right | x
	vertex[2][1] = -0.5;	// back right | y
	vertex[2][2] = -0.5;	// back right | z

	vertex[3][0] = 0.5;		// front right | x
	vertex[3][1] = -0.5;	// front right | y
	vertex[3][2] = 0.5;		// front right | z

	vertex[4][0] = 0;		// middle | x
	vertex[4][1] = 0.5;		// middle | y
	vertex[4][2] = 0;		// middle | z

	// face[x][y]	x = face, y = vertex

	face[0][0] = 0;		// front | front left
	face[0][1] = 3;		// front | front right
	face[0][2] = 4;		// front | top
	face[0][3] = -1;	// empty

	face[1][0] = 1;		// back | back left
	face[1][1] = 2;		// back | back right
	face[1][2] = 4;		// back | top
	face[1][3] = -1;	// empty

	face[2][0] = 0;		// left | front left
	face[2][1] = 1;		// left | back left
	face[2][2] = 4;		// left | top
	face[2][3] = -1;	// empty

	face[3][0] = 3;		// right | front right
	face[3][1] = 2;		// right | back right
	face[3][2] = 4;		// right | top
	face[3][3] = -1;	// empty

	face[4][0] = 0;		// bottom | front left
	face[4][1] = 1;		// bottom | back left
	face[4][2] = 2;		// bottom | back right
	face[4][3] = 3;		// bottom | front right

	r = 1.0;
	g = 1.0;
	b = 0;
}

void Pyramid::draw_face(int i) {
// your drawing of face i

	glBegin(GL_LINE_LOOP);
	glVertex3fv(vertex[face[i][0]]);	// first coord
	glVertex3fv(vertex[face[i][1]]);	// second coord
	glVertex3fv(vertex[face[i][2]]);	// third coord
	if (face[i][3] != -1) {
		glVertex3fv(vertex[face[i][3]]);	// fourth coord
	}
	glEnd();
}

void Pyramid::drawMC() {
	// replace the following by your cube drawing
	glColor3f(r, g, b);
	//glutWireCube(1);
	for (int i = 0; i < 5; i++) {
		draw_face(i);
	}
}

void Pyramid::draw() {
	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	drawMC();
	glPopMatrix();
}
