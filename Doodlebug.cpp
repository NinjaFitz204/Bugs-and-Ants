/*
 * Doodlebug.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: zrfitzgibbon
 */
#include <iostream>
#include "Doodlebug.h"
using namespace std;

Doodlebug::Doodlebug() {
	// TODO Auto-generated constructor stub
	xcord=0;
	ycord=0;
	whatOrg = 2;

}

Doodlebug::Doodlebug(int x,int y){

	xcord=x;
	ycord=y;
	whatOrg = 2;
}

Doodlebug::~Doodlebug() {
	// TODO Auto-generated destructor stub
}

void Doodlebug::move(){

}

int Doodlebug::getOrg(){
	return whatOrg;
}

