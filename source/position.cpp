#include"position.h"

Position::Position(int x,int y) : x(x), y(y)
{	
}
Position::Position(const Position& anti) : x(anti.x), y(anti.y)
{
}
	bool Position::operator !=(const Position& anti){
        if(anti.x == x && anti.y == y){
            return false;
        }else{
            return true;
        }
    }
	
	bool Position::operator ==(const Position& anti) const{
        if(anti.x == x && anti.y == y){
            return true;
        }else{
            return false;
        }
	}
	void Position::operator =(const Position& anti){
        x = anti.x;
        y = anti.y;
    }

