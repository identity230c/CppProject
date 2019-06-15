#ifndef _MAPCONTAINER_H_
#define _MAPCONTAINER_H_

#include<iostream>
#include<string>

using namespace std;

class mapContainer{

public:
	int mapindex = 0;
	int ***maps;
	mapContainer();
	int getNextMap();
	int **getMap();
};

#endif
