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
#include <string>

class TileBag {
public:
	TileBag();
	virtual ~TileBag();

	void loadFile(std::string path);

	Tile *getTile();
	bool empty();

private:
	std::vector<Tile *> tiles;
};

#endif /* TILEBAG_H_ */
