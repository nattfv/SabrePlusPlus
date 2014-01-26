/*
 * Field.cpp
 *
 *  Created on: Jan 26, 2014
 *      Author: sarniakjr
 */

#include "Field.h"
#include "Board.h"

int Field::getX() const {
	return x;
}

int Field::getY() const {
	return y;
}

const Letter *Field::get() const {
	return letter;
}

void Field::put(Letter *l) {
	letter = l;
}

bool Field::operator==(const Field &second) const {
	return x == second.x && y == second.y;
}

bool Field::operator<(const Field &second) const {
	if (x < second.x)
		return true;
	else
		return y < second.y;
}

Field *Field::getNeighbour(Dir dir) {
	switch (dir) {
	case WEST:
		return y > 0 ? board->get(x, y - 1) : NULL;
	case SOUTH:
		return x < board->fields.size() - 1 ? board->get(x + 1, y) : NULL;
	case EAST:
		return y < board->fields.size() - 1 ? board->get(x, y + 1) : NULL;
	case NORTH:
		return x > 0 ? board->get(x - 1, y) : NULL;
	}
}

std::ostream &operator<<(std::ostream &os, const Field &field) {
	return os << "[" << (field.letter ? field.letter->getValue() : '_') << "]";
}
