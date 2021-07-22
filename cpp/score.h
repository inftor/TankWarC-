#pragma once
#include"score.h"
class Score
{
public:
	//移动光标位置
	static void MoveCursorPosition(int x, int y);
	//第一个界面，显示主菜单
	static int showOption();
	//获取数据
	static void getchar(int num);
	//显示计分板
	static void ShowScore();
	////判断输赢退出界面
	//static int IsWin();

};

