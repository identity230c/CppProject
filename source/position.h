#ifndef _POSITION_H_

#define _POSITION_H_



#include<iostream>

using namespace std;



class Box;



class Position {

public:

	int x;

	int y;

	Position(int x = 0, int y = 0) : x(x), y(y){}

	Position(const Position& anti) : x(anti.x), y(anti.y){}





	bool operator !=(const Position& anti){
		if (anti.x == x && anti.y == y) {
        	return false;
    	}else {
    	    return true;
    	}	
	}

	bool operator ==(const Position& anti) const{
 		if (anti.x == x && anti.y == y) {
        	return true;
   		 }else {
        	return false;
    	}
	}



	void operator =(const Position& anti){
		x = anti.x;
	    y = anti.y;
	}

};

#endif
