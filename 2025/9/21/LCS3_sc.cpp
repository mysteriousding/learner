/*
LCS3_sc: 根据 DP表 回溯找到所有可能的 LCS 并输出
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

// 输出动态规划表
void sc_dp()
{
	cout << "dp: " << endl;
	for (int i = 0; i <= n.size(); i++)
	{
		for (int j = 0; j <= m.size(); j++)
			cout << dp[i][j] << "  ";
		cout << endl;
	}
}

// 单个 LCS 输出
void sc()
{
	int i = n.size(), j = m.size();
	string str;
	while (i && j)
		if (n[i - 1] == m[j - 1])
			str = n[i - 1] + str, i--, j--;
		else if (dp[i - 1][j] > dp[i][j - 1])
			i--;
		else
			j--;
	cout << "LCS: " << str << endl;
}

// 递归函数，找到所有 LCS
void LCS(int i, int j, string s)
{
	bool v = 0;
	while (i && j)
		if (n[i - 1] == m[j - 1])
			s = n[i - 1] + s, i--, j--;
		else
		{
			v = 1;
			if (dp[i - 1][j] > dp[i][j - 1])
				i--, v = 0;
			if (dp[i][j - 1] > dp[i - 1][j])
				j--, v = 0;
			if (v && dp[i - 1][j] == dp[i][j - 1])
			{
				string s1 = s;
				LCS(i - 1, j, s1);
				j--;
			}
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

	//sc_dp();

	//sc();

	LCS(n.size(), m.size(), "");
	cout << "All LCS: " << endl;
	for (const string& lcs : str)
		cout << lcs << endl;

	return 0;

}



