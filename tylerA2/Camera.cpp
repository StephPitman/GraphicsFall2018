#include <stdio.h>
#include "Camera.hpp"
#include "Matrix.hpp"

bool DEBUG = false;

Camera::Camera() {
	setDefaultCamera();
}

void Camera::setDefaultCamera(void) { // make default camera
	eye.set(5.0, 5.0, 10.0);
	ref.set(0, 0, 0);
	viewup.set(0, 1, 0);
	aspect = 1.0, vangle = 40.0, dnear = 1.0, dfar = 15.0;
}

void Camera::set(Point Eye, Point Look, Vector Up) {
	eye.set(Eye);
	ref.set(Look);
	viewup.set(Up);
	aspect = 1.0, vangle = 40.0, dnear = 1.0, dfar = 15.0;
}

void Camera::setProjectionMatrix() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(vangle, aspect, dnear, dfar);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye.x, eye.y, eye.z, ref.x, ref.y, ref.z, viewup.x, viewup.y,
			viewup.z);

}

void Camera::rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) { //w.r.p.t WC
// need to be implemented
	Matrix *m = new Matrix();
	m->rotateMatrix(rx, ry, rz, angle);

	GLfloat v[4];

	v[0] = eye.x;
	v[1] = eye.y;
	v[2] = eye.z;
	v[3] = 1;

	m->multiplyVector(v);

	eye.x = v[0];
	eye.y = v[1];
	eye.z = v[2];

	delete m;
}

void Camera::translate(GLfloat tx, GLfloat ty, GLfloat tz) { //w.r.p.t WC
// need to be implemented
	eye.x += tx;
	eye.y += ty;
	eye.z += tz;
}

