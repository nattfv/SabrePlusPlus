/*
 * Letter.h
 *
 *  Created on: Jan 26, 2014
 *      Author: sarniakjr
 */

#ifndef LETTER_H_
#define LETTER_H_

class Letter {
public:
   Letter(char v, int p) : value(v), points(p){}
   Letter(const Letter& orig);
   virtual ~Letter();

   int getPoints() const;
   char getValue() const;

private:
   char value;
   int points;
};

#endif /* LETTER_H_ */
