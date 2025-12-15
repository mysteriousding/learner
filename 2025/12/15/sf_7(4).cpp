/*
4、以TSP问题为例，设计并实现程序，对比回溯法与分支限界法在解决问题的顺序上的不同，并对比两者的优劣。
*/
#include <iostream>
#include <vector>
#include <queue>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace chrono;

const int N = 15, INF = 0x3f3f3f3f;
int n, g[N][N], best = INF;

//---------- 回溯 ----------
void dfs(int u, int cnt, int cost, int vis[])
{
    if (cnt == n) { best = min(best, cost + g[u][0]); return; }
    for (int v = 0; v < n; v++)
        if (!vis[v] && g[u][v] < INF)
        {
            vis[v] = 1;
            dfs(v, cnt + 1, cost + g[u][v], vis);
            vis[v] = 0;
        }
}

//---------- 分支限界 ----------
struct Node {
    int u, cnt, cost, vis;
    bool operator<(const Node& x) const { return cost > x.cost; }
};
void bb()
{
    priority_queue<Node> q;
    q.push({ 0, 1, 0, 1 });
    while (!q.empty())
    {
        Node c = q.top(); q.pop();
        if (c.cnt == n) { best = min(best, c.cost + g[c.u][0]); continue; }
        for (int v = 0; v < n; v++)
            if (!(c.vis >> v & 1) && g[c.u][v] < INF)
                q.push({ v, c.cnt + 1, c.cost + g[c.u][v], c.vis | 1 << v });
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> g[i][j];

    auto t1 = high_resolution_clock::now();
    int vis[N]{};
    vis[0] = 1;
    dfs(0, 1, 0, vis);
    auto t2 = high_resolution_clock::now();
    auto d1 = duration_cast<microseconds>(t2 - t1).count();

    best = INF;
    auto t3 = high_resolution_clock::now();
    bb();
    auto t4 = high_resolution_clock::now();
    auto d2 = duration_cast<microseconds>(t4 - t3).count();

    cout << "backtrack " << best << "  time: " << d1 << "us\n";
    cout << "branchBnd " << best << "  time: " << d2 << "us\n";

    return 0;
}
/*
5
0 14 4 10 20
14 0 7 8 7
4 5 0 7 16
11 7 9 0 2
18 7 17 4 0

*/
