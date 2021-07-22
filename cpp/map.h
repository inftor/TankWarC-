#pragma once
#include<time.h>
#include<iostream>
#include<windows.h>
enum
{
	高 = 40, 宽 = 40
};
enum
{
	空地 = 0,
	边界 = 1,
	子弹 = 2,
	土墙 = 3,
	铁墙 = 4,
	玩家 = 5,
	AI   = 8,


};

extern int g_map[高][宽];


//创建地图边界
class MAP
{
public:
	static void DrawMap();
	static void WriteChar(int High, int Wide, const char* Char, WORD wArr);
private:
	
};


