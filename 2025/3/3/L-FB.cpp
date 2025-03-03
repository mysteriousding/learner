/*
Fizz Buzz 经典问题

题目描述
给定一个整数 N，请按照下面的规则返回：

如果这个数被 3 整除，返回 Fizz。
如果这个数被 5 整除，返回 Buzz
如果这个数能同时被 3 和 5 整除，返回 FizzBuzz。
如果这个数既不能被 3 也不能被 5 整除，返回这个数字。
输入描述
输入 N，1<N≤10^4 .

输出描述
输出一行，如题干所述。

输入输出样例
示例

输入
15

输出
FizzBuzz
*/
#include <iostream>
using namespace std;
int main()
{
	int n;
	bool a, b;
	cin >> n;
	a = n % 3, b = n % 5;
	if (!a)cout << "Fizz";
	if (!b)cout << "Buzz";
	if (a && b)cout << n;

	return 0;
}
