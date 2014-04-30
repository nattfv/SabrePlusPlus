/*
 * SabreTerminalView.cpp
 *
 *  Created on: Apr 30, 2014
 *      Author: sarniakjr
 */

#include "SabreTerminalView.h"

using namespace std;

SabreTerminalView::~SabreTerminalView() {
	// TODO Auto-generated destructor stub
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
	case CANNOT_PUT:
		cout << "Cannot put tile here." << endl;
		break;
	case PICK_FIRST:
		cout << "You must pick a tile before putting it anywhere." << endl;
		break;
	case CANNOT_PICK:
		cout << "Not enough tiles." << endl;
		break;
	default:
		cout << "Error!" << endl;
		break;
	}
}

static void showHelp() {
	cout << "Commands:" << endl
			 << "c <num> - Choose tile number <num>. (Eg: c 1)" << endl
			 << "p <x> <y> - Put previously picked tile on field <x> <y>. (Eg: p 2 3)" << endl
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
		cout << "Player " << i << " is now " << pname[i] << endl;
		controller->addPlayer(pname[i]);
	}

	showHelp();

	/* Player 1 gathers tiles */
	controller->gatherTiles();
	while (!done) {
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
			if (!controller->getActiveTile()) {
				err(PICK_FIRST);
				break;
			}
			cin >> x >> y;
			if (controller->canPutTile(x, y)) {
				controller->putTile(x, y);
			} else {
				err(CANNOT_PUT);
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

