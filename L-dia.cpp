/*
日志统计

题目描述
小明维护着一个程序员论坛。现在他收集了一份"点赞"日志，日志共有 N 行。
其中每一行的格式是：

ts id

表示在 ts 时刻编号 id 的帖子收到一个"赞"。

现在小明想统计有哪些帖子曾经是"热帖"。
如果一个帖子曾在任意一个长度为 D 的时间段内收到不少于 K 个赞，小明就认为这个帖子曾是"热帖"。

具体来说，如果存在某个时刻 T 满足该帖在 [T,T+D) 这段时间内(注意是左闭右开区间)收到不少于 K 个赞，该帖就曾是"热帖"。

给定日志，请你帮助小明统计出所有曾是"热帖"的帖子编号。

输入描述
输入格式：

第一行包含三个整数 N,D,K。

以下 N 行每行一条日志，包含两个整数 ts 和 id。

其中，1≤K≤N≤10^5 ,0≤ts≤10^5 ,0≤id≤10^5 。

输出描述
按从小到大的顺序输出热帖 id。
每个 id 一行。

输入输出样例

示例

输入

7 10 2
0 1
0 10
10 10
10 1
9 1
100 3
100 3


输出

1
3
*/
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct h
{
    int t, b;
};
bool pd(h& x, h& y)
{
    if (x.b != y.b)return x.b < y.b;
    else return x.t < y.t;
}
int main()
{
    int n, d, k, i;
    cin >> n >> d >> k;
    vector<h>a(n + k);
    for (i = 0; i < n; i++)
        cin >> a[i].t >> a[i].b;
    sort(a.begin(), a.end() - k, pd);
    i = 0;
    int l;
    while (i < n)
    {
        l = a[i].b;
        for (; a[i + k - 1].b == l; i++)
            if (a[i + k - 1].t - a[i].t < d)
            {
                cout << a[i].b << endl;
                while (a[i].b == l)i++;
                break;
            }
        if (l == a[i].b)i++;
    }

    return 0;
}
