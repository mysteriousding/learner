/*
直接插入排序
*/
#include<iostream>
using namespace std;
#define N 1000
int main()
{
	int n, a[N], j;
	cout << "请输入数据个数:" << endl;
	cin >> n;
	cout << "请依次输入数据:" << endl;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int i = 2;
	for(int i=2;i<=n;i++)
	{
		a[0] = a[i];
		j = i - 1;
		while (j && a[j] > a[0])
			a[j + 1] = a[j], j--;
				
		a[j + 1] = a[0];
	}
	cout << "排序结果为:" << endl;
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";

	return 0;
}