#include"main.h"
#include"score.h"
#include"game.h"
int main() {
	system("mode con cols=150 lines=60");
	SetConsoleTitle(TEXT("̹�˴�սC++"));

	//Score obj;
	//obj.showOption();

	while (true)
	{
		int option = Score::showOption();
		switch (option)
		{
		case 0:	gaming.GameRun(1);								 break;	 //������Ϸ
		case 1:	gaming.GameRun(2);								 break;	 //˫����Ϸ
		case 2:	MAP::custommap(), gaming.GameRun(3);	 		 break;	 //�༭��ͼ
		case 3:	gaming.GameRun(1);								 break;	 //����
		case 4:	game::ReadFile(),gaming.GameRun(4);								 break;	 //�����浵
		case 5:return 0;										 break;	 //�˳���Ϸ
		}
	}
	return 0;
}
