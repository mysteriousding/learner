#include<graphics.h>
#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<time.h>
using namespace std;

enum
{
	kuan = 800,
	gao = 400,
	//v = 4,
	vy = 20,
	g = 1,
	lu = 300,
	dianw = 100,
	fei = 100,
	//gs = 5
};
double v = 4;
int gs = 1;

struct tu
{
	int x;
	int y;
	IMAGE tu;
}T[6] =
{
	20,20,{0},
	40,40,{0},
	20,20,{0},
	40,40,{0},
	40,60,{0},
	40,60,{0}
};

void sm()
{
	loadimage(&T[0].tu, "石头.png", T[0].x, T[0].y);
	loadimage(&T[1].tu, "石头.png", T[1].x, T[1].y);
	loadimage(&T[2].tu, "鸟.png", T[2].x, T[2].y);
	loadimage(&T[3].tu, "鸟.png", T[3].x, T[3].y);
	loadimage(&T[4].tu, "走.png", T[4].x, T[4].y);
	loadimage(&T[5].tu, "跳.png", T[5].x, T[5].y);
}

class wu
{
public:
	bool live;

	wu(int a):live(1),x(dianw),y(lu- T[4].y),zl(4){}

	wu():live(1)
	{
		zl = rand() % (4);
		x = rand() % (400) + kuan;
		y = lu - (T[zl].y + ((zl > 1) ? 100 : 0));
	}
	
	void hua()
	{
		putimage(x, y, &T[zl].tu);
		x -= v;
		if (x < -1*T[zl].x)live = 0;
	}
	friend void pz(wu* d[]);
	friend void xh(wu* p[]);
private:
	int x;
	int y;
	int zl;

}S[4], wo(1);

ExMessage msg = { 0 };

//int u = 0, h = 0;
//void tiao(int& u)
//{
//	
//	int x,y;
//	if (u <= 20)x = u++;
//	else if (u < 40)x = 40 - u++;
//	else h = x = u = 0;
//
//	y = 0.5 * 10 * ((x + 1) * (x + 1) - x * x);
//	if (u <= 20)h += (102 - y/2 )/10;
//	else if (u <40)h -= (102 - y/2 )/10;
//
//	cout << h << endl;
//	putimage(dianw, lu - T[5].y - h, &T[5].tu);
//}

void tiao(int& u)
{

	int x;
	x = vy * u - 1.0 / 2 * g * u * u++;
	if (u==40)u=0;
	T[5].y = lu - T[4].y - x / 2; 
	/*cout << T[5].y << endl;*/
	putimage(dianw, /*lu - T[5].y - x/2*/ T[5].y, &T[5].tu);
}

void pz(wu* d[])
{
	for (int i = 0; i < gs; i++)
		if (d[i] != NULL)
			if (dianw + T[5].x >= d[i]->x && dianw <= d[i]->x + T[d[i]->zl].x && T[5].y + 9 + T[4].y >= d[i]->y && T[5].y + 9 <= d[i]->y + T[d[i]->zl].y)
			{
				wo.live = 0;
				return;
			}
}

void xc(wu* p[])
{
	for (int i = 0; i < gs; i++)
	{
		if (p[i] == NULL)p[i] = new wu;
		if (!p[i]->live) { delete p[i]; p[i] = NULL; }
	}
}

void xh(wu* p[])
{
	for (int i = 0; i < gs; i++)
		if (p[i] != NULL && p[i]->live)
			for (int j = i + 1; j < gs; j++)
					if (p[j] != NULL&&p[j]->live)
							if (p[i]->x + T[p[i]->zl].x >= p[j]->x && p[i]->x <= p[j]->x + T[p[j]->zl].x)
								p[j]->live = 0;
}

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	initgraph(kuan, gao);
	sm();
	setbkcolor(RGB(100, 100, 100));
	cleardevice();
	setlinecolor(BLACK);
	setlinestyle(PS_DASH, 2);
	int k = 2,j=0,u=0;
	wu* p[10] = { NULL };

	while (wo.live)
	{
		xc(p);
		pz(p);
		xh(p);

		BeginBatchDraw();

		cleardevice();
		line(k *= -1, lu, kuan, lu);

		for (int i = 0; i < gs; i++)if (p[i] != NULL)p[i]->hua();

		peekmessage(&msg, EX_KEY);
		if (!u&&msg.message == WM_KEYDOWN&&msg.vkcode==VK_UP)u = 1;
		if (!u)putimage(dianw, lu-T[4].y, &T[4].tu);
		else tiao(u);
		if (msg.message == WM_KEYDOWN && msg.vkcode == VK_DOWN)u = 0, T[5].y = 231;
		
		
		EndBatchDraw();

		Sleep((msg.message == WM_KEYDOWN && msg.vkcode == VK_RIGHT)?10:100);
		msg.message = 0;
		j++,v+=0.001;
		if (j > 2500)gs++, j = 0;
	}

	system("pause");

	return 0;
}
