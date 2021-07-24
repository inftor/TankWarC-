
#include"map.h"



int g_map[高][宽] = {0};



void MAP:: WriteChar(int High, int Wide, const char* Char, WORD wArr) {
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = FALSE;//是否显示光标
	cci.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	COORD loc;
	loc.X = Wide * 2;
	loc.Y = High;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wArr);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
	printf(Char);
}

void MAP::DrawMap()
{
	for (int i = 0; i < 高; i++)
	{
		for (int j = 0; j < 宽; j++)
		{
			// 如果当前是数组的最外侧，我们将它作为边界
			if (i == 0 || j == 0 || i == 高 - 1 || j == 宽 - 1)
			{
				g_map[i][j] = 边界;
				WriteChar(i, j, "□", 7);
			}

		}
	}


}

void MAP::DrawZaw()
{
	for (int i = 10; i < 20; i++)
	{
		for (int j = 12; j < 19; j++)
		{
			WriteChar(i, j, "▓", 2);
			g_map[i][j] = 土墙;
		}
	}
	for (int i = 10; i < 20; i++)
	{
		for (int j = 19; j < 24; j++)
		{
			WriteChar(i, j, "▓", 1);
			g_map[i][j] = 铁墙;
		}
	}

	for (int i = 26; i < 28; i++)
	{
		for (int j = 12; j < 25; j++)
		{
			WriteChar(i, j, "≈", 3);
			g_map[i][j] = 河流;
		}
	}

	for (int i = 8; i < 10; i++)
	{
		for (int j = 8; j < 25; j++)
		{
			WriteChar(i, j, "■", 7);
			g_map[i][j] = 钢墙;
		}
	}
	

	for (int i = 34; i < 36; i++)
	{
		for (int j = 8; j < 25; j++)
		{
			WriteChar(i, j, "■", 7);
			g_map[i][j] = 钢墙;
		}
	}
	
}



//编辑地图
void MAP::custommap()
{
	system("cls");
	MAP::DrawMap();
	//create_game_area_frame(30, 30);
	//保存地图
	//WriteChar(80, 14, "是否保存!!",6);
	//WriteChar(80, 15, "左键.是 右键.否",6);
	//1 获取控制台输入句柄
	HANDLE hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);
	//2 循环获取控制台输入信息
	INPUT_RECORD ir = { 0 };
	DWORD dwMode = 0;
	//-----------------------------------------------------------
	GetConsoleMode(hConsoleInput, &dwMode);
	SetConsoleMode(hConsoleInput, dwMode | ENABLE_MOUSE_INPUT);
	//-----------------------------------------------------------
	DWORD dwRealCourt = 0;
	while (true)
	{

		MOUSE_EVENT_RECORD MouseEv = ir.Event.MouseEvent;
		ReadConsoleInput(
			hConsoleInput,//控制台输入数据
			&ir,          //获取到的控制台信息就传到这个结构体中
			1,            //缓冲区INPUT_RECORD的数量
			&dwRealCourt  //传出，读取完毕的时候，究竟读取了几个结构体信息
		);
		//是一个鼠标信息
		if (ir.EventType == MOUSE_EVENT)
		{
			//如果是鼠标信息，那么就是联合体中的这个字段起作用

			if (MouseEv.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				int x = MouseEv.dwMousePosition.Y ;
				int y = MouseEv.dwMousePosition.X/ 2;
				WriteChar(x, y, "▓",1);
				g_map[x][y] = 铁墙;
				//SaveMap("qq.txt");
			}
			if (MouseEv.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
			{
				//Savezhangaiwu("./ww.txt");

				WriteChar(20, 45, "保存当前数据成功",6);
				Sleep(2000);
				WriteChar(20, 45, "                  ",6);
				return;
			}
		}
	}
}



