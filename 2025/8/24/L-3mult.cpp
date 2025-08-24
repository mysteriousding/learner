/*
区间内3的倍数的个数

学习助手
题目描述：
求[a, b]区间内3的倍数的个数。注意，区间[a, b]表示大于或等于a、小于或等于b的那些数。

输入描述：
输入数据占一行，为2个正整数a和b，1≤a≤b≤1000。

输出描述：
输出占一行，为求得的答案。

样例输入：
8 100

样例输出：
31
*/
#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	cout << b / 3 - a / 3 + (a % 3 == 0) << endl;

	return 0;

}



