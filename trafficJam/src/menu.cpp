/*
 * menu.cpp
 *
 *  Created on: Nov 24, 2018
 *      Author: Stephanie
 */

#include "menu.hpp"

void menu(){
	GLint levelMenu = glutCreateMenu(levelSelect);
	glutAddMenuEntry("Level 1",1);
	glutAddMenuEntry("Level 2",2);
	glutAddMenuEntry("Level 3",3);

	glutCreateMenu(mainMenu);
	glutAddSubMenu("Level Select",levelMenu);
	glutAddMenuEntry("Quit",1);

}
void levelSelect(GLint option){

}
void mainMenu(GLint option){
	switch(option){
		case 1:
			exit(0);
			break;
	}
}
