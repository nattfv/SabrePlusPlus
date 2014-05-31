/*
 * SabreException.h
 *
 *  Created on: May 27, 2014
 *      Author: sarniakjr
 */

#ifndef SABREEXCEPTION_H_
#define SABREEXCEPTION_H_

#include<string>

class SabreException: public std::exception {
private:
    std::string _msg;
public:
    SabreException(const std::string& msg) : _msg(msg){};
    virtual const char* what() const noexcept;
};

#endif /* SABREEXCEPTION_H_ */
