/*
 * Ant.h
 *
 *  Created on: Sep 18, 2018
 *      Author: zrfitzgibbon
 */

#ifndef ANT_H_
#define ANT_H_

#include <vector>
#include "Organism.h"

class Ant: public Organism {
public:
	Ant(int x,int y);
	Ant();
	virtual ~Ant();
	void move(std::vector<std::vector<Organism*>> board, int size);
	int getOrg();
	void resetMove();
	void didMove();
	int checkOpen(std::vector<std::vector<Organism*>> board, int x, int y);
private:
	int breedLimit;
	int timeSinceBreed;
	bool hasMoved;
};

#endif /* ANT_H_ */
