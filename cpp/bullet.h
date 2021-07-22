#pragma once
#include<windows.h>
#include<ctime>

class tank;
class Bullet
{
public:
	Bullet();
	~Bullet();
	//��ʼ��һ���ӵ�
	void InitBullet(tank& obj);
	//�����ӵ�
	void DrawBullet(bool show);
	//�ƶ��ӵ�
	void MoveBullet();
	//����ӵ�
	bool CheckBullet();
	
	friend class game;
	static Bullet bullets[50];

public:
	int BulletId;//�ӵ����
	int TankId;//̹�˵ı��
	COORD point;//�����ӵ�λ��
	COORD oldpoint;//�����ӵ�λ��
	bool alive;//�����ӵ�״̬
	int dir;  //�����ӵ�����
	int nLeavl;//�����ӵ��ȼ�
	clock_t end;
};




