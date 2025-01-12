/*
 k倍区间

题目描述
给定一个长度为N 的数列，A1,A2,⋯AN, 如果其中一段连续的子序列 Ai,Ai+1,⋯Aj (i≤j) 之和是K 的倍数，我们就称这个区间 [i,j] 是 K 倍区间。

你能求出数列中总共有多少个K 倍区间吗？

输入描述
第一行包含两个整数 N 和 K( 1≤N,K≤10^5 )。

以下 N 行每行包含一个整数 Ai( 1≤Ai≤10^5 )

输出描述
输出一个整数，代表 K 倍区间的数目。

输入输出样例
示例
输入

5 2
1
2
3
4
5

输出

6
*/
#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int n, k, h;
    cin >> n >> k;
    vector<long long>m(n + 1);
    vector<int>num(k);
    long long sum = 0;
    num[0] = 1, m[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> h;
        m[i] = m[i - 1] + h;

        sum += num[m[i] % k];
        num[m[i] % k]++;
    }

    cout << sum << endl;

    return 0;
}
