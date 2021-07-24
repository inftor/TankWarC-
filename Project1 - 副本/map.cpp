
#include"map.h"



int g_map[��][��] = {0};



void MAP:: WriteChar(int High, int Wide, const char* Char, WORD wArr) {
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = FALSE;//�Ƿ���ʾ���
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
	for (int i = 0; i < ��; i++)
	{
		for (int j = 0; j < ��; j++)
		{
			// �����ǰ�����������࣬���ǽ�����Ϊ�߽�
			if (i == 0 || j == 0 || i == �� - 1 || j == �� - 1)
			{
				g_map[i][j] = �߽�;
				WriteChar(i, j, "��", 7);
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
			WriteChar(i, j, "��", 2);
			g_map[i][j] = ��ǽ;
		}
	}
	for (int i = 10; i < 20; i++)
	{
		for (int j = 19; j < 24; j++)
		{
			WriteChar(i, j, "��", 1);
			g_map[i][j] = ��ǽ;
		}
	}

	for (int i = 26; i < 28; i++)
	{
		for (int j = 12; j < 25; j++)
		{
			WriteChar(i, j, "��", 3);
			g_map[i][j] = ����;
		}
	}

	for (int i = 8; i < 10; i++)
	{
		for (int j = 8; j < 25; j++)
		{
			WriteChar(i, j, "��", 7);
			g_map[i][j] = ��ǽ;
		}
	}
	

	for (int i = 34; i < 36; i++)
	{
		for (int j = 8; j < 25; j++)
		{
			WriteChar(i, j, "��", 7);
			g_map[i][j] = ��ǽ;
		}
	}
	
}



//�༭��ͼ
void MAP::custommap()
{
	system("cls");
	MAP::DrawMap();
	//create_game_area_frame(30, 30);
	//�����ͼ
	//WriteChar(80, 14, "�Ƿ񱣴�!!",6);
	//WriteChar(80, 15, "���.�� �Ҽ�.��",6);
	//1 ��ȡ����̨������
	HANDLE hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);
	//2 ѭ����ȡ����̨������Ϣ
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
			hConsoleInput,//����̨��������
			&ir,          //��ȡ���Ŀ���̨��Ϣ�ʹ�������ṹ����
			1,            //������INPUT_RECORD������
			&dwRealCourt  //��������ȡ��ϵ�ʱ�򣬾�����ȡ�˼����ṹ����Ϣ
		);
		//��һ�������Ϣ
		if (ir.EventType == MOUSE_EVENT)
		{
			//����������Ϣ����ô�����������е�����ֶ�������

			if (MouseEv.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				int x = MouseEv.dwMousePosition.Y ;
				int y = MouseEv.dwMousePosition.X/ 2;
				WriteChar(x, y, "��",1);
				g_map[x][y] = ��ǽ;
				//SaveMap("qq.txt");
			}
			if (MouseEv.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
			{
				//Savezhangaiwu("./ww.txt");

				WriteChar(20, 45, "���浱ǰ���ݳɹ�",6);
				Sleep(2000);
				WriteChar(20, 45, "                  ",6);
				return;
			}
		}
	}
}



