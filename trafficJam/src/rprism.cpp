/*
 * rprism.cpp
 *
 *  Created on: Nov 24, 2018
 *      Author: Stephanie
 */

#include "rprism.hpp"

rprism::rprism(GLint len, GLint dir){
	length = len;
	direction = dir;
	vertex[0][0]=0 ;vertex[0][1]=0 ; vertex[0][2]=0 ;
	vertex[1][0]=1 ;vertex[1][1]=0 ; vertex[1][2]=0 ;
	vertex[2][0]=0 ;vertex[2][1]=1 ; vertex[2][2]=0 ;
	vertex[3][0]=1 ;vertex[3][1]=1 ; vertex[3][2]=0 ;
	vertex[4][0]=0 ;vertex[4][1]=0 ; vertex[4][2]=-1*len ;
	vertex[5][0]=1 ;vertex[5][1]=0 ; vertex[5][2]=-1*len ;
	vertex[6][0]=0 ;vertex[6][1]=1 ; vertex[6][2]=-1*len ;
	vertex[7][0]=1 ;vertex[7][1]=1 ; vertex[7][2]=-1*len ;

	face[0][0]=0 ; face[0][1]=1 ;face[0][2]=4 ;face[0][3]=5 ;
	face[1][0]=0 ; face[1][1]=1 ;face[1][2]=2 ;face[1][3]=3 ;
	face[2][0]=4 ; face[2][1]=5 ;face[2][2]=6 ;face[2][3]=7 ;
	face[3][0]=0 ; face[3][1]=2 ;face[3][2]=4 ;face[3][3]=6 ;
	face[4][0]=1 ; face[4][1]=3 ;face[4][2]=5 ;face[4][3]=7 ;
	face[5][0]=2 ; face[5][1]=3 ;face[5][2]=6 ;face[5][3]=7 ;
}
rprism::~rprism(){

}
GLint rprism::getLength(){

}
void rprism::setLength(GLint len){

}
void rprism::setTexture(GLuint text){

}
GLint rprism::getDirection(){

}
void rprism::setDirection(GLint direct){

}
void rprism::draw(){

}
