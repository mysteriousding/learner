/*
确定翻转的位数

题目描述
实现一个算法确定将一个二进制整数翻转为另一个二进制整数，需要翻转的位数。介绍如下：

例如将 11101 翻转为 00111，需要翻转的位置为第 1，2 和 4 位置，则需要翻转的位数为 3。
输入描述
输入两行，为两个二级制整数，均不超过 100 位。

输出描述
输出一个数字，为翻转的位数。

输入输出样例
示例

输入
11101
00111

输出
3
*/
#include <iostream>
#include<string>
using namespace std;
int main()
{
	string n, m;
	int a = 0;
	cin >> n >> m;
	for (int i = 0; n[i] != '\0'; i++)
		if (n[i] != m[i])
			a++;
	cout << a << endl;

	return 0;
}