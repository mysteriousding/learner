/*
函数之和

问题描述
定义 f(n) 函数为正整数的不同数组 a 的个数，使得 a 数组中元素之和等于 n 。

输入格式
第一行包含一个整数 k ，请输出 f(k) 的值。

输出格式
一行输出 1 个整数。

样例输入
3

样例输出
4

说明
f(3)=4 ,四种不同的数组分别是：
{1,1,1}
{1，2}
{2，1}
{3}

评测数据规模
对于 100% 的评测数据，1≤n≤10。
*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin >> n;
	cout << pow(2, n - 1) << endl;

	return 0;
}