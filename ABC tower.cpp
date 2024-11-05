#include<iostream>
using namespace std;
int main()
{
	int n;
	cout << "输入一个 <=26 的数，将因此绘制字母塔。" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - i; j >= 0; j--)
		{
			cout << " ";
		}

		for (int j = i; j > 0; j--)
		{
			cout << (char)(j + 65);
		}

		for (int j = 0; j < i+1; j++)
		{
			cout << (char)(j + 65);
		}

		cout << endl;
	}
	

	return 0;
}