/*
 *  file: menu.hpp
 *  author: HBF
 *  date: 2018/09/14
 */

#ifndef MENU_HPP_
#define MENU_HPP_

#include <GL/glut.h>
#include "World.hpp"
#include "Camera.hpp"

void MCTransMenu(GLint transOption);
void WCTransMenu(GLint transOption);
void mainMenu(GLint option);
void VCTransMenu(GLint transOption);
void ObjSubMenu(GLint objectOption);
void menu();

#endif
