/*
最大数目

问题描述
小蓝有一个长度为 n 的数组 a ，现在对于每一个 ai ，小蓝可以选择下面三种操作之一：
	ai = ai - 1
	ai = ai + 1
	ai = ai

小蓝想知道当她把每一个 ai 都操作之后，数组众数的数目最大是多少。
但是小蓝并不擅长这个问题，请你帮小蓝计算所有操作完成之后数组众数的最大数目。

输入格式
第一行输入一个整数，代表 n 。

第二行输入 n 个整数，代表 a1 ,a2 ,a3 ,...,an。

输出格式
输出一行一个整数，代表众数的最大数目。

样例输入
3
1 2 3

样例输出
3

说明
对于样例，将 a1 加一， a3 减一，a2 不变，此时三个数都是 2 ，而其他操作得到的结果众数数目都小于 3 ，所以最终答案是 3 。

评测数据规模
对于 50% 的评测数据 1≤n≤10^3 ,1≤ai≤10^4 。

对于 100% 的评测数据 1≤n≤10^5 ,1≤ai≤10^9 。
*/
#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n, m = 0, h;
    map<int, int>p;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h, p[h]++;
    for (auto it : p)
    {
        h = it.second + (p.find(it.first - 1) != p.end() ? p[it.first - 1] : 0) + (p.find(it.first + 1) != p.end() ? p[it.first + 1] : 0);
        if (m < h)
            m = h;
    }
    cout << m << endl;

    return 0;
}