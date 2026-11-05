/*\]]】】】
约瑟夫环问题

问题描述
约瑟夫环问题，即出列游戏：
n 个人围成一圈，从第一个人开始报数，数到 m 的人出列，再由下一个人重新从 1 开始报数，数到 m 的人再出列，依次类推，直到所有的人都出列，请依次输出出列的人的编号。

输入描述
输入两个整数 n,m（1≤m,n≤100）。

输出描述
输出一行 n 个整数，按顺序输出每个出列的人的编号。

样例输入
10 3

样例输出：
3 6 9 2 7 1 8 5 10 4
*/
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m;
    queue<int>q;
    for (int i = 1; i <= n; i++)
        q.push(i);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < m; j++)
            k = q.front(), q.push(k), q.pop();
        cout << q.front() << ' ';
        q.pop();
    }

    return 0;
}
