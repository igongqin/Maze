#include <iostream>
#include <string>
#include "MazeMap.h"
#include "Mazer.h"
using namespace std;

int main()
{
	int map[5][5]={
		{WALL,WALL,WALL,ROAD,WALL},
		{WALL,ROAD,WALL,ROAD,WALL},
		{WALL,ROAD,ROAD,ROAD,WALL},
		{WALL,ROAD,WALL,WALL,WALL},
		{WALL,ROAD,WALL,WALL,WALL},
	};

	MazeMap maze;
	maze.setMazeMap(&map[0][0],5,5);
	maze.setMazeWall('*');
	maze.setMazeRoad(' ');
	maze.drawMap();

	Mazer mazer;
	mazer.setPersonPosition(1,5);
	mazer.setPersonSpeed(1);
	mazer.setPersonChar('Y');
	mazer.start();
    
	system("pause");
	return 0;
}
