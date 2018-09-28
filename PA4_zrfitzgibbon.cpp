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
		pause = 0;
	case 7:
		break;
	}
	switch (argc) { //fallthrough is intended!!!
	case 7:
		pause = atoi(argv[6]);
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


	Board *board = new Board(gridSize, numBugs, numAnts, seed);
	//Board board(gridSize, numBugs, numAnts, seed);
	//board->create();
	board->print();
	board->move();
	cout << "first print" << endl;
	board->print();
	board->move();
	cout << "second print" << endl;
	board->print();
	board->move();
	cout << "third print" << endl;
	board->print();
	board->move();
	cout << "fourth print" << endl;
	board->print();
	board->move();
	cout << "fith print" << endl;
	board->print();
	board->move();
	cout << "sixth print" << endl;
	board->print();
	board->move();
	cout << "seventh print" << endl;
	board->print();
	board->move();
	cout << "eighth print" << endl;
	board->print();
	board->move();
	cout << "nineth print" << endl;
	board->print();
	board->move();
	cout << "tenth print" << endl;
	board->print();
	board->move();
	cout << "eleventh print" << endl;
	board->print();
	board->move();
	cout << "twelth print" << endl;
	board->print();

	return 0;

}
