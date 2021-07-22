#include "game.h"
#include "tank.h"
#include"bullet.h"
#include"score.h"
//#include"score.cpp"
game gaming;
game::game()
{
	number = 0;
}




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
		MAP::DrawMap();
		MakeTank();
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
		if (dir == 'j' && (m_Player1.GetLife()==true)) CreatBull(m_Player1);
		if (dir == '5' && (m_Player2.GetLife() == true)) m_Player2.MoveTank2( ��);
		if (dir == '2' && (m_Player2.GetLife() == true)) m_Player2.MoveTank2( ��);
		if (dir == '1' && (m_Player2.GetLife() == true)) m_Player2.MoveTank2( ��);
		if (dir == '3' && (m_Player2.GetLife() == true)) m_Player2.MoveTank2( ��);
		if (dir == ' ' && (m_Player2.GetLife() == true)) CreatBull(m_Player2);
		
		if (((m_Player1.GetLife() == false)&& (m_Player2.GetLife() == false))
			|| ((m_Player1.GetLife() == false)&&(num==1)))
		{
			system("cls");
			MAP::WriteChar(15, 15, "������", 2);
			MAP::WriteChar(16, 13, "��ǰ������", 4);
			Score::MoveCursorPosition(16, 38);
			printf("%d", gaming.number * 10);
			Sleep(2000);
			m_Player1.SetLife(true),m_Player2.SetLife(true);
			AIPlayer[0].SetLife(true), AIPlayer[1].SetLife(true);
			system("cls");
			return 0;
		}
		if ((AIPlayer[0].GetLife() == false) && (AIPlayer[1].GetLife() == false))
		{
			system("cls");
			MAP::WriteChar(15,15, "��Ӯ��", 2);
			MAP::WriteChar(16, 13, "��ǰ������", 4);
			Score::MoveCursorPosition(16, 38);
			printf("%d", gaming.number * 10);
			Sleep(2000);
			m_Player1.SetLife(true), m_Player2.SetLife(true);
			AIPlayer[0].SetLife(true), AIPlayer[1].SetLife(true);
			system("cls");
			return 0;
		}
		MoveBulls();
		AITank();
		SetAITankDie(m_Player1);
		SetAITankDie(m_Player2);
		SetAITankDie(AIPlayer[0]);
		SetAITankDie(AIPlayer[1]);
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
	if (clock()-this->end<50)
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
	
		if (Player.ncountTank1==0)
		{
			Player.SetLife(false);
			Player.DrawTank(false);
			return;
		}


}