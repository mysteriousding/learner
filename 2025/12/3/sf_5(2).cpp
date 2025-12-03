/*
2、用回溯法求解TSP问题。
旅行商问题，即TSP问题（Travelling Salesman Problem）又译为旅行推销员问题、货郎担问题，是数学领域中著名问题之一。
假设有一个旅行商人要拜访n个城市，他必须选择所要走的路径，路径的限制是每个城市只能拜访一次，而且最后要回到原来出发的城市。
路径的选择目标是要求得的路径路程为所有路径之中的最小值。
请使用回溯法求解TSP 问题。
*/
#include<iostream>
using namespace std;
int n, g[20][20], b[20], mi = 1e9;           // n城市数，g邻接矩阵，vis标记是否访问，mi记录最短回路
void dfs(int u, int cnt, int cost)           // u当前城市，cnt已访问城市数，cost当前路径长度
{ 
    if (cnt == n)                            // 所有城市已访问
    { 
        mi = min(mi, cost + g[u][0]);        // 回到起点0，更新最短回路
        return;
    }
    for (int v = 0; v < n; v++)              // 尝试下一城市v
        if (!b[v] && g[u][v])                // v未访问且u到v有路 
        {  
            b[v] = 1;                        // 标记访问
            dfs(v, cnt + 1, cost + g[u][v]); // 递归访问
            b[v] = 0;                        // 回溯撤销标记
        }
}
int main()
{
    cin >> n;                                // 读入城市数
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];                  // 读入邻接矩阵

    b[0] = 1;                                // 起点0标记为已访问
    dfs(0, 1, 0);                            // 从城市0出发，已访问1城，当前花费0
    cout << mi << endl;                      // 输出最短回路长度

    return 0;

}




