/*
硬币支付的可能性

问题描述
乐乐有一堆硬币，每个硬币有不同的面值。
如果只能使用两枚硬币进行支付，乐乐想知道他能支付多少种不同的金额。

输入格式
第一行包含一个整数 N，代表硬币的总数。

第二行包含 N 个整数，分别代表每枚硬币的面值。

输出格式
输出一个整数，代表使用两枚硬币能支付的不同金额数。

样例输入
4
2 2 1 3

样例输出
3

评测数据规模
1≤vi≤100，对于所有 1≤i≤N
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, num = 0;
    bool b[205] = { 0 };
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            b[a[i] + a[j]] = 1;
    for (int i = 0; i < 205; i++)
        num += b[i];
    cout << num << endl;

    return 0;
}