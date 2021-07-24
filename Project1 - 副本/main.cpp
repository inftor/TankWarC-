#include"main.h"
#include"score.h"
#include"game.h"
int main() {
	system("mode con cols=150 lines=60");
	SetConsoleTitle(TEXT("坦克大战C++"));

	//Score obj;
	//obj.showOption();

	while (true)
	{
		int option = Score::showOption();
		switch (option)
		{
		case 0:	gaming.GameRun(1);								 break;	 //单人游戏
		case 1:	gaming.GameRun(2);								 break;	 //双人游戏
		case 2:	MAP::custommap(), gaming.GameRun(3);	 		 break;	 //编辑地图
		case 3:	gaming.GameRun(1);								 break;	 //设置
		case 4:	game::ReadFile(),gaming.GameRun(4);								 break;	 //读档存档
		case 5:return 0;										 break;	 //退出游戏
		}
	}
	return 0;
}
