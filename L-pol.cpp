/*
聚合一块

问题描述
小蓝上完图论课后，小桥给了他一个挑战：

存在 n 个点，m 条边，每条边连接两个点，例如存在一条边为(ui,vi)，代表有一条边连接了 (ui,vi) 两个点。

小桥请小蓝回答，最少加上多少边，可以使得只剩下一个连通块。

连通块：如果某两个点能通过边直接或者间接相连，我们称他们处于一个连通块。

输入格式
第一行输入两个整数 n,m。

接下面 m 行，每行两个整数 ui,vi。

输出格式
一个整数，代表最少加上多少边，可以使得只剩下一个连通块。

样例输入
5 5
1 2
2 3
1 3
4 5
5 4

样例输出
1

评测数据范围
2≤n,m≤10^5,1≤ui,vi≤n。
*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int>a;
int app(int n)
{
    if (n != a[n])a[n] = app(a[n]);
    return a[n];
}
int main()
{
    int n, m, x, y;
    set<int>s;
    cin >> n >> m;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        a[i] = i;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        if (app(y) != app(x))
            a[app(y)] = a[app(x)];
    }
    for (int i = 1; i <= n; i++)
        s.insert(app(i));
    cout << s.size() - 1 << endl;

    return 0;
}