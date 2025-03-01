/*
反转字符串中的字符

题目描述
实现一个算法来实现反转字符数组的功能。反转的要求如下：

将字符数组的字符进行反转，例如 ['b', ' ', 'a', 'r'] 变成 ['r', 'a', ' ', 'b']。

将字符数组替换为反转后的数组。

输入描述
读入一行字符串，长度不超过 100，字符串可能含有空格。

输出描述
输出一行字符串，该字符串为读入字符串的反转字符串。

输入输出样例
示例

输入
b ar

输出
ra b
*/
#include <iostream>
#include<string>
using namespace std;
int main()
{
	string n;
	getline(cin, n);
	for (int i = n.size() - 1; i >= 0; i--)
		cout << n[i];

	return 0;
}