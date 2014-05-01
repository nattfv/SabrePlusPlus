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

string Player::getName() const {
	return name;
}

bool Player::canUseField(Field *field) const {
	return field->isFree();
}

bool Player::canRemoveTileFrom(Field *field) const {
	return move.contains(field);
}

void Player::putTile(Tile *tile, Field *field) {
	hand.erase(find(hand.begin(), hand.end(), tile));
	field->put(tile);
	move.add(field);
}

void Player::removeTile(Field *field) {
	Tile *tile = field->getTile();

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

Move *Player::getMove() {
	return &move;
}

int Player::getHandSize() const {
	return hand.size();
}

int Player::getPoints() const {
	return points;
}

void Player::addPoints(int p) {
	points += p;
}

std::vector<Tile *>::iterator Player::handBegin() {
	return hand.begin();
}

std::vector<Tile *>::iterator Player::handEnd() {
	return hand.end();
}
