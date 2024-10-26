#include<iostream>      //三角形
using namespace std;
int main()
{
	int n;
moon:
	cin >> n;      //上限133
	for (int i = 1; i <= n; i++)
	{
		for (int j = n + 1 - i; 0 < j; j--)
		{
			cout << " ";
		}
		for (int k = 2 * i - 1; 0 < k; k--)
		{
			cout << "*";
		}
		cout << endl;
	}

	goto moon;

	return 0;
}
