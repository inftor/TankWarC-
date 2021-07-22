#include "score.h"
#include"map.h"
#include<conio.h>
#include<stdio.h>
//#include"tank.h"
#include"game.h"


int exit()
{
	return 0;
}

//移动光标位置
void Score::MoveCursorPosition(int x, int y)
{
	//1.指定一个坐标
	COORD pos;
	pos.X = y;//指定横坐标
	pos.Y = x;//指定纵坐标

	//2.获得标准的输出设备的句柄 即获得cmd窗口的打印控制
	HANDLE hCmdWindow;
	hCmdWindow = GetStdHandle(STD_OUTPUT_HANDLE);

	//3.移动光标到pos变量指定的位置
	SetConsoleCursorPosition(hCmdWindow, pos);
	return;
}

//第一个界面，显示主菜单
int Score::showOption()
{
	//清屏
	MAP::WriteChar(10, 15, "坦克大战 v1.0", rand() % 9 + 1);

	//MAP::WriteChar(4, 6, "   _____   ___   _   _  _   __  _      ___", rand() % 9 + 1);
	//MAP::WriteChar(5, 6, "  (_   _) / _ \ | \ | || | / / / |    / _ \ ", rand() % 9 + 1);
	//MAP::WriteChar(6, 6, "    | |  | |_| ||  \| || |/ /  - |   | | | |", rand() % 9 + 1);
	//MAP::WriteChar(7, 6, "    | |  |  _  ||     ||   <   | |   | | | |", rand() % 9 + 1);
	//MAP::WriteChar(8, 6, "    | |  | | | || |\  || |\ \  | | _ | |_| |", rand() % 9 + 1);
	//MAP::WriteChar(9, 6, "    |_|  |_| |_||_| \_||_| \_\ |_|(_) \___/ ", rand() % 9 + 1);

	////MAP::WriteChar(11, 6, "#   _____   ___   _   _  _   __  _      ___", rand() % 9 + 1);
	////MAP::WriteChar(4, 6, "#   _____   ___   _   _  _   __  _      ___", rand() % 9 + 1);
	////MAP::WriteChar(4, 6, "#   _____   ___   _   _  _   __  _      ___", rand() % 9 + 1);






	char  ch;
	int option = 0;

	MAP::WriteChar(13, 13, "→", FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	const char* options[] = { "单人游戏", "双人游戏", "编辑地图", "设    置", "读档存档", "退    出" };
	for (int i = 0; i < 6; i++)
	{
		MAP::WriteChar(13 + i, 15 , options[i], FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	}


	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();

			if (ch == 27)	//esc
			{
				return -1;
			}
			if (ch == 72 || ch == 80 || ch == '\r')  //只检测上下键
			{

				if (ch == 72)	//UP
				{
					MAP::WriteChar( 13 + option,12, "    ", 0);
					option--;
				}
				else if (ch == 80)	//DOWN
				{
					MAP::WriteChar(13+ option, 12 , "    ", 0);
					option++;
				}
				if (option < 0)
				{
					option = 0;
				}
				else if (option >= 6)
				{
					option--;
				}
				//处理按上下键之后的显示
				MAP::WriteChar(13+ option, 13 , "                        ", 0);
				Sleep(100);
				MAP::WriteChar(13+ option, 13 , "→", rand() % 9 +1);
				MAP::WriteChar(13+ option, 15 , options[option], rand()%9-1);

				if (ch == '\r')
				{
					return option;
				}
			}

		}
	}
}

////获取数据
//void Score::getchar(int num)
//{
//
//	switch (num)
//	{
//	case 1:tank1--; break;
//	case 2:tank2--; break;
//	case 3:AI1--; break;
//	case 4:AI2--; break;
//	default:
//		break;
//	}
// }




//显示计分板
void Score::ShowScore(int a)
{

	


	if (a==1)
	{
		MAP::WriteChar(18, 45, "当前分数：", 4);
		MoveCursorPosition(18, 120);
		printf("%d", gaming.number * 10);
		MAP::WriteChar(20, 45, "AI坦克1当前生命值：", 4);
		MoveCursorPosition(20, 120);
		printf("%d", AIPlayer[0].ncountTank1 * 100);
		MAP::WriteChar(23, 45, "AI坦克2当前生命值：", 4);
		MoveCursorPosition(23, 120);
		printf("%d", AIPlayer[1].ncountTank1 * 100);
		MAP::WriteChar(26, 45, "坦克1当前生命值：", 2);
		MoveCursorPosition(26, 120);
		printf("%d", m_Player1.ncountTank1 * 100);
	}
	else
	{
		MAP::WriteChar(18, 45, "当前分数：", 4);
		MoveCursorPosition(18, 120);
		printf("%d", gaming.number * 10);
		MAP::WriteChar(20, 45, "AI坦克1当前生命值：", 4);
		MoveCursorPosition(20, 120);
		printf("%d", AIPlayer[0].ncountTank1 * 100);
		MAP::WriteChar(23, 45, "AI坦克2当前生命值：", 4);
		MoveCursorPosition(23, 120);
		printf("%d", AIPlayer[1].ncountTank1 * 100);
		MAP::WriteChar(26, 45, "坦克1当前生命值：", 2);
		MoveCursorPosition(26, 120);
		printf("%d", m_Player1.ncountTank1 * 100);
		MAP::WriteChar(29, 45, "坦克2当前生命值：", 2);
		MoveCursorPosition(29, 120);
		printf("%d", m_Player2.ncountTank1 * 100);
	}

}


