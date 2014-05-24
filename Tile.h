/*
 * Tile.h
 *
 *  Created on: Jan 26, 2014
 *      Author: sarniakjr
 */

#ifndef Tile_H_
#define Tile_H_

class Tile {
public:
   Tile(char v, int p) : value(v), points(p){}
   Tile(const Tile& orig);
   virtual ~Tile();

   int getPoints() const;
   char getValue() const;

private:
   char value;
   int points;
};

#endif /* Tile_H_ */
