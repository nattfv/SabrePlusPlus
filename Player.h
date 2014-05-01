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
	Player(std::string n, Board *b, TileBag *tb) :
			name(n), board(b), move(b), points(0) {
	}
	virtual ~Player() {
	}

	std::string getName() const;
	bool canUseField(Field *) const;
	bool canRemoveTileFrom(Field *) const;
	void putTile(Tile *, Field *);
	void removeTile(Field *);
	void takeTile(TileBag *);
	int getHandSize() const;
	std::vector<Tile *>::iterator handBegin();
	std::vector<Tile *>::iterator handEnd();
	Tile *pickTile(int idx) const;
	Move *getMove();

	int getPoints() const;
	void addPoints(int);

private:
	std::string name;
	Board *board;
	TileBag *bag;
	std::vector<Tile *> hand;
	Move move;
	int points;
};

#endif /* PLAYER_H_ */
