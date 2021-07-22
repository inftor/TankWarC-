#pragma once

#include <ctime>
#include<windows.h>


class Bullet;
enum
{
	上,
	下,
	左,
	右
};


class tank
{
public:
	//tank();
	bool GetLife();
	void SetLife(bool life);
	static int GetKeyInput();
	void DrawTank( bool show);
	bool retzhenying();
	void DrawAITank(bool show);
	void InitTank(int x, int y, int dir, bool zhenyin);

	bool TankCheak();
	void MoveTank(int Dir);

	void MoveAITank(int Dir);
	int getX();
	int getY();
	COORD point;
	int nDir;
	bool IsBulletOn(Bullet& bullet);
	//初始化坦克生命值
	//static void leafTank( );
	////返回生命值函数：
	//static int getchar(int num);
	 int ncountTank1=5;
	 int ncountTank2=5;
	 int ncountAI1=5;
	 int ncountAI2=5;
	
private:
	bool nlife=true;
	int nspeed;
	bool zhengying;

	clock_t end;
	clock_t end2;
	static int TankMod[4][3][3];

};
extern tank m_Player1;
extern tank m_Player2;
extern tank AIPlayer1;
extern tank AIPlayer2;