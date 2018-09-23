/*
 * Ant.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: zrfitzgibbon
 */

#include "Ant.h"

Ant::Ant(int x, int y){
	xcord=x;
	ycord=y;
	whatOrg=1;
}

Ant::Ant() {
	// TODO Auto-generated constructor stub
	xcord=0;
	ycord=0;
	whatOrg=1;

}

Ant::~Ant() {
	// TODO Auto-generated destructor stub
}

void Ant::move(){

}

int Ant::getOrg(){
	return whatOrg;
}
