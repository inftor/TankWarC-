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
	else if (g_map[this->point.X][this->point.Y] == ���)
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
	else if (g_map[this->point.X][this->point.Y] == ���2)
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
	else if (g_map[this->point.X][this->point.Y] == ����)
	{
		return true;
	}
	else if (g_map[this->point.X][this->point.Y] == ��ǽ)
	{
		return false;
	}
	else if (g_map[this->point.X][this->point.Y] == �ӵ�)
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