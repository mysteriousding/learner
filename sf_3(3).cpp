/*
⒊用代码实现最长公共子序列问题
*/
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
string n, m;
vector<vector<int>>dp;
set<string>str;

// 递归函数，找到所有 LCS
void LCS(int i, int j, string s)
{
	//bool v = 0;
	while (i && j)
		if (n[i - 1] == m[j - 1])
			s = n[i - 1] + s, i--, j--;
		else
		{
			if (dp[i - 1][j] == dp[i][j - 1])
			{
				string s1 = s;
				LCS(i - 1, j, s1);
				j--;
			}
			else if (dp[i - 1][j] > dp[i][j - 1])
				i--;
			else j--;
		}
	str.insert(s);
}

int main()
{
	cin >> n >> m;
	dp.resize(n.size() + 1, vector<int>(m.size() + 1, 0));
	for (int i = 1; i <= n.size(); i++)
		for (int j = 1; j <= m.size(); j++)
		{
			if (n[i - 1] == m[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	cout << "LCS Length: " << dp[n.size()][m.size()] << endl;

	LCS(n.size(), m.size(), "");
	cout << "All LCS: " << endl;
	for (const string& lcs : str)
		cout << lcs << endl;

	return 0;

}
