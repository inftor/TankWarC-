#include "game.h"
#include "tank.h"
#include"bullet.h"
#include"score.h"
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
//#include"score.cpp"
game gaming;
game::game()
{
	number = 0;
}

static int a = 0;


void game::MakeTank()
{
	m_Player1.InitTank(4, 30, 0,true,5);
	m_Player2.InitTank(20, 20, 0, true,5);
	AIPlayer[0].InitTank(10, 3, 0,false,3);
	AIPlayer[1].InitTank(30, 30, 0, false,3);
}
int game::GameRun(int num) {


	if (num==2)
	{
		MakeTank();
		MAP::DrawMap();
		MAP::DrawZaw();

	}
	if (num==1)
	{
		m_Player1.InitTank(4, 30, 0,true,5);
		AIPlayer[0].InitTank(10, 3, 0,false,3);
		AIPlayer[1].InitTank(30, 30, 0,false,3);
		MAP::DrawMap();
		MAP::DrawZaw();
	}
	if (num == 3)//���Ƶ�ͼ
	{
		MakeTank();
		MAP::DrawMap();
		//MAP::DrawZaw();
	}
	if (num == 4)//�����浵
	{
		system("cls");
		MAP::DrawMap();
		game::initDrawMap();
	}

	while (true)
	{
		MAP::DrawMap();

		if (num==1)
		{
			Score::ShowScore(1);
		}
		if (num == 2||num == 3||num==4)
		{
			Score::ShowScore(2);
		}

		int dir = tank::GetKeyInput();


		if (dir == 'w' && (m_Player1.GetLife() == true)) m_Player1.MoveTank(��);
		if (dir == 's' && (m_Player1.GetLife() == true)) m_Player1.MoveTank(��);
		if (dir == 'a' && (m_Player1.GetLife() == true)) m_Player1.MoveTank( ��);
		if (dir == 'd' && (m_Player1.GetLife() == true)) m_Player1.MoveTank( ��);
		if (dir == 'j' && (m_Player1.GetLife() == true)) {
															CreatBull(m_Player1);
															PlaySound(TEXT("./fire.wav"), NULL, SND_FILENAME | SND_ASYNC);//���ſ�����Ч;
		}
		if (dir == '5' && (m_Player2.GetLife() == true)) m_Player2.MoveTank2( ��);
		if (dir == '2' && (m_Player2.GetLife() == true)) m_Player2.MoveTank2( ��);
		if (dir == '1' && (m_Player2.GetLife() == true)) m_Player2.MoveTank2( ��);
		if (dir == '3' && (m_Player2.GetLife() == true)) m_Player2.MoveTank2( ��);
		if (dir == ' ' && (m_Player2.GetLife() == true)) {
														CreatBull(m_Player2);
														PlaySound(TEXT("./fire.wav"), NULL, SND_FILENAME | SND_ASYNC);//���ſ�����Ч;
		}
		if (dir == 'q') { game::SaveFile(); 
						MAP::WriteChar(16, 45, "���浱ǰ���ݳɹ�", 2);
						Sleep(2000);
						MAP::WriteChar(16, 45, "                   ", 2);
							}
		
		
		if (((m_Player1.GetLife() == false)&& (m_Player2.GetLife() == false))
			|| ((m_Player1.GetLife() == false)&&(num==1)))
		{
			PlaySound(TEXT("./lost.wav"), NULL, SND_FILENAME | SND_ASYNC);//����ʧ����Ч
			system("cls");
			MAP::WriteChar(15, 15, "������", 2);
			MAP::WriteChar(16, 13, "��ǰ������", 4);
			Score::MoveCursorPosition(16, 38);
			printf("%d", gaming.number * 10);
			Sleep(2000);
			m_Player1.SetLife(true),m_Player2.SetLife(true);
			AIPlayer[0].SetLife(true), AIPlayer[1].SetLife(true);
			game::initMap();
			gaming.number = 0;
			system("cls");
			return 0;
		}
		if ((AIPlayer[0].GetLife() == false) && (AIPlayer[1].GetLife() == false))
		{
			PlaySound(TEXT("./win.wav"), NULL, SND_FILENAME | SND_ASYNC);//����ʧ����Ч
			system("cls");
			MAP::WriteChar(15,15, "��Ӯ��", 2);
			MAP::WriteChar(16, 13, "��ǰ������", 4);
			Score::MoveCursorPosition(16, 38);
			printf("%d", gaming.number * 10);
			Sleep(2000);
			m_Player1.SetLife(true), m_Player2.SetLife(true);
			AIPlayer[0].SetLife(true), AIPlayer[1].SetLife(true);
			game::initMap();
			gaming.number = 0;
			system("cls");
			return 0;
		}
		MoveBulls();
		AITank();

		/*if (m_Player1.ncountTank1 == 0|| m_Player2.ncountTank1 == 0|| AIPlayer[0].ncountTank1 == 0 || AIPlayer[1].ncountTank1 == 0 )
		{
			SetAITankDie(m_Player1);
			SetAITankDie(m_Player2);
			SetAITankDie(AIPlayer[0]);
			SetAITankDie(AIPlayer[1]);
		}*/
		
	}
	
}

