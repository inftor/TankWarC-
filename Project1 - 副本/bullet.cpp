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
	if (this->oldpoint.X == 0 || this->oldpoint.Y == 0 
		|| this->oldpoint.X == 39 || this->oldpoint.Y == 39
		|| g_map[this->point.X][this->point.Y] == 河流
		|| g_map[this->point.X][this->point.Y] == 钢墙)
	{
		return;
	}
	else
	{
		MAP::WriteChar(this->point.X, this->point.Y, "●", show ? rand() % 9 + 1 : 0);
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
		MAP::WriteChar(this->point.X, this->point.Y, "▓", 4);
		g_map[this->point.X][this->point.Y] = 土墙;
	}
	else if (g_map[this->point.X][this->point.Y] == 边界)
	{
		//MAP::WriteChar(this->point.X, this->point.Y, "□", 7);
		return false;
	}
	else if (g_map[this->point.X][this->point.Y] == AI)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int x = -1; x < 2; x++)
			{
				for (int y = -1; y < 2; y++)
				{
					if (point.X + x == AIPlayer[i].getX() && point.Y + y == AIPlayer[i].getY())
					{
						if (zhenyin != AIPlayer[i].retzhenying())
						{
							AIPlayer[i].ncountTank1--;
							if (AIPlayer[i].ncountTank1 < 0)
							{
								AIPlayer[i].ncountTank1 = 0;
								AIPlayer[i].SetLife(false);
								AIPlayer[i].DrawTank(false);
							}
							gaming.number += 10;
							
						}
					}
				}
			}
		}
		return false;
	}
	else if (g_map[this->point.X][this->point.Y] == 玩家)
	{
		if (zhenyin != m_Player1.retzhenying())
			m_Player1.ncountTank1--;
		if (m_Player1.ncountTank1 < 0)
		{
			m_Player1.ncountTank1 = 0;
			m_Player1.SetLife(false);
			m_Player1.DrawTank(false);
		}
		return false;
	}
	else if (g_map[this->point.X][this->point.Y] == 玩家2)
	{
		if (zhenyin != m_Player2.retzhenying())
			m_Player2.ncountTank1--;
		if (m_Player2.ncountTank1 < 0)
		{
			m_Player2.ncountTank1 = 0;
			m_Player2.SetLife(false);
			m_Player2.DrawTank(false);
		}
		return false;
	}
	else if (g_map[this->point.X][this->point.Y] == 河流)
	{
		return true;
	}
	else if (g_map[this->point.X][this->point.Y] == 钢墙)
	{
		return false;
	}
	else if (g_map[this->point.X][this->point.Y] == 子弹)
	{
		for (int i = 0; i < 50; i++)
		{
			if (bullets[i].point.X == this->point.X
				&& bullets[i].point.Y == this->point.Y)
			{
				bullets[i].DrawBullet(FALSE);
				bullets[i].alive = false;
			}
		}
	}



	return false;
}