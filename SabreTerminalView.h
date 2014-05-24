/*
 * SabreTerminalView.h
 *
 *  Created on: Apr 30, 2014
 *      Author: sarniakjr
 */

#ifndef SABRETERMINALVIEW_H_
#define SABRETERMINALVIEW_H_

#include "SabreView.h"
#include "SabreController.h"
#include <cstdio>
#include <iostream>
#include <thread>

class SabreTerminalView : public SabreView {
public:
	SabreTerminalView(){}
	virtual ~SabreTerminalView(){}

	void setController(SabreController *c);

	void showLoading();
	void dismissLoading();
	bool loadingOccurs() const;

	void start();
private:
	enum err {
			CANNOT_COMMIT, CANNOT_PUT, PICK_FIRST, CANNOT_PICK, NOT_IN_DICT
	};
	SabreController *controller;
	void showTiles();
	void err(enum err e);

	std::thread *loader;
	volatile bool loading;
};

#endif /* SABRETERMINALVIEW_H_ */
