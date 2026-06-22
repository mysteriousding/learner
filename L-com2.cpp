/*
组合魔法石的能量

问题描述
可可和乐乐是一对魔法师，他们有一套魔法石，每块魔法石都有其特定的能量值。
他们很好奇，如果只能使用恰好两块魔法石，能够创造出多少种不同的能量总和。

输入格式
第一行包含一个整数 N，代表魔法石的数量。

第二行包含 N 个整数，分别代表每块魔法石的能量值，第 i 块魔法石的能量值为 vi。

输出格式
输出一个整数，代表能够创造出的不同能量总和的数量。

样例输入
4
2 2 1 3

样例输出
3

评测数据规模
1≤N≤1000。
1≤vi≤1000。
*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int>a(n);
    set<int>q;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            q.insert(a[i] + a[j]);
    cout << q.size() << endl;

    return 0;
}