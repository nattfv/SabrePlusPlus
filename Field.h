/*
 * Field.h
 *
 *  Created on: Jan 26, 2014
 *      Author: sarniakjr
 */

#ifndef FIELD_H_
#define FIELD_H_

#include <iostream>
#include "Letter.h"

class Board;

class Field {
public:
	enum Dir {NORTH, EAST, SOUTH, WEST};

	Field(int _x, int _y, Board *b) :
			x(_x), y(_y), letter(NULL), board(b) {
	}

	virtual ~Field() {
	}

	int getX() const;
	int getY() const;
	const Letter *get() const;
	void put(Letter *);

	Field *getNeighbour(Dir dir);

	bool operator==(const Field &second) const;
	bool operator<(const Field &second) const;
	friend std::ostream &operator<<(std::ostream &os, const Field &field);

private:
	int x;
	int y;
	Letter *letter;
	Board *board;
};

#endif /* FIELD_H_ */
