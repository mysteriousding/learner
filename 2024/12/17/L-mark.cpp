﻿/*
问题描述
蓝桥杯大赛的颁奖典礼马上就要开始了。

本次颁奖典礼，组委会制作了一条超长的空白横幅，并打算在横幅上标记每个选手的名字。标记规则如下：

把横幅的两端分别标记为 0 和 1。

首先，在横幅的正中间 1/2 处标记上第一个决赛选手的名字。

然后，把横幅三等分，在 1/3 和 2/3 处分别标记上另外两名决赛选手的名字。

接下来，把横幅四等分，在 1/4，2/4（也就是 1/2），3/4 处标记选手的名字。但由于 1/2 处已经标记过选手了，所以这次只需在 1/4 和 3/4 两个位置，标记另外两名选手的名字。

以此类推，每次把横幅 N 等分（N 从 2 开始递增），并在每个新的
k/N的位置 (1≤k<N) 标记选手。如果这个位置已经有标记了，就不用再标记。

用f(N) 表示每次新增的标记数量（下图红色表示新增的标记，蓝色表示已被标记）：

f(2) = 1

f(3) = 2

f(4) = 2

现在，组委会想知道，当N 为某个特定值时，新增的标记数量f(N) 是多少。

输入格式
输入仅一行，包含一个整数N(2≤N≤10^10)，表示横幅被分为 N 等分的次数。

输出格式
输出一个整数，表示在将横幅分为N 等分时新增的标记数量f(N)。

样例输入 1
4
copy
样例输出 1
2
copy
样例输入 2
5
copy
样例输出 2
4
*/
//532106293     10个测试点，这是第4个，这个就过不了，限时3000sm.
#include <iostream>
using namespace std;
int main()
{
    long long n, i, k, k1, k2, k3;
    cin >> n;
    for (i = 1; i < n; i++)
    {
        // for(j=1;j<=i;j++)
        // if(i%j==0&&n%j==0)max=j;
        k1 = i, k2 = n, k3 = 0;
        bool u = 0;
        while (k2 == n || k1 > 1)
        {
            k3 = k2 % k1;
            k2 = k1;
            if (k1 == 1 || k3 == 1)u = 1;
            k1 = k3;
        }

        if (u)k++;
    }
    cout << k << endl;

    return 0;
}
