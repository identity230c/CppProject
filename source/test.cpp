#include <bits/stdc++.h>

#include "position.h"
#include "box.h"
#include "game.h"
using namespace std;

void f(int x[][7], int hang){
	int ** tmp /*=  new int * [hang]*/;
	tmp = new int * [hang];

	for(int i=0;i<hang;i++){
		tmp[i] = new int[7];
	}
	tmp[1][1] = x[1][1];
	printf("%d\n", tmp[1][1]);
	/*for(int i=0;i<hang;i++){
		delete[] tmp[i];
	}
	delete[] *tmp;*/
}

int a[9][7] = {
	{4, 4, 4, 4, 4, 4, 4},
	{4, 1, 1, 1, 1, 1, 1},
	{1, 3, 0, 2, 0, 0, 1},
	{1, 3, 2, 5, 0, 0, 1},
	{1, 3, 0, 2, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1},
	{4, 4, 4, 4, 4, 4, 4},
	{4, 4, 4, 4, 4, 4, 4}
};
int main(){
	Position p1(1,3), p2;
	cout<<p1.x<<" "<<p1.y<<endl;
	//Position 테스트
	int arr[5][7]={};
	arr[1][1] = 104729;
	f(arr, 5);
	Box b;
	b = Box(3, 4);
	p2 = b.getPosition();
	cout<<p2.x<<" "<<p2.y<<endl;
	b.setPosition(p1);
	p2 = b.getPosition();
	cout<<p2.x<<" "<<p2.y<<endl;
	p2 = b.move(1);
	cout<<p2.x<<" "<<p2.y<<endl;
	cout<<"게임 테스트"<<endl;
	
	Game g(a);
	for(int i=0;i<9;i++){
		for(int j=0;j<7;j++){
			cout<<g.at(i,j)<<" ";
		}
		cout<<"\n";
	}
	g.printForDebug();
	cout<<g.isWin()<<endl;
	cout<<"이제부터 게임 시작 --------------\n";
	while(!g.isWin()){
		int vector;
		cin>>vector;//좌우하상
		if(g.move(g.getChar(), vector)){
			cout<<"움직임\n";
		}else{
			cout<<"못 움직임\n";
		}
		for(int i=0;i<9;i++){
			for(int j=0;j<7;j++){
				cout<<g.at(i,j)<<" ";
			}
			cout<<"\n";
		}
		if(g.isWin()){
			cout<<"끝남\n";
		}else{
			cout<<"아직 안끝남\n";
		}
		g.printForDebug();
	}
	return 0;
}
