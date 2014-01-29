/*
 * Move.cpp
 *
 *  Created on: Jan 28, 2014
 *      Author: sarniakjr
 */

#include "Move.h"
#include <algorithm>
#include <climits>
#include <set>

using namespace std;

void Move::add(Field *field) {
	fields.push_back(field);
}

void Move::remove(Field *field) {
	fields.erase(find(fields.begin(), fields.end(), field));
}

bool Move::contains(Field *field) const {
	return find(fields.begin(), fields.end(), field) != fields.end();
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

bool Move::isConsistent(Board::Dir dir) const {
	int minX = INT_MAX;
	int minY = INT_MAX;
	size_t used = 0;
	Field *field;

	for (size_t i = 0; i < fields.size(); ++i) {
		if (minX == INT_MAX || fields[i]->getX() < fields[minX]->getX())
			minX = i;
		if (minY == INT_MAX || fields[i]->getY() < fields[minY]->getY())
			minY = i;
	}

	field = fields[dir == Board::SOUTH ? minX : minY];
	while (field != NULL) {
		if (contains(field))
			used++;
		field = field->getNeighbour(dir);
	}

	return fields.size() == used;
}

bool Move::isAdjacent() const {
	set<Tile *> neighbours;

	for (size_t i = 0; i < fields.size(); ++i)
		for (int dir = Board::NORTH; dir < Board::WRONG; dir++)
			neighbours.insert(fields[i]->getNeighbour((Board::Dir) dir)->get());

	neighbours.erase(NULL);
	return fields.size() != neighbours.size();
}

bool Move::isValid() const {
	Board::Dir dir = getDir();

	if (dir == Board::WRONG)
		return false;

	return isConsistent(dir) && isAdjacent();
}
