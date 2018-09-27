/*
 * Organism.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: zrfitzgibbon
 */

#include "Organism.h"

Organism::Organism() {
	// TODO Auto-generated constructor stub
	xcord = 0;
	ycord = 0;
	whatOrg = 0;// o if nothing, 1 if ant, 2 if doodlebug

}

Organism::~Organism() {
	// TODO Auto-generated destructor stub
}

/*void Organism::move(){
}*/

int Organism::getOrg(){
	return whatOrg;
}


/**
 * returns the x coordinate of the organism
 */
int Organism::getxcord(){
	return xcord;
}
/**
 * returns the y coordinate of the organism
 */
int Organism::getycord(){
	return ycord;
}

/**
 * sets the xcord
 */
void Organism::setX(int x){
	xcord = x;
}
/**
 * sets the ycord
 */
void Organism::setY(int y){
	ycord=y;
}
//void Organism::move(Organism **board, int size) {
//
//}
