/*
The 2025 ICPC Asia East Continent Online Contest (II)
F. Square Permutation I
 Statement
 Languages
 Submit
 Custom Test
 Attachments
 Discussions & Issues
Back to the contest
 您正在使用简体中文查看此题目。您可以在个人设置中将简体中文设为默认语言。
 AI Translation — This statement was translated using AI and may contain inaccuracies. Please refer to the original statement if in doubt.×
给定两个长度为
 的排列
 和
。保证
 是一个奇数。对于每个位置
，你必须恰好执行以下操作之一：

不执行任何操作，代价为
。
花费
 的代价，将
 修改为
 或将
 修改为
。
花费
 的代价，同时将
 修改为
 且将
 修改为
。
请计算使数组
 的中位数等于
 且数组
 的中位数等于
 所需的最小代价。如果无法做到，输出
。

输入格式
每个测试点包含多个测试用例。第一行包含测试用例的数量 t(1<=t<=10^4)。接下来是测试用例的描述。

每个测试用例的第一行包含三个整数 n,A,B(1<=n<=10^5,1<=A,B<=n^2)。

第二行包含 n 个正整数，表示排列 p。

第三行包含 n 个正整数，表示排列 q。

第四行包含 n 个正整数，表示数组 x。

第五行包含 n 个正整数，表示数组 y(1<=xi<=yi<=10^4)。

保证所有测试用例中 n 的总和不超过 10^5。

输出格式
对于每个测试用例，如果无法做到，输出 -1。

否则，输出最小代价。

每个输出必须独占一行。

样例
输入样例 1
3
7 6 7
7 3 5 6 2 4 1
1 6 3 4 2 7 5
5 1 1 4 4 1 1
6 4 6 6 6 1 1
9 5 5
1 2 3 4 5 6 7 8 9
9 8 7 6 5 4 3 2 1
1 2 3 4 5 6 7 8 9
2 3 4 5 6 7 8 9 9
3 2 3
1 2 3
2 3 1
10000 1 1
10000 1 1

输出样例 1
7
0
10000
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>a, b, x, y;
vector<bool>ai, bi;
int n, A, B,m;
int dfs(int s, int d,int k, int f)
{
	if (s == 0 && d == 0)
		return f;
	int sum;
	for(int i=k;i<n;i++)
		if (s&&!ai[i])
		{
			
		}
}
int main()
{
	int t;
	while (t--)
	{
		int h[2] = { 0 };
		bool u[2] = { 0 }, v[2] = { 0 };
		cin >> n >> A >> B;
		a.resize(n);
		b.resize(n);
		x.resize(n);
		y.resize(n);
		ai.resize(n,0);
		bi.resize(n,0);
		m = 1e9;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] == A)
				u[0] = 1;
			else if (a[i] * a[i] == A)
				v[0] = 1;
			ai[i] = a[i] > A;
			h[0] += ai[i];
		}
		if (h[0] <= n / 2 && (u[0] || v[0]))
		{
			for (int i = 0; i < n; i++)
			{
				cin >> b[i];
				if (b[i] == B)
					u[1] = 1;
				else if (b[i] * b[i] == B)
					v[1] = 1;
				bi[i] = b[i] > B;
				h[1] += bi[i];
			}
			if (h[1] <= n / 2 && (u[1] || v[1]))
			{
				for (int i = 0; i < n; i++)
					cin >> x[i];
				for (int i = 0; i < n; i++)
					cin >> y[i];

			}
			else
				cout << -1 << endl;

		}
		else
			cout << -1 << endl;
	}

	return 0;
}
