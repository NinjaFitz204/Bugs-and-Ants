/*
 * Doodlebug.h
 *
 *  Created on: Sep 18, 2018
 *      Author: zrfitzgibbon
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

#include "Organism.h"
#include <vector>

class Doodlebug: public Organism {
public:
	Doodlebug(int x,int y);
	Doodlebug();
	virtual ~Doodlebug();
	std::vector<std::vector<Organism*>> move(std::vector<std::vector<Organism*>> gameBoard,int size);
	int getOrg();
	int checkMove(int xcord,int ycord,std::vector<std::vector<Organism*>> gameBoard, int size);
	int timeSinceBreed;
	int breedLimit;
	int starveLim;
	int starveCount;

};

#endif /* DOODLEBUG_H_ */
