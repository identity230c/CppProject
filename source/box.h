#ifndef _BOX_H_

#define _BOX_H_



#include "position.h"

#include<iostream>

int dirx[4] = { 0, 0, -1, 1 };

int diry[4] = { 1, -1, 0, 0 };



class Box {

public:

	Box(int x = 0, int y = 0, bool isChar = false): p(x, y), isChar(isChar)
	{
    	pushed = 0;
	}

	Box(Box& anti): p(anti.p), isChar(anti.isChar) 
	{
	    pushed = 0;
	}


	void setPosition(int x, int y){
	    p.x = x;
    	p.y = y;
	    pushed++;
	}

	void setPosition(Position& anti){
		p.x = anti.x;
		p.y = anti.y;
		pushed++;
	}
	
	int getPushed(){
		return pushed;
	}

	Position getPosition(){
		return p;
	}

	Position move(int vector){
	    return Position(dirx[vector] + p.x, diry[vector] + p.y);
	}

	void setIsChar(bool x) {

		isChar = x;

	}



	bool getIsChar() {

		return isChar;

	}



private:

	Position p;

	bool isChar;
	
	int pushed;
};



#endif
