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

int Field::getX() const {
	return x;
}

int Field::getY() const {
	return y;
}

const Tile *Field::get() const {
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

Field *Field::getNeighbour(Dir dir) {
	switch (dir) {
	case WEST:
		return y > 0 ? board->get(x, y - 1) : NULL;
	case SOUTH:
		return x < board->getX() - 1 ? board->get(x + 1, y) : NULL;
	case EAST:
		return y < board->getY() - 1 ? board->get(x, y + 1) : NULL;
	case NORTH:
		return x > 0 ? board->get(x - 1, y) : NULL;
	}
}

bool Field::isFree() {
	return tile == NULL;
}

char *Field::getWord(Dir dir) const {
  int _y = y;
  int _x = x;
  int at = 0;
  int vx = dir == SOUTH ? 1 : 0;
  int vy = dir == EAST ? 1 : 0;

  static char *word = new char[board->getMaxWordSize()];

  memset(word, 0, board->getMaxWordSize());

  while (_y >= 0 && _x >= 0 && board->get(_x, _y)->get() != NULL ) {
    _y -= vy;
    _x -= vx;
  }
  _y += vy;
  _x += vx;

  while (_y < board->getY() && _x < board->getX() && board->get(_x, _y)->get() != NULL) {
    word[at] = board->get(_x, _y)->get()->getValue();
    _y += vy;
    _x += vx;
    at++;
  }

  return word;
}

std::ostream &operator<<(std::ostream &os, const Field &field) {
	return os << "[" << (field.tile ? field.tile->getValue() : '_') << "]";
}
