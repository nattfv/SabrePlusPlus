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

class SabreTerminalView {
public:
	SabreTerminalView(SabreController *c) : controller(c){}
	virtual ~SabreTerminalView();

	void start();
private:
	SabreController *controller;
	void showTiles();
};

#endif /* SABRETERMINALVIEW_H_ */
