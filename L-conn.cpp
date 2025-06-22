/*
双条件联结词

题目描述
给定原子变元P、Q的真值(用1表示T，用0表示F)，求命题公式P⇄Q的真值。

输入描述
输入原子变元P、Q的真值(1或0)，用空格隔开。

输出描述
输出命题公式P⇄Q的真值(1或0)。

样例输入
1 1

样例输出
1

知识点
联结词
提示
对输入的P、Q，直接输出表达式“P==Q”的值即可。
*/
#include <iostream>
using namespace std;
int main()
{
	bool a, b;
	cin >> a >> b;
	cout << (a == b) << endl;

	return 0;
}