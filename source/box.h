#ifndef _BOX_H_
#define _BOX_H_

#include "position.h"
#include<iostream>

class Box{
public:
//차례대로 위아래 좌우 
	Box(int x=0, int y=0, bool isChar = false);
	Box(Box& anti);
	void setPosition(int x, int y);
	void setPosition(Position& anti);
	Position getPosition();
	Position move(int vector);
	void setIsChar(bool x){
		isChar = x;
	}

	bool getIsChar(){
		return isChar;
	}

private:
	Position p;
	bool isChar;
};

#endif

