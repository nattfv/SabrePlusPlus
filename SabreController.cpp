/*
 * SabreController.cpp
 *
 *  Created on: Feb 5, 2014
 *      Author: sarniakjr
 */

#include "SabreController.h"
#include <cstring>

SabreController::SabreController(Board *board) {
	this->board = board;

}

SabreController::~SabreController() {
	// TODO Auto-generated destructor stub
}

void SabreController::addPlayer(const char *name) {
	Player *player = new Player(name, board, bag);
	players.push_back(player);
}

void SabreController::removePlayer(const char *name) {
	for (std::vector<Player *>::iterator it = players.begin(); it != players.end(); ++it) {
		if (!strcmp((*it)->getName(), name)) {
			players.erase(it);
			break;
		}
	}
}

void SabreController::tileChosen(Tile *tile) {
	/*TODO: manage activeTile & activePlayer etc */
}

void SabreController::fieldChosen(Field *field) {

}

void SabreController::commitChosen() {

}

void SabreController::tileFlushChosen() {

}
