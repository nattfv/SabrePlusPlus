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
#include <cstring>

using namespace std;

void testWord(Board *board, TileBag *bag) {
	char *word;
	board->get(1, 1)->put(bag->getTile());
	board->get(1, 2)->put(bag->getTile());
	board->get(1, 3)->put(bag->getTile());
	board->get(1, 4)->put(bag->getTile());
	board->get(0, 3)->put(bag->getTile());
	board->get(2, 3)->put(bag->getTile());
	board->get(3, 3)->put(bag->getTile());
	board->get(4, 3)->put(bag->getTile());

	word = board->get(1, 2)->getWord(Field::EAST);
	cout << word << endl;
	word = board->get(3, 3)->getWord(Field::SOUTH);
	cout << word << endl;
}

int main() {
	Board board = Board(5, 6);
	TileBag bag;

	testWord(&board, &bag);
	board.printBoard(cout);
	return 0;
}
