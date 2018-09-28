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
	int gridSize = 2;
	int numBugs = 1; //5
	int numAnts = 3; //100
	int steps = 1000;
	int seed = 1;
	int pause = 1;

	//nkdghkjl

	//char** gameBoard;

	/*for (int i = 0; i < argc; i++) {
	 switch (i) {

	 case 0:
	 gridSize = argv[i];
	 break;

	 case 1:
	 numBugs = argv[i];
	 break;
	 case 2:
	 numAnts = argv[i];
	 break;
	 case 3:
	 steps = argv[i];
	 break;
	 case 4:
	 seed = argv[i];
	 break;
	 case 5:
	 pause = argv[i];
	 break;
	 }*/

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
