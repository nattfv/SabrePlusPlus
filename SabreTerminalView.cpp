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
	for (vector<Tile *>::iterator it = p->handBegin(); it != p->handEnd(); ++it) {
		wcout << "[" << (*it)->getValue() << "]";
	}
	wcout << endl;
}

void SabreTerminalView::start() {
	bool done = false;
	char command;
	char pname[2][1024];

	for (int i = 0; i < 2; ++i) {
		cout << "Enter name for player " << i << endl;
		cin >> pname[i];
		cout << "Player " << i << " is now " << pname[i] << endl;
		controller->addPlayer(pname[i]);
	}


	while (!done) {
		controller->gatherTiles();
		cout << "Tiles of player " << controller->getActivePlayer()->getName() << ':' << endl;
		showTiles();
		cin >> command;
		switch (command) {
		case 'g': done = true; break;
		default: break;
		}
	}
}

