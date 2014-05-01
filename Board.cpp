/*
 * Board.cpp
 *
 *  Created on: Jan 26, 2014
 *      Author: sarniakjr
 */

#include "Board.h"
#include "Field.h"
#include <iostream>

Board::Board(int x, int y) {
	fields = std::vector<std::vector<Field *> >(x, std::vector<Field *>(y));

	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			fields[i][j] = new Field(i, j, this);
		}
	}
}

Field *Board::get(int x, int y) {
	return fields[x][y];
}

void Board::printBoard(std::wostream& os) const {
	for (size_t i = 0; i < fields.size(); ++i) {
		for (size_t j = 0; j < fields[0].size(); ++j) {
			os << *fields[i][j];
		}
		os << std::endl;
	}
}

int Board::getX() const {
	return fields.size();
}

int Board::getY() const {
	return fields[0].size();
}

int Board::getMaxWordSize() const {
	return MAX(fields.size(), fields[0].size());
}
