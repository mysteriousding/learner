/*
3、用贪心算法解决最小生成树问题。
设G=(V,E)是一个连通带权图，E中每条边(v,w)的权为c[v][w]。
如果G的一个子图G'是一棵包含G的所有顶点的树，称G'为G的生成树。
在G的所有生成树中，各边权的总和最小的称为G的最小生成树。
利用贪心算法求解最小生成树。
*/
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
#define N 100

typedef int a3[3];          // 边类型：0起点 1终点 2权值

/* 交换两条边（用于排序） */
void jh(a3& a, a3& b)
{
    a3  h;
    h[0] = a[0];
    h[1] = a[1];
    h[2] = a[2];

    a[0] = b[0];
    a[1] = b[1];
    a[2] = b[2];

    b[0] = h[0];
    b[1] = h[1];
    b[2] = h[2];
}

/* 并查集-路径压缩 */
int ys(int d[], int n)
{
    if (n == d[n])return n;
    d[n] = ys(d, d[n]);
    return d[n];
}

/* Kruskal 最小生成树 */
void Kru(a3 b[], int d[], int n, int m)
{
    int e[N], k = 0, num = 0, h;

    /* 1. 手写选择排序：按边权升序 */
    for (int i = 0; i < m; i++)
    {
        h = b[i][2], k = i;               // 当前最小权值及下标
        for (int j = i + 1; j < m; j++)
            if (h > b[j][2])              // 找更小权值
                h = b[j][2], k = j;
        jh(b[k], b[i]);                   // 交换到第 i 位
    }

    /* 2. 并查集初始化：每个点自成一个集合 */
    for (int i = 1; i <= n; i++)
        d[i] = i;

    /* 3. 贪心加边 */
    k = 0;
    for (int j = 0; j < m; j++)
    {
        d[b[j][0]] = ys(d, d[b[j][0]]);   // 查起点根
        d[b[j][1]] = ys(d, d[b[j][1]]);   // 查终点根
        if (d[b[j][0]] != d[b[j][1]])     // 不形成环
        {
            d[d[b[j][1]]] = d[b[j][0]];   // 合并集合
            num += b[j][2];               // 累加总造价
            e[k++] = j;                   // 记录选边序号
        }
    }

    /* 4. 输出结果 */
    cout << "最低为:" << endl;
    cout << num << endl;
    cout << "线路为:" << endl;
    for (int i = 0; i < k; i++)
        cout << b[e[i]][0] << " " << b[e[i]][1] << " " << b[e[i]][2] << " " << endl;
}

/* 主函数：读边 -> 跑 Kruskal */
int main()
{
    int d[N], n, m;
    a3 b[N];
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> b[i][0] >> b[i][1] >> b[i][2];
    Kru(b, d, n, m);

    return 0;

}




