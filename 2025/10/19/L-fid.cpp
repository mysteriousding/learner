/*
二分查找数组元素

题目描述
给定一个数组，其采用如下代码定义：

int data[200];
for(i = 0 ; i < 200 ; i ++）data[i] = 4 * i + 6;

现给定某个数，请你求出它在 data 数组中的位置（下标）。

输入描述
输入一个待查找的整数（该整数一定在数组 data 中）。

输出描述
输出该整数在数组中的指标。

输入输出样例
示例 1
输入
262

输出
64

示例 2
输入
438

输出
108

示例 3
输入
774

输出
192
*/
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	cout << (n - 6) / 4 << endl;

	return 0;

}




