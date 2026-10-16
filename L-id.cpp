/*
身份证

问题描述
一共有 n 个身份证，编号 1∼n，还有 m 个门，可以进入第 i 个门的身份证编号是 li∼ri ，请问 n 个身份证中，所有门都可进入的身份证有几个。

输入格式
第一行有两个整数 n,m 。

接下来第 m 行，每行两个整数，按顺序表示每个门可以进入的身份证编号 li∼ri。

输出格式
输出一个整数表示所有门都可以进入的身份证个数。

样例输入
4 2
1 3
2 4

样例输出
2

说明
保证对于所有数据有：
1≤n,m≤1×10^5,1≤li,ri≤n 。
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m, l, r, sum = 0;
    cin >> n >> m;
    vector<int>a(n + 2, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        a[l]++, a[r + 1]--;
    }
    for (int i = 1; i < n; i++)
    {
        a[i] += a[i - 1];
        if (a[i] == m)
            sum++;
    }
    cout << sum << endl;

    return 0;
}