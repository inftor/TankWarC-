#include "Bullet.h"
#include "tank.h"
#include<time.h>
#include "map.h"
#include "game.h"

Bullet::Bullet():alive(false){};
Bullet::~Bullet() {};

Bullet Bullet::bullets[50];
//创造一颗子弹
void Bullet::InitBullet(tank& obj )
{
	end = clock();
	point.X = obj.point.X;
	point.Y = obj.point.Y;
	dir = obj.nDir;
	alive = true;
	switch (dir)
	{
	case 上:point.X -= 2; break;
	case 下:point.X += 2; break;
	case 左:point.Y -= 2; break;
	case 右:point.Y += 2; break;
	default:
		break;
	}
	oldpoint.X = point.X;
	oldpoint.Y = point.Y;
	DrawBullet(true);
}
//绘制子弹
void Bullet::DrawBullet( bool show)
{
	if (this->oldpoint.X == 0 || this->oldpoint.Y == 0 || this->oldpoint.X == 39 || this->oldpoint.Y == 39)
	{
		return;
	}
	else
	{
		MAP::WriteChar(this->point.X, this->point.Y, "as", show ? 2 : 0);
		g_map[this->point.X][this->point.Y] = show ? 子弹 : 空地;
	}
	

}
//移动子弹
void Bullet::MoveBullet()
{

		 if (clock() - this->end < 50)
		 {
			 return;
		 }
		 DrawBullet(false);

		 switch (this->dir)
		 {
		 case 上:this->point.X--; break;
		 case 下:this->point.X++; break;
		 case 左:this->point.Y--; break;
		 case 右:this->point.Y++; break;
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


//检查子弹
bool Bullet::CheckBullet() {
	if (g_map[this->point.X][this->point.Y] == 空地)
	{
		return true;
	}
	else if (g_map[this->point.X][this->point.Y] == 土墙)
	{
		MAP::WriteChar(this->point.X, this->point.Y, " ", 0);
		g_map[this->point.X][this->point.Y] = 空地;

	}
	else if (g_map[this->point.X][this->point.Y] == 铁墙)
	{
		MAP::WriteChar(this->point.X, this->point.Y, "77", 2);
		g_map[this->point.X][this->point.Y] = 土墙;
	}
	else if (g_map[this->point.X][this->point.Y] == 边界)
	{
		//MAP::WriteChar(this->point.X, this->point.Y, "□", 7);
		return false;
	}
	else if (g_map[this->point.X][this->point.Y] == AI)
	{
 		game::SetAITankDie(*this);
		return false;
	}
	else if (g_map[this->point.X][this->point.Y] == 玩家)
	{
		game::SetAITankDie(*this);
		return false;
	}



	return false;
}