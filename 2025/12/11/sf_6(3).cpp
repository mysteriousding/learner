/*
3、用队列式分支限界法求解装载问题
有一批共n个集装箱要装上2艘载重量分别为c1和c2的轮船，其中集装箱i的重量为wi，且装船的集装箱总重量之和小于等于c1+c2。
装载问题实质是要求第1艘船的最优装载。
利用队列式分支限界给出合理的装载方案，并通过最优值求出最优解。
*/
#include <iostream>
#include <queue>
using namespace std;

const int N = 1010;      // 最大物品数
int n, c1, c2;           // n物品数，c1船1容量，c2船2容量
int w[N];                // w[i]物品i重量
int bestW = 0;           // bestW船1当前最优载重
int bestX[N];            // bestX[i]=1表示物品i最终装入船1

struct Nd              // 分支限界节点
{
    int lev;             // 当前决策层（物品编号1..n+1）
    int wt;              // 已装船1重量
    int x[N];            // x[i]=1/0 船1已装/未装物品i
};

// 队列式分支限界主过程
void Bb()
{
    queue<Nd> q;       // FIFO队列
    Nd root{};         // 根节点
    root.lev = 1;      // 从物品1开始决策
    root.wt = 0;       // 船1当前重量0
    q.push(root);      // 入队

    while (!q.empty())
    {
        Nd cur = q.front();
        q.pop();                  // 取出队首节点
        int i = cur.lev;          // 当前要决策的物品编号

        if (i > n)                // 到达叶子，所有物品已决策
        {
            if (cur.wt > bestW)   // 更新船1最优载重
            {
                bestW = cur.wt;
                for (int j = 1; j <= n; j++)
                    bestX[j] = cur.x[j]; // 保存最优解向量
            }
            continue;
        }

        // 左孩子：当不超重把物品i装入船1
        if (cur.wt + w[i] <= c1)
        {
            Nd lc = cur;     // 复制当前节点
            lc.wt += w[i];   // 船1重量增加
            lc.x[i] = 1;     // 标记装入
            lc.lev = i + 1;  // 决策下一件
            q.push(lc);      // 入队
        }

        // 右孩子：不把物品i装入船1
        Nd rc = cur;         // 复制当前节点
        rc.x[i] = 0;         // 标记不装
        rc.lev = i + 1;      // 决策下一件
        q.push(rc);          // 入队
    }
}

int main()
{
    cin >> n >> c1 >> c2;        // 读物品数、两船容量
    int sum = 0;                 // 总重量校验
    for (int i = 1; i <= n; i++)
        cin >> w[i],sum += w[i];
    if (sum > c1 + c2)           // 总重超限无解
    {
        cout << "没有解决方案\n";
        return 0;
    }
    Bb();                        // 执行分支限界
    sum = 0;
    for (int i = 1; i <= n; i++)
		if (!bestX[i]) sum += w[i];
    if (sum > c2)                // 无解
    {
        cout << "没有解决方案\n";
        return 0;
    }
    cout << bestW << '\n';       // 输出船1最大载重
    for (int i = 1; i <= n; i++)
        cout << bestX[i] << (i < n ? ' ' : '\n'); // 输出装载方案

    return 0;
}
/*
10 29 25
3 4 5 6 7 8 9 2 3 4

1 20 25
26

*/



