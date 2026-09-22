/*
异常频率

问题描述
给定乐乐一个由 N 个整数组成的数组。
除了一个值之外，每个不同的值出现的次数相同。
现在他要找到这个值。

请注意：数组中至少有 3 个不同的值。

输入格式
第一行包含一个整数 N。

第二行包含 N 个整数，表示数组的元素 ai。

输出格式
输出一个整数，表示出现次数与其他所有元素不同的值。

样例输入
5
1 1 2 2 3

样例输出
3

评测数据规模 
4≤N≤1000，0≤ai≤10^9 。
*/
#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n, h, x = -1, s, b, t = 0;
    map<int, int>p;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h;
        p[h]++;
    }
    for (auto it : p)
        if (x == -1)
            x = it.first, s = it.second;
        else if (s != it.second)
            b = it.first, t++;
    cout << (t == 1 ? b : x) << endl;

    return 0;
}
