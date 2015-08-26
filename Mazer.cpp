#include "Mazer.h"
#include "MazeMap.h"
#include<Windows.h>

Mazer::Mazer():m_cPerson('R')
{
	m_iPosX = 1;
	m_iPosY = 5;
	m_iPreX = 10000;
	m_iPreY = 10000;
	m_iSpeed = 10000;
	forward = NORTH;	
	outOrNot = false;
}

void Mazer::savePrePosition()          //保存前一个坐标位置
{
	m_iPreX=m_iPosX;
	m_iPreY=m_iPosY;
}
void Mazer::moveSouth()                 //声明向南走的方法Y+1
{
	savePrePosition();
	m_iPosX=m_iPosX;
	m_iPosY=m_iPosY+1;
}

void Mazer::moveNorth()                 //声明向北走的方法Y-1
{
	savePrePosition();
	m_iPosX=m_iPosX;
	m_iPosY=m_iPosY-1;
}
void Mazer::moveWest()                  //声明向西走的方法X-1
{
	savePrePosition();
	m_iPosX=m_iPosX-1;
	m_iPosY=m_iPosY;
}
void Mazer::moveEast()                  //声明向东走的方法X+1
{
	savePrePosition();
	m_iPosX=m_iPosX+1;
	m_iPosY=m_iPosY;
}

void Mazer::setPersonForwardDirection(objectiveDirections myForward)		     //声明设定人的方向的方法
{
	forward=myForward;
}

void Mazer::turnLeft()                 //声明向左转的方法
{
	switch(forward)
	{
	case NORTH: forward = WEST;  break;
	case WEST:	forward = SOUTH; break;
	case SOUTH:	forward = EAST;  break;
	case EAST:	forward = NORTH; break;
	default: cout << "方向错误。" << endl;
	}
}
void Mazer::turnRight()				  //声明向右转的方法
{
	switch(forward)
	{
	case NORTH: forward = EAST;  break;
	case WEST:  forward = NORTH; break;
	case SOUTH: forward = WEST;  break;
	case EAST:  forward = SOUTH; break;
	default: cout << "方向错误。" << endl;
	}
}

void Mazer::gotoxy(int x,int y)
{
	COORD cd;
	cd.X=x;
	cd.Y=y;
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle,cd);
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cd);  
}

void Mazer::drawPerson()                //声明绘制走迷宫者的行走动画的方法
{
	//在当前位置上绘制人
	char mRoad = MazeMap::getRoadChar();  //只能引用static成员函数(非静态成员应用必须与特定对象相对)
	gotoxy(m_iPreX,m_iPreY);
	cout << mRoad;
	gotoxy(m_iPosX,m_iPosY);
	cout << m_cPerson;
	//为制作动画效果使用时间延迟
	Sleep(m_iSpeed);
}

void Mazer::goAhead()					  //声明向当前方向前进的方法
{
	switch(forward)
	{
	case NORTH: moveNorth(); break;
	case WEST:  moveWest();  break;
	case SOUTH: moveSouth(); break;
	case EAST:  moveEast();  break;
	default: cout << "方向不明，无法前进。" << endl;
	}
	drawPerson();
	if(MazeMap::checkMazeDoor(m_iPosX, m_iPosY))
	{
		gotoxy(0,10);
		cout << "哈哈，终于出来啦！" << endl;
		outOrNot = true;
	}
}
bool Mazer::moveForward()              //声明可以进行主观判断如何前进的方法
{
	//检查右侧是否是墙，如果是墙，检查前方是否是墙，如果不是墙则前进，前进后检查是否是出口
	int rightX;
	int rightY;

	int forwardX;
	int forwardY;
	
	switch(forward)
	{
	case SOUTH: rightX = m_iPosX - 1; rightY = m_iPosY; 
		forwardX = m_iPosX; forwardY = m_iPosY + 1; break; 
	case NORTH: rightX = m_iPosX + 1; rightY = m_iPosY; 
	    forwardX = m_iPosX; forwardY = m_iPosY - 1;	break;
	case WEST:  rightX = m_iPosX; rightY = m_iPosY - 1; 
		forwardX = m_iPosX - 1; forwardY = m_iPosY;	break;
	case EAST:  rightX = m_iPosX; rightY = m_iPosY + 1; 
		forwardX = m_iPosX + 1; forwardY = m_iPosY;	break;
	}
	//如果右侧是墙

	//system("PAUSE");

	if(MazeMap::checkWallOrNot(rightX,rightY))
	{

		//检测前方也是墙壁
		if(MazeMap::checkWallOrNot(forwardX,forwardY))
		{
			//按逆时针换一个方向
			turnLeft();
			return NO;
		}
		//检测前方是通路
		else
		{
			//向前移动
			goAhead();
			return YES;
		}
	}
	//如果右侧是通路
	else
	{
		Sleep(3000);
		turnRight();
		goAhead();
		return YES;
	}

}

void Mazer::start()
{
	int i = 0;
	while(!outOrNot)
	{
		gotoxy(0,9);
		cout << i;
		i++;
		moveForward();
	}
	
}

void Mazer::setPersonPosition(int x,int y)
{
	m_iPreX=x;
	m_iPreY=y;
}
void Mazer::setPersonSpeed(int speed)   //通过等级设定速度
{
	m_iSpeed=speed*500;
}
void Mazer::setPersonSpeed(long speed)  //通过数值设定速度
{
	//设置一个时间延迟的值
	m_iSpeed = speed;
	
}
void Mazer::setPersonChar(char m)
{
	m_cPerson=m;
}
