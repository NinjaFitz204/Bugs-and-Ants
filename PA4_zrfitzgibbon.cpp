//============================================================================
// Name        : PA4_zrfitzgibbon.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Organism.h"
#include "Doodlebug.h"
#include "Board.h"
using namespace std;

int main(int argc, char** argv) {
	int gridSize;
	int numBugs; //5
	int numAnts; //100
	int steps;
	int seed;
	int pause;
	int turnCount = 0;


	switch (argc) { //fallthrough is intended!!!!
	case 1:
		gridSize = 20;
	case 2:
		numBugs = 5;
	case 3:
		numAnts = 100;
	case 4:
		steps = 1000;
	case 5:
		seed = 1;
	case 6:
		pause = -1;
	case 7:
		break;
	}
	switch (argc) { //fallthrough is intended!!!
	case 7:
		pause = atoi(argv[6]);
		if (pause <= 0) {
			cout << "pause argument must be > 0" << endl;
			return(1);
		}
	case 6:
		seed = atoi(argv[5]);
	case 5:
		steps = atoi(argv[4]);
	case 4:
		numAnts = atoi(argv[3]);
	case 3:
		numBugs = atoi(argv[2]);
	case 2:
		gridSize = atoi(argv[1]);
	case 1:
		break;
	}

	if (pause >= steps) {
		cout << "set pause to less than the number of steps" << endl;
		return 1;
	}

	Board *board = new Board(gridSize, numBugs, numAnts, seed);
	//Board board(gridSize, numBugs, numAnts, seed);
	//board->create();
	bool checkAnts = board->noAnts();
	bool checkBugs = board->noBugs();

	if (pause != -1) {
		while (!checkAnts && !checkBugs && turnCount < pause) {
			board->move();
			turnCount++;

		}
		board->print();
		cout << "In pause- press enter to continue" << endl;
		getchar();
	}
	while (!checkAnts && !checkBugs && turnCount < steps) {
		board->move();
		checkAnts = board->noAnts();
		checkBugs = board->noBugs();
		turnCount++;
	}
	board->print();
	cout << "Game over" << endl;
	if (checkAnts) {
		cout << "All ants died" << endl;
	}
	if (checkBugs) {
		cout << "All bugs died" << endl;
	}
	if (turnCount >= steps) {
		cout << "step limit reached. Limit was:" << endl;
		cout << steps << endl;
	}
	return 0;

}
