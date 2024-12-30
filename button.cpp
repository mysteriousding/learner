//#include<iostream>
//#include<conio.h>
//#include<windows.h>
//#include<graphics.h>
//using namespace std;
//int main()
//{
//	POINT p;
//	
//	/*for(int i=0;i<100;i++)
//	{
//		GetCursorPos(&p);
//		cout << p.x << " " << p.y << endl;
//		Sleep(100);
//	}*/
//
//
//	
//
//	int x = 100, y = 100;
//
//
//	for (int i = 0; i < 30; i++)
//	{
//		x += 10, y += 10;
//		//GetCursorPos(100,100);
//		if(_kbhit())
//		{
//			_getch();
//			break;
//		}
//		SetCursorPos(x, y);
//		Sleep(100);
//	}
//
//	
//
//	return 0;
//}





//#include<iostream>
//#include<graphics.h>
//#include<windows.h>
//#include<conio.h>
//using namespace std;
//int main()
//{
//	
//	int x = 100, y = 100;
//	initgraph(400, 400);
//	HWND hwnd = GetHWnd();
//	IMAGE age;
//	loadimage(&age, "警告.gif",400, 400);
//	putimage(0, 0, &age);
//	
//	for (int i = 0; i < 30; i++)
//	{
//		 
//		x += 10,y += 10; 
//		SetWindowPos(hwnd, NULL, x, y, 0, 0, SWP_NOSIZE); 
//		/*if (_kbhit())
//		{
//			_getch();
//			break;
//		}*/
//		SetCursorPos(x+100, y+50); 
//		Sleep(100); 
//	}
//
//	getchar();
//
//	return 0;
//}


//#include<iostream>
//#include<graphics.h>
//#include<windows.h>
//#include<conio.h>
//#include<thread>
//using namespace std;
//int x = 100, y = 100;
//
//void xc()
//{
//	initgraph(400, 400);
//	HWND hwnd = GetHWnd();
//	IMAGE age;
//	loadimage(&age, "警告.gif", 400, 400);
//	putimage(0, 0, &age);
//	SetWindowPos(hwnd, NULL, x, y, 0, 0, SWP_NOSIZE);
//	SetCursorPos(x + 100, y + 50);
//}
//
//int main()
//{
//
//	
//	thread* arr[30];
//
//	for (int i = 0; i < 30; i++)
//	{
//		x += 10, y += 10;
//		arr[i] = new thread(xc);
//		
//		Sleep(100);
//	}
//
//
//	for (int i = 0; i < 30; i++)
//	{
//		arr[i]->join();
//		delete arr[i];
//	}
//	
//
//	getchar();
//
//	return 0;
//}



#include<graphics.h>
#include<windows.h>
#include<iostream>
#include<conio.h>
#include <thread>
using namespace std;

struct tu
{
	bool live;
	bool on;
	/*IMAGE age;*/
	int y;
	int x;
};

int main()
{
	initgraph(500, 500);
	HWND hwnd = GetHWnd();
	SetWindowPos(hwnd, NULL, 500, 250, 0, 0, SWP_NOSIZE);
	IMAGE age1;
	IMAGE age2;
	IMAGE OK;
	loadimage(&age1, "按钮1.png", 112, 60);
	loadimage(&age2, "按钮2.png", 112, 60);
	loadimage(&OK, "long.jpg", 500, 500);
	int n, x = 41, y;
	//cin >> n;
	tu* T[3][3];
	for (int i = 0; i < 3; i++)
	{
		y = 80;
		for (int j = 0; j < 3; j++)
		{
			T[i][j] = new tu;
			T[i][j]->live = 1;
			T[i][j]->on = 0;
			T[i][j]->x = x;
			T[i][j]->y = y;
			putimage(x, y, &age1);
			y += 140;
		}
		x += 153;
	}

	POINT p;

	
	while(1)
	//for (int k = 0; k < 100; k++)
	{	
		GetCursorPos(&p);
		ScreenToClient(hwnd, &p);

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				x = T[i][j]->x, y = T[i][j]->y;
				bool u=(p.x >= x && p.x <= x + 112 && p.y >= y && p.y <= y + 60);
				if(u&&!T[i][j]->on)
				{
					putimage(x, y, &age2);
					T[i][j]->on = 1;
				}
				if(!u&& T[i][j]->on)
				{
					putimage(x, y, &age1);
					T[i][j]->on = 0;
				}
				if (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && u)
				{
					putimage(0, 0, &OK);
					goto ok;
				}
			}

		if (_kbhit())
		{
			_getch();
			break;
		}
		Sleep(100);
	}

	ok:
	cout << " 结束！ " << endl;


	//for (int i = 0; i < 500/3; i++)
	//{
	//	for (int j = 0; j < 500/3; j++)
	//	{
	//		if (4 * i + 3 * j == 500)
	//			cout << i << " "<<j << endl;
	//	}
	//}


	getchar();


	return 0;
}