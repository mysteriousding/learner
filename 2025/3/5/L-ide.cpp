/*
排列序数

题目描述
如果用 a b c d 这 4 个字母组成一个串，有 4!=24 种，如果把它们排个序，每个串都对应一个序号：

abcd 0

abdc 1

acbd 2

acdb 3

adbc 4

adcb 5

bacd 6

badc 7

bcad 8

bcda 9

bdac 10

bdca 11

cabd 12

cadb 13

cbad 14

cbda 15

cdab 16

cdba 17

⋯⋯

现在有不多于 10 个两两不同的小写字母，给出它们组成的串，你能求出该串在所有排列中的序号吗？

输入描述
输入一行，一个串。

输出描述
输出一行，一个整数，表示该串在其字母所有排列生成的串中的序号。注意：最小的序号是 0。

输入输出样例
示例

输入
bdca

输出
11
*/
#include <iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	int a[11] = { 1 }, num, sum = 0;
	for (int i = 1; i < 11; i++)
		a[i] = a[i - 1] * i;
	string n, m = "abcdefghij";
	cin >> n;
	for (int i = 0, j = n.size() - 1; i < n.size(); i++, j--)
		sum += abs((n[i] - m[i]) * a[j]);
	cout << sum - 1 << endl;

	return 0;
}
