#ifndef _GAME_H_
#define _GAME_H_

#include "position.h"
#include "box.h"

const int hang = 9;

class Game{
public:
	Game(int map[][7]) : imChar(){//1벽 2상자 3목적지 4바깥
		lenBox=0;
		gameMap = new int * [9];
		for(int i=0;i<hang;i++){//박스 몇개인지 세는 단계
			gameMap[i] = new int[7];
			for(int j=0;j<7;j++){
				gameMap[i][j] = map[i][j];
				if(map[i][j] == 2){
					lenBox += 1;
				}
			}
		}
		desti = new Position[lenBox];
		boxArray = new Box[lenBox];
		int b=0, d=0;
		for(int i=0;i<hang;i++){//박스 몇개인지 배치해줌
			for(int j=0;j<7;j++){
				if(gameMap[i][j]==5){
					imChar.setPosition(i,j);
					imChar.setIsChar(true);
				}else if(gameMap[i][j] == 2){
					boxArray[b] = Box(i,j);
					b++;
				}else if(gameMap[i][j] == 3){
					desti[d] = Position(i,j);
					d++;
				}
			}
		}
	}

	bool isWin(){
		int isEnd = 0;
		for(int i=0;i<lenBox;i++){
			for(int j=0;j<lenBox;j++){
				if(desti[j] == boxArray[i].getPosition()){
					isEnd++;
				}
			}
		}
		if(isEnd == lenBox){
			return true;
		}else{
			return false;
		}
		/*
		if(isEnd == lenBox){
			return true;
		}else{
			return false;
		}*/
	}
	
	bool move(Box& b,int input){
		bool canMove;
		Position tmp = b.move(input);
		if(at(tmp) == 1){
			canMove = false;	
		}else if(at(tmp) == 3 || at(tmp) == 0){
			canMove = true;
		}else if(at(tmp) == 2){
			int i;
			for(i=0;i<lenBox;i++){
				if(boxArray[i].getPosition() == tmp){
					break;
				}
			}
			canMove = move(boxArray[i], input);
		}
		if(canMove){
			setMap(b.getPosition(), 0);
			if(b.getIsChar()){
				setMap(tmp, 5);
			}else{
				setMap(tmp, 2);
			}
			b.setPosition(tmp);
		}
		return canMove;
	}

	int at(int i,int j){//배열을 get메서드로 넘기긴 좀get메서드로 넘기긴 좀;;
		return gameMap[i][j];
	}

	int at(const Position& p){
		return gameMap[p.x][p.y];
	}
	void setMap(int i, int j,int k){
		gameMap[i][j] = k;
	}
	void setMap(const Position& p, int k){
		gameMap[p.x][p.y] = k;
	}
	
	void printForDebug(){
		cout<<lenBox<<endl;
		cout<<"목적지"<<endl;
		for(int i=0;i<lenBox;i++){
			cout<<desti[i].x<<" "<<desti[i].y<<endl;
		}
		cout<<"박스 위치"<<endl;
		for(int i=0;i<lenBox;i++){
			cout<<boxArray[i].getPosition().x<<" "<<boxArray[i].getPosition().y<<endl;
		}
	}

	Box& getChar(){
		return imChar;
	}

private:
	int** gameMap;
	Box* boxArray;
	Box imChar;
	Position * desti;//목적지
	int lenBox;
};

#endif
