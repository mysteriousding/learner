/*
乐乐的玩具拍卖

问题描述
乐乐决定拍卖一批手工制作的玩具。
共有 N 位潜在买家对这批玩具感兴趣，每位买家愿意支付的最高价钱不同。
你的任务是确定一个拍卖价格，以此来最大化乐乐的收入。
每位买家只会购买一个玩具或者不购买。

输入格式
第一行包含一个整数 N。

第二行包含 N 个整数，分别代表每位买家愿意支付的最高价钱 Vi。

输出格式
输出一个整数，表示乐乐通过拍卖能获得的最大收入。

样例输入
4
2 10 6 3

样例输出
12

评测数据规模
1≤N≤1000
1≤Vi≤10^6
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool pd(int x, int y) { return x > y; }
int main()
{
    long long n, ma = 0;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), pd);
    for (int i = 0; i < n; i++)
        if (ma <= a[i] * (i + 1))
            ma = a[i] * (i + 1);

    cout << ma << endl;

    return 0;
}