/*
 * Move.h
 *
 *  Created on: Jan 28, 2014
 *      Author: sarniakjr
 */

#ifndef MOVE_H_
#define MOVE_H_

#include "Board.h"
#include "Field.h"
#include <vector>

class Move {
public:
	Move(Board *b) :
			board(b) {
	}
	virtual ~Move() {
	}

	void add(Field *);
	void remove(Field *);
	bool contains(Field *) const;
	bool isDirected() const;
	bool isConsistent(Board::Dir) const;
	bool isValid() const;
	bool isValidAsFirst() const;
	bool isAdjacent() const;
	int getScore() const;
	Board::Dir getDir() const;

private:
	Board *board;
	std::vector<Field *> fields;
};

#endif /* MOVE_H_ */
