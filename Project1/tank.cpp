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
tank AIPlayer[2];

bool tank::retzhenying()
{
	return zhengying;
}
bool tank::GetLife()
{
	return ncountTank1;
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
				switch (judge)
				{
				case ���: g_map[x][y] = show ? ��� : �յ�; break;
				case ���2: g_map[x][y] = show ? ���2 : �յ�; break;
				case AI: g_map[x][y] = show ? AI : �յ�; break;
				default:
					break;
				}
				//g_map[x][y] = show ? ��� : �յ�;
				MAP map;
				const char* s = this->zhengying ? "��" : "��";
				map.WriteChar(x, y, s, show ? color : 0);

			}
		}

	}
}



//void tank::DrawTank2(bool show) {
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			if (TankMode[nDir][i][j] == 1) {
//				int x = point.X + i - 1;
//				int y = point.Y + j - 1;
//				g_map[x][y] = show ? ���2 : �յ�;
//				MAP map;
//				map.WriteChar(x, y, "��", show ? 2 : 0);
//
//			}
//		}
//
//	}
//}
//void tank::DrawAITank(bool show) {
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			if (TankMode[nDir][i][j] == 1) {
//				int x = point.X + i - 1;
//				int y = point.Y + j - 1;
//				g_map[x][y] = show ? AI : �յ�;
//				MAP::WriteChar(x, y, "��", show ? color : 0);
//
//			}
//		}
//
//	}
//}
//
//void tank::DrawAITank2(bool show) {
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			if (TankMode[nDir][i][j] == 1) {
//				int x = point.X + i - 1;
//				int y = point.Y + j - 1;
//				g_map[x][y] = show ? AI : �յ�;
//				MAP::WriteChar(x, y, "��", show ? 3 : 0);
//
//			}
//		}
//
//	}
//}

//��ʼ��̹�����꼰λ��
void tank::InitTank( int x, int y, int dir,bool zhenyin,int xueliang, int color, int speed,	int judge)
{
	this->color = color;
	this->speed = speed;
	this->point.X = x;
	this->point.Y = y;
	this->nDir = dir;
	this->end = this->end2 = clock();
	this->zhengying = zhenyin;
	this->ncountTank1 = xueliang;
	this->judge = judge;
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
		if (clock() - this->end < this->speed)
			return;
		DrawTank(false);
		if (this->nDir != Dir)
		{
			this->nDir = Dir;
		}
		else
		{
			if (TankCheak()/*|| g_map[this->point.X][this->point.Y] == �ݵ�*/) {
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

//void tank::MoveTank2(int Dir) {
//
//	if (nlife == true)
//	{
//		if (clock() - this->end < 50)
//			return;
//		DrawTank(false);
//		if (this->nDir != Dir)
//		{
//			this->nDir = Dir;
//		}
//		else
//		{
//			if (TankCheak()) {
//				switch (nDir)
//				{
//				case ��:
//					point.X--; break;
//				case ��:
//					point.X++; break;
//				case ��:
//					point.Y--; break;
//				case ��:
//					point.Y++; break;
//
//				default:
//					break;
//				}
//			}
//
//		}
//		DrawTank2(true);
//		this->end = clock();
//	}
//	else
//	{
//		return;
//	}
//}

//void tank::MoveAITank(int Dir) {
//
//	if (nlife==true)
//	{
//		if (clock() - this->end < this->speed)
//			return;
//
//		DrawAITank(false);
//		if (this->nDir != Dir)
//		{
//			this->nDir = Dir;
//		}
//		else
//		{
//			if (TankCheak()) {
//				switch (nDir)
//				{
//				case ��:
//					point.X--; break;
//				case ��:
//					point.X++; break;
//				case ��:
//					point.Y--; break;
//				case ��:
//					point.Y++; break;
//
//				default:
//					break;
//				}
//			}
//
//		}
//		DrawAITank(true);
//		this->end = clock();
//
//	}
//	else
//	{
//		return;
//	}
//}

//void tank::MoveAITank2(int Dir) {
//
//	if (nlife == true)
//	{
//		if (clock() - this->end < 50)
//			return;
//
//		DrawAITank2(false);
//		if (this->nDir != Dir)
//		{
//			this->nDir = Dir;
//		}
//		else
//		{
//			if (TankCheak()) {
//				switch (nDir)
//				{
//				case ��:
//					point.X--; break;
//				case ��:
//					point.X++; break;
//				case ��:
//					point.Y--; break;
//				case ��:
//					point.Y++; break;
//
//				default:
//					break;
//				}
//			}
//
//		}
//		DrawAITank2(true);
//		this->end = clock();
//
//	}
//	else
//	{
//		return;
//	}
//}



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

