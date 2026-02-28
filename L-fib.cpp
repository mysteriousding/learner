/*
Fibonacci 数列与黄金分割

题目描述
Fibonacci 数列是非常著名的数列：
F[1]=1,F[2]=1,

对于 i>3，F[i]=F[i−1]+F[i−2]。

Fibonacci 数列有一个特殊的性质，前一项与后一项的比值，F[N]/F[N+1]， 会趋近于黄金分割。

为了验证这一性质，给定正整数 N，请你计算 F[N]/F[N+1]，并保留 8 位小数。

输入描述
输入一个正整数 N (1≤N≤2×10^9)。

输出描述
输出
F[N]/F[N+1]。
答案保留 8 位小数。

输入输出样例
输入
2

输出
0.50000000
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double a = 1, b = 1, h;
    int n;
    cin >> n;
    if (n > 20)n = 20;
    for (int i = 1; i < n; i++)
        h = b, b += a, a = h;
    cout << fixed << setprecision(8) << a / b << endl;

    return 0;

}
