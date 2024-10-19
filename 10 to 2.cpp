#include<iostream>
using namespace std;
int main()
{
	int a, b, c, i = 0;
	cout << "请输入一个十进制数，让我为你将他转化为二进制。" << endl;
	cin >> a;
	c = a;
	int arr[10];
	for (i;; i++)
	{
		b = a % 2;
		a /= 2;
		arr[i] = b;

		if (a == 0)break;
	}
	a = c;
	cout << endl << a << "的二进制=";
	for (; i >= 0; i--)
	{
		cout << arr[i];
	}
	cout << endl;

	return 0;
}