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

using namespace std;

int main() {
	Board board = Board(5,6);
	board.get(2,1)->put(new Letter('a', 1));
	board.get(2,2)->put(new Letter('b', 1));
	board.printBoard(cout);
	cout << board.get(2,2)->getNeighbour(Field::WEST)->getNeighbour(Field::WEST)->getNeighbour(Field::EAST)->get()->getValue();
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
