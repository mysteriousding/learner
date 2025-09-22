/*
LCS4: 动态规划空间优化 计算最长公共子序列的长度
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string n, m;
	cin >> n >> m;
	int x, y;
	vector<int>dp(m.size() + 1, 0);
	for (int i = 1; i <= n.size(); i++)
	{
		x = 0;
		for (int j = 1; j <= m.size(); j++)
		{
			if (n[i - 1] == m[j - 1])
				dp[j] = dp[j - 1] + 1;
			else
			{
				y = dp[j];
				dp[j] = max(x, dp[j]);
				x = y;
			}
		}
	}
	cout << "LCS Length: " << dp[m.size()] << endl;

	return 0;

}




