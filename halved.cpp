#include<iostream>
using namespace std;
int main()
{
	int a[100];
	int j, n, m, b, c, d, e;
	j = n = m = b = c = d = e = 0;

	for (int i = 0; i < 100; i++)
	{
		a[i] = i;
		if (i % 2 == 0)
		{
			a[j] = a[i];
			j += 1;
			if (j % 2 == 0)
			{
				a[n] = a[j];
				n += 1;
				if (n % 2 == 0)
				{
					a[m] = a[n];
					m += 1;
					if (m % 2 == 0)
					{
						a[b] = a[m];
						b += 1;
						if (b % 2 == 0)
						{
							a[c] = a[b];
							c += 1;
							if (c % 2 == 0)
							{
								a[d] = a[c];
								d += 1;
								if (d % 2 == 0)
								{
									a[e] = a[d];
									e += 1;

								}
							}
						}
					}
				}
			}
		}
	}

	cout << a[0] << endl;

	return 0;
}