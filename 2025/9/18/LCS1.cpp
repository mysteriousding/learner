/*
LCS1: 暴力递归 计算最长公共子序列的长度
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string n, m;
int u = 0;

// 递归函数，计算 n 的前 a 个字符和 m 的前 b 个字符的 LCS 长度
int dfs(int a, int b)
{
	u++;
	if (a == 0 || b == 0)
		return 0;
	if (n[a - 1] == m[b - 1])
		return  dfs(a - 1, b - 1) + 1;
	else
		return max(dfs(a, b - 1), dfs(a - 1, b));
}

int main()
{
	int num;
	cin >> n >> m;
	num = dfs(n.size(), m.size());
	cout << "LCS Length: " << num << endl;
	cout << "递归次数: " << u << endl;

	return 0;

}






