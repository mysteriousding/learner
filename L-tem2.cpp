/*
温度单位的转换

问题描述
给定一个整数 C，表示摄氏度。
你需要将 C 转换为华氏度。

摄氏度转华氏度公式为 F=C×9/5+32。

输出转换后的华氏度，结果只保留整数部分。

输入格式
输入一个整数 (−89≤C≤54)

输出格式
输出一个整数，表示转换后的华氏度。

样例输入
7

样例输出
44
*/
#include <iostream>
using namespace std;
int main()
{
	float n;
	cin >> n;
	n = n * 9 / 5 + 32;
	cout << (int)n << endl;

	return 0;
}
