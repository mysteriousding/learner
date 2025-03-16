/*
确定一个数字是否为 2 的幂

题目描述
实现一个算法确定一个数字 N 是否为 2 的幂。

若该数字是 2 的幂则输出 YES，否则输出 NO。

输入描述
输入一个数字 N (1≤N≤10^8 )。

输出描述
输出一行，若 N 是 2 的幂则输出 YES，否则输出 NO。

输入输出样例
示例

输入
8

输出
YES
*/
#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n;
    while (n >= 2)
    {
        m = n % 2;
        if (m)
        {
            cout << "NO" << endl;
            return 0;
        }
        n /= 2;
    }
    cout << "YES" << endl;

    return 0;
}