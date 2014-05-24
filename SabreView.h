/*
 * SabreView.h
 *
 *  Created on: May 24, 2014
 *      Author: sarniakjr
 */

#ifndef SABREVIEW_H_
#define SABREVIEW_H_

#include "SabreController.h"

class SabreView {
public:
	SabreView(){}
	virtual ~SabreView(){}

	virtual void setController(SabreController *c) = 0;

	virtual void showLoading() = 0;
	virtual void dismissLoading() = 0;

	virtual void start() = 0;
};

#endif /* SABREVIEW_H_ */
