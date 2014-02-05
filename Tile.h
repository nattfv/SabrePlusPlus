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
   Tile(wchar_t v, int p) : value(v), points(p){}
   Tile(const Tile& orig);
   virtual ~Tile();

   int getPoints() const;
   wchar_t getValue() const;

private:
   wchar_t value;
   int points;
};

#endif /* Tile_H_ */
