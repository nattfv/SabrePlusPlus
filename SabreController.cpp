/*
 * SabreController.cpp
 *
 *  Created on: Feb 5, 2014
 *      Author: sarniakjr
 */

#include "SabreController.h"
#include <cstring>
#include <algorithm>

SabreController::SabreController(Board *board) {
	this->board = board;
	firstMove = true;
	activeTile = NULL;
	activeField = NULL;
	this->bag = new TileBag();
}

SabreController::~SabreController() {
	delete bag;
}

void SabreController::addPlayer(const char *name) {
	Player *player = new Player(name, board, bag);
	players.push_back(player);
	activePlayer = players.front();

}

void SabreController::removePlayer(const char *name) {
	for (std::vector<Player *>::iterator it = players.begin(); it != players.end(); ++it) {
		if (!strcmp((*it)->getName(), name)) {
			players.erase(it);
			break;
		}
	}
}

void SabreController::nextPlayer() {
	std::vector<Player *>::iterator p = std::find(players.begin(), players.end(), activePlayer);
	p++;
	activePlayer = p == players.end() ? players.front() : *p;
}

void SabreController::pickTile(int idx) {
	Tile *tile = activePlayer->pickTile(idx);
	activeTile = tile;
}

bool SabreController::canPutTile(int x, int y) {
	Field *field = board->get(x, y);
	return field->isFree();
}

void SabreController::putTile(int x, int y) {
	Field *field = board->get(x, y);
	activePlayer->putTile(activeTile, field);
	activeTile = NULL;
}

void SabreController::gatherTiles() {
	bool done = activePlayer->getHandSize() == MAX_TILES || bag->empty();

	while (!done) {
		activePlayer->takeTile(bag);
		done = activePlayer->getHandSize() == MAX_TILES || bag->empty();
	}
}

Player *SabreController::getActivePlayer() {
	return activePlayer;
}

Tile *SabreController::getActiveTile() {
	return activeTile;
}

Board *SabreController::getBoard() {
	return board;
}

TileBag *SabreController::getTileBag() {
	return bag;
}

bool SabreController::canCommit() {
	if (firstMove) {
		firstMove = false;
		return activePlayer->getMove()->isValidAsFirst();
	}
	return activePlayer->getMove()->isValid();
}

void SabreController::commit() {
	const Move *move = activePlayer->getMove();
	activePlayer->addPoints(move->getScore());
}

void SabreController::flushTiles() {

}
