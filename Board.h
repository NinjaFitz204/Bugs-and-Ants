/*
 * Board.h
 *
 *  Created on: Sep 19, 2018
 *      Author: zrfitzgibbon
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "Organism.h"
#include <bits/stdc++.h>
#include <vector>

class Board {
public:
	Board();
	virtual ~Board();
	Board(int x,int b, int a,unsigned int s);
	void create();
	void print();
private:
	int size;
	int numBugs;
	int numAnts;
	vector< vector<int> > place; // 0 if there is no organism, 1 if bug, 2 if ant
	unsigned int seed;
	Organism** gameBoard;
	int getRnd(int top);
	void addAnt();
	void addBug();
};

#endif /* BOARD_H_ */
