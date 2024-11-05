#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	cout << "把整数从中剪开分为两个数(若位数为奇数则中间位分两次），此时再将这两数之和平方，计算结果又等于原数。这样的数叫“雷劈数”,如:\n(30 + 25) * (30 + 25) = 55 * 55 = 3025" << endl;
	cout << "请输入一个数X，让我为你找出0 - X的所有雷劈数" << endl;
	int n,k0,l,p1,p2;
	cin >> n;
	
	for (int k = 0; k <= n; k++)
	{
		k0 = k;
		for (l = 1;; l++)
		{
			k /= 10;
			if (k == 0)break;
		}
		if (l % 2 == 0)
		{
			p1 = p2 = pow(10, l / 2);
		}
		else
		{
			p1 = pow(10, l / 2);
			p2 = pow(10, l / 2 + 1);
		}
		k = k0;

		int i = k / p1;
		int j = k % p2;
		if (pow((i + j), 2) == k)cout << k << " ";
	}

	return 0;
}
