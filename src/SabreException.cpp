/*
 * SabreException.cpp
 *
 *  Created on: May 27, 2014
 *      Author: sarniakjr
 */

#include "SabreException.h"

const char* SabreException::what() const noexcept {
	return _msg.c_str();
}

