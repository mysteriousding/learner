/*
最尖位置

问题描述
对于一个序列 a[1],a[2],…,a[n]，如果 a[i] 满足 a[i]<a[i−1] 且 a[i]<a[i+1]，则称 i 是一个尖位置，i 位置尖的程度定为 (a[i−1]−a[i])×(a[i+1]−a[i])。

给定一个序列，请找到一个尖的位置，这个位置尖的程度值最大。

输入格式
输入的第一行包含一个整数 n ，表示序列的长度。

第二行包含 n 个整数，相邻的整数之间使用一个空格分隔，表示给定的序列。

输出格式
输出一行包含一个整数，表示找到的最大的尖的程度值。如果不存在尖位置，输出 0。

样例输入
8
1 8 2 4 4 3 5 3

样例输出
12

数据范围
对于所有评测用例，1≤n≤1000，0≤a[i]≤10000。
*/
#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int n, m = 0;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = n - 1; i > 0; i--)
        a[i] -= a[i - 1];
    for (int i = 1; i < n - 1; i++)
        if (a[i] < 0 && a[i + 1]>0 && m < -a[i] * a[i + 1])
            m = -a[i] * a[i + 1];
    cout << m << endl;

    return 0;

}

