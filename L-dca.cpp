/*
分糖果

题目背景
现在有 n 个糖果，要分给小蓝和小桥，规则如下：
每次操作时，小蓝能够拿当前糖果数 和 a 的最大公约数个糖果，小桥能够拿当前糖果数 和 b 的最大公约数个糖果，不断循环，直到糖果被拿完。
现在让小蓝先拿糖果，请你计算最后小蓝和小桥各拿到多少个糖果。

输入格式
输入一行包含三个整数 n，a，b(1≤n,a,b≤10^3)，含义见问题描述。

输出格式
一行包含两个整数，分别表示小蓝和小桥拿到的糖果数。

样例输入
10 4 6

样例输出
6 4
*/
#include <iostream>
using namespace std;
int main()
{
    int n, a, b, h, m, k, x = 0, y = 0;
    cin >> n >> a >> b;
    while (n)
    {
        m = n, h = a;
        while (h)
            k = m % h, m = h, h = k;
        x += m, n -= m;
        if (n)
        {
            m = n, h = b;
            while (h)
                k = m % h, m = h, h = k;
            y += m, n -= m;
        }
    }
    cout << x << ' ' << y << endl;

    return 0;
}
