/*
拮据的生活

问题描述
新年到了，小蓝正在给家人准备礼物。

他来到礼品店，货架上共有 n 个礼物，编号 1∼n，每个礼物的价格用一个整数 pi 表示。

由于小蓝最近都把钱拿去投资了，所以生活很拮据。

小蓝会选择尽可能便宜的去买，总共买 3 个，请你告诉他，所购买的物品价格和为多少？

输入格式
第一行一个整数 n。

第二行 n 个整数 p1 ,p2 ,p3 ,...,pn 。

输出格式
一个整数，所购买的物品价格和。

样例输入
6
4 3 5 2 1 9

样例输出
6

评测数据范围
3≤n≤10^4 ,1≤pi ≤10^5 。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    cout << a[0] + a[1] + a[2] << endl;

    return 0;
}
