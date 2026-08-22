/*
缺失的书籍

问题描述
乐乐在整理图书时，发现每本书都有一个非负整数编号。
他想知道在当前图书集合中，最小的尚未被使用的编号是多少。
你的任务是编写一个函数，给定一组图书编号的数组，返回最小的未出现在该数组中的非负整数编号。

输入格式
第一行包含一个整数 N，表示数组的长度。

第二行包含 N 个整数，表示图书的编号。

输出格式
输出一个整数，表示最小的未出现的非负整数编号。

样例输入
4
3 1 0 7

样例输出
2

评测数据规模
1≤N≤10^5

书籍上的编号是 0 到 10^9 之间的正整数。
*/
#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int n, h;
    cin >> n;
    vector<bool>a(n + 1, 1);
    for (int i = 0; i < n; i++)
    {
        cin >> h;
        if (h <= n)
            a[h] = 0;
    }
    for (int i = 0; i <= n; i++)
        if (a[i])
        {
            cout << i << endl;
            break;
        }

    return 0;
}
