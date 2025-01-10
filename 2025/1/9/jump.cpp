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
	float sh = -0.9;
	while (vx!=0||vy!=0)
	{
		x += vx, y += vy;
		if (x + 210 > 600) { x = 600 - 210; vx *= sh; }
		if (x <0) { x = 0; vx *= sh; }
		if (y + 48 > 400 ) { y=400-48; vy *= sh; }
		if (y<0) { y = 0; vy *= sh; }
	
		BeginBatchDraw();
		cleardevice();
		outtextxy(x, y, "hello EasyX!");	
		EndBatchDraw();

		Sleep(10);
	}
	
	system("pause");

	return 0;
}
