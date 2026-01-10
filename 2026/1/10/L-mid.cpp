/*
乐乐的中间值求和

问题描述
乐乐有一串宝石，每个宝石都有其价值。
为了评估这串宝石的中间价值，乐乐决定抛去最昂贵和最廉价的宝石，仅计算剩余宝石的总价值。
现在需要你帮乐乐计算出这个中间价值。

输入格式
第一行包含一个整数 N。

第二行包含 N 个整数，代表每个宝石的价值。

输出格式
输出一行，包含一个整数，表示去掉最高价和最低价宝石后，剩余宝石的总价值。

样例输入
8
1 1 2 2 3 3 4 4

样例输出
10

评测数据规模
3≤N≤1000
1≤Ai≤1000
数组 A 中至少有 3 个不同的数值
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, m = 0, k = -1, u = 0;
    bool v = 0;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int h : a)
        if (!v)
        {
            if (k == -1)
                k = h;
            if (k != h)v = 1, m += h;
            k = h;
        }
        else
        {
            m += h;
            if (h == k)u += h;
            else u = h, k = h;
        }
    cout << m - u << endl;

    return 0;

}


