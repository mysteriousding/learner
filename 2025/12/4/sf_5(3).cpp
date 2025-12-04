/*
3、给定无向图G=(V,E)，其中V是非空集合，称为顶点集；E是V中元素构成的无序二元组的集合，称为边集，无向图中的边均是顶点的无序对，无序对常用圆括号“( )”表示。
如果UV，且对任意两个顶点u，v∈U有(u,v)∈E，则称U是G的完全子图。
G的完全子图U是G的团。G的最大团是指G的最大完全子图。
最大团问题（Maximum Clique Problem, MCP）又称为最大独立集问题（Maximum Independent Set Problem）,使用回溯法求解图1的最大团。

图1 无向图G
*/
#include<iostream>
using namespace std;
int n, g[20][20], b[20], best = 0; // n顶点数，g邻接矩阵，vis标记是否已选，best记录最大团大小

bool ok(int u)                     // 检查顶点u能否加入当前团
{
	for (int i = 0; i < u; i++)    // 只需看编号小于u的已选顶点
		if (b[i] && !g[i][u])      // 若已选顶点i与u无边，则u不能加入
			return 0;
	return 1;                      // 所有已选顶点都与u相邻，可加入
}

void dfs(int u, int sz)            // u当前顶点编号，sz当前团大小
{
	if (u == n)                    // 所有顶点尝试完毕
	{
		best = max(best, sz);      // 更新最大团
		return;
	}
	if (ok(u))                     // 若u可加入团
	{
		b[u] = 1;                  // 选u
		dfs(u + 1, sz + 1);        // 递归下一个顶点
		b[u] = 0;                  // 回溯撤销选u
	}
	if (sz + n - u > best)         // 剪枝：即使剩下全选也无法超best则不再递归
		dfs(u + 1, sz);            // 不选u，直接递归下一个顶点
}

int main()
{
	n = 5;                                 // 图1共5个顶点
	int eg[7][2] = { {0,1},{0,2},{0,3},{1,2},{1,3},{2,3},{2,4} }; // 图1的边
	memset(g, 0, sizeof g);                // 初始化邻接矩阵
	for (auto& e : eg)                     // 无向图双向置1
		g[e[0]][e[1]] = g[e[1]][e[0]] = 1;
	dfs(0, 0);                             // 从顶点0开始，当前团大小0
	cout << "最大团大小:" << best << endl; // 输出最大团大小

	return 0;

}



