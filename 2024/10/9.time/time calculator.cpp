#include<iostream>
using namespace std;
int main()
{
	int a, b, c, d, e, f, i, num, a0, d0;
	cout << "欢迎使用时间计算机：" << endl;
	cout << "请输入你的生日：" << endl;
	cout << "年：";
	cin >> a;
	cout << "月：";
	cin >> b;
	cout << "日：";
	cin >> c;
	cout << "请输入今天的日期：" << endl;
	cout << "年：";
	cin >> d;
	cout << "月：";
	cin >> e;
	cout << "日：";
	cin >> f;
	i = 1; a0 = a; d0 = d;

	//1.生月余日
	if (b == 2)
	{
		if (a % 100 == 0)
		{
			if (a % 400 == 0) { num = 29 - c + 1; }
			else { num = 28 - c + 1; }
		}
		else
		{
			if (a % 4 == 0) { num = 29 - c + 1; }
			else { num = 28 - c + 1; }
		}
	}
	else if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) { num = 31 - c + 1; }
	else { num = 30 - c + 1; }

	//2.生年余月
	b = b + 1;
	while (b <= 12)
	{
		if (b == 2)
		{
			if (a % 100 == 0)
			{
				if (a % 400 == 0) { num = num + 29; }
				else { num = num + 28; }
			}
			else
			{
				if (a % 4 == 0) { num = num + 29; }
				else { num = num + 28; }
			}
		}
		else if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) { num = num = num + 31; }
		else { num = num + 30; }

		b++;
	}

	//3.完整年月
	a = a + 1;
	d = d - 1;
	while (a <= d)
	{
		if (a % 100 == 0)
		{
			if (a % 400 == 0) { num = num + 366; }
			else { num = num + 365; }
		}
		else
		{
			if (a % 4 == 0) { num = num + 366; }
			else { num = num + 365; }
		}

		a++;
	}

	//4.今昔溢月
	e = e - 1; //a = a0;
	while (i <= e)
	{
		if (i == 2)
		{
			if (a % 100 == 0)
			{
				if (a % 400 == 0) { num = num + 29; }
				else { num = num + 28; }
			}
			else
			{
				if (a % 4 == 0) { num = num + 29; }
				else { num = num + 28; }
			}
		}
		else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) { num = num + 31; }
		else { num = num + 30; }

		i++;
	}

	//5.今昔溢日
	num = num + f;

	//6.同年补充
	a = a0; d = d0;
	if (a == d)
	{
		if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)){num = num - 366;}
		   else{ num = num - 365; }
	}

	cout << "今天是你的第" << num << "个白天！" << endl;
	cout << "祝你每一天都开心快乐！！" << endl;

	return 0;
}
