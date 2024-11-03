#include<iostream>
using namespace std;
int main()
{
	int n;
	float m, k = 0;
	cout << "N 个正数的算数平均是这些数的和除以 N，它们的调和平均是它们倒数的算数平均的倒数"<<endl;
	cout << "请先输入N，再输入N个数；";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		m = 1.0 / m;
		k += m;
	}
	k = n / k;

	cout << k << endl;


	return 0;
}

