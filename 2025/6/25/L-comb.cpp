/*
不可兼析取

题目描述
给定原子变元P、Q的真值(用1表示T，用0表示F)，求命题公式P Q的真值。

输入描述
输入原子变元P、Q的真值(1或0)，用空格隔开。

输出描述
输出命题公式P Q的真值(1或0)。

样例输入
1 1

样例输出
0
*/
#include <iostream>
using namespace std;
int main()
{
	bool u, v;
	cin >> u >> v;
	cout << (u != v) << endl;

	return 0;
}
