#pragma once
#include<time.h>
#include<iostream>
#include<windows.h>
enum
{
	�� = 40, �� = 40
};
enum
{
	�յ� = 0,
	�߽� = 1,
	�ӵ� = 2,
	��ǽ = 3,
	��ǽ = 4,
	��� = 5,
	���2=7,
	��ǽ = 6,
	AI = 8,
	���� = 9


};

extern int g_map[��][��];


//������ͼ�߽�
class MAP
{
public:
	static void DrawMap();
	static void WriteChar(int High, int Wide, const char* Char, WORD wArr);
	static void DrawZaw();
	//�༭��ͼ
	static void custommap();

private:
	
};


