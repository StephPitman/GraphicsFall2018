/*
 * board.cpp
 *
 *  Created on: Nov 24, 2018
 *      Author: Stephanie
 */

#include "board.hpp"

board::board(){
	int i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if((i==0 && j == 0) || (i == 0 || j ==0) || (i == 7 || j == 7)){
				matrix[i][j] = 1;
			}
			else{
				matrix[i][j] = 0;
			}
		}
	}

	vertex[0][0]=-4;vertex[0][1]=-1;vertex[0][2]=4;
	vertex[1][0]=4;vertex[1][1]=-1;vertex[1][2]=4;
	vertex[2][0]=-4 ;vertex[2][1]=1 ;vertex[2][2]=4;
	vertex[3][0]=4 ;vertex[3][1]=1 ;vertex[3][2]=4 ;

	vertex[4][0]=-3 ;vertex[4][1]=-1 ;vertex[4][2]=3 ;
	vertex[5][0]=3 ;vertex[5][1]=-1 ;vertex[5][2]=3 ;
	vertex[6][0]=-3 ;vertex[6][1]=1 ;vertex[6][2]= 3;
	vertex[7][0]=3 ;vertex[7][1]=1 ;vertex[7][2]=3 ;

	vertex[8][0]=-4;vertex[8][1]=-1;vertex[8][2]=-4;
	vertex[9][0]=4;vertex[9][1]=-1;vertex[9][2]=-4;
	vertex[10][0]=-4 ;vertex[10][1]=1 ;vertex[10][2]=-4;
	vertex[11][0]=4 ;vertex[11][1]=1 ;vertex[11][2]=-4 ;

	vertex[12][0]=-3 ;vertex[12][1]=-1 ;vertex[12][2]=-3 ;
	vertex[13][0]=3 ;vertex[13][1]=-1 ;vertex[13][2]=-3 ;
	vertex[14][0]=-3 ;vertex[14][1]=1 ;vertex[14][2]= -3;
	vertex[15][0]=3 ;vertex[15][1]=1 ;vertex[15][2]=-3 ;


	face[0][0]=4 ;face[0][1]=5 ;face[0][2]=12 ;face[0][3]=13 ;

	face[1][0]=4 ;face[1][1]=5 ;face[1][2]=6 ;face[1][3]=7 ;
	face[2][0]=4 ;face[2][1]=6 ;face[2][2]=12 ;face[2][3]=14 ;
	face[3][0]=12 ;face[3][1]=13 ;face[3][2]=14 ;face[3][3]=15 ;
	face[4][0]=5 ;face[4][1]=7 ;face[4][2]=13 ;face[4][3]=15 ;

	face[5][0]=0 ;face[5][1]=1 ;face[5][2]=2 ;face[5][3]=3 ;
	face[6][0]=0 ;face[6][1]=2 ;face[6][2]=8 ;face[6][3]=10 ;
	face[7][0]=8 ;face[7][1]=9 ;face[7][2]=10 ;face[7][3]=11 ;
	face[8][0]=1 ;face[8][1]=3 ;face[8][2]=9 ;face[8][3]=11 ;

	face[9][0]=2 ;face[9][1]=6 ;face[9][2]=10 ;face[9][3]=14 ;
	face[10][0]=2 ;face[10][1]=3 ;face[10][2]=6 ;face[10][3]=7 ;
	face[11][0]=3 ;face[11][1]=7 ;face[11][2]=11 ;face[11][3]=15 ;
	face[12][0]=10 ;face[12][1]=11 ;face[12][2]=14 ;face[12][3]=15 ;


}
board::~board(){

}
void board::setMatrix(GLint mat[8][8]){

}



GLint* board::getMatrix(){


}

void board::drawFace(GLint f){
	if(f == 0){
		glColor3f(1.0, 0.0, 0.0);
	}
	else if(f >=1 && f <=4){
		glColor3f(0.0, 1.0, 0.0);
	}
	else if(f >=5 && f <=8){
		glColor3f(0.0, 0.0, 1.0);
	}
	else{
		glColor3f(1.0, 1.0, 1.0);
	}
	glBegin(GL_POLYGON);
	glVertex3fv(vertex[face[f][1]]);
	glVertex3fv(vertex[face[f][0]]);
	glVertex3fv(vertex[face[f][2]]);
	glVertex3fv(vertex[face[f][3]]);
	glEnd();

}
void board::draw(){
	glPushMatrix();
	this->ctmMultiply();
	glScalef(s,s,s);

	for (int i = 0; i < 13; i++) {
		drawFace(i);
	}

	glPopMatrix();
}


