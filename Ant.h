/*
 * Ant.h
 *
 *  Created on: Sep 18, 2018
 *      Author: zrfitzgibbon
 */

#ifndef ANT_H_
#define ANT_H_

#include "Organism.h"

class Ant: public Organism {
public:
	Ant(int x,int y);
	Ant();
	virtual ~Ant();
	void move(Organism **gameBoard);
	int getOrg();
private:
	const int breedLimit = 3;
	int timeSinceBreed = 0;
};

#endif /* ANT_H_ */
