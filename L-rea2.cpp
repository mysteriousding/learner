/*
元音大写

问题描述
输入一个由小写英文字母组成的字符串，请将其中的元音字母 (a,e,i,o,u) 转换成大写，其它字母仍然保持小写。

输入格式
输入一行包含一个字符串。

输出格式
输出转换后的字符串。

样例输入
lanqiao

样例输出
lAnqIAO

评测用例规模与约定
对于所有评测用例，字符串的长度不超过 100。
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    int n;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++)
    {
        switch (s[i])
        {
        case 'a':s[i] = 'A'; break;
        case 'e':s[i] = 'E'; break;
        case 'i':s[i] = 'I'; break;
        case 'o':s[i] = 'O'; break;
        case 'u':s[i] = 'U'; break;
        }
    }
    cout << s << endl;

    return 0;
}