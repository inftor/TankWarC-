#pragma once

#include <ctime>
#include<windows.h>


class Bullet;
enum
{
	��,
	��,
	��,
	��
};


class tank
{
public:
	//tank();
	bool GetLife();
	void SetLife(bool life);
	static int GetKeyInput();
	void DrawTank( bool show);

	void DrawAITank(bool show);
	void InitTank(int x, int y, int dir);

	bool TankCheak();
	void MoveTank(int Dir);

	void MoveAITank(int Dir);
	int getX();
	int getY();
	COORD point;
	int nDir;
	bool IsBulletOn(Bullet& bullet);
	//��ʼ��̹������ֵ
	//static void leafTank( );
	////��������ֵ������
	//static int getchar(int num);
	 int ncountTank1=5;
	 int ncountTank2=5;
	 int ncountAI1=5;
	 int ncountAI2=5;
	
private:
	bool nlife=true;
	int nspeed;


	clock_t end;
	clock_t end2;
	static int TankMod[4][3][3];

};