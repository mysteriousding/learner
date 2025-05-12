/*
希尔排序
*/
#include<iostream>
using namespace std;
#define N 1000

int main()
{
	int n, a[N], j, k;
	cout << "请输入数据个数:" << endl;
	cin >> n;
	cout << "请依次输入数据:" << endl;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	k = n / 4 + 1;
	while (k)
	{
		for (int i = 1; i <= n; i++)
		{
			a[0] = a[i];
			j = i - k;
			while (j > 0 && a[j] > a[0])
				a[j + k] = a[j], j -= k;
			a[j + k] = a[0];
		}
		k /= 2;
	}
	cout << "排序结果为:" << endl;
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";

	return 0;
}
