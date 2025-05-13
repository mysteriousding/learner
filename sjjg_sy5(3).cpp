/*
冒泡排序
*/
#include<iostream>
using namespace std;
#define N 1000

int main()
{
	int n, a[N], j, k, h;
	cout << "请输入数据个数:" << endl;
	cin >> n;
	cout << "请依次输入数据:" << endl;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	j = n;
	while (j)
	{
		k = j, j = 0;
		for (int i = 1; i < k; i++)
			if (a[i] > a[i + 1])
				h = a[i], a[i] = a[i + 1], a[i + 1] = h, j = i;
	}
	cout << "排序结果为:" << endl;
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";

	return 0;
}
