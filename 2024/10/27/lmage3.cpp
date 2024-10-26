/*
#include<iostream>          //77
using namespace std;
int main()
{
	int n;
moon:
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cout << "     ";
		for (int j = 1; j <= 2.1 * n; j++)
		{
			if ((int)(n / 4.0 + 0.5) < i && i <= (int)(3 * n / 4.0+0.49))
			{
				if (j <= (int)(n / 2.0 + 0.5) || j >= (int)(3 * n / 2.0+1)) { cout << "*"; }
				   else { cout << " "; }
		    }
			   else { cout << "*"; };
		}
		cout << endl;
	}
	goto moon;

	return 0;
}
*/

#include<iostream>          //77
using namespace std;
int main()
{
	int n, x, y, x0, y0;
moon:
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "     ";
		for (int j = 1; j <= 2 * n; j++)
		{
			if (n % 4 == 2 || n % 4 == 3) { x = n / 4 + 1; }
			   else { x = n / 4; }
			if ( n % 4 == 1) { y = 3 * n / 4 + 2; }
			   else { y = 3 * n / 4 + 1; }
			if (x < i && i < y)
			{
				if (n % 2 == 1 || n % 2 == 3) { x0 = n / 2 + 1; }         //(2.1*/4)替换(n / 2)
				   else { x0 = n / 2; }
				y0 = 3 * n / 2 + 1;
				if (j <= x0 || y0 <= j) { cout << "*"; }
				   else { cout << " "; }
			}
			   else { cout << "*"; };
		}
		cout << endl;
	}
	goto moon;

	return 0;
}
