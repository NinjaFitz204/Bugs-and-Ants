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
#include "twoD.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

Board::Board() {
	// TODO Auto-generated constructor stub
	size = 20;
	numAnts = 5;
	numBugs = 100;
	seed = 1;

	int place[20][20] = { {}, {}};

	srand(seed);

	gameBoard = make2Dorg(size);
}

Board::Board(int x, int b, int a, unsigned int s) {
	size = x;
	numAnts = a;
	numBugs = b;
	seed = s;
	int place[20][20] = { {}, {}};
	if (seed == 0)
		srand(time(0));
	else
		srand(seed);
	gameBoard = make2Dorg(size);
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
	return rand()%top;
}

/**
 * adds a Doodlebug to the board
 */
void Board::addBug() {
	bool isEmpty = false;
	int xval;
	int yval;
	Doodlebug bug;

	while (!isEmpty) {//loop invarient is that isEmpty = false
		xval = getRnd(size);
		yval = getRnd(size);

		if (place[xval][yval] > 0) {
			isEmpty = false;
		} else {
			isEmpty = true;
		}
	}

	bug.setX(xval);
	bug.setY(yval);
	gameBoard[xval][yval] = &bug;

	place[xval][yval]=1;
}

/**
 * adds an Ant to the board
 */
void Board::addAnt() {
	bool isEmpty = false;
	int xval;
	int yval;
	Ant ant;

	while (!isEmpty) {//loop invarient is that isEmpty = false
		xval = getRnd(size);
		yval = getRnd(size);

		if (place[xval][yval] > 0) {
			isEmpty = false;
		} else {
			isEmpty = true;
		}
	}

	ant.setX(xval);
	ant.setY(yval);
	gameBoard[xval][yval] = &ant;

	place[xval][yval]=2;
}

Board::~Board() {
	// TODO Auto-generated destructor stub
}

/**
 * prints the board as x's and o's
 */
void Board::print(){
	for(int i = 0;i<size;i++){
		for(int j=0;j<size;i++){
			if(place[i][j] == 0){
				cout << ' ';
			}if(place[i][j] == 1){
				cout << 'x';
			}if(place[i][j] == 2){
				cout << 'o';
			}
		}
		cout << endl;
	}
}
