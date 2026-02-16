/*
小哲的字符串统计

问题描述
小哲有一个长度为 n 由小写字母组成的字符串 s。
他定义字符串的价值为：

对于 1≤i<n，满足 s(i) = s(i+1)
​
  的数量。
请你求出字符串 s 的价值。

输入格式
第一行输入一个整数 n（2≤n≤10^5），表示字符串的长度。

第二行输入一个长度为 n 由小写字母组成的字符串 s。

输出格式
输出仅一行，包含一个整数，表示字符串 s 的价值。

样例输入
3
aab

样例输出
1
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    int n, m = 0;
    cin >> n;
    cin.ignore();
    getline(cin, s);
    for (int i = 1; i < n; i++)
        m += s[i] == s[i - 1];
    cout << m << endl;

    return 0;

  
  
}

