/*
直接选择排序
*/
#include<iostream>
using namespace std;
#define N 1000

int main()
{
	int n, a[N], k, h;
	cout << "请输入数据个数:" << endl;
	cin >> n;
	cout << "请依次输入数据:" << endl;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++)
	{
		h = a[i], k = i;
		for (int j = i + 1; j <= n; j++)
			if (h > a[j])
				h = a[j], k = j;
		a[k] = a[i], a[i] = h;
	}
	cout << "排序结果为:" << endl;
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";

	return 0;
}
