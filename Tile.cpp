/*
 * Tile.cpp
 *
 *  Created on: Jan 26, 2014
 *      Author: sarniakjr
 */

#include "Tile.h"

Tile::Tile(const Tile& orig) {
}

Tile::~Tile() {
}

int Tile::getPoints() const {
	return points;
}

wchar_t Tile::getValue() const {
	return value;
}
