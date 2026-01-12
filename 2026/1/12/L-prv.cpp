/*
连通分量的个数

问题描述
给定一个有 n 个顶点和 m 条边的无向图，顶点编号为 1 到 n。
求无向图中连通分量的个数。

在无向图中，若从顶点 v 到到顶点 w 有路径存在，则称 v 和 w 是连通的。
若图中任意两个顶点都是连通的，则称该图为连通图，否则称为非连通图。
无向图中的极大连通子图称为连通分量。

无向图的极大连通子图不被无向图的其它任何一个连通子图所包含。

保证图中无自环无重边。

输入格式
第一行包含两个整数 n,m，分别表示无向图的顶点数和边数。

接下来 m 行，每行包含两个整数 u,v，表示 u 和 v 之间存在一条无向边。

输出格式
输出共一行，包含一个整数，表示连通分量的个数。

样例输入
5 4
1 2
2 3
3 1
4 5

样例输出
2

评测数据规模
1≤n≤10^5。
1≤m≤10^6。
1≤u,v≤n。
*/
#include <iostream>
#include <vector>
using namespace std;
vector<int>b;
int cz(int n)
{
    if (n != b[n])b[n] = cz(b[n]);
    return b[n];
}
int main()
{
    int n, m, u, v, ans = 0;
    cin >> n >> m;
    b.resize(n + 1);
    for (int i = 1; i <= n; i++)
        b[i] = i;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        b[cz(v)] = cz(u);
    }
    for (int i = 1; i <= n; i++)
        if (b[i] == i)ans++;
    cout << ans << endl;

    return 0;

}
