/*
 * Ant.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: zrfitzgibbon
 */

#include "Ant.h"
#include <cstdlib>
#include <vector>
using namespace std;

Ant::Ant(int x, int y) {
	xcord = x;
	ycord = y;
	whatOrg = 1;
	breedLimit = 3;
	timeSinceBreed = 0;
	hasMoved = false;
}

Ant::Ant() {
	// TODO Auto-generated constructor stub
	xcord = 0;
	ycord = 0;
	whatOrg = 1;
	hasMoved = false;
	breedLimit = 3;
	timeSinceBreed = 0;

}

Ant::~Ant() {
	// TODO Auto-generated destructor stub
}

std::vector<std::vector<Organism*>> Ant::move(
		std::vector<std::vector<Organism*>> board, int size) {
	if(hasMoved){
		return board;
	}


	int canMove = 0;
	int moveRight = 0;
	int moveLeft = 0;
	int moveUp = 0;
	int moveDown = 0;
	bool done = false;
	int newX = 0;
	int newY = 0;
	if (xcord < size - 1) {
		moveRight = checkOpen(board, xcord + 1, ycord) * 2;
		canMove++;
	}
	if (xcord > 0) {
		moveLeft = checkOpen(board, xcord - 1, ycord) * 3;
		canMove++;
	}
	if (ycord < size - 1) {
		moveDown = checkOpen(board, xcord, ycord + 1) * 4;
		canMove++;
	}
	if (ycord > 0) {
		moveUp = checkOpen(board, xcord, ycord - 1) * 5;
		canMove++;
	}
	int spotsToGo[] = { moveRight, moveLeft, moveUp, moveDown };
	if (canMove > 0) {
		int randomIndex;
		while (!done) {
			randomIndex = spotsToGo[rand() % 5];
			if (randomIndex) {
				done = true;
			}
		}
		switch (randomIndex) {
		case 2:
			newX = xcord + 1;
			newY = ycord;
			break;
		case 3:
			newX = xcord - 1;
			newY = ycord;
			break;
		case 4:
			newX = xcord;
			newY = ycord + 1;
			break;
		case 5:
			newX = xcord;
			newY = ycord - 1;
			break;
		}
		board[newX][newY] = this;
		board[xcord][ycord] = NULL;
		xcord = newX;
		ycord = newY;
		hasMoved = true;

	}

	timeSinceBreed++;

	if (timeSinceBreed >= 3) {
		int moveRight = 0;
		int moveLeft = 0;
		int moveUp = 0;
		int moveDown = 0;
		if (xcord < size - 1) {
			moveRight = checkOpen(board, xcord + 1, ycord) * 2;
			canMove++;
		}
		if (xcord > 0) {
			moveLeft = checkOpen(board, xcord - 1, ycord) * 3;
			canMove++;
		}
		if (ycord < size - 1) {
			moveDown = checkOpen(board, xcord, ycord + 1) * 4;
			canMove++;
		}
		if (ycord > 0) {
			moveUp = checkOpen(board, xcord, ycord - 1) * 5;
			canMove++;
		}
		int spotsToGo[] = { moveRight, moveLeft, moveUp, moveDown };

		int sum = spotsToGo[0] + spotsToGo[1] + spotsToGo[2] + spotsToGo[3];

		if (sum == 0) { // leaves method if it cant breed
			return board;
		}


		bool canBreed = false;
		int randomIndex;
		while (!canBreed) {
			randomIndex = spotsToGo[rand() % 4];
			if (randomIndex) {
				canBreed = true;
			}
		}
		switch (randomIndex) {
		case 2: // right
			board[xcord + 1][ycord] = new Ant(xcord + 1, ycord);
			board[xcord + 1][ycord]->hasMoved = true;
			break;
		case 3: //left
			board[xcord + 1][ycord] = new Ant(xcord - 1, ycord);
			board[xcord + 1][ycord]->hasMoved = true;
			break;
		case 4: //top
			board[xcord][ycord + 1] = new Ant(xcord, ycord + 1);
			board[xcord][ycord+1]->hasMoved = true;
			break;
		case 5: //bot
			board[xcord][ycord - 1] = new Ant(xcord, ycord - 1);
			board[xcord][ycord-1]->hasMoved = true;
			break;
		}
		timeSinceBreed = 0;

	}

	return board;

}

//
int Ant::checkOpen(std::vector<std::vector<Organism*>> board, int x, int y) {
	if (board[x][y] == NULL) {
		return 1;
	} else {
		return 0;
	}
}

int Ant::getOrg() {
	return whatOrg;
}

void Ant::resetMove() {
	hasMoved = false;
}

void Ant::didMove() {
	hasMoved = true;
}
