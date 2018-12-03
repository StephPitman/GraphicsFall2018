//============================================================================
// Name        : trafficJam.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "Board.hpp"
#include "World.hpp"
#include "Camera.hpp"
#include "Menu.hpp"
#include "Vehicle.hpp"
using namespace std;

//Global Variables
GLint winWidth = 700;
GLint winHeight = 700;
GLint xbegin = 0;
Board *myBoard;	// Game board
Vehicle* myVehicles[13];
GLint numVehicles = 0;
GLint numMoves;
bool loaded[13];

GLint selected;	// Selected vehicle (from color menu)
GLint moving = 0;
GLint movingDir = 0;

World myWorld;
Camera myCamera;

void init() {

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Traffic Jam");
	glClearColor(0.0, 0.0, 0.0, 1.0);  //Set display-window color to black
	myCamera.setProjectionMatrix();

}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	myCamera.setProjectionMatrix();

	myWorld.drawWorld();

	glFlush();
	glutSwapBuffers();
}

void mouseAction(int button, int action, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
		if (action == GLUT_DOWN) {
			moving = 1;
			xbegin = x;
		} else if (action == GLUT_UP) {
			moving = 0;
		}
	}
}

void mouseMotion(GLint x, GLint y) {
	GLfloat rx, ry, rz, theta;
	Shape *sshapep = NULL;
	sshapep = myWorld.list[selected];

	if (moving) {

		if (movingDir == 0) {	// Translate x
			theta = (xbegin - x > 0) ? 1 : -1;
			rx = theta;
			ry = 0;
			rz = 0;
			sshapep->translate(rx, ry, rz);
		}

		else {	// Translate Z
			theta = (xbegin - x > 0) ? 1 : -1;
			rx = 0;
			ry = 0;
			rz = theta;
			sshapep->translate(rx, ry, rz);
		}

		sshapep->getMC().normalize();

		glutPostRedisplay();
	}

}

int main(int argc, char** argv) {
	setvbuf(stdout, NULL, _IONBF, 0);  //used for prompt Eclipse console output
	setvbuf(stderr, NULL, _IONBF, 0);
	//ShowWindow(FindWindowA("ConsoleWindowClass", NULL), false);  //used to hide console

	glutInit(&argc, argv);
	menu();	// initialize menu
	init(); // initialize window

	myBoard = new Board(); // initialize board
	myWorld.insert(myBoard, 0); // initialize world

	glutDisplayFunc(display);
	glutMotionFunc(mouseMotion);
	glutMouseFunc(mouseAction);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();

	return 0;

}
