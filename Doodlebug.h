/*
 * Doodlebug.h
 *
 *  Created on: Sep 18, 2018
 *      Author: zrfitzgibbon
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

#include "Organism.h"

class Doodlebug: public Organism {
public:
	Doodlebug(int x,int y);
	Doodlebug();
	virtual ~Doodlebug();
	void move();
};

#endif /* DOODLEBUG_H_ */
