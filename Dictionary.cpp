/*
 * Dictionary.cpp
 *
 *  Created on: May 1, 2014
 *      Author: sarniakjr
 */

#include "Dictionary.h"
#include <fstream>

using namespace std;

Dictionary::Dictionary() {
	// TODO Auto-generated constructor stub

}

Dictionary::~Dictionary() {
	// TODO Auto-generated destructor stub
}

void Dictionary::loadFile(std::string path) {
	ifstream s;
	string line;

	s.open(path.c_str());
	while (getline(s, line)) {
		data.insert(line);
	}
}

bool Dictionary::contains(std::string str) {
	return data.find(str) != data.end();
}

