/*
LCS2: 记忆化搜索 计算最长公共子序列的长度
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string n, m;
vector<vector<int>>arr;
int u = 0;

// 递归函数，计算 n 的前 a 个字符和 m 的前 b 个字符的 LCS 长度
int dfs(int a, int b)
{
	u++;
	if (arr[a][b])
		return arr[a][b];
	int num;
	if (a == 0 || b == 0)
		num = 0;
	else
	{
		if (n[a - 1] == m[b - 1])
			num = dfs(a - 1, b - 1) + 1;
		else
			num = max(dfs(a, b - 1), dfs(a - 1, b));
	}
	arr[a][b] = num;
	return num;
}

int main()
{
	int num;
	cin >> n >> m;
	arr.resize(n.size() + 1, vector<int>(m.size() + 1));
	num = dfs(n.size(), m.size());
	cout << "LCS Length: " << num << endl;
	cout << "递归次数: " << u << endl;

	return 0;

}




