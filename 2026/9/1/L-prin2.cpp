/*
打印口字

问题描述
给定你一个 n，你需要打印一个 '口' 字，该口字内部由 n×n 的空白构成，外部由一圈 * 构成。

例如 n=2，你需要输出如下内容：

****
*  *
*  *
****

输入格式
输入一行，包含 1 个正整数 n。

输出格式
按照题目要求输出。

样例输入
3

样例输出
*****
*   *
*   *
*   *
*****

评测数据规模
1≤n≤100。
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    string s = "*", m = "*";
    cin >> n;
    for (int i = 0; i < n; i++)
        s += '*', m += ' ';
    s += '*', m += '*';
    cout << s << endl;
    for (int i = 1; i <= n; i++)
        cout << m << endl;
    cout << s << endl;

    return 0;
}
