/*
 奇数求和

问题描述
乐乐得到两个整数 A 和 B。
计算区间 [A,B] 中有奇数个约数的数字数量。

输入格式
第一行包含两个整数 A 和 B。

输出格式
输出一个整数，表示具有奇数个约数的值的数量。

样例输入
1 10

样例输出
3

评测数据规模
1≤A≤B≤1000。
*/
#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	cout << int(sqrt(b)) - int(sqrt(a - 1)) << endl;

	return 0;
}