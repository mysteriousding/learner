#include<iostream>
#include<graphics.h>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
#include<ctime>
using namespace std;

bool Time(int ms, int id);
void Load();
void YD();
void HUIZHI();
void zdcj();
void djcj();
void drzdcj();
void playplane();
void WWW();
void peng();
void dx();

const int MAX = 10;
int fenshu = 0;
enum data
{
	wide = 591,
	high = 864,

	feiji_v = 10,        //飞机

	zidan_sum = 30,      //子弹
	zidan_v = 15,

	diji_sum = 7,       //敌机
	diji_v = 5,
	drzidan_sum = 50,
	da,
	xiao
};

struct plane
{
	int x = 0;
	int y = 0;
	bool live = false;
	int HP;
	bool type;       //敌机大小标记

	int kuan;       //飞机大小实际
	int gao;
}MY, zidan[zidan_sum], diji[diji_sum], drzidan[drzidan_sum];

IMAGE BJ;
IMAGE FEIJI[2];
IMAGE XIAODI[2];
IMAGE DADI[2];
IMAGE ZIDAN[2];
IMAGE DRZIDAN[2];
IMAGE JIESHU;



int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	Load();

	while (MY.live)
	{
		WWW();
		peng();
		HUIZHI();
		YD();
		if (Time(3000, 0))
			djcj();
		if (Time(2500, 2))
			drzdcj();
		playplane();
		dx(); 
	}

	Sleep(200);
	putimage(0, 0, &JIESHU);
	cout << "你被淘汰了，再玩一局试试吧！" << endl;

	system("pause");

	return 0;
}



//定时器
bool Time(int ms, int id)
{
	static DWORD t[MAX];
	if (clock() - t[id] > ms)
	{
		t[id] = clock();
		return 1;
	}
	return 0;
}

//图片加载 + 游戏初始化
void Load()
{
	loadimage(&BJ, "image/BJ.png", wide, high);

	loadimage(&FEIJI[0], "image/plane0.jpg", 70, 89);
	loadimage(&FEIJI[1], "image/plane.jpg", 70, 89);

	loadimage(&XIAODI[0], "image/xiao0.jpg", 32, 32);
	loadimage(&XIAODI[1], "image/xiao.jpg", 32, 32);
	
	loadimage(&DADI[0], "image/da.jpg", 35, 50);
	//loadimage();
	loadimage(&ZIDAN[0], "image/zd.png", 10, 20);
	//loadimage();
	loadimage(&DRZIDAN[0], "image/drzd.png", 10, 10);
	//loadimage();
	loadimage(&JIESHU, "image/结束.jpg", wide, high);


	MY.x = wide / 2 - 35;
	MY.y = high - 100;
	MY.live = true;
	MY.HP = 20000;
	MY.kuan = 70;
	MY.gao = 89;

	initgraph(wide, high);
}

//控制
void YD()
{
	switch (_getch())
	{
	case 'w':
		MY.y -= feiji_v;
		if (MY.y < 0)MY.y = 0;
		break;
	case 's':
		MY.y += feiji_v;
		if (MY.y > 775)MY.y = 775;
		break;
	case 'a':
		MY.x -= feiji_v;
		if (MY.x < 0)MY.x = 0;
		break;
	case 'd':
		MY.x += feiji_v;
		if (MY.x > 521)MY.x = 521;
		break;
	case 'l':
		zdcj();
		break;
	}
}

//画图
void HUIZHI()
{
	cleardevice();

	putimage(0, 0, &BJ);
	putimage(MY.x, MY.y, &FEIJI[0],NOTSRCERASE);
	putimage(MY.x, MY.y, &FEIJI[1],SRCINVERT);

	for (int i = 0; i < zidan_sum; i++)
	{
		if (zidan[i].live)
		{
			putimage(zidan[i].x, zidan[i].y, &ZIDAN[0]);
			zidan[i].y -= zidan_v;
		}
		if (zidan[i].y < 0)
			zidan[i].live = false;
	}

	for (int i = 0; i < diji_sum; i++)
	{
		if (diji[i].live)
		{
			if (!diji[i].type)
				putimage(diji[i].x, diji[i].y, &DADI[0]);
			else 
			{
				putimage(diji[i].x, diji[i].y, &XIAODI[0], NOTSRCERASE);
				putimage(diji[i].x, diji[i].y, &XIAODI[1], SRCINVERT);
			}

			diji[i].y += diji_v;
		}
		if (diji[i].y > high)
		{
			diji[i].live = false;
			diji[i].x = 0;
			diji[i].y = 0;
			MY.HP--;
			if (MY.HP <= 0)MY.live = false;
		}
	}

	for (int i = 0; i < drzidan_sum; i++)
	{
		if (drzidan[i].live)
		{
			putimage(drzidan[i].x, drzidan[i].y, &DRZIDAN[0]);
			drzidan[i].y += zidan_v;
		}
		if (drzidan[i].y > high)
			drzidan[i].live = false;
	}
	
	system("cls");
	cout << "制作者:DSQ" << endl;
	cout << "得分: " << fenshu << endl;
	cout << "HP: " << MY.HP << endl;
}

