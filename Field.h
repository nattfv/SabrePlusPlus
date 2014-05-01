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
			x(_x), y(_y), tile(NULL), board(b), fieldBonus(1), wordBonus(1) {
	}

	virtual ~Field() {
	}

	int getX() const;
	int getY() const;
	Tile *getTile() const;
	void put(Tile *);
	bool isFree();
	std::wstring getWord(Board::Dir dir) const;

	Field *getNeighbour(Board::Dir dir);

	bool operator==(const Field &second) const;
	bool operator<(const Field &second) const;
	//friend std::ostream &operator<<(std::ostream &os, const Field &field);
	friend std::wostream &operator<<(std::wostream &os, const Field &field);

protected:
	int x;
	int y;
	Tile *tile;
	Board *board;
	int fieldBonus;
	int wordBonus;

};

class LightBlueField : public Field {
public:
	LightBlueField(int _x, int _y, Board *b) :
		Field(_x, _y, b) {
		fieldBonus = 2;
		wordBonus = 1;
	}

	virtual ~LightBlueField() {
	}
};

class DarkBlueField : public Field {
public:
	DarkBlueField(int _x, int _y, Board *b) :
		Field(_x, _y, b) {
		fieldBonus = 3;
		wordBonus = 1;
	}
	virtual ~DarkBlueField() {
	}
};

class OrangeField : public Field {
public:
	OrangeField(int _x, int _y, Board *b) :
		Field(_x, _y, b) {
		fieldBonus = 1;
		wordBonus = 2;
	}
	virtual ~OrangeField() {
	}
};

class RedField : public Field {
public:
	RedField(int _x, int _y, Board *b) :
		Field(_x, _y, b) {
		fieldBonus = 1;
		wordBonus = 3;
	}
	virtual ~RedField() {
	}
};

#endif /* FIELD_H_ */
