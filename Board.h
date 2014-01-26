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

class Field;

class Board {
public:
	Board(int x, int y);
	Board(const Board& orig) {
	}

	Field *get(int x, int y);
	void printBoard(std::ostream &) const;

	virtual ~Board() {
	}

	friend class Field;

private:
	std::vector<std::vector<Field *> > fields;
};

#endif /* BOARD_H_ */
