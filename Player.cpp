/*
 * Player.cpp
 *
 *  Created on: Jan 27, 2014
 *      Author: sarniakjr
 */

#include "Player.h"
#include "Field.h"
#include "Tile.h"
#include <algorithm>

using namespace std;

const char *Player::getName() const {
	return name;
}

bool Player::canUseField(Field *field) const {
	return field->isFree();
}

bool Player::canRemoveTileFrom(Field *field) const {
	return move.contains(field);
}

void Player::putTile(Tile *tile, Field *field) {
    hand.erase( find(hand.begin(), hand.end(), tile) );
    field->put(tile);
    move.add(field);
}

void Player::removeTile(Field *field) {
	Tile *tile = field->get();

	hand.push_back(tile);
	field->put(NULL);
	move.remove(field);
}

void Player::takeTile(TileBag *bag) {
	hand.push_back(bag->getTile());
}

Tile *Player::pickTile(int idx) const {
	return hand[idx];
}

const Move *Player::getMove() const {
	return &move;
}
