#include"snake_.h"

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	CHANGDI KK; 
	apple JPG(KK);
	snake o1(18, 10, NULL, KK, 2), o2(19, 10, &o1, KK, 2), head(20, 10, &o2, KK, 1);
	int time = 0, DF = 0;

	while (1)
	{
		system("cls"); 
		cout << "时间: " << time << endl;
		cout << "得分: " << DF << endl;
		KK.HZ();
		JPG.H(KK);
		JIANCHE(head);
		if (!head.CXsnakeL()) { Sleep(500); system("cls");  break; }
		head.KZ(head, JPG, KK, DF);
		time++;
	}

	
	cout << "游戏结束了！" << endl;
	cout << "存活时间: " << time << endl;
	cout << "本局得分: " << DF << endl;
	cout << "\n再来一局吧！" << endl;


	system("pause");

	return 0;
}