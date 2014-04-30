/*
 * SabreTerminalView.h
 *
 *  Created on: Apr 30, 2014
 *      Author: sarniakjr
 */

#ifndef SABRETERMINALVIEW_H_
#define SABRETERMINALVIEW_H_

#include "SabreController.h"
#include <cstdio>
#include <iostream>

enum err {
		CANNOT_PUT, PICK_FIRST, CANNOT_PICK
};

class SabreTerminalView {
public:
	SabreTerminalView(SabreController *c) : controller(c){}
	virtual ~SabreTerminalView();

	void start();
private:
	SabreController *controller;
	void showTiles();
	void err(enum err e);
};

#endif /* SABRETERMINALVIEW_H_ */