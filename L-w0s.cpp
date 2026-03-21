/*
0 的个数

问题描述
给定一个正整数 n ，请问 n 的十进制表示中末尾总共有几个 0 ？

输入格式
输入一行包含一个正整数 n。

输出格式
输出一个整数，表示答案。

样例输入
20220000

样例输出
4

评测用例规模与约定
对于所有评测用例，1 <= n <= 1000000000。
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	int i = s.size() - 1;
	for (; !(s[i] - '0'); i--);
	cout << s.size() - i - 1 << endl;

	return 0;
}
