#include<iostream>
using namespace std;
int main()
{
	int a, b, c, a0, b0, c0, n = 3, m;
	a = b = c = 1;
	cin >> m;
	while (true)
	{
		a0 = a%10000; b0 = b%10000; c0 = c%10000;
		a = b0; b = c0; c = a0;

		a = a + b + c;
		n++;
		if(n==m)
		{
			break;
		}
	}
	cout << a % 10000 << endl;

	return 0;
}
