/*
英文字母

问题描述
输入一个正整数 n, 输出第 n 个大写英文字母。

输入格式
输入一行包含一个正整数 n 。

输出格式
输出一行包含一个字母。

样例输入 1
12

样例输出 1
L

样例输入 2
17

样例输出 2
Q

评测用例规模与约定
对于所有评测用例,1≤n≤26 。
*/
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	cout << char('A' + n - 1) << endl;

	return 0;

}

