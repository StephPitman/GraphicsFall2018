#include "Menu.hpp"

extern GLint coordinate, objIndex, option;
extern World myWorld;

void ObjSubMenu(GLint objectOption) {
	objIndex = objectOption;
	glutPostRedisplay();
}

void MCTransMenu(GLint transOption) {
	coordinate = 1;
	option = transOption;
	glutPostRedisplay();
}

void WCTransMenu(GLint transOption) {
	coordinate = 2;
	option = transOption;
	glutPostRedisplay();;
}

void VCTransMenu(GLint transOption) {
	coordinate = 3;
	option = transOption;
	glutPostRedisplay();
}


void mainMenu(GLint transOption) {
	switch (transOption) {
	case 1:
		myWorld.reset();
		break;
	case 2:
	  exit(1);
		break;
	}
	glutPostRedisplay();
}

void menu() {
	GLint  MCTrans_Menu = glutCreateMenu(MCTransMenu);
	glutAddMenuEntry("Rotate x ", 1);
	glutAddMenuEntry("Rotate y ", 2);
	glutAddMenuEntry("Rotate z", 3);
	glutAddMenuEntry("Scale", 4);

	GLint WCTrans_Menu = glutCreateMenu(WCTransMenu);
	glutAddMenuEntry("Rotate x ", 1);
	glutAddMenuEntry("Rotate y ", 2);
	glutAddMenuEntry("Rotate z", 3);
	glutAddMenuEntry("Translate x ", 4);
	glutAddMenuEntry("Translate y ", 5);
	glutAddMenuEntry("Translate z", 6);

	GLint VCTrans_Menu = glutCreateMenu(VCTransMenu);
	glutAddMenuEntry("Rotate x ", 1);
	glutAddMenuEntry("Rotate y ", 2);
	glutAddMenuEntry("Rotate z", 3);
	glutAddMenuEntry("Translate x ", 4);
	glutAddMenuEntry("Translate y ", 5);
	glutAddMenuEntry("Translate z", 6);
	glutAddMenuEntry("Clipping Near ", 7);
	glutAddMenuEntry("Clipping Far ", 8);

	GLint Object_Menu = glutCreateMenu(ObjSubMenu);
	glutAddMenuEntry("Cube ", 0);
	glutAddMenuEntry("Pyramid ", 1);
	glutAddMenuEntry("House ", 2);

	glutCreateMenu(mainMenu);      // Create main pop-up menu.
	glutAddMenuEntry("Reset ", 1);
	glutAddSubMenu("Object Selection ", Object_Menu);
	glutAddSubMenu("Model Transformations ", MCTrans_Menu);
	glutAddSubMenu("WC Transformations ", WCTrans_Menu);
	glutAddSubMenu("View Transformations ", VCTrans_Menu);
	glutAddMenuEntry("Quit", 2);
}

