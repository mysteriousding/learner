/*
一本书的页码从自然数l开始顺序编码直到自然数n。
书的页码按照通常的习惯编排，每个页码都不含多余的前导数字0。
例如，第6页用数字6表示，而不是06或006等。
数字计数问题要求对给定书的总页码n，计算出书的全部页码中分别用到多少次数字0,1，2，…，9。

★编程任务：
给定表示书的总页码的十进制整数n(1≤n≤109)。
编程计算书的全部页码中分别用到多少次的数字0,1,2,3,4,5,6,7,8,9。
*/
#include<iostream>
using namespace std;

void yz(int n)
{
	int arr[10] = { 0 },x,p=1;
	for (int i = 1; i <= n; i++)
	{
		x = i;
		while (x)
			arr[x % 10]++, x /= 10;
	}
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void zs(int n)
{
	int arr[10][10] = { 0 }, x;
	
	for (int i = 1; i <= n; i++)
	{
		x = i;
		for (int j = 0; x; j++)
			arr[j][x % 10]++, x /= 10;
	}
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
	cout << endl << endl;

}

int main()
{
	int n, arr[11] = { 0 }, x = 1, y, z, p = 1;
	cin >> n;

	//zs(n);
	//yz(n);
	while (x)
	{
		x = n / 10 / p;
		y = n % p;
		z = n / p % 10;

		if (z)
		{
			arr[1] += (x + 1) * p;
			arr[z] += y + 1 - p;
			arr[z + 1] -= y + 1;
			arr[10] -= x * p;
			arr[0] += x * p;
		}
		else
		{
			arr[1] += x * p;
			arr[10] -= x * p;
			arr[0] +=  (x - 1) * p + y + 1;
		}

		p *= 10;
	}
	for (int i = 0; i < 10; i++)
	{
		if (i)arr[i + 1] += arr[i];
		cout << arr[i] << "\t";
	}


	return 0;

}




