/*
Problem F. 23 子序列
Input file:
Output file:
standard input
standard output
定义一个序列b=(b1,b2,...,bm) 是好的，当且仅当对于每一个i=2,3,...,m，都有
2 · bi−1 ≤ bi ≤ 3·bi−1.
特别地，长度为1的序列总是好的。
现在给定一个长度为n的正整数序列a=(a1,a2,...,an)。你需要回答q 次询问，每次询问给出一个区
间[l,r]（1 ≤ l ≤ r ≤ n），请找出在子序列al,al+1,...,ar 中（保持原顺序），最长的好的子序列的长
度。
注意：子序列不一定是连续的，但必须保持原序列中的相对顺序。
Input
第一行两个整数n,q，分别表示序列长度和询问次数。
第二行n个整数a1,a2,...,an。
接下来q 行，每行两个整数l,r，表示一次询问的区间。
Output
输出q 行，每行一个整数，依次为每个询问的答案。
Example
standard input
5 4
1 2 4 6 17
1 3
2 4
1 5
1 4
3
2
4
3
standard output
Note
1 ≤n,q ≤2×105，1≤ai ≤1018，对于每次询问，1≤l≤r≤n。
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n, t, x, y;
	long long b, c;
	cin >> n >> t;
	vector<long long>a(n);
	vector<int>m(n, 0);
	vector<vector<int>>dp(n - 1);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (i)
			dp[i - 1].resize(n - i);
	}
	for (int i = 0; i < n - 1; i++)
    {
        b = a[i] * 2, c = b + a[i];
        for (int j = i; j < n - 1; j++)
			if (a[j + 1] >= b && a[j + 1] <= c)
			{
				dp[i][j - i] = m[i] + 1;
				if (dp[i][j - i] > m[j + 1])
					m[j + 1] = dp[i][j - i];
			}
    }
	while (t--)
	{
		cin >> x >> y;
		cout << m[y - 1] - m[x - 1] + 1 << endl;
	}

	return 0;
}
