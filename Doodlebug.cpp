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

/**
 * basic constructor
 */
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

/**
 * constructor with params
 * @param x xcord of bug
 * @param y ycord of bug
 */
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

/**
 * deconstructor
 */
Doodlebug::~Doodlebug() {
	// TODO Auto-generated destructor stub
}

/**
 * checks to see if the doodlebug can move to the specified spot
 */
int Doodlebug::checkMove(int x, int y, std::vector<std::vector<Organism*>> gameBoard,
		int size) {

	int place = 0;
	if (x < 0 || y < 0)
		return place;
	if (x >= size || y >= size)
		return place;

	if (gameBoard[x][y] == NULL)
		place = 1;
	if (gameBoard[x][y] != NULL && gameBoard[x][y]->getOrg() == 1)
		place = 2;

	return place;

}

/**
 * moves the bug to an open spot
 */
std::vector<std::vector<Organism*>> Doodlebug::move(
		std::vector<std::vector<Organism*>> gameBoard, int size) {

	//0 if it cant move, 1 if its open, 2 if its an ant
	int top = 0;
	int left = 0;
	int bot = 0;
	int right = 0;

	if (hasMoved)
		return gameBoard;

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
		starveCount = 0;
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
			return gameBoard;
		}

		int rnd1;
		bool canBreed = false;
		while (!canBreed) {
			rnd1 = rand() % 4;
			if (moves[rnd1] == 1) {
				timeSinceBreed=0;
				canBreed=true;
			}
		}

		switch (rnd1) {
		case 0: // right
			gameBoard[xcord + 1][ycord] = new Doodlebug(xcord + 1, ycord);
			gameBoard[xcord + 1][ycord]->hasMoved=true;
			break;
		case 1: //left
			gameBoard[xcord - 1][ycord] = new Doodlebug(xcord - 1, ycord);
			gameBoard[xcord - 1][ycord]->hasMoved=true;
			break;
		case 2: //top
			gameBoard[xcord][ycord + 1] = new Doodlebug(xcord, ycord+1);
			gameBoard[xcord][ycord+1]->hasMoved=true;
			break;
		case 3: //bot
			gameBoard[xcord][ycord - 1] = new Doodlebug(xcord, ycord-1);
			gameBoard[xcord][ycord-1]->hasMoved=true;
			break;
		}

	}

	return gameBoard;

}

/**
 * returns the kind of org it is
 * @return 2
 */
int Doodlebug::getOrg() {
	return whatOrg;
}

