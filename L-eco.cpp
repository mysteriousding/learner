/*
经济游戏中的投资策略

问题描述
在一个模拟经济游戏中，玩家乐乐初始拥有 X 元资金。
接下来的 12 个月中，将有 Q 个商机出现，每个商机需要投资 Ai 元，并在下个月初获得 Bi 元的收益。

玩家每个月最多选择一个商机进行投资，而且只能选择在当前资金范围内的商机。
求玩家在规则允许的情况下，12 个月后能获得的最大收益。

输入格式
第一行包含两个整数 Q 和 X。

接下来的 Q 行，每行包含两个整数 A 和 B。

输出格式
输出一行一个整数，代表 12 个月后的最大收益。

样例输入
2 5
1 2
7 10

样例输出
37

评测数据规模
1≤Q,A,B≤100
1≤X≤1000
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct s
{
    int a, b, c;
};
bool pd(s ai, s bi)
{
    return ai.c > bi.c;
}
int main()
{
    int q, x, k;
    cin >> q >> x;
    k = q;
    vector<s>arr(q);
    for (int i = 0; i < q; i++)
    {
        cin >> arr[i].a >> arr[i].b;
        arr[i].c = arr[i].b - arr[i].a;
    }
    sort(arr.begin(), arr.end(), pd);
    for (int i = 0; i < 12; i++)
        for (int j = 0; j <= k; j++)
            if (x >= arr[j].a)
                k = j, x += arr[j].c;
    cout << x << endl;

    return 0;
}