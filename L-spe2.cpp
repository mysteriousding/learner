/*
乐乐最少花费

问题描述
乐乐有无限数量的价值为 1、5 和 50 美元的硬币。

乐乐需要支付 K 美元，他现在需要计算最少硬币数量。

输入格式
第一行包含一个整数 K。

输出格式
输出一个整数，表示所需的最少硬币数量。

样例输入
13

样例输出
5

评测数据规模
1≤K≤1000。
*/
#include <iostream>
using namespace std;
int main()
{
    int n, m = 0, a[3] = { 50,5,1 }, i = 0;
    cin >> n;
    while (n)
        m += n / a[i], n %= a[i], i++;
    cout << m << endl;

    return 0;
}