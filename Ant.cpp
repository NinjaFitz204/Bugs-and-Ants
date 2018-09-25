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
	bool hasMoved = false;
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
	bool done = false;
	if (xcord < size -1) {
		moveRight = checkOpen(board, xcord + 1, ycord) * 2;
		canMove++;
	}
	if (xcord > 0) {
		moveLeft = checkOpen(board, xcord - 1, ycord) * 3;
		canMove++;
	}
	if (ycord < size - 1) {
		moveDown = checkOpen(board, xcord,ycord + 1) * 4;
		canMove++;
	}
	if (ycord > 0) {
		moveUp = checkOpen(board, xcord,ycord - 1) * 5;
		canMove++;
	}
	int spotsToGo[] = { moveRight, moveLeft, moveUp, moveDown };
	if (canMove > 0) {
		int randomIndex;
		while (!done) {
			randomIndex = spotsToGo[rand()%5];
			if (randomIndex) {
				done = true;
			}
		}
		switch(randomIndex) {
		case 2:
			xcord++;
			break;
		case 3:
			xcord--;
			break;
		case 4:
			ycord++;
			break;
		case 5:
			ycord --;
			break;
		}

	}
	timeSinceBreed++;
}

int checkOpen(Organism **board, int x, int y) {
	if (board[x][y].getOrg() == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int Ant::getOrg(){
	return whatOrg;
}

void Ant::resetMove() {
	hasMoved = false;
}
