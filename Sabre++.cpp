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
#include <cstring>

#define PRINT_TEST(cout, a) (cout << ((a) ? "OK" : "FAIL") << endl)

using namespace std;

bool testWord(Board *board) {
	char *word;
	board->get(1, 1)->put(new Tile('a', 1));
	board->get(1, 2)->put(new Tile('b', 1));
	board->get(1, 3)->put(new Tile('c', 1));
	board->get(1, 4)->put(new Tile('d', 1));
	board->get(0, 3)->put(new Tile('e', 1));
	board->get(2, 3)->put(new Tile('f', 1));
	board->get(3, 3)->put(new Tile('g', 1));
	board->get(4, 3)->put(new Tile('h', 1));

	word = board->get(1, 2)->getWord(Field::EAST);
	if (strcmp(word, "abcd"))
		return false;
	word = board->get(3, 3)->getWord(Field::SOUTH);
	if (strcmp(word, "ecfgh"))
		return false;
	return true;
}

int main() {
	Board board = Board(5, 6);
	board.printBoard(cout);

	PRINT_TEST(cerr, testWord(&board));
	return 0;
}
