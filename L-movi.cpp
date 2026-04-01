/*
云神的电影节

问题描述
云神在电影节上将展示 n 部电影。
你知道每部电影的开始和结束时间，问你最多能完整观看多少部电影？

输入格式
第一行输入一个整数 n，表示电影的数量。

接下来有 n 行描述电影。
每行包含两个整数 a 和 b，表示电影的开始和结束时间。

输出格式
输出一个整数，表示最大观影数量。

样例输入
3
3 5
4 9
5 8

样例输出
2

评测数据规模
1≤n≤10^5，1≤a<b≤10^9。
*/
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct T
{
    int x, y;
};
bool pd(T& q, T& p)
{
    return q.y < p.y;
}
int main()
{
    int n, m, num = 1;
    cin >> n;
    vector<T>a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;
    sort(a.begin(), a.end(), pd);
    m = a[0].y;
    for (int i = 1; i < n; i++)
        if (a[i].x >= m)
            num++, m = a[i].y;
    cout << num << endl;

    return 0;
}