#include "Vehicle.hpp"

Vehicle::~Vehicle(){

}

Vehicle::Vehicle(GLint size, GLint col, GLint dir) {
	if(dir){	// Vertical
		vertex[0][0] = 0; vertex[0][1] = 0; vertex[0][2] = 0; // Back left bottom
		vertex[1][0] = 0; vertex[1][1] = 1; vertex[1][2] = 0; // Back left top
		vertex[2][0] = 1; vertex[2][1] = 1; vertex[2][2] = 0; // Back right top
		vertex[3][0] = 1; vertex[3][1] = 0; vertex[3][2] = 0; // Back right bottom

		vertex[4][0] = 0; vertex[4][1] = 0; vertex[4][2] = size; // Front left bottom
		vertex[5][0] = 0; vertex[5][1] = 1; vertex[5][2] = size; // Front left top
		vertex[6][0] = 1; vertex[6][1] = 1; vertex[6][2] = size; // Front right top
		vertex[7][0] = 1; vertex[7][1] = 0; vertex[7][2] = size; // Front right bottom
	}
	else{	// Horizontal
		vertex[0][0] = 0; vertex[0][1] = 0; vertex[0][2] = 0; // Back left bottom
		vertex[1][0] = 0; vertex[1][1] = 1; vertex[1][2] = 0; // Back left top
		vertex[2][0] = size; vertex[2][1] = 1; vertex[2][2] = 0; // Back right top
		vertex[3][0] = size; vertex[3][1] = 0; vertex[3][2] = 0; // Back right bottom

		vertex[4][0] = 0; vertex[4][1] = 0; vertex[4][2] = 1; // Front left bottom
		vertex[5][0] = 0; vertex[5][1] = 1; vertex[5][2] = 1; // Front left top
		vertex[6][0] = size; vertex[6][1] = 1; vertex[6][2] = 1; // Front right top
		vertex[7][0] = size; vertex[7][1] = 0; vertex[7][2] = 1; // Front right bottom
	}

	face[0][0] = 1; face[0][1] = 2; face[0][2] = 6; face[0][3] = 5; // Top
	face[1][0] = 0; face[1][1] = 3; face[1][2] = 7; face[1][3] = 4; // Bottom
	face[2][0] = 6; face[2][1] = 2; face[2][2] = 3; face[2][3] = 7; // Right
	face[3][0] = 1; face[3][1] = 5; face[3][2] = 4; face[3][3] = 0; // Left
	face[4][0] = 5; face[4][1] = 6; face[4][2] = 7; face[4][3] = 4; // Front
	face[5][0] = 1; face[5][1] = 2; face[5][2] = 3; face[5][3] = 0; // Back

	switch(col){
	case 2:
		r = 1.0;
		g = 0.0;
		b = 0.0;
		break;
	case 3:
		r = 1.0;
		g = 1.0;
		b = 0.0;
		break;
	case 4:
		r = 0.1;
		g = 0.7;
		b = 0.6;
		break;
	case 5:
		r = 0.0;
		g = 1.0;
		b = 1.0;
		break;
	case 6:
		r = 0.8;
		g = 0.4;
		b = 0.4;
		break;
	case 7:
		r = 1.0;
		g = 0.5;
		b = 0.0;
		break;
	case 8:
		r = 0.5;
		g = 0.0;
		b = 0.6;
		break;
	case 9:
		r = 0.0;
		g = 0.2;
		b = 0.5;
		break;
	case 10:
		r = 0.6;
		g = 0.4;
		b = 0.1;
		break;
	case 11:
		r = 0.2;
		g = 0.2;
		b = 0.2;
		break;
	case 12:
		r = 0.8;
		g = 0.8;
		b = 0.8;
		break;
	case 13:
		r = 0.0;
		g = 0.5;
		b = 0.3;
		break;
	case 14:
		r = 0.9;
		g = 0.9;
		b = 0.5;
		break;
	}
	id = col;
	direction = dir;
}

GLint Vehicle::getID(){
	return id;
}

void Vehicle::draw_face(int i) {
	glBegin(GL_POLYGON);
		glVertex3fv(vertex[face[i][0]]);	// first coord
		glVertex3fv(vertex[face[i][1]]);	// second coord
		glVertex3fv(vertex[face[i][2]]);	// third coord
		glVertex3fv(vertex[face[i][3]]);	// fourth coord
	glEnd();
}

void Vehicle::drawMC() {
	glColor3f(r, g, b);

	for (int i = 0; i < 6; i++) {
		draw_face(i);
	}
}

void Vehicle::draw() {
	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	drawMC();
	glPopMatrix();
}
