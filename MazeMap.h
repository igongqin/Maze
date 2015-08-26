#ifndef MAZEMAP_H
#define MAZEMAP_H

#include <iostream>
using namespace std;

const int WALL=0;
const int ROAD=1;

class MazeMap
{
public:
	MazeMap();
	MazeMap(int *map,int m,int n);
	~MazeMap();
	void setMazeMap(int *map,int m,int n);
	void setMazeWall(char a);
	void setMazeRoad(char b);
	void drawMap();
	static char getRoadChar();                           //获取表示通路的字符
    static bool checkWallOrNot(int mazeX,int mazeY);     //声明检查是否遇到迷宫墙壁的函数
	static bool checkMazeDoor(int mazeX,int mazeY);      //声明检查是否遇到迷宫入口/出口的函数
private:
	static int m_iRow;
	static int m_iColumn;
	char m_cWall;
	static char m_cRoad;
	static int m_iMaze[8][8];
};

#endif
