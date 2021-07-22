#include"main.h"
#include"score.h"
int main() {
	system("mode con cols=120 lines=50");
	SetConsoleTitle(TEXT("坦克大战C++"));
	game gaming;
	//Score obj;
	//obj.showOption();

	while (true)
	{
		int option = Score::showOption();
		switch (option)
		{
		case 0:	gaming.GameRun();			 break;	 //单人游戏
		case 1:	gaming.GameRun();			 break;	 //双人游戏
		case 2:	gaming.GameRun();		 	 break;	 //编辑地图
		case 3:	gaming.GameRun();			 break;	 //设置
		case 4:	gaming.GameRun();		     break;	 //游戏帮助
		case 5:return 0;					 break;	 //退出游戏
		}
	}
	return 0;
}
