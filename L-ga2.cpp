/*
最大间隙

题目描述
给定一个序列 a1,a2,⋯,an 。
其中 a1≤a2≤⋯≤an。

相邻两个数之间的差（后一个数减前一个数）称为它们的间隙。

请问序列中最大的间隙值是多少？

输入描述
输入的第一行包含一个整数 n，表示序列的长度。

第二行包含 n 个正整数，为给定的序列。

其中，1≤n≤1000，1≤ai≤10^5。

输出描述
输出一个整数，表示序列中最大的间隙值。

输入输出样例
示例 1
输入
5
1 3 8 9 12

输出
5
*/
#include <iostream>
using namespace std;
int main()
{
    int n, x, y, z = 0;
    cin >> n >> y;
    for (int i = 0; i < n; i++)
    {
        x = y;
        cin >> y;
        if (y - x > z)
            z = y - x;
    }
    cout << z << endl;

    return 0;
}