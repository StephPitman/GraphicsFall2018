/**
 *	CP411A2
 *	author: HBF, Tyler Allen
 *	date: 2019/09/29
 */

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "Menu.hpp"

// gloable variables
GLint winWidth = 800, winHeight = 800;
GLint xbegin = 0;     // x coordinate of mouse click
GLint coordinate = 1; // coordinate system selection : 1 for MC, 2 for WC, 3 for CV
GLint option = 4;     // transform option
GLint objIndex;       // index of selected object

GLint move1 = 0;

World myWorld;
Camera myCamera;

void init(void) {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("A2");
	glClearColor(0.0, 0.0, 0.0, 1.0);  //Set display-window color to black
	myCamera.setProjectionMatrix();
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	myCamera.setProjectionMatrix();
	myWorld.draw();
	glFlush();
	glutSwapBuffers();
}

void winReshapeFcn(GLint newWidth, GLint newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	winWidth = newWidth;
	winHeight = newHeight;
}

void mouseAction(int button, int action, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
		if (action == GLUT_DOWN) {
			move1 = 1;
			xbegin = x;
		} else if (action == GLUT_UP) {
			move1 = 0;
		}
	}
}

void mouseMotion(GLint x, GLint y) {
	GLfloat rx, ry, rz, theta;
	Shape *sshapep = NULL;
	sshapep = myWorld.list[objIndex];

	if (move1) {

		if (coordinate == 1 && option == 1) {	// MC rotate x
			theta = (xbegin - x > 0) ? 1 : -1;
			rx = sshapep->getMC().mat[0][0];
			ry = sshapep->getMC().mat[1][0];
			rz = sshapep->getMC().mat[2][0];
			sshapep->rotateMC(rx, ry, rz, theta);
		}

		else if (coordinate == 1 && option == 2) {	// MC rotate y
			theta = (xbegin - x > 0) ? 1 : -1;
			rx = sshapep->getMC().mat[0][1];
			ry = sshapep->getMC().mat[1][1];
			rz = sshapep->getMC().mat[2][1];
			sshapep->rotateMC(rx, ry, rz, theta);
		}

		else if (coordinate == 1 && option == 3) {	// MC rotate z
			theta = (xbegin - x > 0) ? 1 : -1;
			rx = sshapep->getMC().mat[0][2];
			ry = sshapep->getMC().mat[1][2];
			rz = sshapep->getMC().mat[2][2];
			sshapep->rotateMC(rx, ry, rz, theta);
		}

		else if (coordinate == 1 && option == 4) {	// MC scale
			theta = (xbegin - x < 0) ? 1 : -1;
			sshapep->scaleChange(theta * 0.02);
		}

		else if (coordinate == 2 && option == 1) {	// WC rotate x
			theta = (xbegin - x > 0) ? 1 : -1;
			rx = 1;
			ry = 0;
			rz = 0;
			theta = 1 * theta;
			sshapep->rotate(rx, ry, rz, theta);
		}

		else if (coordinate == 2 && option == 2) {	// WC rotate y
			theta = (xbegin - x > 0) ? 1 : -1;
			rx = 0;
			ry = 1;
			rz = 0;
			theta = 1 * theta;
			sshapep->rotate(rx, ry, rz, theta);
		}

		else if (coordinate == 2 && option == 3) {	// WC rotate z
			theta = (xbegin - x > 0) ? 1 : -1;
			rx = 0;
			ry = 0;
			rz = 1;
			theta = 1 * theta;
			sshapep->rotate(rx, ry, rz, theta);
		}

		else if (coordinate == 2 && option == 4) {	// WC translate x
			theta = (xbegin - x > 0) ? 1 : -1;
			rx = 0.05 * theta;
			ry = 0;
			rz = 0;
			sshapep->translate(rx, ry, rz);
		}

		else if (coordinate == 2 && option == 5) {	// WC translate y
			theta = (xbegin - x > 0) ? 1 : -1;
			rx = 0;
			ry = 0.05 * theta;
			rz = 0;
			sshapep->translate(rx, ry, rz);
		}

		else if (coordinate == 2 && option == 6) {	// WC translate z
			theta = (xbegin - x > 0) ? 1 : -1;
			rx = 0;
			ry = 0;
			rz = 0.05 * theta;
			sshapep->translate(rx, ry, rz);
		}

		else if (coordinate == 3 && option == 1) {	// CV rotate x
			theta = (xbegin - x < 0) ? 1 : -1;
			myCamera.rotate(1.0, 0.0, 0.0, theta * 0.5);
		}

		else if (coordinate == 3 && option == 2) {	// CV rotate y
			theta = (xbegin - x < 0) ? 1 : -1;
			myCamera.rotate(0.0, 1.0, 0.0, theta * 0.5);
		}

		else if (coordinate == 3 && option == 3) {	// CV rotate z
			theta = (xbegin - x < 0) ? 1 : -1;
			myCamera.rotate(0.0, 0.0, 1.0, theta * 0.5);
		}

		else if (coordinate == 3 && option == 4) {	// CV translate x
			theta = (xbegin - x > 0) ? 1 : -1;
			rx = 0.05 * theta;
			ry = 0;
			rz = 0;
			myCamera.translate(rx, ry, rz);
		}

		else if (coordinate == 3 && option == 5) {	// CV translate y
			theta = (xbegin - x > 0) ? 1 : -1;
			rx = 0;
			ry = 0.05 * theta;
			rz = 0;
			myCamera.translate(rx, ry, rz);
		}

		else if (coordinate == 3 && option == 6) {	// CV translate z
			theta = (xbegin - x > 0) ? 1 : -1;
			rx = 0;
			ry = 0;
			rz = 0.05 * theta;
			myCamera.translate(rx, ry, rz);
		}

		else if (coordinate == 3 && option == 7) {	// CV clipping near
		//empty
		}

		else if (coordinate == 3 && option == 8) {	// CV clipping far
		//empty
		}

		sshapep->getMC().normalize();

		glutPostRedisplay();
	}

}

int main(int argc, char** argv) {
	setvbuf(stdout, NULL, _IONBF, 0);  //used for prompt Eclipse console output
	setvbuf(stderr, NULL, _IONBF, 0);
	//	ShowWindow(FindWindowA("ConsoleWindowClass", NULL), false);  //used to hide console

	glutInit(&argc, argv);
	menu();
	init();
	glutDisplayFunc(display);
	glutMotionFunc(mouseMotion);
	glutMouseFunc(mouseAction);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}

