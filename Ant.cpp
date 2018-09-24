/*
 * Ant.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: zrfitzgibbon
 */

#include "Ant.h"
#include <cstdlib>

Ant::Ant(int x, int y){
	xcord=x;
	ycord=y;
	whatOrg=1;
	const int breedLimit = 3;
	int timeSinceBreed = 0;
}

Ant::Ant() {
	// TODO Auto-generated constructor stub
	xcord=0;
	ycord=0;
	whatOrg=1;

}

Ant::~Ant() {
	// TODO Auto-generated destructor stub
}

void Ant::move(Organism **board, size){
	int canMove = 0;
	int moveRight = 0;
	int moveLeft = 0;
	int moveUp = 0;
	int moveDown = 0;
	if (xcord < size -1) {
		moveRight = checkOpen(xcord + 1, ycord);
		canMove++;
	}
	if (xcord > 0) {
		moveLeft = checkOpen(xcord - 1, ycord);
		canMove++;
	}
	if (ycord < size - 1) {
		moveDown = checkOpen(xcord, ycord + 1);
		canMove++;
	}
	if (ycord > 0) {
		moveUp = checkOpen(xcord, ycord - 1);
		canMove++;
	}
	if (canMove > 0) {
		int randomIndex;
		while (!done) {
			randomIndex = rand(sizeToRandomChoose);
			if (randomIndex) {
				done = true;
			}
		}

	}
	timeSinceBreed++;
}

int Ant::getOrg(){
	return whatOrg;
}
