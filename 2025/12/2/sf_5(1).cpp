/*
1、用回溯法求解0-1背包问题。
现有n种物品，对1<=i<=n，已知第i种物品的重量为正整数Wi，价值为正整数Vi，背包能承受的最大载重量为正整数W，现要求找出这n种物品的一个子集，使得子集中物品的总重量不超过W且总价值尽量大。
（注意：这里对每种物品或者全取或者一点都不取，不允许只取一部分）。
使用回溯法使得装入背包的物品价值之和最大。
*/
#include<iostream>
using namespace std;
int n, W, w[30], v[30], nu = 0;

void dfs(int i, int cw, int cv) 
{
	if (i == n) 
	{ 
		if (nu < cv) 
			nu = cv;
		return; 
	}

	if (cw + w[i] <= W)
		dfs(i + 1, cw + w[i], cv + v[i]);

	dfs(i + 1, cw, cv);
}
int main() 
{
	cin >> n >> W;
	for (int i = 0; i < n; ++i)
		cin >> w[i] >> v[i];
	dfs(0, 0, 0);
	cout << nu << endl;

	return 0;

}




