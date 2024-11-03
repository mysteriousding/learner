#include<iostream>
using namespace std;
int main()
{
	int n;
	cout << "请输入漏斗大小:";
	cin >> n;
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i <= k; i++)
		{
			cout << " ";
		}
		for (int j = 0; j < (n - k) * 2 - 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (int k = 1; k < n; k++)
	{
		for (int i = 0; i < n - k; i++)
		{
			cout << " ";
		}
		for (int j = 0; j < k * 2 + 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}
