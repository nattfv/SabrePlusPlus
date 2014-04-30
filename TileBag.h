/*
 * TileBag.h
 *
 *  Created on: Jan 26, 2014
 *      Author: sarniakjr
 */

#ifndef TILEBAG_H_
#define TILEBAG_H_

#include "Tile.h"
#include <vector>

class TileBag {
public:
	TileBag();
	virtual ~TileBag();

	Tile *getTile();
	bool empty();

private:
	std::vector<Tile *> tiles;
};

#endif /* TILEBAG_H_ */
