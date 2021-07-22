#pragma once

#include<time.h>
#include<iostream>
#include<windows.h>
#include"tank.h"
#include "bullet.h"
#include"map.h"

class game 
{
public:
	game();
	//初始化坦克
	void MakeTank();

	int GameRun(int num);
	// 创建一颗子弹，并将子弹添加到子弹数组中
	void CreatBull(tank obj);
	//移动所有的子弹
	void MoveBulls();
	//创建AI坦克
	void AITank();
	//AI坦克生命为0
	static void SetAITankDie(Bullet& bullet);

	

public:
	/*static tank m_Player1;
	static tank m_Player2;
	static tank AIPlayer1;
	static tank AIPlayer2;*/
	MAP map;
	clock_t end;
	
};

