/*
 * Organism.h
 *
 *  Created on: Sep 18, 2018
 *      Author: zrfitzgibbon
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_

#include <vector>

class Organism {
public:
	Organism();
	virtual ~Organism();
	virtual std::vector<std::vector<Organism*>> move(std::vector<std::vector<Organism*>> gameBoard, int size)=0;
	int getxcord();
	int getycord();
	void setX(int x);
	void setY(int y);
	int getOrg();
	int xcord;
	int ycord;
	int whatOrg;// 0 if nothing, 1 if ant, 2 if doodlebug
	bool hasMoved;
private:
};

#endif /* ORGANISM_H_ */
