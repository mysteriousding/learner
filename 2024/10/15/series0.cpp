/*
#include<iostream>
using namespace std;
int main()
{
	int a, b, c, a0, b0, c0, n = 3, m;
	a = b = c = 1;
	cin >> m;
	while (true)
	{
		a0 = a%10000; b0 = b%10000; c0 = c%10000;
		a = b0; b = c0; c = a0;

		a = a + b + c;
		n++;
		if(n==m)
		{
			break;
		}
	}
	cout << a % 10000 << endl;

	return 0;
*/

#include<iostream>
using namespace std;
int main()
{
	int a, b, c, a0, b0, c0, n = 3, m;
	a = b = c = 1;
	cout << "给定数列1,1,1,3,5,9,17,…，从第4项开始，每项都是前3项的和。求第X项的最后4位数字。" << endl;
	cout << "请输入X为你计算" << endl;
	cin >> m;
	while (true)
	{
		a0 = a % 10000; b0 = b % 10000; c0 = c % 10000;
		a = b0; b = c0; c = a0;

		a = a + b + c;
		n++;
		if (n == m)
		{
			break;
		}
	}
	cout << "X=" << a % 10000 << endl;
	cout << "计算完毕，谢谢使用！" << endl;

	return 0;
}
