/*
大写

题目描述
给定一个只包含大写字母和小写字母的字符串，请将其中所有的小写字母转换成大写字母后将字符串输出。

输入描述
输入一行包含一个字符串。

输出描述
输出转换成大写后的字符串。

输入输出样例
示例
输入

LanQiao

输出

LANQIAO

评测用例规模与约定
对于所有评测用例，字符串的长度不超过 100。
*/
#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    for (char& i : s)
        if (i > 'Z')
            i -= 32;
    cout << s << endl;

    return 0;

}


