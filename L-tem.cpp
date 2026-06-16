/*
植物生长温度

问题描述
怂怂有 N 盆植物和 M 个不同的生长环境。每个环境的特征是一个恒定的温度。
对于每盆植物，怂怂都知道一个可以生存的温度区间 [Ai,Bi]。现在需要确定每盆植物有多少个环境适宜它们生长。

输入格式
第一行包含两个整数 N 和 M。

第二行包含 M 个整数，表示每个环境的温度 Ti 。

接下来 N 行，每行包含两个整数 Ai 和 Bi，表示每盆植物能生存的温度区间。

输出格式
输出 N 个整数，每个整数占一行，表示每盆植物适宜生长的环境数量。

样例输入
4 5
5 1 4 4 3
2 4
1 2
3 4
0 100

样例输出
3
1
3
5

评测数据规模
1≤N,M≤100
0≤Ti≤100
0≤Ai≤Bi≤100
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, m, b[4];
    cin >> n >> m;
    vector<int>a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        cin >> b[0] >> b[1];
        for (b[2] = 0; b[2] < m && a[b[2]] < b[0]; b[2]++);
        for (b[3] = m - 1; b[3] > 0 && a[b[3]] > b[1]; b[3]--);
        cout << b[3] - b[2] + 1 << endl;
    }

    return 0;
}
