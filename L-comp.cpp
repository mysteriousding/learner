/*
压缩字符串

题目描述
实现一个算法来压缩一个字符串。压缩的要求如下：

需要判断压缩能不能节省空间，仅在压缩后字符串比原字符串长度更短时进行压缩。

压缩的格式是将连续相同字符替换为字符 + 数字形式，例如 "AAABCCDDDD" 变为 "A3BC2D4"。

输入描述
输入一行字符串，长度不超过 500.

输出描述
输出一行。若输入的字符串可压缩，则输出压缩后的字符串，否则输出 NO。

输入输出样例
示例
输入

AAABCCDDDD

输出

A3BC2D4
*/
#include <iostream>
#include<string>
using namespace std;
int main()
{
    string m;
    int i = 1, j = 1;
    bool u = 1;
    cin >> m;
    char h = m[i - 1];
    while (m[i - 1])
        if (m[i] == h)j++, i++;
        else
        {
            cout << h;
            if (j > 1) { cout << j; u = 0; }
            h = m[i], j = 0;
        }
    if (u)cout << "NO";

    return 0;
}