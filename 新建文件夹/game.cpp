#include "game.h"
#include "tank.h"
#include"bullet.h"
#include"score.h"
//#include"score.cpp"
game::game()
{
}




void game::MakeTank()
{
	m_Player1.InitTank(4, 30, 0,true);
	m_Player2.InitTank(20, 20, 0, true);
	AIPlayer1.InitTank(10, 3, 0,false);
	AIPlayer2.InitTank(30, 30, 0, false);
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
		m_Player1.InitTank(4, 30, 0,true);
		AIPlayer1.InitTank(10, 3, 0,false);
		AIPlayer2.InitTank(30, 30, 0,false);
		MAP::DrawMap();
		MAP::DrawZaw();
	}
	if (num == 3)//绘制地图
	{
		MakeTank();
		MAP::DrawMap();
		//MAP::DrawZaw();
	}
	if (num == 4)//读档存档
	{
		MAP::DrawMap();
		MakeTank();
	}

	while (true)
	{

		if (num==1)
		{
			Score::ShowScore(1);
		}
		if (num == 2||num == 3||num==4)
		{
			Score::ShowScore(2);
		}

		int dir = tank::GetKeyInput();


		if (dir == 'w' && (m_Player1.GetLife() == true)) m_Player1.MoveTank(上);
		if (dir == 's' && (m_Player1.GetLife() == true)) m_Player1.MoveTank(下);
		if (dir == 'a' && (m_Player1.GetLife() == true)) m_Player1.MoveTank( 左);
		if (dir == 'd' && (m_Player1.GetLife() == true)) m_Player1.MoveTank( 右);
		if (dir == 'j' && (m_Player1.GetLife()==true)) CreatBull(m_Player1);
		if (dir == '5' && (m_Player2.GetLife() == true)) m_Player2.MoveTank( 上);
		if (dir == '2' && (m_Player2.GetLife() == true)) m_Player2.MoveTank( 下);
		if (dir == '1' && (m_Player2.GetLife() == true)) m_Player2.MoveTank( 左);
		if (dir == '3' && (m_Player2.GetLife() == true)) m_Player2.MoveTank( 右);
		if (dir == ' ' && (m_Player2.GetLife() == true)) CreatBull(m_Player2);

		if (((m_Player1.GetLife() == false)&& (m_Player2.GetLife() == false))
			|| ((m_Player1.GetLife() == false)&&(num==1)))
		{
			system("cls");
			MAP::WriteChar(15, 15, "您输了", 2);
			Sleep(2000);
			m_Player1.SetLife(true),m_Player2.SetLife(true);
			AIPlayer1.SetLife(true), AIPlayer2.SetLife(true);
			Score::initLeaf();
			system("cls");
			return 0;
		}
		if ((AIPlayer1.GetLife() == false) && (AIPlayer1.GetLife() == false))
		{
			system("cls");
			MAP::WriteChar(15,15, "您赢了", 2);
			Sleep(2000);
			m_Player1.SetLife(true), m_Player2.SetLife(true);
			AIPlayer1.SetLife(true), AIPlayer2.SetLife(true);
			Score::initLeaf();
			system("cls");
			return 0;
		}
		MoveBulls();
		AITank();
	}
	
}

// 创建一颗子弹，并将子弹添加到子弹数组中
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


//移动所有的子弹
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
	if (AIPlayer1.GetLife())
	{
		AIPlayer1.MoveAITank(rand() % 4);
		CreatBull(AIPlayer1);
	}
	if (AIPlayer2.GetLife())
	{
		AIPlayer2.MoveAITank(rand() % 4);
		CreatBull(AIPlayer2);
	}
	//
	//AIPlayer2.MoveAITank(rand() % 4);
	//CreatBull(AIPlayer2);
	this->end = clock();
}


//判断子弹击中后的效果
void game::SetAITankDie(Bullet& bullet)
{
	if (m_Player1.IsBulletOn(bullet))
	{
		m_Player1.ncountTank1--;
		Score::getchar(1);
		if (m_Player1.ncountTank1==0)
		{
			m_Player1.SetLife(false);
			m_Player1.DrawTank(false);
		}
		
		return;
	}
	if (m_Player2.IsBulletOn(bullet))
	{
		m_Player1.ncountTank2--;
		Score::getchar(2);
		if (m_Player1.ncountTank2==0)
		{
			m_Player2.SetLife(false);
			m_Player2.DrawTank(false);
		}
		
		return;
	}
	if (AIPlayer1.IsBulletOn(bullet))
	{
		AIPlayer1.ncountAI1--;
		Score::getchar(3);
		if (AIPlayer1.ncountAI1==0)
		{
			AIPlayer1.SetLife(false);
			AIPlayer1.DrawTank(false);
		}
		return;
	}
	if (AIPlayer2.IsBulletOn(bullet))
	{
		AIPlayer1.ncountAI2--;
		Score::getchar(4);
		if (AIPlayer1.ncountAI2 == 0)
		{
			AIPlayer2.SetLife(false);
			AIPlayer2.DrawTank(false);
		}
		
		return;
	}
}