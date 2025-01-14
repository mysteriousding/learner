/*
密文搜索

题目描述
福尔摩斯从 X 星收到一份资料，全部是小写字母组成。

他的助手提供了另一份资料：许多长度为 8 的密码列表。

福尔摩斯发现，这些密码是被打乱后隐藏在先前那份资料中的。

请你编写一个程序，从第一份资料中搜索可能隐藏密码的位置。要考虑密码的所有排列可能性。

输入描述
输入第一行：一个字符串s，全部由小写字母组成，长度小于 1024*1024。

紧接着一行是一个整数n,表示以下有n 行密码，1≤n≤1000。

紧接着是n 行字符串，都是小写字母组成，长度都为 8。

输出描述
输出一个整数, 表示每行密码的所有排列在 s 中匹配次数的总和。

输入输出样例
示例
输入

aaaabbbbaabbcccc
2
aaaabbbb
abcabccc

输出

4
*/
#include <iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int n, j, sum = 0;
	string m;
	getline(cin, m);
	cin >> n;
	cin.ignore();
	vector<string>N(n);
	vector<int[26]>M(n + 1);
	for (int i = 0; i < n; i++)
	{
		j = 0;
		getline(cin, N[i]);
		while (N[i][j] != '\0')
			M[i][N[i][j++] - 'a']++;
	}

	int h = 0;
	j = 0;
	while (j < 8)
		M[n][m[j++] - 'a']++;
	while (m[j - 1] != '\0')
	{
		for (int i = 0; i < n; i++)
		{
			bool u = 1;
			for (int k = 0; k < 26; k++)
				if (M[i][k] != M[n][k]) { u = 0; break; }
			if (u)sum++;
		}
		if (m[j] == '\0')break;
		M[n][m[h++] - 'a']--;
		M[n][m[j++] - 'a']++;
	}

	cout << sum << endl;

	return 0;
}
