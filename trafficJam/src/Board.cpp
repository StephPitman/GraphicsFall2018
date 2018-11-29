/*
 * board.cpp
 *
 *  Created on: Nov 24, 2018
 *      Author: Stephanie
 */

#include "Board.hpp"

Board::Board(){
	int i, j;
	for(i = 0; i < 8; i++){
		for(j = 0; j < 8; j++){
			if((i == 0 || j == 0) || (i == 7 || j == 7)){
				matrix[i][j] = 1;
			}
			else{
				matrix[i][j] = 0;
			}
		}
	}
	matrix[3][7] = 0;	// Escape block

	/*-------Base Plate-------*/
	vertex[0][0] = -4; vertex[0][1] = -1; vertex[0][2] = -4; // Back left bottom
	vertex[1][0] = -4; vertex[1][1] = 0; vertex[1][2] = -4; // Back left top
	vertex[2][0] = 4; vertex[2][1] = 0; vertex[2][2] = -4; // Back right top
	vertex[3][0] = 4; vertex[3][1] = -1; vertex[3][2] = -4; // Back right bottom

	vertex[4][0] = -4; vertex[4][1] = -1; vertex[4][2] = 4; // Front left bottom
	vertex[5][0] = -4; vertex[5][1] = 0; vertex[5][2] = 4; // Front left top
	vertex[6][0] = 4; vertex[6][1] = 0; vertex[6][2] = 4; // Front right top
	vertex[7][0] = 4; vertex[7][1] = -1; vertex[7][2] = 4; // Front right bottom

	/*-------Top Wall-------*/

	// Back left bottom -- vertex[1][]
	vertex[8][0] = -4; vertex[8][1] = 1; vertex[8][2] = -4; // Back left top
	vertex[9][0] = 4; vertex[9][1] = 1; vertex[9][2] = -4; // Back right top
	// Back right bottom -- vertex[2][]

	vertex[10][0] = -4; vertex[10][1] = 0; vertex[10][2] = -3; // Front left bottom
	vertex[11][0] = -4; vertex[11][1] = 1; vertex[11][2] = -3; // Front left top
	vertex[12][0] = 4; vertex[12][1] = 1; vertex[12][2] = -3; // Front right top
	vertex[13][0] = 4; vertex[13][1] = 0; vertex[13][2] = -3; // Front right bottom

	/*-------Bottom Wall-------*/

	vertex[14][0] = -4; vertex[14][1] = 0; vertex[14][2] = 3; // Back left bottom
	vertex[15][0] = -4; vertex[15][1] = 1; vertex[15][2] = 3; // Back left top
	vertex[16][0] = 4; vertex[16][1] = 1; vertex[16][2] = 3; // Back right top
	vertex[17][0] = 4; vertex[17][1] = 0; vertex[17][2] = 3; // Back right bottom

	// Front left bottom -- vertex[5][]
	vertex[18][0] = -4; vertex[18][1] = 1; vertex[18][2] = 4; // Front left top
	vertex[19][0] = 4; vertex[19][1] = 1; vertex[19][2] = 4; // Front right top
	// Front right bottom -- vertex[6][]

	/*-------Left Wall-------*/

	// Back left bottom -- vertex[10][]
	// Back left top -- vertex[11][]
	vertex[20][0] = -3; vertex[20][1] = 1; vertex[20][2] = -3; // Back right top
	vertex[21][0] = -3; vertex[21][1] = 0; vertex[21][2] = -3; // Back right bottom

	// Front left bottom -- vertex[14][]
	// Front left top -- vertex[15][]
	vertex[22][0] = -3; vertex[22][1] = 1; vertex[22][2] = 3; // Front right top
	vertex[23][0] = -3; vertex[23][1] = 0; vertex[23][2] = 3; // Front right bottom

	/*-------Right Top Wall-------*/

	vertex[24][0] = 3; vertex[24][1] = 0; vertex[24][2] = -3; // Back left bottom
	vertex[25][0] = 3; vertex[25][1] = 1; vertex[25][2] = -3; // Back left top
	// Back right top -- vertex[12][]
	// Back right bottom -- vertex[13][]

	vertex[26][0] = 3; vertex[26][1] = 0; vertex[26][2] = -1; // Front left bottom
	vertex[27][0] = 3; vertex[27][1] = 1; vertex[27][2] = -1; // Front left top
	vertex[28][0] = 4; vertex[28][1] = 1; vertex[28][2] = -1; // Front right top
	vertex[29][0] = 4; vertex[29][1] = 0; vertex[29][2] = -1; // Front right bottom

	/*-------Right Bottom Wall-------*/

	vertex[30][0] = 3; vertex[30][1] = 0; vertex[30][2] = 0; // Back left bottom
	vertex[31][0] = 3; vertex[31][1] = 1; vertex[31][2] = 0; // Back left top
	vertex[32][0] = 4; vertex[32][1] = 1; vertex[32][2] = 0; // Back right top
	vertex[33][0] = 4; vertex[33][1] = 0; vertex[33][2] = 0; // Back right bottom

	vertex[34][0] = 3; vertex[34][1] = 0; vertex[34][2] = 3; // Front left bottom
	vertex[35][0] = 3; vertex[35][1] = 1; vertex[35][2] = 3; // Front left top
	// Front right top -- vertex[16][]
	// Front right bottom -- vertex[17][]

	/*-------Base Plate-------*/
	face[0][0] = 1; face[0][1] = 2; face[0][2] = 6; face[0][3] = 5; // Top
	face[1][0] = 0; face[1][1] = 3; face[1][2] = 7; face[1][3] = 4; // Bottom
	face[2][0] = 6; face[2][1] = 2; face[2][2] = 3; face[2][3] = 7; // Right
	face[3][0] = 1; face[3][1] = 5; face[3][2] = 4; face[3][3] = 0; // Left
	face[4][0] = 5; face[4][1] = 6; face[4][2] = 7; face[4][3] = 4; // Front
	face[5][0] = 1; face[5][1] = 2; face[5][2] = 3; face[5][3] = 0; // Back

	/*-------Top Wall-------*/
	face[6][0] = 8; face[6][1] = 9; face[6][2] = 12; face[6][3] = 11; // Top
	face[7][0] = 1; face[7][1] = 2; face[7][2] = 13; face[7][3] = 10; // Bottom
	face[8][0] = 12; face[8][1] = 9; face[8][2] = 2; face[8][3] = 13; // Right
	face[9][0] = 8; face[9][1] = 11; face[9][2] = 10; face[9][3] = 1; // Left
	face[10][0] = 11; face[10][1] = 12; face[10][2] = 13; face[10][3] = 10; // Front
	face[11][0] = 8; face[11][1] = 9; face[11][2] = 2; face[11][3] = 1; // Back

	/*-------Bottom Wall-------*/
	face[12][0] = 15; face[12][1] = 16; face[12][2] = 19; face[12][3] = 18; // Top
	face[13][0] = 14; face[13][1] = 17; face[13][2] = 6; face[13][3] = 5; // Bottom
	face[14][0] = 19; face[14][1] = 16; face[14][2] = 17; face[14][3] = 6; // Right
	face[15][0] = 15; face[15][1] = 18; face[15][2] = 5; face[15][3] = 14; // Left
	face[16][0] = 18; face[16][1] = 19; face[16][2] = 6; face[16][3] = 5; // Front
	face[17][0] = 15; face[17][1] = 16; face[17][2] = 17; face[17][3] = 14; // Back

	/*-------Left Wall-------*/
	face[18][0] = 11; face[18][1] = 20; face[18][2] = 22; face[18][3] = 15; // Top
	face[19][0] = 10; face[19][1] = 21; face[19][2] = 23; face[19][3] = 14; // Bottom
	face[20][0] = 22; face[20][1] = 20; face[20][2] = 21; face[20][3] = 23; // Right
	face[21][0] = 11; face[21][1] = 15; face[21][2] = 14; face[21][3] = 10; // Left
	face[22][0] = 15; face[22][1] = 22; face[22][2] = 23; face[22][3] = 14; // Front
	face[23][0] = 11; face[23][1] = 20; face[23][2] = 21; face[23][3] = 10; // Back

	/*-------Right Top Wall-------*/
	face[24][0] = 25; face[24][1] = 12; face[24][2] = 28; face[24][3] = 27; // Top
	face[25][0] = 24; face[25][1] = 13; face[25][2] = 29; face[25][3] = 26; // Bottom
	face[26][0] = 28; face[26][1] = 12; face[26][2] = 13; face[26][3] = 29; // Right
	face[27][0] = 25; face[27][1] = 27; face[27][2] = 26; face[27][3] = 24; // Left
	face[28][0] = 27; face[28][1] = 28; face[28][2] = 29; face[28][3] = 26; // Front
	face[29][0] = 25; face[29][1] = 12; face[29][2] = 13; face[29][3] = 24; // Back

	/*-------Right Bottom Wall-------*/
	face[30][0] = 31; face[30][1] = 32; face[30][2] = 16; face[30][3] = 35; // Top
	face[31][0] = 30; face[31][1] = 33; face[31][2] = 17; face[31][3] = 34; // Bottom
	face[32][0] = 16; face[32][1] = 32; face[32][2] = 33; face[32][3] = 17; // Right
	face[33][0] = 31; face[33][1] = 35; face[33][2] = 34; face[33][3] = 30; // Left
	face[34][0] = 35; face[34][1] = 16; face[34][2] = 17; face[34][3] = 34; // Front
	face[35][0] = 31; face[35][1] = 32; face[35][2] = 33; face[35][3] = 30; // Back

}

