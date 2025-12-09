#include <iostream>
using namespace std;
int n, g[20][20], b[20], mi = 1e9, q[20], p[20];
void dfs(int u, int cnt, int cost)
{
    p[cnt - 1] = u + 1;
    if (cost >= mi)
        return;
    if (cnt == n)
    {
        int x = cost + g[u][0];
        if (x < mi)
        {
            mi = x;
            for (int i = 0; i < n; i++)
                q[i] = p[i];
            q[n] = 0;
        }
        return;
    }
    for (int v = 0; v <n; v++)
        if (!b[v] && g[u][v] != -1)
        {
            b[v] = 1;
            dfs(v, cnt + 1, cost + g[u][v]);
            b[v] = 0;
        }
}

int main() 
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
   
    b[0] = 1;
    dfs(0, 1, 0);
    cout << "最优值为:" << mi;
    if (mi != 1e9)
    {
        cout << "最优解为:";
        for (int i = 0; i < n; i++)
            cout << q[i];
        cout << endl;
    }

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
