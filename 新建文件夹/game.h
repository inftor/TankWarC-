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
	//��ʼ��̹��
	void MakeTank();

	int GameRun(int num);
	// ����һ���ӵ��������ӵ���ӵ��ӵ�������
	void CreatBull(tank obj);
	//�ƶ����е��ӵ�
	void MoveBulls();
	//����AI̹��
	void AITank();
	//AI̹������Ϊ0
	static void SetAITankDie(Bullet& bullet);

	

public:
	/*static tank m_Player1;
	static tank m_Player2;
	static tank AIPlayer1;
	static tank AIPlayer2;*/
	MAP map;
	clock_t end;
	
};

