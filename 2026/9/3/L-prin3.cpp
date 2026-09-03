/*
多组输入输出练习

问题描述
这是一道练习题。

给定若干行数据，每行数据为一个正整数，该正整数范围在 int 范围内。

你的任务是将这些数据全部输出。

输入格式
输入若干行数据，每行一个正整数。

输出格式
输出这些数据。

样例输入
3
2
4
5

样例输出
3
2
4
5
*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
        cout << n << endl;

    return 0;
}
