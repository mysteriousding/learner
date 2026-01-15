/*
相邻对的最大和

问题描述
给定一个长度为 n 的整数数组 A。
对于任意 1≤i≤n−1，我们称 ( Ai,A(i+1) ) 为一个相邻对，其值为 Ai + A(i+1) 。
求数组 A 中的相邻对的值的最大值。

输入格式
第一行包含一个整数 n，表示数组长度。

第二行包含 n 个整数，依次表示 A1  到 An 。

输出格式
输出共一行，包含一个整数，表示相邻对的值的最大值。

样例输入
3
1 2 3

样例输出
5

评测数据规模
2≤n≤10^5 。
−10^9 ≤ Ai ≤10^9 。
*/
#include <iostream>
using namespace std;
int main()
{
    int n, h, k;
    long long m = -2e9;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h;
        if (i && k + h > m)
            m = k + h;
        k = h;
    }
    cout << m << endl;

    return 0;
}
