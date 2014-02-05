/*
 * SabreController.h
 *
 *  Created on: Feb 5, 2014
 *      Author: sarniakjr
 */

#ifndef SABRECONTROLLER_H_
#define SABRECONTROLLER_H_

#include "Board.h"
#include "Player.h"
#include <vector>

class SabreController {
public:
	SabreController(Board *board);
	virtual ~SabreController();

	void addPlayer(const char *name);
	void removePlayer(const char *name);
	void tileChosen(Tile *tile);
	void fieldChosen(Field *field);
	void commitChosen();
	void tileFlushChosen();

private:
	void nextPlayer();
	void nextRound();
	Board *board;
	TileBag *bag;
	Player *activePlayer;
	Field *activeField;
	Tile *activeTile;
	std::vector<Player *> players;
};

#endif /* SABRECONTROLLER_H_ */