Board::~Board(){

}

void Board::setMatrix(GLint mat[8][8]){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			matrix[i][j] = mat[i][j];
		}
	}
}

void Board::drawFace(GLint f, GLint l){

	if(f < 6){
		glColor3f(0.5, 0.5, 0.5);
	}
	else{
		glColor3f(0.4, 0.3, 0.2);
	}
	glBegin(GL_POLYGON);
	glVertex3fv(vertex[face[f][0]]);
	glVertex3fv(vertex[face[f][1]]);
	glVertex3fv(vertex[face[f][2]]);
	glVertex3fv(vertex[face[f][3]]);
	glEnd();

	if(l){
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_LINE_LOOP);
		glVertex3fv(vertex[face[f][0]]);
		glVertex3fv(vertex[face[f][1]]);
		glVertex3fv(vertex[face[f][2]]);
		glVertex3fv(vertex[face[f][3]]);
		glEnd();
	}

}

void Board::draw(){
	glPushMatrix();
	this->ctmMultiply();
	glScalef(s,s,s);

	for (int i = 0; i < 36; i++) {
		if(i != 0 && (i % 6 == 0 || i == 10 || i == 17 || i == 20 || i == 27 || i == 28 || i == 33 || i == 37 )){
			drawFace(i, 1);
		}
		else{
			drawFace(i, 0);
		}
	}


	glPopMatrix();
}


