/*
 * Field.cpp
 *
 *  Created on: Jan 26, 2014
 *      Author: sarniakjr
 */

#include "Field.h"
#include "Board.h"
#include "Tile.h"
#include <cstring>

using namespace std;

int Field::getX() const {
	return x;
}

int Field::getY() const {
	return y;
}

Tile *Field::getTile() const {
	return tile;
}

void Field::put(Tile *l) {
	tile = l;
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

Field *Field::getNeighbour(Board::Dir dir) {
	switch (dir) {
	case Board::WEST:
		return y > 0 ? board->get(x, y - 1) : nullptr;
	case Board::SOUTH:
		return x < board->getX() - 1 ? board->get(x + 1, y) : nullptr;
	case Board::EAST:
		return y < board->getY() - 1 ? board->get(x, y + 1) : nullptr;
	case Board::NORTH:
		return x > 0 ? board->get(x - 1, y) : nullptr;
	default:
		return (Field *) nullptr;
	}
}

bool Field::isFree() {
	return tile == nullptr;
}

string Field::getWord(Board::Dir dir) const {
	int _y = y;
	int _x = x;
	int vx = dir == Board::SOUTH ? 1 : 0;
	int vy = dir == Board::EAST ? 1 : 0;
	string word;

	while (_y >= 0 && _x >= 0 && board->get(_x, _y)->getTile() != nullptr) {
		_y -= vy;
		_x -= vx;
	}
	_y += vy;
	_x += vx;

	while (_y < board->getY() && _x < board->getX()
			&& board->get(_x, _y)->getTile() != nullptr) {
		word += board->get(_x, _y)->getTile()->getValue();
		_y += vy;
		_x += vx;

	}
	return word;
}

/*std::ostream &operator<<(std::ostream &os, const Field &field) {
	return os << "[" << (field.tile ? field.tile->getValue() : '_') << "]";
}*/

std::wostream &operator<<(std::wostream &os, const Field &field) {
	return os << "[" << (field.tile ? field.tile->getValue() : field.token) << "]";
}