// ����һ���ӵ��������ӵ���ӵ��ӵ�������
void game::CreatBull(tank obj)
{

	for (int i = 0; i < 50; i++)
	{
		if (Bullet::bullets[i].alive == false)
		{
			Bullet::bullets[i].InitBullet(obj);
			Bullet::bullets[i].DrawBullet(true);
			break;
		}
	}
}
   

//�ƶ����е��ӵ�
void game::MoveBulls() {
	for (int i = 0; i < 50; i++)
	{
		if (Bullet::bullets[i].alive == true)
		{
			Bullet::bullets[i].MoveBullet();
		}
	}
}

void game::AITank()
{
	srand((unsigned)time(NULL));
	if (clock()-this->end<100)
	{
		return;
	}
	if (AIPlayer[0].GetLife())
	{
		AIPlayer[0].MoveAITank(rand() % 4);
		CreatBull(AIPlayer[0]);
	}
	if (AIPlayer[1].GetLife())
	{
		AIPlayer[1].MoveAITank(rand() % 4);
		CreatBull(AIPlayer[1]);
	}
	//
	//AIPlayer2.MoveAITank(rand() % 4);
	//CreatBull(AIPlayer2);
	this->end = clock();
}


//�ж��ӵ����к��Ч��
void game::SetAITankDie(tank &Player)
{
	

		//if (Player.GetLife() == true)
		//{
		//		Player.SetLife(false);
		//		Player.DrawTank(false);
		//	return;
		//}
	/*if (Player.ncountTank1 == 0)
	{

		Player.SetLife(false);
		Player.DrawTank(false);
		return;
	}*/
}


//��ʼ����ͼ
void  game::initMap()
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			g_map[i][j] = 0;
		}
	}
}



//�ļ�����
void game::SaveFile()
{
	//1.���ļ�
	FILE* fp_map = nullptr;
	FILE* fp_tank = nullptr;
	FILE* fp_bullet = nullptr;

	fopen_s(&fp_map, "map.txt", "w+");
	fopen_s(&fp_tank, "tank.txt", "w+");
	fopen_s(&fp_bullet, "bullet.txt", "w+");

	//2.�����ļ�

	//2.1 �����ͼ
	fwrite(g_map, sizeof(g_map), 1, fp_map);
	//fwrite(, sizeof(g_map), 1, fp_map);
	//fwrite(, sizeof(g_map), 1, fp_map);
	//fwrite(, sizeof(g_map), 1, fp_map);
	//fwrite(, sizeof(g_map), 1, fp_map);
	//fwrite(&g_ncount, 4, 1, pFile);
	//fwrite(&g_fangXaing, 4, 1, pFile);
	//2.2�������̹��
	fwrite(&m_Player1, sizeof(m_Player1), 1, fp_tank);
	fwrite(&m_Player2, sizeof(m_Player2), 1, fp_tank);
	//2.2.1 ����AI̹��
	fwrite(&AIPlayer[0], sizeof(AIPlayer[0]), 1, fp_tank);
	fwrite(&AIPlayer[1], sizeof(AIPlayer[1]), 1, fp_tank);
	//2.3 �����ӵ�

	//3.�ر��ļ�
	fclose(fp_map);
	fclose(fp_tank);
	fclose(fp_bullet);
}

//�ļ���ȡ
void game::ReadFile()
{
	//1.���ļ�
	FILE* fp_map = nullptr;
	FILE* fp_tank = nullptr;
	FILE* fp_bullet = nullptr;

	fopen_s(&fp_map, "map.txt", "r");
	fopen_s(&fp_tank, "tank.txt", "r");
	fopen_s(&fp_bullet, "bullet.txt", "r");

	//2.�����ļ�

	//2.1 �����ͼ
	fread(g_map, sizeof(g_map), 1, fp_map);
	//fwrite(&g_ncount, 4, 1, pFile);
	//fwrite(&g_fangXaing, 4, 1, pFile);
	//2.2�������̹��
	fread(&m_Player1, sizeof(m_Player1), 1, fp_tank);
	fread(&m_Player2, sizeof(m_Player2), 1, fp_tank);
	//2.2.1 ����AI̹��
	fread(&AIPlayer[0], sizeof(AIPlayer[0]), 1, fp_tank);
	fread(&AIPlayer[1], sizeof(AIPlayer[1]), 1, fp_tank);
	//2.3 �����ӵ�

	//3.�ر��ļ�
	fclose(fp_map);
	fclose(fp_tank);
	fclose(fp_bullet);
}

//������ȡ֮��ĵ�ͼ
void  game::initDrawMap()
{
	{
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				switch (g_map[i][j])
				{
				case �߽�:	MAP::WriteChar(i, j, "��", 7); break;
			//	case �ӵ�:	MAP::WriteChar(i, j, "��", rand() % 9 + 1); break;
				case ��ǽ:	MAP::WriteChar(i, j, "��", 2); break;
				case ��ǽ:	MAP::WriteChar(i, j, "��", 1); break;
				case ���:	MAP::WriteChar(i, j, "��", 2); break;
				case ���2:	MAP::WriteChar(i, j, "��", 2); break;
				case ��ǽ:	MAP::WriteChar(i, j, "��", 7); break;
				case AI:	MAP::WriteChar(i, j, "��", 5); break;
				case ����:	MAP::WriteChar(i, j, "��", 3); break;
				default:
					break;
				}



			}
		}
	}
}

