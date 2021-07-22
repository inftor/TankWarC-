#pragma once
#include<windows.h>
#include<ctime>

class tank;
class Bullet
{
public:
	Bullet();
	~Bullet();
	//初始化一颗子弹
	void InitBullet(tank& obj);
	//绘制子弹
	void DrawBullet(bool show);
	//移动子弹
	void MoveBullet();
	//检查子弹
	bool CheckBullet();
	
	friend class game;
	static Bullet bullets[50];

public:
	int BulletId;//子弹编号
	int TankId;//坦克的编号
	COORD point;//定义子弹位置
	COORD oldpoint;//定义子弹位置
	bool alive;//定义子弹状态
	int dir;  //定义子弹方向
	int nLeavl;//定义子弹等级
	clock_t end;
};




