#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

const int v = 4;

struct tu
{
	int x;
	IMAGE tu;
}T[6] = { 20,{0},40,{0},20,{0},40,{0},100,{0},100,{0} };

void sm()
{
	loadimage(&T[0].tu, "石头.png", T[0].x, T[0].x);
	loadimage(&T[1].tu, "石头.png", T[1].x, T[1].x);
	loadimage(&T[2].tu, "鸟.png", T[2].x, T[2].x);
	loadimage(&T[3].tu, "鸟.png", T[3].x, T[3].x);
	loadimage(&T[4].tu, "走.png", 40, 60);
	loadimage(&T[5].tu, "跳.png", 40, 60);
}




class za
{
public:
	bool live;
	za():live(1),x(800)
	{
		zl = rand() % (3);
	}
	void hua()
	{
		int y= T[zl].x;
		if (zl > 1)y += 100;

		putimage(x, 300 -y, &T[zl].tu);
		x -= v;
		if (x < -1*T[zl].x)live = 0;
	}
private:
	int x;
	int zl;
}S[4];

bool u = 0;
ExMessage msg = { 0 };

void tiao()
{
	if(peekmessage(&msg,EX_KEY/*EX_MOUSE*/))
		if (msg.message == WM_KEYDOWN/*VK_SPACE*//*WM_LBUTTONDOWN*/)
		{
			printf("hello!\n");   
		}
}


int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	initgraph(800, 400);
	sm();
	setbkcolor(RGB(100, 100, 100));
	cleardevice();
	setlinecolor(BLACK);
	setlinestyle(PS_DASH,2);
	int k = 2,i=0;
	za* p = NULL;
	if (peekmessage(&msg, EX_KEY));
	while (1)
	{
		if (p == NULL)p = new za;
		
		BeginBatchDraw();
		cleardevice();
		tiao();
		
		if (msg.message == WM_KEYDOWN)
		{
			printf("hello!\n");
		}
		else putimage(T[4].x, 300-60, &T[4].tu);
		p->hua();
		line(k *= -1, 300, 800, 300);
		EndBatchDraw();
		
		if (!p->live) { delete p; p = NULL; }

		Sleep(100);
		msg.message = 0;
	}

	system("pause");

	return 0;
}