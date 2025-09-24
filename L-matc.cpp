/*
乐乐的配对游戏

问题描述
乐乐有一个含有 N 个元素的珠宝箱，现在她想找出所有可能的珠宝对 (i,j) （满足 1≤i<j≤N 且 i ≠ j）使得两件珠宝的魔力值之和为奇数。

输入格式
第一行包含一个整数 N。

第二行包含 N 个整数，表示珠宝箱中每件珠宝的魔力值。

输出格式
输出一行，表示符合条件的珠宝对数量。

样例输入
4
1 2 3 4

样例输出
4

评测数据规模
1≤N≤100
1≤Ai ≤100
*/
#include <iostream>
using namespace std;
int main()
{
    int n, m, a = 0, b = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        if (m % 2)b++;
        else a++;
    }
    cout << a * b << endl;

    return 0;
}