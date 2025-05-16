/*
堆排序
*/
#include<iostream>
using namespace std;
#define N 1000

void sf(int a[], int m)
{
	while (m > 1)
	{
		if (a[m] > a[m / 2])
			a[0] = a[m], a[m] = a[m / 2], a[m / 2] = a[0];
		else return;
		m /= 2;
	}
}

void xc(int a[], int n, int m)
{
	int i;
	while (m * 2 <= n)
	{
		i = m * 2;
		if (i + 1 <= n)
			if (a[i] < a[i + 1])
				i++;
		if (a[m] < a[i])
			a[0] = a[m], a[m] = a[i], a[i] = a[0];
		else return;
		m = i;
	}
}

void jl(int a[],int n)
{
	for (int i = n / 2; i > 0; i--)
		xc(a, n, i);
}

void cr(int a[], int& n, int m)
{
	a[++n] = m;
	sf(a, n);
}

int main()
{
	int n, a[N];
	cout << "请输入数据个数:" << endl;
	cin >> n;
	cout << "请依次输入数据:" << endl;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	jl(a, n);
	for (int i = n; i > 1; i--)
	{
		a[0] = a[i], a[i] = a[1], a[1] = a[0];
		xc(a, i - 1, 1);
	}
	cout << "排序结果为:" << endl;
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";

	return 0;
}
