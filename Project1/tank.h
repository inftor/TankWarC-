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
	void MoveTank(int Dir);//�ƶ�tank1
	void DrawTank( bool show);//��tank1
	void MoveTank2(int Dir);//�ƶ�tank2
	void DrawTank2(bool show);//��tank2
	void MoveAITank(int Dir);//�ƶ�AItank
	void DrawAITank(bool show);//��AItank
	void InitTank(int x, int y, int dir, bool zhenyin,int xueliang);
	bool retzhenying();
	bool TankCheak();



	int getX();
	int getY();
	COORD point;
	int nDir;
	bool IsBulletOn(Bullet& bullet);
	//��ʼ��̹������ֵ
	//static void leafTank( );
	////��������ֵ������
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