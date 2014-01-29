/*
 * Player.h
 *
 *  Created on: Jan 27, 2014
 *      Author: sarniakjr
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Board.h"
#include "TileBag.h"
#include "Move.h"
#include <vector>

class Player {
public:
	Player(const char *n, Board *b, TileBag *tb) :
			name(n), board(b), move(b) {
	}
	virtual ~Player() {
	}

	const char *getName() const;
	bool canUseField(Field *) const;
	bool canRemoveTileFrom(Field *field) const;
	void putTile(Tile *, Field *);
	void removeTile(Field *);
	void takeTile(TileBag *bag);
	Tile *pickTile(int idx) const;
	const Move *getMove() const;

private:
	const char *name;
	Board *board;
	TileBag *bag;
	std::vector<Tile *> hand;
	Move move;
};

#endif /* PLAYER_H_ */
