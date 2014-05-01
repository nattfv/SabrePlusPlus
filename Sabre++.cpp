//============================================================================
// Name        : Sabre++.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Board.h"
#include "Field.h"
#include "TileBag.h"
#include "Player.h"
#include "SabreController.h"
#include "SabreTerminalView.h"
#include <cstring>

using namespace std;

void testWord(SabreController *controller) {
	wstring word;
	Board *board = controller->getBoard();

	controller->gatherTiles();

	controller->pickTile(0);
	if (controller->canPutTile(1,1))
		controller->putTile(1,1);
	controller->pickTile(0);
	if (controller->canPutTile(1,2))
		controller->putTile(1,2);
	controller->pickTile(0);
	if (controller->canPutTile(1,3))
		controller->putTile(1,3);
	controller->pickTile(0);
	if (controller->canPutTile(1,4))
		controller->putTile(1,4);

	word = board->get(1, 2)->getWord(Board::EAST);
	wcout << word << endl;
	word = board->get(3, 3)->getWord(Board::SOUTH);
	wcout << word << endl;
}

int main() {
	Board board = Board(5, 6);
	SabreController controller(&board);
	SabreTerminalView view(&controller);

	view.start();

	cout << controller.getActivePlayer()->getName() << endl;
	cout << controller.getActivePlayer()->getPoints() << endl;
	testWord(&controller);
	cout << "Can commit? " << (controller.canCommit() ? "yes" : "no") << endl;
	controller.commit();
	cout << "Score: " << controller.getActivePlayer()->getPoints() << endl;
	board.printBoard(wcout);
	return 0;
}
