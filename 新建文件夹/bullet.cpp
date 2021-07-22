#include "Bullet.h"
#include "tank.h"
#include<time.h>
#include "map.h"
#include "game.h"

Bullet::Bullet():alive(false){};
Bullet::~Bullet() {};

Bullet Bullet::bullets[50];
//����һ���ӵ�
void Bullet::InitBullet(tank& obj )
{
	end = clock();
	point.X = obj.point.X;
	point.Y = obj.point.Y;
	if (g_map[obj.point.X][obj.point.Y] == AI)
	{
		zhenyin = false;
	}
	else
	{
		zhenyin = true;
	}
	dir = obj.nDir;
	alive = true;
	switch (dir)
	{
	case ��:point.X -= 2; break;
	case ��:point.X += 2; break;
	case ��:point.Y -= 2; break;
	case ��:point.Y += 2; break;
	default:
		break;
	}
	oldpoint.X = point.X;
	oldpoint.Y = point.Y;
	DrawBullet(true);
}
//�����ӵ�
void Bullet::DrawBullet( bool show)
{
	if (this->oldpoint.X == 0 || this->oldpoint.Y == 0 
		|| this->oldpoint.X == 39 || this->oldpoint.Y == 39
		|| g_map[this->point.X][this->point.Y] == ����
		|| g_map[this->point.X][this->point.Y] == ��ǽ)
	{
		return;
	}
	else
	{
		MAP::WriteChar(this->point.X, this->point.Y, "��", show ? rand() % 9 + 1 : 0);
		g_map[this->point.X][this->point.Y] = show ? �ӵ� : �յ�;
	}
	

}
//�ƶ��ӵ�
void Bullet::MoveBullet()
{

		 if (clock() - this->end < 50)
		 {
			 return;
		 }
		 DrawBullet(false);

		 switch (this->dir)
		 {
		 case ��:this->point.X--; break;
		 case ��:this->point.X++; break;
		 case ��:this->point.Y--; break;
		 case ��:this->point.Y++; break;
		 default:
			 break;
		 }
		 if (CheckBullet())
		 {
			 DrawBullet(true);
			 this->end = clock();
		 }
		 else
		 {
			 this->alive = 0;

		 }


}


//����ӵ�
bool Bullet::CheckBullet() {
	if (g_map[this->point.X][this->point.Y] == �յ�)
	{
		return true;
	}
	else if (g_map[this->point.X][this->point.Y] == ��ǽ)
	{
		MAP::WriteChar(this->point.X, this->point.Y, " ", 0);
		g_map[this->point.X][this->point.Y] = �յ�;

	}
	else if (g_map[this->point.X][this->point.Y] == ��ǽ)
	{
		MAP::WriteChar(this->point.X, this->point.Y, "��", 4);
		g_map[this->point.X][this->point.Y] = ��ǽ;
	}
	else if (g_map[this->point.X][this->point.Y] == �߽�)
	{
		//MAP::WriteChar(this->point.X, this->point.Y, "��", 7);
		return false;
	}
	else if (g_map[this->point.X][this->point.Y] == AI)
	{
 		game::SetAITankDie(*this);
		return false;
	}
	else if (g_map[this->point.X][this->point.Y] == ���)
	{
		game::SetAITankDie(*this);
		return false;
	}
	else if (g_map[this->point.X][this->point.Y] == ����)
	{
		return true;
	}
	else if (g_map[this->point.X][this->point.Y] == ��ǽ)
	{
		return false;
	}
	//
	/*else if (g_map[this->point.X][this->point.Y] == ��� && tank::IsBulletOn(*this))
	{

	}*/



	return false;
}