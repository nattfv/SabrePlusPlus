/*
 * Field.h
 *
 *  Created on: Jan 26, 2014
 *      Author: sarniakjr
 */

#ifndef FIELD_H_
#define FIELD_H_

#include <iostream>
#include "Tile.h"
#include "Board.h"

//class Board;

class Field {
public:
	Field(int _x, int _y, Board *b) :
			x(_x), y(_y), tile(NULL), board(b) {
	}

	virtual ~Field() {
	}

	int getX() const;
	int getY() const;
	Tile *get() const;
	void put(Tile *);
	bool isFree();
	char *getWord(Board::Dir dir) const;

	Field *getNeighbour(Board::Dir dir);

	bool operator==(const Field &second) const;
	bool operator<(const Field &second) const;
	friend std::ostream &operator<<(std::ostream &os, const Field &field);

private:
	int x;
	int y;
	Tile *tile;
	Board *board;
};

#endif /* FIELD_H_ */
