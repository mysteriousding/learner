﻿/*
最大化股票交易的利润

题目描述
实现一个算法寻找最大化股票交易利润的策略。介绍如下：

股票价格每天都在变化，以数组的索引表示交易日，以数组的元素表示每天的股票价格。
可以通过买入和卖出获得利润。一天只能进行一次买入或卖出操作，一次买入加卖出操作称为一次交易次数。
你只能交易一次，求使得利润最大的交易策略。
输入描述
第一行为数字 N，表示共有 N 天。

第二行为 N 个数字 Ai ，表示每天的股票价格。

其中，1≤N,Ai≤10^4 。

输出描述
输出一行，为交易一次的最大利润（有可能利润为负）。

输入输出样例
示例

输入
8
2 5 6 1 4 3 1 3

输出
4
*/
#include <iostream>
using namespace std;
int main()
{
    int n, a[1010], sum = -10000, x;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < n; j++)
    {
        x = j;
        while (j < n)
        {
            if (a[j] > a[j + 1])break;
            if (a[x] > a[j])x = j;
            j++;
        }
        if (sum < a[j] - a[x])sum = a[j] - a[x];
    }
    cout << sum << endl;

    return 0;
}
