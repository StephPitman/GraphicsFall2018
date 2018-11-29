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

#include "board.hpp"
#include "menu.hpp"
#include "level.hpp"
#include "World.hpp"
#include "Camera.hpp"
using namespace std;

//Global Variables
GLint winWidth = 700;GLint winHeight = 700;
board myBoard;
level curLevel;
GLint numMoves;

World myWorld;
Camera myCamera;

void init(){

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Traffic Jam");
	glClearColor(0.0, 0.0, 0.0, 1.0);  //Set display-window color to black
	myCamera.setProjectionMatrix();


}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Shape *p = NULL;
	p = &myBoard;



	p->draw();
	/*rx = p->getMC().mat[0][1];
	ry = p->getMC().mat[1][1];
	rz = p->getMC().mat[2][1];
	p->rotateMC(rx, ry, rz, 100 * 0.5);
	p->draw();*/
	//std::cout << "HERE\n";
	glutPostRedisplay();
	glFlush();
	glutSwapBuffers();
	//getchar();
}

int main(int argc, char** argv) {
	setvbuf(stdout, NULL, _IONBF, 0);  //used for prompt Eclipse console output
	setvbuf(stderr, NULL, _IONBF, 0);
	//ShowWindow(FindWindowA("ConsoleWindowClass", NULL), false);  //used to hide console

	glutInit(&argc, argv);
	menu();
	init(); //MAY NOT NEED THIS

	Shape *p = NULL;
	p = &myBoard;
	GLfloat rx,ry,rz;
	rx = p->getMC().mat[0][1];
	ry = p->getMC().mat[1][1];
	rz = p->getMC().mat[2][1];
	p->rotateMC(rx, ry, rz, 53 * 0.5);



	rx = p->getMC().mat[0][0];
	ry = p->getMC().mat[1][0];
	rz = p->getMC().mat[2][0];
	p->rotateMC(rx, ry, rz, 130 * 0.5);



	glutDisplayFunc(display);
	/*glutMotionFunc(mouseMotion);
	glutMouseFunc(mouseAction);*/ //WORK WITH THESE AFTER CLASSES IMPLEMENTED
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();

	return 0;


}
