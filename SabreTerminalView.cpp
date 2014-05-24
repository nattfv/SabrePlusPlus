/*
 * SabreTerminalView.cpp
 *
 *  Created on: Apr 30, 2014
 *      Author: sarniakjr
 */

#include "SabreTerminalView.h"
#include <iostream>
#include <unistd.h>

using namespace std;

void SabreTerminalView::setController(SabreController *c) {
	controller = c;
}

void SabreTerminalView::showTiles() {
	Player *p = controller->getActivePlayer();
	Tile *activeTile = controller->getActiveTile();

	cout << "Tiles of player " << p->getName() << ':' << endl;
	for (vector<Tile *>::iterator it = p->handBegin(); it != p->handEnd(); ++it) {
		wcout << "[" << (*it)->getValue() << "]";
	}
	if (activeTile)
		wcout << "Picked: " << '[' << activeTile->getValue() << ']' << endl;
	wcout << endl;
}

void SabreTerminalView::err(enum err err) {
	switch (err) {
	case CANNOT_COMMIT:
		cout << "Cannot commit - move is invalid." << endl;
		break;
	case CANNOT_PUT:
		cout << "Cannot put tile here." << endl;
		break;
	case PICK_FIRST:
		cout << "You must pick a tile before putting it anywhere." << endl;
		break;
	case CANNOT_PICK:
		cout << "Not enough tiles." << endl;
		break;
	case NOT_IN_DICT:
		cout << "Word not in dictionary." << endl;
		break;
	default:
		cout << "Error!" << endl;
		break;
	}
}

void showHelp() {
	cout << "Commands:" << endl
			 << "c <num> - Choose tile number <num>. (Eg: c 1)" << endl
			 << "p <x> <y> - Put previously picked tile on field <x> <y>. (Eg: p 2 3)" << endl
			 << "x - Commit move." << endl
			 << "b - Print board" << endl
			 << "t - Print tiles" << endl
			 << "h - help" << endl
			 << "------------" << endl << endl;
}

void SabreTerminalView::start() {
	bool done = false;
	char command;
	int x, y;
	char pname[2][1024];

	for (int i = 0; i < 2; ++i) {
		cout << "Enter name for player " << i << endl;
		cin >> pname[i];
		controller->addPlayer(pname[i]);
	}

	showHelp();

	/* Player 1 gathers tiles */
	controller->gatherTiles();
	while (!done && cin.good()) {
		cin >> command;
		switch (command) {
		case 'c':
			cin >> x;
			if (x >= controller->getActivePlayer()->getHandSize()) {
				err(CANNOT_PICK);
				break;
			}
			controller->pickTile(x);
			wcout << "Picked " << controller->getActiveTile()->getValue() << endl;
			break;
		case 'p':
			cin >> x >> y;
			if (!controller->getActiveTile()) {
				err(PICK_FIRST);
				break;
			}
			if (controller->canPutTile(x, y)) {
				controller->putTile(x, y);
			} else {
				err(CANNOT_PUT);
			}
			break;
		case 'x':
			if (controller->canCommit()) {
				if (controller->isMoveCorrect()) {
					controller->commit();
					cout << "Move commited!" << endl;
				} else {
					err(NOT_IN_DICT);
					controller->rollback();
				}
				controller->nextPlayer();
				controller->gatherTiles();
				cout << "Player: " << controller->getActivePlayer()->getName() << endl << endl;
			} else {
				err(CANNOT_COMMIT);
			}
			break;
		case 'b':
			controller->getBoard()->printBoard(wcout);
			break;
		case 't':
			showTiles();
			break;
		case 'h':
			showHelp();
			break;
		default:
			break;
		}
	}
}

void processLoading(SabreTerminalView *view) {
	cout << "Loading. Please wait" << endl;
	while(view->loadingOccurs()) {
		cout << '.';
		cout.flush();
		sleep(1);
	}
	cout << endl;
}

bool SabreTerminalView::loadingOccurs() const {
	return loading;
}

void SabreTerminalView::showLoading() {
	loading = true;
	loader = new thread(processLoading, this);
}
void SabreTerminalView::dismissLoading() {
	loading = false;
	loader->join();
	delete loader;
}


