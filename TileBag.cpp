/*
 * TileBag.cpp
 *
 *  Created on: Jan 26, 2014
 *      Author: sarniakjr
 */

#include "TileBag.h"
#include "SabreException.h"

#include <algorithm>
#include <ctime>
#include <fstream>
#include <string>

#define ADD_TILES(c, p, n) do { for (int i = 0; i < n; ++i) { tiles.push_back(new Tile(c, p)); } } while (0)

using namespace std;

TileBag::TileBag() {
}

TileBag::~TileBag() {
}

void TileBag::loadFile(std::string path) {
	ifstream s;
	char c = '\0';
	int points, quantity;
	string newline;

	s.open(path.c_str());

	if (!s.is_open()) {
		throw SabreException("Tile bag file not found.\n");
	}

	while (s.good()) {
		s >> c;
		s >> points >> quantity;

		for (int i = 0; i < quantity; ++i)
			if(isalpha(c))
				tiles.push_back(new Tile(c, points));

		getline(s, newline);
	}

	srand(unsigned(time(0)));
	std::random_shuffle(tiles.begin(), tiles.end());
}

Tile *TileBag::getTile() {
	Tile *tile = tiles.back();
	tiles.pop_back();
	return tile;
}

bool TileBag::empty() {
	return tiles.empty();
}
