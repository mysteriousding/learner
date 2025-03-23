/*
标题统计

题目描述
凯凯刚写了一篇美妙的作文，请问这篇作文的标题中有多少个字符？

注意：标题中可能包含大、小写英文字母、数字字符、空格和换行符。
统计标题字符数时，空格和换行符不计算在内。

输入描述
输入文件只有一行，一个字符串 s (1≤∣s∣≤5)。

输出描述
输出只有一行，包含一个整数，即作文标题的字符数（不含空格和换行符）。

输入输出样例
示例

输入
Ca 45

输出
4
*/
#include <iostream>
#include<string>
using namespace std;
int main()
{
	string n;
	int m = 0;
	getline(cin, n);
	for (int i = 0; i < n.size(); i++)
		if (n[i] != ' ')m++;
	cout << m << endl;

	return 0;
}