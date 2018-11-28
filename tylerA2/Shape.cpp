#include "Shape.hpp"

Shape::Shape() {
	reset();
}

Shape::~Shape() {
}

void Shape::reset() {
	mc.loadIdentity();
	s = 1;
}

Matrix Shape::getMC() {
	return mc;
}

GLfloat Shape::getS() {
	return s;
}

void Shape::translate(GLfloat tx, GLfloat ty, GLfloat tz) {
	mc.mat[0][3] += tx;
	mc.mat[1][3] += ty;
	mc.mat[2][3] += tz;
	mc.mat[3][3] = 1;
}

void Shape::scaleChange(GLfloat x) {
	s += x;
}

/**
 * Shape::ctm_multiply() multiply this matrix to openGL current matrix
 */
void Shape::ctmMultiply() {
	/*GLfloat M[16];
	 M[0] = mc.mat[0][0];
	 M[1] = mc.mat[1][0];
	 M[2] = mc.mat[2][0];
	 M[3] = 0;
	 M[4] = mc.mat[0][1];
	 M[5] = mc.mat[1][1];
	 M[6] = mc.mat[2][1];
	 M[7] = 0;
	 M[8] = mc.mat[0][2];
	 M[9] = mc.mat[1][2];
	 M[10] = mc.mat[2][2];
	 M[11] = 0;
	 M[12] = mc.mat[0][3];
	 M[13] = mc.mat[1][3];
	 M[14] = mc.mat[2][3];
	 M[15] = 1;
	 glMultMatrixf(M);*/

// change the following when transpose is implemented
	mc.transpose();
	glMultMatrixf(&mc.mat[0][0]);
	mc.transpose();

}

void Shape::rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) {
// your implementation
	Matrix* m = new Matrix();
	m->rotateMatrix(rx, ry, rz, angle);
	GLfloat v[4];
	v[0] = mc.mat[0][3];
	v[1] = mc.mat[1][3];
	v[2] = mc.mat[2][3];
	v[3] = mc.mat[3][3];

	m->multiplyVector(v);
	mc.mat[0][3] = v[0];
	mc.mat[1][3] = v[1];
	mc.mat[2][3] = v[2];
	mc.mat[3][3] = v[3];

	delete m;
}

void Shape::rotateMC(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) {
// your implementation
	Matrix* m = new Matrix();

	GLfloat v[3];
	v[0] = mc.mat[0][3];
	v[1] = mc.mat[1][3];
	v[2] = mc.mat[2][3];

	m->rotateMatrix(rx, ry, rz, angle);
	mc.matrixPreMultiply(m);

	mc.mat[0][3] = v[0];
	mc.mat[1][3] = v[1];
	mc.mat[2][3] = v[2];

	delete m;
}

void Shape::rotateOrigin(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) {
// your implementation

}

