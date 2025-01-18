/*
用天平称重时，我们希望用尽可能少的砝码组合称出尽可能多的重量。
如果只有 5 个砝码，重量分别是 1，3，9，27，81。则它们可以组合称出 1 到 121 之间
任意整数重量（砝码允许放在左右两个盘中）。
本题目要求编程实现：对用户给定的重量，给出砝码组合方案。
例如：
用户输入：
5
程序输出：
9-3-1
用户输入：
19
程序输出：
27-9+1

要求程序输出的组合总是大数在前小数在后。
可以假设用户的输入的数字符合范围 1~121。
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n, m = 0, i = 0, j, k = 0;
	int N[5] = { 1,3,9,27,81 }, M[5];
	//int N[6] = { 1,3,9,27,81,243 }, M[6];
	bool u;
	cin >> n;

	for (; i < 4; i++)
		if (m < n)m += N[i];
		else break;

	while (n)
	{
		u = 1;
		for (j = 0; j < i; j++)
			if (0.66 * abs(n) < N[j])  //一个小时  运气  猜测
			{
				i = j - 1;
				u = 0;
				break;
			}
		if (u)i--;
		if (n > 0)
		{
			n -= N[j];
			M[k++] = N[j];
		}
		else
		{
			n += N[j];
			M[k++] = -1 * N[j];
		}
	}

	for (i = 0; i < k; i++)
	{
		if (i && M[i] > 0)cout << "+";
		cout << M[i];
	}

	return 0;
}
