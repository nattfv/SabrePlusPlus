/*
 * Letter.cpp
 *
 *  Created on: Jan 26, 2014
 *      Author: sarniakjr
 */

#include "Letter.h"

Letter::Letter(const Letter& orig) {
}

Letter::~Letter() {
}

int Letter::getPoints() const {
	return points;
}

char Letter::getValue() const {
	return value;
}
