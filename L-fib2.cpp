/*
斐波拉契求和

问题描述
给定一个斐波那契数列（该斐波那契数列从 2 开始），前几项分别是：
	2,3,5,8,13,…

每一项分别记为 fib[1],,fib[2],,…,,fib[n]

定义序列 g：
	gi = fib[i]/fib[i+1]​

现在给定一个正整数 n，你需要求出
	n∑i=1 gi​

换句话说，你需要求出序列 g 的前 n 项和，结果保留 5 位小数。

输入格式
输入一行，包含 1 个正整数 (1≤n≤20)

输出格式
输出一行，为序列 g 的前 n 项和，结果保留 5 位小数。

样例输入
4

样例输出
2.50705

说明
计算得：
	2/3 + 3/5 + 5/8 + 8/13 = 2.5070512

保留 5 位小数为 2.50705。
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double n, m = 0, a = 3, b = 2, c;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		m += b / a;
		c = a + b;
		b = a;
		a = c;
	}
	cout << fixed << setprecision(5) << m << endl;

	return 0;
}
