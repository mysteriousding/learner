/*
字符计数

题目描述
给定一个单词，请计算这个单词中有多少个元音字母，多少个辅音字母。

元音字母包括 a, e, i, o, u，共五个，其他均为辅音字母。

输入描述
输入格式：

输入一行，包含一个单词，单词中只包含小写英文字母。单词中的字母个数不超过 100。

输出描述
输出两行，第一行包含一个整数，表示元音字母的数量。

第二行包含一个整数，表示辅音字母的数量。

输入输出样例
示例
输入

lanqiao

输出

4
3
*/
#include <iostream>
#include<string>
using namespace std;
int main()
{
	int i = 0, j = 0, k = 0;
	string m;
	cin >> m;
	while (m[k] != '\0')
		if (m[k] == 'a' || m[k] == 'e' || m[k] == 'i' || m[k] == 'o' || m[k] == 'u')i++, k++;
		else j++, k++;
	cout << i << endl << j << endl;

	return 0;
}
