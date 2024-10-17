#include<iostream>
using namespace std;
int main()
{
	int a, b, i, j, n = 0, m, k=1;
	cout << "如果一个分数的分子和分母的最大公约数是1，这个分数称为既约分数。例如，3/4,5/2,1/8,7/1都是既约分数。\n请问有多少个既约分数,分子和分母都是1到X之间的整数（包括1和X）" << endl;
	cout << "请输入X为你计算" << endl;
	cin >> m;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= m; j++)
		{
			while (k<=i||k<=j)
			{
				a = i % k;
				b = j % k;
				if(k!=1&&a==0&&b==0)
				{
					break;
				}
				if (k >= i && k >= j)
				{
					n += 1;
				}
				k++;
			}
			k = 1;

		}
	}
	cout << "X=" << n << endl;
	cout << "计算完毕，谢谢使用！" << endl;

	return 0;
}
