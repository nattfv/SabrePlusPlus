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
#include <cstring>

using namespace std;

void testWord(Board *board, TileBag *bag, Player *player) {
	char *word;

	for (int i = 0; i < 8; ++i)
		player->takeTile(bag);

	board->get(1, 1)->put(new Tile('x', 1));
	/*player->putTile(player->pickTile(0), board->get(1,1));*/
	player->putTile(player->pickTile(0), board->get(1, 2));
	player->putTile(player->pickTile(0), board->get(1, 3));
	/*player->putTile(player->pickTile(0), board->get(1,4));*/
	player->putTile(player->pickTile(0), board->get(0, 3));
	/*player->putTile(player->pickTile(0), board->get(2,3));
	 player->putTile(player->pickTile(0), board->get(3,3));
	 player->putTile(player->pickTile(0), board->get(4,3));*/

	cout << (player->getMove()->isValid() ? "VALID" : "NAH") << endl;

	word = board->get(1, 2)->getWord(Board::EAST);
	cout << word << endl;
	word = board->get(3, 3)->getWord(Board::SOUTH);
	cout << word << endl;
}

int main() {
	Board board = Board(5, 6);
	TileBag bag;
	Player p = Player("Janusz", &board, &bag);

	testWord(&board, &bag, &p);
	board.printBoard(cout);
	return 0;
}
