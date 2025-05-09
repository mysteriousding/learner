/*
3．散列表的应用（可根据实际情况进行调整）选择合适散列函数和冲突处理方法，编程实现QQ账户的申请与登录。
*/
#include<iostream>
#include<string>
using namespace std;
#define N 1000

typedef struct
{
	int n;
	string m;
}ys;

class slb
{
	ys a[N];
	int zs;

	slb()
	{
		for (int i = 0; i < N; i++)
			a[i].n = -1;
		int j;
		bool u;
		for (int i = N; i > 1; i--)
		{
			u = 1;
			if (i % 2 == 0 && i > 2 || i % 3 == 0)u = 0;
			if (u)
				for (j = 5; j * j <= i; j += 2)
					if (i % j == 0)
					{
						u = 0;
						break;
					}
			if (u)
			{
				zs = j;
				break;
			}
		}
	}

	int hx(int x);
	int cz(int x);
	bool cr();
	bool sc();
	bool xg();
};

int slb::hx(int x)
{
	return x % zs;
}

int slb::cz(int x)
{
	int y0 = hx(x),y=y0;
	for (int i = 0; a[y].n != x && a[y].n != -1; i++)
		y = (y0 + N + (i * i) % N * (i % 2 ? 1 : -1)) % N;
	return y;
}

int main()
{


}
