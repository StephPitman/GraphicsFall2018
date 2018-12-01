/*
 * menu.cpp
 *
 *  Created on: Nov 24, 2018
 *      Author: Stephanie
 */

#include "Menu.hpp"

extern Board myBoard;
extern GLint* myLevel;
extern Vehicle* myVehicles[13];
extern GLint numVehicles;

void menu() {
	GLint levelMenu = glutCreateMenu(levelSelect);
	glutAddMenuEntry("Level 1", 1);
	glutAddMenuEntry("Level 2", 2);
	glutAddMenuEntry("Level 3", 3);

	glutCreateMenu(mainMenu);
	glutAddSubMenu("Level Select", levelMenu);
	glutAddMenuEntry("Quit", 1);

}
void levelSelect(GLint option) {
	for(int i = 0; i < numVehicles; i++){
		delete myVehicles[i];
	}
	switch (option) {
	//http://www.puzzles.com/products/rushhour/rhfrommarkriedel/Jam.html?1
	case 1:
		numVehicles = 8;
		myVehicles[0] = new Vehicle(2, 2, 0);
		myVehicles[1] = new Vehicle(2, 3, 0);
		myVehicles[2] = new Vehicle(3, 4, 1);
		myVehicles[3] = new Vehicle(2, 5, 1);
		myVehicles[4] = new Vehicle(3, 6, 1);
		myVehicles[5] = new Vehicle(2, 7, 1);
		myVehicles[6] = new Vehicle(2, 8, 0);
		myVehicles[7] = new Vehicle(4, 9, 0);
		//myLevel = new int[6][6];
		GLint lvl = {{3,3,0,0,0,4},{5,0,0,6,0,4},{5,2,2,6,0,4},{5,0,0,6,0,0},{7,0,0,0,8,8},{7,0,9,9,9,9}};
		myBoard.setLevel(lvl);
		break;
		case 2:
		break;
	};
	glutPostRedisplay();
}
void mainMenu(GLint option) {
	switch (option) {
	case 1:
		exit(0);
		break;
	}
}
