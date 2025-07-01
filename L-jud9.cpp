/*
输出“(P∨Q)∧(P→R)∧(Q→R)”真值表

题目描述
编程输出命题合式公式(P∨Q)∧(P→R)∧(Q→R)的真值表。
禁止采用手工画出真值表，再用输出语句输出整个真值表。

输入描述
无输入。

输出描述
输出该命题公式的真值表，前两行示例如下。

P Q R -> (P|Q)&(P->R)&(Q->R)

0 0 0 -> 0
*/
#include <iostream>
using namespace std;
int main()
{
	int i, j, k;
	cout << "P Q R -> (P|Q)&(P->R)&(Q->R)" << endl;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			for (k = 0; k < 2; k++)
				cout << i << " " << j << " " << k << " -> " << ((i || j) && !(i && !k) && !(j && !k)) << endl;

	return 0;
}