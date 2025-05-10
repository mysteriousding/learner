/*
编程实现折半查找的非递归算法；
*/
#include<iostream>
using namespace std;
#define N 1000
int main()
{
	int a[N], n, m, q, p, k, b = 0;
	cout << "请输入数据个数：" << endl;
	cin >> n;
	cout << "请依次输入数据：(自动排序)" << endl;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++)
	{
		a[0]=a[i],k = i;
		for (int j = i + 1; j <= n; j++)
			if (a[0] > a[j])
				a[0] = a[j], k = j;
		a[k] = a[i], a[i] = a[0];
	}
	cout << "请输入查找的值：" << endl;
	cin >> m;
	a[0] = -1, q = 1, p = n;
	while (q <= p)
	{
		b++;
		k = (q + p) / 2;
		if (a[k] == m)
		{
			a[0] = k;
			break;
		}
		else if (a[k] > m) p = k - 1;
		else q = k + 1;
	}
	cout << "共查询" << b << "次，";
	if (a[0] != -1) cout << m << "位于第" << a[0] << "位" << endl;
	else cout << "该值不存在！" << endl;

	return 0;
}