//子弹创建
void zdcj()
{
	for (int i = 0; i < zidan_sum; i++)
		if (!zidan[i].live)
		{
			zidan[i].live = true;
			zidan[i].x = MY.x + 30;
			zidan[i].y = MY.y;
			zidan[i].kuan = 10;
			zidan[i].gao = 20;
			break;
		}
}

//敌机创建
void djcj()
{
	for (int i = 0; i < diji_sum; i++)
		if (!diji[i].live)
		{
			diji[i].live = true;
			diji[i].x = rand()%(wide-35);
			diji[i].y = -50;
			diji[i].type = rand() % (3);
			diji[i].HP = diji[i].type ? 2 : 4;
			diji[i].kuan = diji[i].type ? 32 : 35;
			diji[i].gao = diji[i].type ? 32 : 50;
			break;
		}
}

//敌人子弹创建
void drzdcj()
{
	for (int j = 0; j < diji_sum; j++)
		if (diji[j].live)
			for (int i = 0; i < drzidan_sum; i++)
				if (!drzidan[i].live)
				{
					drzidan[i].live = true;
					drzidan[i].x = diji[j].x + (diji[j].type ? 11 : 12);
					drzidan[i].y = diji[j].y + diji[j].gao;
					drzidan[i].kuan = 10;
					drzidan[i].gao = 10;
					break;
				}
}

//攻击
void playplane()
{
	for (int i = 0; i < diji_sum; i++)
		if (diji[i].live)
			for (int j = 0; j < zidan_sum; j++)
				if (zidan[j].live)
					if (zidan[j].x > diji[i].x - zidan[j].kuan && zidan[j].x < diji[i].x + diji[i].kuan &&
						zidan[j].y > diji[i].y - zidan[j].gao && zidan[j].y < diji[i].y + diji[i].gao)
					{
						zidan[j].live = false;
						if (!--diji[i].HP) 
						{
							diji[i].live = false; 
							fenshu += (diji[j].type ? 1 : 2);
							break;
						}
					}
}

//受伤
void WWW()
{
	for (int i = 0; i < drzidan_sum; i++)
		if (drzidan[i].live)
			if (MY.x >= drzidan[i].x - MY.kuan && MY.x <= drzidan[i].x + drzidan[i].kuan &&
				MY.y >= drzidan[i].y - MY.gao && MY.y <= drzidan[i].y + drzidan[i].gao)
			{
				drzidan[i].live = false;
				MY.HP--;
				if (MY.HP <= 0) { MY.live = false; break; }
			}
}

//碰撞
void peng()
{
	for (int i = 0; i < diji_sum; i++)
		if (diji[i].live)
			if (MY.x >= diji[i].x - MY.kuan && MY.x <= diji[i].x + diji[i].kuan &&
				MY.y >= diji[i].y - MY.gao && MY.y <= diji[i].y + diji[i].gao)
			{
				MY.HP = 0;
				MY.live = false;
			}
}

//抵消
void dx()
{
	for (int i = 0; i < drzidan_sum; i++)
		if (drzidan[i].live)
			for (int j = 0; j < zidan_sum; j++)
				if (zidan[j].live)
					if (zidan[j].x >= drzidan[i].x - zidan[j].kuan && zidan[j].x <= drzidan[i].x + drzidan[i].kuan &&
						zidan[j].y >= drzidan[i].y - zidan[j].gao && zidan[j].y <= drzidan[i].y + drzidan[i].gao)
					{
						zidan[j].live = false;
						drzidan[i].live = false;
					}
}