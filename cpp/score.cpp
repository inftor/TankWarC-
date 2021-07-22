#include "score.h"
#include"map.h"
#include<conio.h>
#include<stdio.h>
//#include"tank.h"
#include"game.h"
int tank1 = 5;
int tank2 = 5;
int AI1 = 5;
int AI2 = 5;

int exit()
{
	return 0;
}

//�ƶ����λ��
void Score::MoveCursorPosition(int x, int y)
{
	//1.ָ��һ������
	COORD pos;
	pos.X = y;//ָ��������
	pos.Y = x;//ָ��������

	//2.��ñ�׼������豸�ľ�� �����cmd���ڵĴ�ӡ����
	HANDLE hCmdWindow;
	hCmdWindow = GetStdHandle(STD_OUTPUT_HANDLE);

	//3.�ƶ���굽pos����ָ����λ��
	SetConsoleCursorPosition(hCmdWindow, pos);
	return;
}

//��һ�����棬��ʾ���˵�
int Score::showOption()
{
	//����
	MAP::WriteChar(10, 15, "̹�˴�ս v1.0", FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	char  ch;
	int option = 0;

	MAP::WriteChar(13, 13, "��", FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	const char* options[] = { "������Ϸ", "˫����Ϸ", "�༭��ͼ", "��    ��", "��Ϸ����", "��    ��" };
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
			if (ch == 72 || ch == 80 || ch == '\r')  //ֻ������¼�
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
				//�������¼�֮�����ʾ
				MAP::WriteChar(13+ option, 13 , "                        ", 0);
				Sleep(100);
				MAP::WriteChar(13+ option, 13 , "��", FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				MAP::WriteChar(13+ option, 15 , options[option], FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

				if (ch == '\r')
				{
					return option;
				}
			}

		}
	}
}

//��ȡ����
void Score::getchar(int num)
{

	switch (num)
	{
	case 1:tank1--; break;
	case 2:tank2--; break;
	case 3:AI1--; break;
	case 4:AI2--; break;
	default:
		break;
	}
 }




//��ʾ�Ʒְ�
void Score::ShowScore()
{

	
	MAP::WriteChar(20,45,"AI̹��1��ǰ����ֵ��",4);
	MoveCursorPosition(20, 120);
	printf("%d",AI1*100 );
	MAP::WriteChar(23, 45, "AI̹��2��ǰ����ֵ��", 4);
	MoveCursorPosition(23, 120);
	printf("%d", AI2 * 100);
	MAP::WriteChar(26, 45, "̹��1��ǰ����ֵ��", 2);
	MoveCursorPosition(26, 120);
	printf("%d", tank1 * 100);
	MAP::WriteChar(29, 45, "̹��2��ǰ����ֵ��", 2);
	MoveCursorPosition(29, 120);
	printf("%d", tank2 * 100);

}


