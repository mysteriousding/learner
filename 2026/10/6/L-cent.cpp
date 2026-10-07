/*
居中输出

题目描述
输入一个整数，请在整数前后补上等号，使得总的长度为 10，而且整数在正中间。

输入描述
输入一行包含一个整数 n。

输出描述
输出补上等号后的表示。如果没办法使整数在正中间，在前面多补一个等号。

输入输出样例
示例
输入
2021

输出
===2021===

示例2
输入
2021101

输出
==2021101=

评测用例规模与约定
对于所有评测用例，给定的数是不超过 8 位的非负整数。
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    string s, m = "";
    getline(cin, s);
    n = (10 - s.size()) / 2;
    for (int i = 0; i < n; i++)
        m += '=';
    cout << m + (s.size() % 2 ? "=" : "") << s << m << endl;

    return 0;
}
