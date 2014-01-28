/*
 * Move.cpp
 *
 *  Created on: Jan 28, 2014
 *      Author: sarniakjr
 */

#include "Move.h"
#include <algorithm>

using namespace std;

void Move::add(Field *tile) {
	fields.push_back(tile);
}

void Move::remove(Field *tile) {
	fields.erase(find(fields.begin(), fields.end(), tile));
}

bool Move::contains(Field *tile) const {
	return find(fields.begin(), fields.end(), tile) != fields.end();
}

Board::Dir Move::getDir() const {
	int x0 = fields[0]->getX();
	int y0 = fields[0]->getY();
	bool horizontal = true;
	bool vertical = true;

	for (size_t i = 0; i < fields.size(); ++i)
		if (fields[i]->getX() != x0)
			horizontal = false;

	for (size_t i = 0; i < fields.size(); ++i)
		if (fields[i]->getY() != y0)
			vertical = false;

	if (horizontal)
		return Board::EAST;
	if (vertical)
		return Board::SOUTH;
	return Board::WRONG;
}

bool Move::isDirected() const {
	return getDir() != Board::WRONG;
}

