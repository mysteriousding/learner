/*
求解台阶问题

题目描述
现一个算法求解台阶问题。介绍如下：

对于高度为 n 的台阶，从下往上走，每一步的阶数为 1，2，3 中的一个。问要走到顶部一共有多少种走法。
输入描述
输入一个数字 N (1≤N≤35)，表示台阶的高度。

输出描述
输出一行，为走法总数。

输入输出样例
示例

输入
4

输出
 7
*/
#include <iostream>
using namespace std;
int main()
{
	int n;
	long long a[40] = { 1,2,4 };
	cin >> n;
	for (int i = 3; i < n; i++)
		a[i] = a[i - 1] + a[i - 2] + a[i - 3];
	cout << a[n - 1] << endl;

	return 0;
}