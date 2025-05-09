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

	slb()
	{
		for (int i = 0; i < N; i++)
			a[i].n = -1;
	}

	int hx(int x);
	int cz(int x);
	bool cr();
	bool sc();
	bool xg();
};

int slb::hx(int x)
{
	return x % N;
}

int slb::cz(int x)
{
	int y = hx(x);
	return x % N;
}

int main()
{
	cout << -7 % 5 << endl;


}