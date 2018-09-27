/*
 * Doodlebug.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: zrfitzgibbon
 */
#include <iostream>
#include "Doodlebug.h"
#include <vector>
using namespace std;

Doodlebug::Doodlebug() {
	// TODO Auto-generated constructor stub
	xcord = 0;
	ycord = 0;
	whatOrg = 2;
	timeSinceBreed = 0;
	breedLimit = 8;

}

Doodlebug::Doodlebug(int x, int y) {

	xcord = x;
	ycord = y;
	whatOrg = 2;
	timeSinceBreed = 0;
	breedLimit = 8;
}

Doodlebug::~Doodlebug() {
	// TODO Auto-generated destructor stub
}

void Doodlebug::move(std::vector<std::vector<Organism*>> gameBoard, int size) {

	//0 if it cant move, 1 if its open, 2 if its an ant
	int top = 0;
	int left = 0;
	int bot = 0;
	int right = 0;

	if (xcord == 0 && ycord == 0) { //top leftcorner
		if (gameBoard[xcord + 1][ycord]->getOrg() == 0)
			right = 1;
		if (gameBoard[xcord + 1][ycord]->getOrg() == 1) {
			right = 2;
		}
		if (gameBoard[xcord][ycord + 1]->getOrg() == 0)
			bot = 1;
		if (gameBoard[xcord][ycord + 1]->getOrg() == 1) {
			bot = 2;
		}

	} else if (xcord == 0 && ycord == size - 1) { //bottom left corner
		if (gameBoard[xcord + 1][ycord]->getOrg() == 0)
			right = 1;
		if (gameBoard[xcord + 1][ycord]->getOrg() == 1) {
			right = 2;
		}
		if (gameBoard[xcord][ycord - 1]->getOrg() == 0)
			top = 1;
		if (gameBoard[xcord][ycord - 1]->getOrg() == 1) {
			top = 2;
		}

	} else if (xcord == size - 1 && ycord == 0) { //top right corner
		if (gameBoard[xcord - 1][ycord]->getOrg() == 0)
			left = 1;
		if (gameBoard[xcord - 1][ycord]->getOrg() == 1) {
			left = 2;
		}
		if (gameBoard[xcord][ycord + 1]->getOrg() == 0)
			bot = 1;
		if (gameBoard[xcord][ycord + 1]->getOrg() == 1) {
			bot = 2;
		}

	} else if (xcord == size - 1 && ycord == size - 1) { // bottom right corner
		if (gameBoard[xcord - 1][ycord]->getOrg() == 0)
			left = 1;
		if (gameBoard[xcord - 1][ycord]->getOrg() == 1) {
			left = 2;
		}
		if (gameBoard[xcord][ycord - 1]->getOrg() == 0)
			top = 1;
		if (gameBoard[xcord][ycord - 1]->getOrg() == 1) {
			top = 2;
		}

	} else if (xcord == 0) { //left coloum
		if (gameBoard[xcord + 1][ycord]->getOrg() == 0)
			right = 1;
		if (gameBoard[xcord + 1][ycord]->getOrg() == 1) {
			right = 2;
		}
		if (gameBoard[xcord][ycord - 1]->getOrg() == 0)
			top = 1;
		if (gameBoard[xcord][ycord - 1]->getOrg() == 1) {
			top = 2;
		}
		if (gameBoard[xcord][ycord + 1]->getOrg() == 0)
			bot = 1;
		if (gameBoard[xcord][ycord + 1]->getOrg() == 1) {
			bot = 2;
		}

	} else if (xcord == size) { //right colloum
		if (gameBoard[xcord - 1][ycord]->getOrg() == 0)
			left = 1;
		if (gameBoard[xcord - 1][ycord]->getOrg() == 1) {
			left = 2;
		}
		if (gameBoard[xcord][ycord - 1]->getOrg() == 0)
			top = 1;
		if (gameBoard[xcord][ycord - 1]->getOrg() == 1) {
			top = 2;
		}
		if (gameBoard[xcord][ycord + 1]->getOrg() == 0)
			bot = 1;
		if (gameBoard[xcord][ycord + 1]->getOrg() == 1) {
			bot = 2;
		}

	} else if (ycord == 0) { //top row
		if (gameBoard[xcord + 1][ycord]->getOrg() == 0)
			right = 1;
		if (gameBoard[xcord + 1][ycord]->getOrg() == 1) {
			right = 2;
		}
		if (gameBoard[xcord - 1][ycord]->getOrg() == 0)
			left = 1;
		if (gameBoard[xcord - 1][ycord]->getOrg() == 1) {
			left = 2;
		}
		if (gameBoard[xcord][ycord + 1]->getOrg() == 0)
			bot = 1;
		if (gameBoard[xcord][ycord + 1]->getOrg() == 1) {
			bot = 2;
		}

	} else if (ycord == size) { //bottom row
		if (gameBoard[xcord + 1][ycord]->getOrg() == 0)
			right = 1;
		if (gameBoard[xcord + 1][ycord]->getOrg() == 1) {
			right = 2;
		}
		if (gameBoard[xcord - 1][ycord]->getOrg() == 0)
			left = 1;
		if (gameBoard[xcord - 1][ycord]->getOrg() == 1) {
			left = 2;
		}
		if (gameBoard[xcord][ycord - 1]->getOrg() == 0)
			top = 1;
		if (gameBoard[xcord][ycord - 1]->getOrg() == 1) {
			top = 2;
		}

	} else { //middle of the board
		if (gameBoard[xcord + 1][ycord]->getOrg() == 0)
			right = 1;
		if (gameBoard[xcord + 1][ycord]->getOrg() == 1) {
			right = 2;
		}
		if (gameBoard[xcord - 1][ycord]->getOrg() == 0)
			left = 1;
		if (gameBoard[xcord - 1][ycord]->getOrg() == 1) {
			left = 2;
		}
		if (gameBoard[xcord][ycord - 1]->getOrg() == 0)
			top = 1;
		if (gameBoard[xcord][ycord - 1]->getOrg() == 1) {
			top = 2;
		}
		if (gameBoard[xcord][ycord + 1]->getOrg() == 0)
			bot = 1;
		if (gameBoard[xcord][ycord + 1]->getOrg() == 1) {
			bot = 2;
		}

	}

}

int Doodlebug::getOrg() {
	return whatOrg;
}

