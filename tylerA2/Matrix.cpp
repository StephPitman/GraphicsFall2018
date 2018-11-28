/**
 *	File Matrix.cpp
 *	Description: implementation of Matrix class
 *
 */

#include "Matrix.hpp"

// mat <- identity matrix
Matrix::Matrix() {
	loadIdentity();
}

void Matrix::loadIdentity() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j)
				mat[i][j] = 1;
			else
				mat[i][j] = 0;
		}
	}
}

// multiplication  mat <- m * mat
void Matrix::matrixPreMultiply(Matrix* m) {
	GLfloat temp[4][4], sum = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			sum = 0;
			for (int k = 0; k < 4; k++) {
				sum += m->mat[i][k] * mat[k][j];
			}
			temp[i][j] = sum;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mat[i][j] = temp[i][j];
		}
	}
}

// transpose  mat <- mat'
void Matrix::transpose() {
// your implementation
	GLfloat temp;
	for (int i = 0; i < 4; i++) {
		for (int j = i; j < 4; j++) {
			if (i == j) {
				continue;
			}
			temp = mat[i][j];
			mat[i][j] = mat[j][i];
			mat[j][i] = temp;
		}
	}
}

// normalize mat
void Matrix::normalize() {
// your implementaiton
	GLfloat norm = sqrt(
			mat[0][0] * mat[0][0] + mat[1][0] * mat[1][0]
					+ mat[2][0] * mat[2][0]);
	mat[0][0] = mat[0][0] / norm;
	mat[1][0] = mat[1][0] / norm;
	mat[2][0] = mat[2][0] / norm;
	mat[0][2] = mat[1][0] * mat[2][1] - mat[2][0] * mat[1][1];
	mat[1][2] = mat[2][0] * mat[0][1] - mat[0][0] * mat[2][1];
	mat[2][2] = mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];
	norm = sqrt(
			mat[0][2] * mat[0][2] + mat[1][2] * mat[1][2]
					+ mat[2][2] * mat[2][2]);
	mat[0][2] = mat[0][2] / norm;
	mat[1][2] = mat[1][2] / norm;
	mat[2][2] = mat[2][2] / norm;
	mat[0][1] = mat[1][2] * mat[2][0] - mat[1][0] * mat[2][2];
	mat[1][1] = mat[2][2] * mat[0][0] - mat[2][0] * mat[0][2];
	mat[2][1] = mat[0][2] * mat[1][0] - mat[0][0] * mat[1][2];
	mat[3][0] = 0;
	mat[3][1] = 0;
	mat[3][2] = 0;
	mat[3][3] = 1;
}

// v  <- mat * v
void Matrix::multiplyVector(GLfloat *v) {
// your implementaiton
	GLfloat sum, temp[4];
	for (int i = 0; i < 4; i++) {
		sum = 0;
		for (int j = 0; j < 4; j++) {
			sum += v[j] * this->mat[i][j];
		}
		temp[i] = sum;
	}
	for (int k = 0; k < 4; k++) {
		v[k] = temp[k];
	}
}

// mat <- rotation matrix (rx, ry, rz, angle)
void Matrix::rotateMatrix(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) {
// your implementaiton

	GLfloat a = angle * 3.1415926 / 180;
	GLfloat vLen = sqrt(rx * rx + ry * ry + rz + rz);

	GLfloat cosA = cos(a);
	GLfloat subA = 1 - cosA;
	GLfloat sinA = sin(a);

	Matrix* m = new Matrix();

	m->mat[0][0] = rx * rx * subA + cosA;
	m->mat[0][1] = rx * ry * subA + rz * sinA;
	m->mat[0][2] = rx * rz * subA - ry * sinA;
	m->mat[0][3] = 0;

	m->mat[1][0] = rx * ry * subA - rz * sinA;
	m->mat[1][1] = ry * ry * subA + cosA;
	m->mat[1][2] = ry * rz * subA + rx * sinA;
	m->mat[1][3] = 0;

	m->mat[2][0] = rx * rz * subA + ry * sinA;
	m->mat[2][1] = ry * rz * subA - rx * sinA;
	m->mat[2][2] = rz * rz * subA + cosA;
	m->mat[2][3] = 0;

	m->mat[3][0] = 0;
	m->mat[3][1] = 0;
	m->mat[3][2] = 0;
	m->mat[3][3] = 1;

	this->matrixPreMultiply(m);
	delete m;
}

