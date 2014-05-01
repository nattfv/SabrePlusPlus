/*
 * Dictionary.h
 *
 *  Created on: May 1, 2014
 *      Author: sarniakjr
 */

#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include <set>
#include <string>

class Dictionary {
public:
	Dictionary();
	virtual ~Dictionary();

	void loadFile(std::string path);
	bool contains(std::wstring str);
private:
	std::set<std::wstring> data;
};

#endif /* DICTIONARY_H_ */
