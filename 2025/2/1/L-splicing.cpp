/*
拼数

问题描述
给定 n 个正整数 a1,a2,…,an ，你可以将它们任意排序。

现要将这 n 个数字连接成一排，即令相邻数字收尾相接，组成一个数。

问，这个数最大可以是多少。

输入格式
第一行输入一个正整数 n（ 1≤n≤20）。

第二行输入 n 个正整数 a1,a2,…,an ,（ 1≤ai≤10^5）。

输出格式
输出一个整数，表示答案。

样例输入
3
13 312 343

样例输出
34331213
*/
#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
string m[22];
bool pd(string a, string b)
{
	for (int i = 0;; i++)
		if (!a[i])return a[i - 1] > b[0];
		else if (!b[i])return b[i - 1] > a[0];
		else if (a[i] != b[i])return a[i] < b[i];
}
int main()
{
	int n;
	string k = "";
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> m[i];
	sort(m, m + n, pd);
	for (int i = n - 1; i >= 0; i--)
		k += m[i];
	cout << k << endl;

	return 0;
}
