/*
寻找 3 个数的最大乘积

题目描述
实现一个算法在数组中找到 3 个数字的最大乘积。介绍如下：

例如数组 [5, -2, 3, 1, -1, 4] 中 3 个数字的最大乘积为 60。
输入描述
第一行为数字 N (3≤N≤1000)，表示数组元素的个数。

第二行为数组元素 −1000≤Ai≤1000。

输出描述
输出一行，为 3 个数字的最大乘积。

输入输出样例
示例

输入
6
5 -2 3 1 -1 4

输出
60
*/
#include <iostream>
using namespace std;
int main()
{
	int n, a[1005], h;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1])
				h = a[j], a[j] = a[j + 1], a[j + 1] = h;
	h = a[n - 1] * a[n - 2] * a[n - 3];
	if (h < a[0] * a[1] * a[n - 1])h = a[0] * a[1] * a[n - 1];
	cout << h << endl;

	return 0;
}
