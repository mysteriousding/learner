/*
1、用优先队列式分支限界法求解单源最短路径问题。
/1.png
计算上图中从s到其他所有节点的最短路径，并分析剪枝函数的效率。
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 20;            // 最大顶点数
int n, m, s;                 // n顶点数，m边数，s起点
int dist[N];                 // dist[i]记录s→i当前最短距离
int pre[N];                  // pre[i]记录最短路中i的前驱，用于输出路径
vector<pair<int, int>> g[N]; // g[i]存i出发的边：{目标顶点,权值}

struct Node                  // 优先队列单元
{
    int u, d;                // u顶点编号，d当前路径长度
    bool operator<(const Node& x) const
    {
        return d > x.d;      // 小根堆：路径短者优先
    }
};

void dijk(int s)                // 单源最短路径
{
    priority_queue<Node> q;     // 小根堆
    for (int i = 0; i < n; ++i)
        dist[i] = 1e9, pre[i] = -1;// 初始化为“无穷”
    dist[s] = 0;                // 起点距离0
    q.push({ s, 0 });           // 起点入堆
    while (!q.empty())
    {
        Node t = q.top();       // 取当前最短路径节点
        q.pop();
        int u = t.u, d = t.d;
        if (d > dist[u])        // 剪枝：已找到更优解，跳过
            continue;
        int v, w;               // 目标顶点,边权
        for (auto& e : g[u])    // 松弛所有邻接边
        {
            v = e.first;
            w = e.second;
            if (dist[v] > d + w)// 发现更短路径
            {
                dist[v] = d + w;// 更新距离
                pre[v] = u;     // 记录前驱
                q.push({ v, dist[v] }); // 新状态入堆
            }
        }
    }
}

int main()
{
    cin >> n >> m >> s;         // 读入顶点数、边数、起点
    for (int i = 0; i < m; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;     // 读入无向边
        g[x].push_back({ y, c });
        g[y].push_back({ x, c });
    }
    dijk(s);                    // 求s为源的最短路

    int a[N], k;                // a[]临时存路径，k为路径长度
    for (int i = 0; i < n; ++i)
    {
        cout << i << " : " << dist[i] << "     "; // 输出顶点i及最短距离
        if (i == s)
        {
            cout << i << '\n';  // 起点到起点路径就是自身
            continue;
        }
        k = 0;
        for (int j = i; j != -1; j = pre[j]) // 从i倒序追到起点
            a[k++] = j;         // 将路径顶点依次存入a[]
        for (int j = k - 1; j >= 0; j--)     // 逆序输出即为正序路径
            cout << a[j] << (j ? "->" : "\n");
    }

    return 0;
}
/*
7 12 0
0 1 2
0 2 4
0 3 1
1 2 1
1 4 3
2 3 2
2 5 5
3 4 1
3 5 3
4 5 1
4 6 2
5 6 4

*/

