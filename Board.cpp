/*
 * Board.cpp
 *
 *  Created on: Jan 26, 2014
 *      Author: sarniakjr
 */

#include "Board.h"
#include "Field.h"
#include <fstream>

using namespace std;

Board::Board(int x, int y) {
	fields = std::vector<std::vector<Field *> >(x, std::vector<Field *>(y));
}

Field *Board::get(int x, int y) {
	return fields[x][y];
}

void Board::printBoard(std::wostream& os) const {
	for (size_t i = 0; i < fields.size(); ++i) {
		for (size_t j = 0; j < fields[0].size(); ++j) {
			if (i == fields.size()/2 && j == fields[0].size()/2
					&& fields[i][j]->isFree())
				os << "[X]";
			else
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

Field *Board::getCentre() const {
	return fields[getX()/2][getY()/2];
}

int Board::getMaxWordSize() const {
	return MAX(fields.size(), fields[0].size());
}

void Board::fromFile(string path) {
	wifstream s;
	wchar_t c;
	wstring dummy;
	Field *f;

	s.open(path.c_str());
	for (int i = 0; i < getX(); ++i) {
		for (int j = 0; j < getY(); ++j) {
			c = s.get();
			switch (c) {
			case '_':
				f = new Field(i, j, this);
				break;
			case 'L':
				f = new LightBlueField(i, j, this);
				break;
			case 'D':
				f = new DarkBlueField(i, j, this);
				break;
			case 'O':
				f = new OrangeField(i, j, this);
				break;
			case 'R':
				f = new RedField(i, j, this);
				break;
			default:
				f = new Field(i, j, this);
				break;
			}
			fields[i][j] = f;
		}
		/* Eating newline characters */
		if (s.good())
			getline(s, dummy);
	}
}
