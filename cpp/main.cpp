#include"main.h"
#include"score.h"
int main() {
	system("mode con cols=120 lines=50");
	SetConsoleTitle(TEXT("̹�˴�սC++"));
	game gaming;
	//Score obj;
	//obj.showOption();

	while (true)
	{
		int option = Score::showOption();
		switch (option)
		{
		case 0:	gaming.GameRun();			 break;	 //������Ϸ
		case 1:	gaming.GameRun();			 break;	 //˫����Ϸ
		case 2:	gaming.GameRun();		 	 break;	 //�༭��ͼ
		case 3:	gaming.GameRun();			 break;	 //����
		case 4:	gaming.GameRun();		     break;	 //��Ϸ����
		case 5:return 0;					 break;	 //�˳���Ϸ
		}
	}
	return 0;
}
