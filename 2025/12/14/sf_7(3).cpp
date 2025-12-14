/*
3、以0-1背包问题为例，设计并实现程序，比较回溯法与动态规划的渐进时间复杂度与实际运行的时间差异。
*/
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

const int N = 1e4 + 10;
int n, C, w[N], v[N], best = 0;

void dfs(int i, int cw, int cv) // 回溯
{
    if (i > n) { best = max(best, cv); return; }
    if (cw + w[i] <= C) dfs(i + 1, cw + w[i], cv + v[i]);
    dfs(i + 1, cw, cv);
}

int dp() // 0-1 背包 动规
{
    static int f[N];
    fill(f, f + C + 1, 0);
    for (int i = 1; i <= n; ++i)
        for (int j = C; j >= w[i]; --j)
            f[j] = max(f[j], f[j - w[i]] + v[i]);
    return f[C];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> C;
    for (int i = 1; i <= n; ++i) cin >> w[i] >> v[i];

    auto t1 = high_resolution_clock::now();
    dfs(1, 0, 0);
    auto t2 = high_resolution_clock::now();
    auto d1 = duration_cast<microseconds>(t2 - t1).count();

    auto t3 = high_resolution_clock::now();
    int r2 = dp();
    auto t4 = high_resolution_clock::now();
    auto d2 = duration_cast<microseconds>(t4 - t3).count();

    cout << "backtrack " << best << "  time: " << d1 << "us\n";
    cout << "dp        " << r2 << "  time: " << d2 << "us\n";

    return 0;
}
/*
20 50
15 12
8 7
20 15
5 3
15 10
12 8
10 6
18 11
6 4
9 5
20 14
7 4
15 9
12 7
10 5
8 6
18 10
6 3
9 4
20 13

*/


