#include <bits/stdc++.h>

#include "position.h"

#include "box.h"
int dirx[4] = {0, 0, -1, 1};
int diry[4] = {1, -1, 0, 0};

Box::Box(int x, int y, bool isChar) : p(x,y), isChar(isChar)
{
}

Box::Box(Box& anti) : p(anti.p), isChar(anti.isChar){}
void Box::setPosition(int x,int y){
	p.x = x;
	p.y = y;
}

void Box::setPosition(Position& anti){
	p.x = anti.x;
	p.y = anti.y;
}

Position Box::getPosition(){
	return p;
}

Position Box::move(int vector){//좌우상하
	return Position(dirx[vector] + p.x, diry[vector] + p.y);
}

