#include<iostream>
using namespace std;
int main()
{
	int a, b, n = 0, m, i = 1, i0;
	cin >> m;
	while(i<=m)
	{
		i0 = i;
		while (true)
		{
			b = i % 10;
			i /= 10;
			if (b == 2)
			{
				n += 1;
			}
			if (i == 0)
			{
				break;
			}
		}
		i = i0;
		i++;
	}
	cout << n << endl;

	return 0;
}
