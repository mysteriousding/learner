/*
14. 奇数次数【省模拟赛】

问题描述
给定一个仅包含数字字符的字符串，请统计一下这个字符串中出现了多少个值为奇数的数位。

输入格式
输入一行包含一个字符串，仅由数字字符组成。

输出格式
输出一行包含一个整数，表示答案。

样例输入
123455
样例输出
4

样例输入
111222333111222333111222333
样例输出
18

评测用例规模与约定
对于所有评测用例，
1≤ 字符数量 ≤10000。
*/
#include <iostream>
#include<string>
using namespace std;
int main()
{
	string n;
	int m = 0;
	getline(cin, n);
	for (int i = n.size() - 1; i >= 0; i--)
		m += n[i] % 2;
	cout << m << endl;

	return 0;
}
