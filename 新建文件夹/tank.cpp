#include "tank.h"
#include"map.h"
#include "bullet.h"
#include <time.h>
#include <conio.h>
#include <stdbool.h>

//��ʼ��̹��Ϊ��״̬
//tank::tank():nlife(true) {};
tank m_Player1;
tank m_Player2;
tank AIPlayer1;
tank AIPlayer2;
bool tank::retzhenying()
{
	return zhengying;
}
bool tank::GetLife()
{
	return nlife;
}
void tank::SetLife(bool life)
{
	nlife = life;
}

int TankMode[4][3][3] =
{
	{
		{0,1,0},
		{1,1,1},
		{1,0,1},
	},
	{
		{1,0,1},
		{1,1,1},
		{0,1,0},
	},
		{
		{0,1,1},
		{1,1,0},
		{0,1,1},
	},
		{

		{1,1,0},
		{0,1,1},
		{1,1,0},
	},


};


int tank::getX()
{
	return point.X;
}
int tank::getY()
{
	return point.Y;
}


int tank::GetKeyInput()
{
	if (_kbhit())
		return _getch();
	return 0;
}

void tank::DrawTank( bool show) {

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (TankMode[nDir][i][j] == 1) {
				int x = point.X + i - 1;
				int y = point.Y + j - 1;
				g_map[x][y] = show ? ��� : �յ�;
				MAP map;
				map.WriteChar(x, y, "��", show ? 2 : 0);

			}
		}

	}
}

void tank::DrawAITank(bool show) {

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (TankMode[nDir][i][j] == 1) {
				int x = point.X + i - 1;
				int y = point.Y + j - 1;
				g_map[x][y] = show ? AI : �յ�;
				MAP::WriteChar(x, y, "��", show ? 5 : 0);

			}
		}

	}
}

//��ʼ��̹�����꼰λ��
void tank::InitTank( int x, int y, int dir,bool zhenyin)
{
	this->point.X = x;
	this->point.Y = y;
	this->nDir = dir;
	this->end = this->end2 = clock();
	zhengying = zhenyin;
	DrawTank(true);
}


bool tank::TankCheak()  //���̹��ǰ���ϰ�����,����Ϊ�����ꡣ��ֵ1Ϊ��ͨ��,��ֵ0Ϊ�赲(�˻�����)
{
	switch (this->nDir)                    //direction����   1�ϣ�2�£�3��4��
	{
	case ��:
		if (g_map[point.X - 2][point.Y] == 0 && g_map[point.X - 2][point.Y - 1] == 0 && g_map[point.X - 2][point.Y + 1] == 0)
			return 1;
		else
			return 0;
	case ��:
		if (g_map[point.X + 2][point.Y] == 0 && g_map[point.X + 2][point.Y - 1] == 0 && g_map[point.X + 2][point.Y + 1] == 0)
			return 1;
		else
			return 0;
	case ��:
		if (g_map[point.X][point.Y - 2] == 0 && g_map[point.X - 1][point.Y - 2] == 0 && g_map[point.X + 1][point.Y - 2] == 0)
			return 1;
		else
			return 0;
	case ��:
		if (g_map[point.X][point.Y + 2] == 0 && g_map[point.X - 1][point.Y + 2] == 0 && g_map[point.X + 1][point.Y + 2] == 0)
			return 1;
		else
			return 0;
	default:
		printf("���󣡣�");
		//Sleep(5000);
		return 0;
	}
}




void tank::MoveTank( int Dir) {

	if (nlife==true)
	{
		if (clock() - this->end < 50)
			return;
		DrawTank(false);
		if (this->nDir != Dir)
		{
			this->nDir = Dir;
		}
		else
		{
			if (TankCheak()) {
				switch (nDir)
				{
				case ��:
					point.X--; break;
				case ��:
					point.X++; break;
				case ��:
					point.Y--; break;
				case ��:
					point.Y++; break;

				default:
					break;
				}
			}

		}
		DrawTank(true);
		this->end = clock();
	}
	else
	{
		return;
	}
}


void tank::MoveAITank(int Dir) {

	if (nlife==true)
	{
		if (clock() - this->end < 50)
			return;
		DrawAITank(false);
		if (this->nDir != Dir)
		{
			this->nDir = Dir;
		}
		else
		{
			if (TankCheak()) {
				switch (nDir)
				{
				case ��:
					point.X--; break;
				case ��:
					point.X++; break;
				case ��:
					point.Y--; break;
				case ��:
					point.Y++; break;

				default:
					break;
				}
			}

		}
		DrawAITank(true);
		this->end = clock();

	}
	else
	{
		return;
	}
}

bool tank::IsBulletOn(Bullet& bullet)
{
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if (TankMode[this->nDir][i + 1][j + 1] == 1)
			{
				if (g_map[this->point.X][this->point.Y]== g_map[bullet.point.X][bullet.point.Y])
				{
					if (this->zhengying != bullet.zhenyin)
					{
						return true;
					}
					else
					{
						return false;
					}
					
				}
			}
		}
	}
}




//��ʼ��̹������ֵ
//��ʼ��̹������ֵ
// void tank::leafTank()
//{
//	ncountTank1 = 5;
//}

// int tank::getchar(int num)
//{
//	if (num == 1)
//	{
//		return 	ncountTank1;
//	}
//	else if (num == 2)
//	{
//		return 	ncountTank2;
//	}
//	else if (num == 3)
//	{
//		return 	ncountAI1;
//	}
//	else 
//	{
//		return 	ncountAI2;
//	}
//
