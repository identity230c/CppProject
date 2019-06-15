
#include<iostream>


#include "position.h"
#include "box.h"
#include "game.h"
#include "mapContainer.h"

using namespace std;

int main() {

	Position p1(1, 3), p2;

	cout << p1.x << " " << p1.y << endl;

	//Position Test

	int arr[5][7] = {};

	arr[1][1] = 104729;

	Box b;

	b = Box(3, 4);

	p2 = b.getPosition();

	cout << p2.x << " " << p2.y << endl;

	b.setPosition(p1);

	p2 = b.getPosition();

	cout << p2.x << " " << p2.y << endl;

	p2 = b.move(1);

	cout << p2.x << " " << p2.y << endl;

	cout << "Game header Test" << endl;

	mapContainer map;
	while(map.mapindex != 5){
	Game g(map.getMap());

	for (int i = 0; i < 9; i++) {

		for (int j = 0; j < 7; j++) {

			cout << g.at(i, j) << " ";

		}

		cout << "\n";

	}

	g.printForDebug();

	cout << g.isWin() << endl;

	cout << "Game Start\n";

	while (!g.isWin()) {

		int vector;

		cin >> vector;//ÁÂ¿ìÇÏ»ó

		if (g.move(g.getChar(), vector)) {

			cout << "you can move\n";

		}
		else {

			cout << "you can't move\n";

		}

		for (int i = 0; i < 9; i++) {

			for (int j = 0; j < 7; j++) {

				cout << g.at(i, j) << " ";

			}

			cout << "\n";

		}

		if (g.isWin()) {

			cout << "Game End\n";
			map.getNextMap();

		}
		else {

			cout << "give me next input\n";

		}

		g.printForDebug();

	}
	}

	return 0;

}
