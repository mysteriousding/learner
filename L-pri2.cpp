/*
分解质因数

题目描述
给定一个区间 [a,b]，请你求出区间 [a,b] 中所有整数的质因数分解。

输入描述
输入共一行，包含两个整数 a,b。

2≤a≤b≤10^3。

输出描述
每行输出一个数的分解，形如 k=a1×a2×a3 ⋯ (a1≤a2≤a3  ⋯ ，k也是从小到大的)(具体可看样例)

输入输出样例
示例
输入
3 10

输出
3=3
4=2*2
5=5
6=2*3
7=7
8=2*2*2
9=3*3
10=2*5
*/
#include <iostream>
using namespace std;
int main()
{
    int n, m, h;
    bool b;
    cin >> n >> m;
    for (int i = n, j; i <= m; i++)
    {
        cout << i << '=';
        h = i, b = 0, j = 2;
        while (h > 1)
            if (h % j == 0)
            {
                if (b)cout << '*';
                cout << j;
                h /= j, b = 1;
            }
            else j++;
        cout << endl;
    }

    return 0;
}