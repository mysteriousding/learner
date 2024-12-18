﻿/*
问题描述
一日清晨，贾宝玉睡眼惺忪地从怡红院出来，准备去给长辈们请安。他需要先去凤姐的蘅芜苑请安，再到王夫人的潇湘馆请安（或先去潇湘馆，再到蘅芜苑，顺序不限）。

大观园里的道路是东西走向的。宝玉现在位于大观园正门（朝东方向）
x1步的位置。蘅芜苑位于距离正门（朝东方向）
x2步的位置，潇湘馆位于距离正门（朝东方向）
x3步的位置。

已知宝玉可以向东、向西两个方向行走。现在，请你帮宝玉算算，他最少需要走多少步才能完成这两次请安？

输入格式
第一行包含一个整数
(1≤t≤10^3)，表示测试用例的数量。

接下来的
t 行，每行包含三个整数
x1​
 ，
x2​
  和
x3
 （1≤x1​,x2​,x3≤10^9),x1,x2,x3 互不相同），分别表示宝玉、蘅芜苑和潇湘馆所在位置距离正门的步数。

输出格式
对于每个测试用例，输出一个整数，表示宝玉最少需要走的步数。

样例输入
2
1 2 3
2 1 3

样例输出
2
3


样例说明
对于样例一，宝玉的路线可以是：
1→2→3
总共需要
2 步。

对于样例二，宝玉的路线可以是：
2→1→2→3
总共需要
3 步。
*/
#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    int x1, x2, x3, t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> x1 >> x2 >> x3;
        if (abs(x1 - x2) > abs(x1 - x3))
        {
            x2 += x3;
            x3 = x2 - x3;
            x2 -= x3;
        }
        cout << abs(x1 - x2) + abs(x2 - x3) << endl;
    }

    return 0;
}