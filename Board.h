/*
 * Board.h
 *
 *  Created on: Sep 19, 2018
 *      Author: zrfitzgibbon
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "Organism.h"
#include<vector>
#include <bits/stdc++.h>

class Board {
public:
	Board();
	virtual ~Board();
	Board(int x,int b, int a,unsigned int s);
	void create();
	void print();
	bool isEmpty();
	void move();
private:
	int size;
	int numBugs;
	int numAnts;
	unsigned int seed;
	std::vector<std::vector<Organism*>> gameBoard;
	int getRnd(int top);
	void addAnt();
	void addBug();
};

#endif /* BOARD_H_ */
