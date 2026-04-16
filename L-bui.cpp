/*
乐乐的积木塔

问题描述
在乐乐的玩具箱中，有一系列的积木，每个积木上都标记有一个高度值。
乐乐想要找出每个积木能够成为最高的连续递减积木塔的一部分的最大高度。
对于每个积木，求出包含该积木的最长递减积木序列的长度。

输入格式
第一行包含一个整数 N。

第二行包含 N 个整数，表示每个积木的高度。

输出格式
输出 N 个整数，每个整数代表以第 i 个积木为一部分的最长递减积木序列的长度。

样例输入
5
3 2 1 1 4

样例输出
3 3 3 1 1

评测数据规模
1≤N≤10^5
0≤Ai≤10^5
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int>a(n + 1), b(n + 1, 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = n - 2; i >= 0; i--)
        if (a[i] > a[i + 1])
            b[i] = b[i + 1] + 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[i + 1])
            b[i + 1] = b[i];
        cout << b[i] << " ";
    }

    return 0;
}