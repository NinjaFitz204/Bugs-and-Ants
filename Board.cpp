/*
 * Board.cpp
 *
 *  Created on: Sep 19, 2018
 *      Author: zrfitzgibbon
 */

#include "Board.h"
#include "Organism.h"
#include "Doodlebug.h"
#include "Ant.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

Board::Board() {
	// TODO Auto-generated constructor stub
	size = 20;
	numAnts = 5;
	numBugs = 100;
	seed = 1;

	srand(seed);

	//gameBoard[size][size];
	//gameBoard = new Organism*[size];
	//starts with an empty array of organisms, with each step fills the given
	//space in the array with a new organism, continues until the correct number of
	//organisms specified by the user has been input into the array
//	for (int i = 0; i < size; ++i) {
//		for(int j =0; j<size; ++j){
//			&gameBoard[i][j] = NULL;
//		}
//	}

	gameBoard.resize(size, vector<Organism*>(size));

	for (int i = 0; i < numBugs; i++) {
		addBug();
	}
	for (int i = 0; i < numAnts; i++) {
		addAnt();
	}

}

Board::Board(int x, int b, int a, unsigned int s) {
	size = x;
	numAnts = a;
	numBugs = b;
	seed = s;

	if (seed == 0)
		srand(time(0));
	else
		srand(seed);

	//gameBoard = make2Dorg(size);

	//gameBoard[size][size];
	//gameBoard = new Organism*[size];
	//starts with an empty array of organisms, with each step fills the given
	//space in the array with a new organism, continues until the correct number of
	//organisms specified by the user has been input into the array
//	for (int i = 0; i < size; ++i) {
//		for(int j = 0; j<size; ++j){
//			&gameBoard[i][j] = NULL;
//		}
//	}

	gameBoard.resize(size, vector<Organism*>(size));

	for (int i = 0; i < numBugs; i++) {
		addBug();
	}
	for (int i = 0; i < numAnts; i++) {
		addAnt();
	}

}

/**
 * creates board full of Ants and Doodlebugs
 */
void Board::create() {

	for (int i = 0; i < numBugs; i++) {
		addBug();
	}
	for (int i = 0; i < numAnts; i++) {
		addAnt();
	}

}

/**
 * gets a random number to get place for ants and doodlebugs
 * @param top highest value for rnd #
 * @return the random number
 */
int Board::getRnd(int top) {
	return rand() % top;
}

/**
 * adds a Doodlebug to the board
 */
void Board::addBug() {
	bool isEmpty = false;
	int xval;
	int yval;

	while (!isEmpty) {	//loop invarient is that isEmpty = false
		xval = getRnd(size);
		yval = getRnd(size);

		if (gameBoard[xval][yval] == NULL) {
			break;
		}
		if (gameBoard.at(xval).at(yval)->whatOrg > 0) {
			isEmpty = false;
		} else {
			isEmpty = true;
		}
	}

	Organism *bug;
	bug = new Doodlebug(xval, yval);
	gameBoard.at(xval).at(yval) = bug;
}

/**
 * adds an Ant to the board
 */
void Board::addAnt() {
	bool isEmpty = false;
	int xval;
	int yval;


	while (!isEmpty) {	//loop invarient is that isEmpty = false
		xval = getRnd(size);
		yval = getRnd(size);


		if (gameBoard[xval][yval] == NULL) {
				break;
			}
		if (gameBoard[xval][yval]->whatOrg > 0) {
			isEmpty = false;
		} else {
			isEmpty = true;
		}
	}

	Organism* ant;
	ant = new Ant(xval, yval);
	gameBoard[xval][yval] = ant;
}

Board::~Board() {
	// TODO Auto-generated destructor stub
}

/**
 * prints the board as x's and o's
 */
void Board::print() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			bool didPrint = false;

			if (gameBoard[i][j] != NULL && gameBoard[i][j]->getOrg() == 1) {
				cout << 'x';
				didPrint = true;
			}
			if (gameBoard[i][j] != NULL && gameBoard[i][j]->getOrg() == 2) {
				cout << 'o';
				didPrint = true;
			}
			if(!didPrint){
				cout << ' ';
			}
		}
		cout << endl;
	}
}

bool Board::isEmpty() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (gameBoard[i][j]->getOrg() != 0) {
				return false;
			}
		}
	}
	return true;
}
