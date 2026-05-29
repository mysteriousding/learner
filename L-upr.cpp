/*
方阵

问题描述
有 n 个人要排列成一个 k 行 k 列的方阵，请问 k 最大是多少?

输入格式
输入一行包含一个整数 n。
​


输出格式
输出一行包含一个整数，表示答案。

样例输入
15

样例输出
3

样例输入
81

样例输出
9

评测用例规模与约定
对于 50 的评测用例，2<=n<=1000 。
对于所有评测用例，2<=n<=100000000 。
*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin >> n;
	cout << (int)sqrt(n) << endl;

	return 0;
}