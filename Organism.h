/*
 * Organism.h
 *
 *  Created on: Sep 18, 2018
 *      Author: zrfitzgibbon
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_

class Organism {
public:
	Organism();
	virtual ~Organism();
	virtual void move(Organism **board, int size)=0;
	int getxcord();
	int getycord();
	void setX(int x);
	void setY(int y);
	int getOrg();
	int xcord;
	int ycord;
	int whatOrg;// 0 if nothing, 1 if ant, 2 if doodlebug
private:
};

#endif /* ORGANISM_H_ */
