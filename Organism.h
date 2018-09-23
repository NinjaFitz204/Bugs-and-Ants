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
	virtual void move() =0;
	int getxcord();
	int getycord();
	void setX(int x);
	void setY(int y);
	int xcord;
		int ycord;
private:
};

#endif /* ORGANISM_H_ */
