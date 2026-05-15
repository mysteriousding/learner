/*
快乐数

问题描述
定义快乐数满足：

数字 x 能被所有数位上的非 0 数字整除。
请你求出 [1,n] 中快乐数的数量。

输入格式
第一行输入一个整数 n（1≤n≤1000），表示 n 的大小。

输出格式
输出仅一行，包含一个整数，表示 [1,n] 中快乐数的数量。

样例输入
10

样例输出
10
*/
#include <iostream>
using namespace std;
int main()
{
    int n, m = 0, h, k;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        h = i;
        while (h)
        {
            k = h % 10;
            if (k && i % k)
                break;
            h /= 10;
        }
        m += h == 0;
    }
    cout << m << endl;

    return 0;
}