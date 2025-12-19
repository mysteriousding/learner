/*
数位计数【省模拟赛】

问题描述
输入一个正整数，输出这个整数有多少个数位。

输入格式
输入一行包含一个整数 n。

输出格式
输出一行包含一个整数，表示答案。

样例输入
2021

样例输出
4

评测用例规模与约定
对于所有评测用例，2≤n≤100000000。
*/
#include <iostream>
using namespace std;
int main()
{
    int n, m = 0;
    cin >> n;
    while (n)
        n /= 10, m++;
    cout << m << endl;

    return 0;

}


