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
	starveLim = 3;
	starveCount = 0;
	hasMoved = false;

}

Doodlebug::Doodlebug(int x, int y) {

	xcord = x;
	ycord = y;
	whatOrg = 2;
	timeSinceBreed = 0;
	breedLimit = 8;
	starveLim = 3;
	starveCount = 0;
	hasMoved = false;
}

Doodlebug::~Doodlebug() {
	// TODO Auto-generated destructor stub
}

int checkMove(int x, int y, std::vector<std::vector<Organism*>> gameBoard,
		int size) {

	int place = 0;
	if (x < 0 || y < 0)
		return place;
	if (x >= size || y >= size)
		return place;

	if (gameBoard[x][y]->getOrg() == 0)
		place = 1;
	if (gameBoard[x][y]->getOrg() == 1)
		place = 2;

	return place;

}

std::vector<std::vector<Organism*>> Doodlebug::move(
		std::vector<std::vector<Organism*>> gameBoard, int size) {

	//0 if it cant move, 1 if its open, 2 if its an ant
	int top = 0;
	int left = 0;
	int bot = 0;
	int right = 0;

	if (hasMoved)
		return gameBoard;

//	if (xcord == 0 && ycord == 0) { //top leftcorner
//		if (gameBoard[xcord + 1][ycord]->getOrg() == 0)
//			right = 1;
//		if (gameBoard[xcord + 1][ycord]->getOrg() == 1) {
//			right = 2;
//		}
//		if (gameBoard[xcord][ycord + 1]->getOrg() == 0)
//			bot = 1;
//		if (gameBoard[xcord][ycord + 1]->getOrg() == 1) {
//			bot = 2;
//		}
//
//	} else if (xcord == 0 && ycord == size - 1) { //bottom left corner
//		if (gameBoard[xcord + 1][ycord]->getOrg() == 0)
//			right = 1;
//		if (gameBoard[xcord + 1][ycord]->getOrg() == 1) {
//			right = 2;
//		}
//		if (gameBoard[xcord][ycord - 1]->getOrg() == 0)
//			top = 1;
//		if (gameBoard[xcord][ycord - 1]->getOrg() == 1) {
//			top = 2;
//		}
//
//	} else if (xcord == size - 1 && ycord == 0) { //top right corner
//		if (gameBoard[xcord - 1][ycord]->getOrg() == 0)
//			left = 1;
//		if (gameBoard[xcord - 1][ycord]->getOrg() == 1) {
//			left = 2;
//		}
//		if (gameBoard[xcord][ycord + 1]->getOrg() == 0)
//			bot = 1;
//		if (gameBoard[xcord][ycord + 1]->getOrg() == 1) {
//			bot = 2;
//		}
//
//	} else if (xcord == size - 1 && ycord == size - 1) { // bottom right corner
//		if (gameBoard[xcord - 1][ycord]->getOrg() == 0)
//			left = 1;
//		if (gameBoard[xcord - 1][ycord]->getOrg() == 1) {
//			left = 2;
//		}
//		if (gameBoard[xcord][ycord - 1]->getOrg() == 0)
//			top = 1;
//		if (gameBoard[xcord][ycord - 1]->getOrg() == 1) {
//			top = 2;
//		}
//
//	} else if (xcord == 0) { //left coloum
//		if (gameBoard[xcord + 1][ycord]->getOrg() == 0)
//			right = 1;
//		if (gameBoard[xcord + 1][ycord]->getOrg() == 1) {
//			right = 2;
//		}
//		if (gameBoard[xcord][ycord - 1]->getOrg() == 0)
//			top = 1;
//		if (gameBoard[xcord][ycord - 1]->getOrg() == 1) {
//			top = 2;
//		}
//		if (gameBoard[xcord][ycord + 1]->getOrg() == 0)
//			bot = 1;
//		if (gameBoard[xcord][ycord + 1]->getOrg() == 1) {
//			bot = 2;
//		}
//
//	} else if (xcord == size) { //right colloum
//		if (gameBoard[xcord - 1][ycord]->getOrg() == 0)
//			left = 1;
//		if (gameBoard[xcord - 1][ycord]->getOrg() == 1) {
//			left = 2;
//		}
//		if (gameBoard[xcord][ycord - 1]->getOrg() == 0)
//			top = 1;
//		if (gameBoard[xcord][ycord - 1]->getOrg() == 1) {
//			top = 2;
//		}
//		if (gameBoard[xcord][ycord + 1]->getOrg() == 0)
//			bot = 1;
//		if (gameBoard[xcord][ycord + 1]->getOrg() == 1) {
//			bot = 2;
//		}
//
//	} else if (ycord == 0) { //top row
//		if (gameBoard[xcord + 1][ycord]->getOrg() == 0)
//			right = 1;
//		if (gameBoard[xcord + 1][ycord]->getOrg() == 1) {
//			right = 2;
//		}
//		if (gameBoard[xcord - 1][ycord]->getOrg() == 0)
//			left = 1;
//		if (gameBoard[xcord - 1][ycord]->getOrg() == 1) {
//			left = 2;
//		}
//		if (gameBoard[xcord][ycord + 1]->getOrg() == 0)
//			bot = 1;
//		if (gameBoard[xcord][ycord + 1]->getOrg() == 1) {
//			bot = 2;
//		}
//
//	} else if (ycord == size) { //bottom row
//		if (gameBoard[xcord + 1][ycord]->getOrg() == 0)
//			right = 1;
//		if (gameBoard[xcord + 1][ycord]->getOrg() == 1) {
//			right = 2;
//		}
//		if (gameBoard[xcord - 1][ycord]->getOrg() == 0)
//			left = 1;
//		if (gameBoard[xcord - 1][ycord]->getOrg() == 1) {
//			left = 2;
//		}
//		if (gameBoard[xcord][ycord - 1]->getOrg() == 0)
//			top = 1;
//		if (gameBoard[xcord][ycord - 1]->getOrg() == 1) {
//			top = 2;
//		}
//
//	} else { //middle of the board
//		if (gameBoard[xcord + 1][ycord]->getOrg() == 0)
//			right = 1;
//		if (gameBoard[xcord + 1][ycord]->getOrg() == 1) {
//			right = 2;
//		}
//		if (gameBoard[xcord - 1][ycord]->getOrg() == 0)
//			left = 1;
//		if (gameBoard[xcord - 1][ycord]->getOrg() == 1) {
//			left = 2;
//		}
//		if (gameBoard[xcord][ycord - 1]->getOrg() == 0)
//			top = 1;
//		if (gameBoard[xcord][ycord - 1]->getOrg() == 1) {
//			top = 2;
//		}
//		if (gameBoard[xcord][ycord + 1]->getOrg() == 0)
//			bot = 1;
//		if (gameBoard[xcord][ycord + 1]->getOrg() == 1) {
//			bot = 2;
//		}
//
//	}

	right = checkMove(xcord + 1, ycord, gameBoard, size);
	left = checkMove(xcord - 1, ycord, gameBoard, size);
	top = checkMove(xcord, ycord + 1, gameBoard, size);
	bot = checkMove(xcord, ycord - 1, gameBoard, size);

	int moves[4] = { 0, 0, 0, 0 };

	moves[0] = right;
	moves[1] = left;
	moves[2] = top;
	moves[3] = bot;
	int sum = moves[0] + moves[1] + moves[2] + moves[3];

	if (sum == 0) { // leaves method if it cant move
		starveCount++;
		if (starveCount == 3) {
			gameBoard[xcord][ycord] = NULL;
		}
		return gameBoard;
	}

	bool hasAnt = false; // if true will only move into a cell with an Ant

	if (moves[0] == 2 || moves[1] == 2 || moves[2] == 2 || moves[3] == 2)
		hasAnt = true;

	int place; //2 if ant, 1 if open
	if (hasAnt) {
		place = 2;
	} else {
		place = 1;
		starveCount++;
		if (starveCount == 3) {
			gameBoard[xcord][ycord] = NULL;
			return gameBoard;
		}

	}

	//finds where to move to
	int rnd;
	while (!hasMoved) {
		rnd = rand() % 4;
		if (moves[rnd] == place) {
			hasMoved = true;
			timeSinceBreed++;
		}
	}

	//moves the doodlebug
	gameBoard[xcord][ycord] = NULL;
	switch (rnd) {
	case 0: // right
		gameBoard[xcord + 1][ycord] = this;
		xcord++;
		break;
	case 1: //left
		gameBoard[xcord - 1][ycord] = this;
		xcord--;
		break;
	case 2: //top
		gameBoard[xcord][ycord + 1] = this;
		ycord++;
		break;
	case 3: //bot
		gameBoard[xcord][ycord - 1] = this;
		ycord--;
		break;
	}

	//breeds if able
	if (timeSinceBreed >= 8) {
		right = checkMove(xcord + 1, ycord, gameBoard, size);
		left = checkMove(xcord - 1, ycord, gameBoard, size);
		top = checkMove(xcord, ycord + 1, gameBoard, size);
		bot = checkMove(xcord, ycord - 1, gameBoard, size);

		moves[0] = right;
		moves[1] = left;
		moves[2] = top;
		moves[3] = bot;
		int sum = moves[0] + moves[1] + moves[2] + moves[3];

		if (sum == 0) { // leaves method if it cant breed
			break;
		}

		int rnd1;
		bool canBreed = false;
		while (!canBreed) {
			rnd1 = rand() % 4;
			if (moves[rnd1] == 0) {
				canBreed=true;
			}
		}

		switch (rnd1) {
		case 0: // right
			gameBoard[xcord + 1][ycord] = new Doodlebug(xcord + 1, ycord);
			break;
		case 1: //left
			gameBoard[xcord - 1][ycord] = new Doodlebug(xcord - 1, ycord);
			break;
		case 2: //top
			gameBoard[xcord][ycord + 1] = new Doodlebug(xcord, ycord+1);
			break;
		case 3: //bot
			gameBoard[xcord][ycord - 1] = new Doodlebug(xcord, ycord-1);
			break;
		}

	}

	return gameBoard;

}

int Doodlebug::getOrg() {
	return whatOrg;
}

