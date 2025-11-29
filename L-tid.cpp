/*
乐乐的礼物分配

问题描述
乐乐有 N 个礼物，她想要将它们分成两组非空的子集，条件是第一组的数量必须是第二组数量的一个因数。
请计算乐乐有多少种不同的分配方式。

输入格式
第一行包含一个整数 N。

输出格式
在第一行打印分配方式的数量。

样例输入
6

样例输出
3

评测数据规模
2≤N≤10^9
*/
#include <iostream>
using namespace std;
int main()
{
    int n, m = 0;
    cin >> n;
    for (int i = 1; i <= n / 2; i++)
        if (n % i == 0)
            m++;
    cout << m << endl;

    return 0;
}