//	system("shutdown -s -t 30");

#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
class tu
{
public:
	static bool live;

	tu();
	void huizhi();
	void kunzhi();
	void xuigao(int y, int x, int z);
private:
	char t[13][13];
	int y;
	int x;
};

bool tu::live = 1;

tu::tu() : y(0), x(5) ,t
{
	{ '#','#','#','#','#','O','#','#','#','#','#','#','#' },
	{ '#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#' },
	{ '#',' ','#','#','#','#','#','#',' ','#',' ','#','#' },
	{ '#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#' },
	{ '#','#','#','#','#',' ','#','#','#','#','#',' ','#' },
	{ '#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#' },
	{ '#','#',' ','#','#','#','#','#',' ',' ',' ','#','#' },
	{ '#',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ','#' },
	{ '#',' ','#','#','#',' ','#','#','#','#',' ','#','#' },
	{ '#',' ','#',' ',' ',' ','#',' ',' ',' ',' ','#','#' },
	{ '#','#','#',' ','#','#','#','#','#',' ',' ',' ','#' },
	{ '#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#' },
	{ '#','#','#','#','#','#','#',' ','#','#','#','#','#' }
} {}

void tu::huizhi()
{
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
			cout << t[i][j];
		cout << endl;
	}
}

void tu::kunzhi()
{
	this->xuigao(y, x, 0);
	int X = x, Y = y;
	switch (_getch())
	{
	case 'a':x--; break;
	case 'd':x++; break;
	case 'w':y--; break;
	case 's':y++; break;
	default:return;
	}

	if (t[y][x] == '#')y = Y, x = X;

	this->xuigao(y, x, 1);
	
	if (y == 12 && x == 7)tu::live = 0;

}

void tu::xuigao(int y, int x, int z)
{
	t[y][x] = (z) ? 'O' : ' ';
}



int main()
{
	tu t;
	t.huizhi();
	do {

		t.kunzhi();
		system("cls"); 
		t.huizhi();

	} while (tu::live);

	Sleep(500);
	cout << "\n恭喜你！游戏胜利了！！！" << endl;
	cout << "再来一局吧！!" << endl;

	system("pause");


	return 0;
}
