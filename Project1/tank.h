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
	void MoveTank(int Dir);//移动tank1
	void DrawTank( bool show);//画tank1
	void MoveTank2(int Dir);//移动tank2
	void DrawTank2(bool show);//画tank2
	void MoveAITank(int Dir);//移动AItank
	void DrawAITank(bool show);//画AItank
	void InitTank(int x, int y, int dir, bool zhenyin,int xueliang);
	bool retzhenying();
	bool TankCheak();



	int getX();
	int getY();
	COORD point;
	int nDir;
	bool IsBulletOn(Bullet& bullet);
	//初始化坦克生命值
	//static void leafTank( );
	////返回生命值函数：
	//static int getchar(int num);
	 int ncountTank1;
	
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
extern tank AIPlayer[2];