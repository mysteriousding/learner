/*
最小生成树

问题描述
给定一个包含  n 个顶点和 m 条边的无向图。
图中可能存在重边和自环，且边的权值可能为负数。
你需要求出最小生成树（MST）的边权重之和。
如果无法构造最小生成树，则输出 "impossible"。

最小生成树：在一个无向图中，由 n 个顶点和 n−1 条边构成的连通子图，且该子图的边权重之和最小。

如果图不连通，无法形成最小生成树。

输入格式
第一行输入二个正整数 n,m。

接下来 m 行，每行输入 3 个正整数 a,b,c。
表示点 a 到点 b 存在一条无向边，权值为 c。

2≤n≤500,1≤m≤10^5,1≤a,b≤n,1≤c≤10^4。

输出格式
输出一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出 "impossible"。

样例输入
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4

样例输出
6
*/
#include <iostream>
#include<vector>
using namespace std;
struct V
{
    bool l = 0;
    int f;
};
struct E
{
    int c;
    int r;
    int q;
};
int main()
{
    int n, m, min, k, sum = 0;
    cin >> n >> m;
    vector<V>v(n + 1);
    vector<E>e(m);
    E h;
    for (int i = 0; i < m; i++)
        cin >> e[i].c >> e[i].r >> e[i].q;
    for (int i = 0; i < m; i++)
    {
        min = e[i].q, k = i;
        for (int j = i; j < m; j++)
            if (min > e[j].q)
                min = e[j].q, k = j;
        h = e[i], e[i] = e[k], e[k] = h;
    }
    k = 1;
    for (int i = 0; i < m; i++)
    {
        if (!v[e[i].c].l && !v[e[i].r].l && e[i].c != e[i].r)
        {
            sum += e[i].q;
            v[e[i].r].l = v[e[i].c].l = 1;
            v[e[i].r].f = v[e[i].c].f = k++;
        }
        else if ((v[e[i].c].l && !v[e[i].r].l) || (!v[e[i].c].l && v[e[i].r].l))
        {
            sum += e[i].q;
            if (v[e[i].c].l)v[e[i].r].l = 1, v[e[i].r].f = v[e[i].c].f;
            else v[e[i].c].l = 1, v[e[i].c].f = v[e[i].r].f;
        }
        else
        {
            if (v[e[i].c].f == v[e[i].r].f)continue;
            sum += e[i].q;
            int p = v[e[i].r].f;
            for (int j = 1; j <= n; j++)
                if (v[j].l && v[j].f == p)
                    v[j].f = v[e[i].c].f;
        }
    }
    k = v[e[0].c].f;
    for (int i = 1; i <= n; i++)
        if (!v[i].l || v[i].f != k)
        {
            cout << "impossible" << endl;
            return 0;
        }
    cout << sum << endl;

    return 0;
}