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
#include "Dictionary.h"
#include <vector>

#define MAX_TILES (7)

#ifndef DICT_PATH
#define DICT_PATH "dict/dict.dat"
#endif

class SabreController {
public:
	SabreController(Board *board);
	virtual ~SabreController();

	void addPlayer(std::string name);
	void removePlayer(std::string name);
	void nextPlayer();

	void pickTile(int idx);
	bool canPutTile(int x, int y);
	void putTile(int x, int y);
	void gatherTiles();
	Player *getActivePlayer();
	Tile *getActiveTile();

	Board *getBoard();
	TileBag *getTileBag();
	bool canCommit();
	void commit();
	void rollback();
	bool isMoveCorrect();
	void flushTiles();

private:
	void nextRound();
	Board *board;
	TileBag *bag;
	Dictionary *dict;
	Player *activePlayer;
	Field *activeField;
	Tile *activeTile;
	std::vector<Player *> players;
	bool firstMove;
};

#endif /* SABRECONTROLLER_H_ */
