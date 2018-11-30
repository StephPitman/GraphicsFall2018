/*
 * level.cpp
 *
 *  Created on: Nov 24, 2018
 *      Author: Stephanie
 */

#include "Level.hpp"

Level::Level(GLint lvl[6][6]) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			levelMatrix[i][j] = lvl[i][j];
		}
	}
}

Level::~Level() {

}

void Level::setLevel(GLint lvl[6][6]) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			levelMatrix[i][j] = lvl[i][j];
		}
	}
}
