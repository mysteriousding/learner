#include<iostream>
using namespace std;
int main()
{
	int Jia(int x, int y);
	int Jian(int x, int y);
	int Chen(int x, int y);
	int Chu(int x, int y);
	int n, m, i = 0;
	char h;
	cout << "请输入一个数，一个运算符（‘+’,‘-’,‘*’,‘/’），再加一个数。(中间以空格隔开）" << endl;
	cin >> n;
	while (i < 20)
	{
		if (!cin)
		{
			cin.clear(); break;
		}
		if (i != 0)cout << "请再输入一个运算符和一个数延续后面的运算。或输入‘!’结束运算(中间以空格隔开）;" << endl;
		cin >> h;
		if (h == '!')break;
		cin >> m;
		if (h == '+')n = Jia(n, m);
		if (h == '-')n = Jian(n, m);
		if (h == '*')n = Chen(n, m);
		if (h == '/')n = Chu(n, m);
		i++;
	}

	cout << "运算结果为:" << n << endl;


	return 0;
}
int Jia(int x, int y)
{
	int z;
	z = x + y;
	return z;
}
int Jian(int x, int y)
{
	int z;
	z = x - y;
	return z;
}
int Chen(int x, int y)
{
	int z;
	z = x * y;
	return z;
}
int Chu(int x, int y)
{
	int z;
	z = x / y;
	return z;
}
