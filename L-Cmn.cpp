/*
递归求组合数

问题描述n,m。你需要求解Cmn的结果。

输入格式
第一行输入一个正整数t，表示数据总数。(1≤t≤100)

接下来 t 行，每行输入两个非负整数 n,m。(0≤m≤n≤15)

输出格式
输出t 行，每行为 Cmn 的结果。

样例输入
4
1 0
3 2
7 5
4 3

样例输出
1
3
21
4
*/
#include <iostream>
using namespace std;
long long arr[16] = { 1 };
int main()
{
    int t, n, m;
    for (int i = 1; i <= 15; i++)
        arr[i] = i * arr[i - 1];

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> m >> n;
        cout << (arr[m] / arr[m - n]) / arr[n] << endl;
    }

    return 0;
}
