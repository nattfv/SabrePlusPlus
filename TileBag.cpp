/*
 * TileBag.cpp
 *
 *  Created on: Jan 26, 2014
 *      Author: sarniakjr
 */

#include "TileBag.h"

#include <algorithm>
#include <ctime>

#define ADD_TILES(c, p, n) do { for (int i = 0; i < n; ++i) { tiles.push_back(new Tile(c, p)); } } while (0)

TileBag::TileBag() {

	ADD_TILES('a', 1, 9);
	ADD_TILES('e', 1, 7);
	ADD_TILES('i', 1, 8);
	ADD_TILES('n', 1, 5);
	ADD_TILES('o', 1, 6);
	ADD_TILES('r', 1, 4);
	ADD_TILES('s', 1, 4);
	ADD_TILES('w', 1, 4);
	ADD_TILES('z', 1, 5);

	ADD_TILES('c', 2, 3);
	ADD_TILES('d', 2, 3);
	ADD_TILES('k', 2, 3);
	ADD_TILES('l', 2, 3);
	ADD_TILES('m', 2, 3);
	ADD_TILES('p', 2, 3);
	ADD_TILES('t', 2, 3);
	ADD_TILES('y', 2, 4);

	ADD_TILES('b', 3, 2);
	ADD_TILES('g', 3, 2);
	ADD_TILES('h', 3, 2);
	ADD_TILES('j', 3, 2);
	ADD_TILES('u', 3, 2);

	ADD_TILES('f', 5, 1);

	srand(unsigned(time(NULL)));
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

TileBag::~TileBag() {
	// TODO Auto-generated destructor stub
}

