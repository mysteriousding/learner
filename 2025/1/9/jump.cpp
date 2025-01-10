#include<iostream>
#include<graphics.h>
using namespace std;
int main()
{
	initgraph(600, 400);

	setbkcolor(RGB(100,100,100));
	cleardevice();

	settextstyle(48, 0, "微软雅黑");
	settextcolor(BROWN);
	setbkmode(TRANSPARENT);
	int x = 0, y = 0, vx = 100, vy = 100;
	while (y<=400)
	{
		x += vx, y += vy;
		if (x + 210 > 600) { x = 600 - 210; vx *= -0.9; }
		if (x <0) { x = 0; vx *= -0.9; }
		if (y + 48 > 400 ) { y=400-48; vy *= -0.9; }
		if (y<0) { y = 0; vy *= -0.9; }
	
		BeginBatchDraw();
		cleardevice();
		outtextxy(x, y, "hello EasyX!");
			
		EndBatchDraw();
		Sleep(10);
	}
	

	system("pause");

	return 0;
}
