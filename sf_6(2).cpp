/*
2、用优先队列式分支限界法求解0-1背包问题。
给定n种物品和一背包。物品i的重量是wi，其价值为vi，背包的容量为C。
试用优先队列分支限界法求解如何选择装入背包的物品，使得装入背包中物品的总价值最大?
0-1背包问题是一个特殊的整数规划问题。0-1背包问题的解空间树是子集树。
*/
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 1010;             // 最大物品数
int n, C;                       // n物品数，C背包容量
int w[N], v[N];                 // w重量，v价值
int best = 0;                   // 当前最优总价值
int id[N];                      // id[i]排序后第i件物品的原始编号

struct Nd                       // 分支限界节点
{
    int val;                    // 已得价值
    int wei;                    // 已用重量
    int id;                     // 待决策物品序号（排序后）
    int ub;                     // 上界（可能达到的最大价值）
    bool operator<(const Nd& x) const
    {
        return ub < x.ub;       // 最大堆：上界大者优先扩展
    }
};

// 计算上界：剩余容量按单位价值贪心装（允许“假切割”仅用于估值）
int bd(int val, int wei, int i)
{
    int left = C - wei;         // 剩余容量
    if (left < 0) return -1;    // 超重，无效
    int up = val;               // 初始上界
    // 整件整件装
    while (i <= n && left >= w[id[i]])
    {
        left -= w[id[i]];
        up += v[id[i]];
        i++;
    }
    // 剩余容量不足一件时，假装可以切割一小块（仅估值，实际不切割）
    if (i <= n) up += v[id[i]] * left / w[id[i]];
    return up;
}

// 按单位重量价值降序排序的比较函数
bool cmp(int a, int b)
{
    return v[a] * w[b] > v[b] * w[a];
}

// 优先队列式分支限界主过程
void solve()
{
    priority_queue<Nd> q;       // 最大堆
    q.push({ 0, 0, 1, bd(0, 0, 1) }); // 初始节点：价值0，重量0，从第1件开始
    while (!q.empty())
    {
        Nd c = q.top(); q.pop(); // 取上界最大的节点
        int i = c.id;            // 当前待决策物品序号
        if (i > n)               // 已到达叶子，所有物品决策完毕
        {
            best = c.val;        // 此时必为最优，可提前终止
            break;
        }
        if (c.ub <= best) continue; // 剪枝：上界不优于当前最优

        // 左分支：选物品 id[i]（必须整件）
        if (c.wei + w[id[i]] <= C)
        {
            int nv = c.val + v[id[i]]; // 新价值
            int nw = c.wei + w[id[i]]; // 新重量
            best = max(best, nv);      // 更新全局最优
            int ub = bd(nv, nw, i + 1); // 计算新上界
            if (ub > best) q.push({ nv, nw, i + 1, ub });
        }

        // 右分支：不选物品 id[i]
        int ub = bd(c.val, c.wei, i + 1); // 不选，直接计算上界
        if (ub > best) q.push({ c.val, c.wei, i + 1, ub });
    }
}

int main()
{
    cin >> n >> C;              // 读物品数、背包容量
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i], id[i] = i; // 读重量、价值，并记录原始编号
    sort(id + 1, id + n + 1, cmp); // 按单位重量价值降序排序
    solve();                    // 执行分支限界
    cout << best << endl;       // 输出最优总价值

    return 0;
}