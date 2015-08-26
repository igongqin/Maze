#include <iostream>
#include "MazeMap.h"
using namespace std;

enum objectiveDirections
{
	SOUTH,NORTH,WEST,EAST         //南(上)，北(下)，西(左)，东(右)
};
const bool YES = true;
const bool NO = false;

class Mazer
{
public:
	Mazer();
	void setPersonPosition(int x,int y);   //设置人的位置
	void setPersonSpeed(int speed);      //设置人的速度
	void setPersonSpeed(long speed); 
	void setPersonChar(char m);            //设置人的字符
	void setPersonForwardDirection(objectiveDirections myForward);//声明设定人的方向的方法
	void start();                          //开始
private:
	char m_cPerson;
	int m_iDirection;
	int m_iPosX;
	int m_iPosY;
	int m_iPreX;
	int m_iPreY;
	int m_iSpeed;
	bool outOrNot;					  //声明人是否走出迷宫
	objectiveDirections forward;      //声明逻辑的前方

	void savePrePosition();           //保存前一个坐标位置
	void moveSouth();                 //声明向南走的方法
	void moveNorth();                 //声明向北走的方法
	void moveWest();                  //声明向西走的方法
	void moveEast();                  //声明向东走的方法
	void turnLeft();                  //声明向左转的方法
	void turnRight();				  //声明向右转的方法
	void goAhead();					  //声明向当前方向前进的方法
	bool moveForward();               //声明可以进行主观判断如何前进的方法
	void gotoxy(int x, int y);		  //声明设定输出位置的方法
	void drawPerson();                //声明绘制走迷宫者的行走动画的方法
};
