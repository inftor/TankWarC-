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
	if (num == 3)//绘制地图
	{
		MakeTank();
		MAP::DrawMap();
		//MAP::DrawZaw();
	}
	if (num == 4)//读档存档
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


		if (dir == 'w' && (m_Player1.GetLife() == true)) m_Player1.MoveTank(上);
		if (dir == 's' && (m_Player1.GetLife() == true)) m_Player1.MoveTank(下);
		if (dir == 'a' && (m_Player1.GetLife() == true)) m_Player1.MoveTank( 左);
		if (dir == 'd' && (m_Player1.GetLife() == true)) m_Player1.MoveTank( 右);
		if (dir == 'j' && (m_Player1.GetLife() == true)) {
															CreatBull(m_Player1);
															PlaySound(TEXT("./fire.wav"), NULL, SND_FILENAME | SND_ASYNC);//播放开火音效;
		}
		if (dir == '5' && (m_Player2.GetLife() == true)) m_Player2.MoveTank2( 上);
		if (dir == '2' && (m_Player2.GetLife() == true)) m_Player2.MoveTank2( 下);
		if (dir == '1' && (m_Player2.GetLife() == true)) m_Player2.MoveTank2( 左);
		if (dir == '3' && (m_Player2.GetLife() == true)) m_Player2.MoveTank2( 右);
		if (dir == ' ' && (m_Player2.GetLife() == true)) {
														CreatBull(m_Player2);
														PlaySound(TEXT("./fire.wav"), NULL, SND_FILENAME | SND_ASYNC);//播放开火音效;
		}
		if (dir == 'q') { game::SaveFile(); 
						MAP::WriteChar(16, 45, "保存当前数据成功", 2);
						Sleep(2000);
						MAP::WriteChar(16, 45, "                   ", 2);
							}
		
		
		if (((m_Player1.GetLife() == false)&& (m_Player2.GetLife() == false))
			|| ((m_Player1.GetLife() == false)&&(num==1)))
		{
			PlaySound(TEXT("./lost.wav"), NULL, SND_FILENAME | SND_ASYNC);//播放失败音效
			system("cls");
			MAP::WriteChar(15, 15, "您输了", 2);
			MAP::WriteChar(16, 13, "当前分数：", 4);
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
			PlaySound(TEXT("./win.wav"), NULL, SND_FILENAME | SND_ASYNC);//播放失败音效
			system("cls");
			MAP::WriteChar(15,15, "您赢了", 2);
			MAP::WriteChar(16, 13, "当前分数：", 4);
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


//判断子弹击中后的效果
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


//初始化地图
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



//文件保存
void game::SaveFile()
{
	//1.打开文件
	FILE* fp_map = nullptr;
	FILE* fp_tank = nullptr;
	FILE* fp_bullet = nullptr;

	fopen_s(&fp_map, "map.txt", "w+");
	fopen_s(&fp_tank, "tank.txt", "w+");
	fopen_s(&fp_bullet, "bullet.txt", "w+");

	//2.保存文件

	//2.1 保存地图
	fwrite(g_map, sizeof(g_map), 1, fp_map);
	//fwrite(, sizeof(g_map), 1, fp_map);
	//fwrite(, sizeof(g_map), 1, fp_map);
	//fwrite(, sizeof(g_map), 1, fp_map);
	//fwrite(, sizeof(g_map), 1, fp_map);
	//fwrite(&g_ncount, 4, 1, pFile);
	//fwrite(&g_fangXaing, 4, 1, pFile);
	//2.2保存玩家坦克
	fwrite(&m_Player1, sizeof(m_Player1), 1, fp_tank);
	fwrite(&m_Player2, sizeof(m_Player2), 1, fp_tank);
	//2.2.1 保存AI坦克
	fwrite(&AIPlayer[0], sizeof(AIPlayer[0]), 1, fp_tank);
	fwrite(&AIPlayer[1], sizeof(AIPlayer[1]), 1, fp_tank);
	//2.3 保存子弹

	//3.关闭文件
	fclose(fp_map);
	fclose(fp_tank);
	fclose(fp_bullet);
}

//文件读取
void game::ReadFile()
{
	//1.打开文件
	FILE* fp_map = nullptr;
	FILE* fp_tank = nullptr;
	FILE* fp_bullet = nullptr;

	fopen_s(&fp_map, "map.txt", "r");
	fopen_s(&fp_tank, "tank.txt", "r");
	fopen_s(&fp_bullet, "bullet.txt", "r");

	//2.保存文件

	//2.1 保存地图
	fread(g_map, sizeof(g_map), 1, fp_map);
	//fwrite(&g_ncount, 4, 1, pFile);
	//fwrite(&g_fangXaing, 4, 1, pFile);
	//2.2保存玩家坦克
	fread(&m_Player1, sizeof(m_Player1), 1, fp_tank);
	fread(&m_Player2, sizeof(m_Player2), 1, fp_tank);
	//2.2.1 保存AI坦克
	fread(&AIPlayer[0], sizeof(AIPlayer[0]), 1, fp_tank);
	fread(&AIPlayer[1], sizeof(AIPlayer[1]), 1, fp_tank);
	//2.3 保存子弹

	//3.关闭文件
	fclose(fp_map);
	fclose(fp_tank);
	fclose(fp_bullet);
}

//画出读取之后的地图
void  game::initDrawMap()
{
	{
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				switch (g_map[i][j])
				{
				case 边界:	MAP::WriteChar(i, j, "□", 7); break;
			//	case 子弹:	MAP::WriteChar(i, j, "●", rand() % 9 + 1); break;
				case 土墙:	MAP::WriteChar(i, j, "▓", 2); break;
				case 铁墙:	MAP::WriteChar(i, j, "▓", 1); break;
				case 玩家:	MAP::WriteChar(i, j, "□", 2); break;
				case 玩家2:	MAP::WriteChar(i, j, "□", 2); break;
				case 钢墙:	MAP::WriteChar(i, j, "■", 7); break;
				case AI:	MAP::WriteChar(i, j, "□", 5); break;
				case 河流:	MAP::WriteChar(i, j, "≈", 3); break;
				default:
					break;
				}



			}
		}
	}
}

