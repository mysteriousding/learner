/*
快速排序
*/
#include<iostream>
using namespace std;
#define N 1000

void sort(int a[], int b, int c)
{
	if (b >= c)return;
	int i = b, j = c;
	a[0] = a[i];
	while (i < j)
	{
		while (i < j && a[0] <= a[j])
			j--;
		a[i] = a[j];
		while (i < j && a[i] <= a[0])
			i++;
		a[j] = a[i];
	}
	a[i] =a[0];
	sort(a, b, j - 1);
	sort(a, i + 1, c);
}

int main()
{
	int n, a[N];
	cout << "请输入数据个数:" << endl;
	cin >> n;
	cout << "请依次输入数据:" << endl;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a, 1, n);
	cout << "排序结果为:" << endl;
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";

	return 0;
}