/*
 * Board.h
 *
 *  Created on: Jan 26, 2014
 *      Author: sarniakjr
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <vector>
#include <iostream>
#include <string>

#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

class Field;

class Board {
public:
	enum Dir {
		NORTH, EAST, SOUTH, WEST, WRONG
	};

	Board(int x, int y);
	Board(const Board& orig) {
	}

	Field *get(int x, int y);
	int getX() const;
	int getY() const;
	Field *getCentre() const;
	void fromFile(std::string path);
	int getMaxWordSize() const;
	void printBoard(std::wostream &) const;

	virtual ~Board() {
	}

	friend class Field;

private:
	std::vector<std::vector<Field *> > fields;
};

#endif /* BOARD_H_ */
