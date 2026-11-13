/*]]
10的倍数

问题描述
数学课上，老师给你一个整数 k，让你判断各个数位上的数加起来之和是否是 10 的倍数。

输入格式
第一行包含一个正整数 k，表示老师给的数，1≤k≤10^100000 。

输出格式
输出共一行，包含一个字符串，如果这个数符合要求，则输出 yes，否则输出 no。

样例输入1
19

样例输出1
yes

样例输入2
9999999999999999999999999999999999999999999

样例输出2
no
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int m = 0;
    string s;
    getline(cin, s);
    for (char c : s)
        m += c - '0';
    cout << (m % 10 ? "no" : "yes") << endl;

    return 0;
}
