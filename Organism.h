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
	virtual void move();
	int getxcord();
	int getycord();
	void setX(int x);
	void setY(int y);
	int getOrg();
	int xcord;
		int ycord;
		int whatOrg;
private:
};

#endif /* ORGANISM_H_ */
