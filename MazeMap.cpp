#include<iostream>
#include "MazeMap.h"
using namespace std;

//初始化静态变量（static不能用析构函数初始化）
int MazeMap::m_iRow=0;
int MazeMap::m_iColumn=0;
char MazeMap::m_cRoad=' ';
int MazeMap::m_iMaze[8][8];

MazeMap::MazeMap()
{

}

MazeMap::MazeMap(int *map,int m,int n):m_cWall('#')
{
	m_iRow=m;
	m_iColumn=n;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			m_iMaze[i][j]=*map;
			map++;
		}
	}
}
MazeMap::~MazeMap()
{

}
void MazeMap::setMazeMap(int *map,int m,int n)
{
	m_iRow=m;
	m_iColumn=n;
//	m_iMaze = new int*[m];
	for(int i=0;i<m;i++)
	{
//		m_iMaze[i] = map + i*n;

		for(int j=0;j<n;j++)
		{
			m_iMaze[i][j]=*map;
			map++;
		}
	}
}
void MazeMap::setMazeWall(char a)
{
	m_cWall=a;
}
void MazeMap::setMazeRoad(char b)
{
	m_cRoad=b;
}
void MazeMap::drawMap()
{
	//输出迷宫
	for(int i=0;i<m_iRow;i++)
	{
		for(int j=0;j<m_iColumn;j++)
		{
			//cout<<m_iMaze[i][j];
			if(m_iMaze[i][j]==WALL)
			{
				cout<<m_cWall;
			}
			else
				cout<<m_cRoad;
			
		}
		cout<<endl;
	}
}

char MazeMap::getRoadChar()                          //获取表示通路的字符
{
	return m_cRoad;      //static成员函数只能访问static成员
}
bool MazeMap::checkWallOrNot(int mazeX,int mazeY)     //声明检查是否遇到迷宫墙壁的函数
{
	if(m_iMaze[mazeY][mazeX] == WALL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool MazeMap::checkMazeDoor(int mazeX,int mazeY)      //声明检查是否遇到迷宫入口/出口的函数
{
	//检查迷宫左右两侧
	if(mazeX == 0 || mazeX == (m_iColumn - 1))
	{
		if(m_iMaze[mazeY][mazeX] == ROAD)
		{
			return true;
		}
	}
	//检查迷宫上下两侧
	if(mazeY == 0)            //mazeY == 0 || mazeY == (m_iRow - 1)
	{
		if(m_iMaze[mazeY][mazeX] == ROAD)
		{
			return true;
		}
	}
	return false;
}
