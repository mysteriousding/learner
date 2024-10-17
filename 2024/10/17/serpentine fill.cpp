#include<iostream>
using namespace std;
int main()
{
	int a = 0, b, c, i, j, n, m;
	cin >> m;
	for (j = 0; j <= m - 1; j++)
	{
		n = (m - 1) - j;
		if (j % 2 == 1) { a += 2 * j; }
		   else
		   {
			   a += 1;
		   }
		b = a;
		cout << a << "\t";
		for (i = 1; i <= n; i++)
		{
			if (j % 2 == 0)
			{
				if (i % 2 == 1) { a += j * 2 + 1; }
				   else
				   {
					   a += 2 * i;
				   }
			}
			else
			{
				if (i % 2 == 0) { a += j * 2 + 1; }
				else
				{
					a += i * 2;
				}
			}
			cout << a << "\t";
		}
		a = b;
		cout << endl;
		n--;
	}
	/*cout << "\n\n\n" << c << endl;*/


	return 0;
}
