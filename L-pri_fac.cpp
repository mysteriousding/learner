/*
质因数分解

题目描述
已知正整数 n 是两个不同的质数的乘积，试求出较大的那个质数。

输入描述
输入只有一行，包含一个正整数 n，6≤n≤2×10^9 。

输出描述
输出只有一行，包含一个正整数 p，即较大的那个质数。

输入输出样例
示例

输入
21

输出
7
*/
#include <iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    for (int i = a / 4 * 2 + 1; i >= 2; i -= 2)   //i=a/2+(a%4?1:0)
        if (a % i == 0)
        {
            cout << i << endl;
            break;
        }

    return 0;
}