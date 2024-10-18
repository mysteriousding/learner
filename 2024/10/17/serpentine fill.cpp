#include<iostream>
using namespace std;
int main()
{
	int a = 0, b, c, i, j, n, m;
	cout << "如下图所示，小明用从1开始的正整数“蛇形”填充无限大的矩阵。\n容易看出矩阵第二行第二列中的数是5。请你计算矩阵中第20行第20列的数是多少？\n1 2 6 7 15 …\n3 5 8 14 …\n4 9 13 …\n10 12 …\n11 …" << endl;
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
