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
#include <cstdlib>

using namespace std;

#ifndef BOARD_PATH
#define BOARD_PATH "board/board.dat"
#endif

#ifndef TILEBAG_PATH
#define TILEBAG_PATH "tilebag/bag.dat"
#endif

#ifndef DICT_PATH
#define DICT_PATH "dict/dict.dat"
#endif

int main(int argc,char *argv[]) {
	const char *dictPath = DICT_PATH;
	SabreView *view = new SabreTerminalView();

	view->showLoading();

	Board board = Board(15, 15);
	SabreController controller(&board, dictPath);
	view->setController(&controller);

	view->dismissLoading();

	switch(argc) {
	case 0:
		break;
	case 1:
		dictPath = argv[0];
		break;
	default:
		cout << "Usage: ./Sabre++ [dictionary-path]";
		exit(1);
	}

	board.fromFile(BOARD_PATH);
	controller.loadTileBag(TILEBAG_PATH);
	view->start();

	delete view;
	return 0;
}
