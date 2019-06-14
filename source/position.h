#ifndef _POSITION_H_
#define _POSITION_H_

#include<iostream>
using namespace std;

class Box;

class Position{
public:
	int x;
	int y;
	Position(int x=0, int y=0);
	Position(const Position& anti);


	bool operator !=(const Position& anti);
	bool operator ==(const Position& anti) const;

	void operator =(const Position& anti);
};
#endif

