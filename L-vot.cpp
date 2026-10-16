/*【【
投票【省模拟赛】

问题描述
同学们正在投票选班长，有 A 和 B 两位同学参选。

有 n 张（奇数）有效选票，每张上有一个字母 A 或 B。被选得多的赢得选举。

请问谁赢得了选举？

输入格式
输入的第一行包含一个整数 n。

第二行包含一个长度为 n 字符串，表示每张选票。

输出格式
如果 A 赢得选举，输出 A，否则输出 B。

样例输入
7
ABAABBA

样例输出
A

评测用例规模与约定
对于所有评测用例，2<=n<=1000，n 为奇数。
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, m = 0;
    string s;
    cin >> n;
    cin.ignore();
    getline(cin, s);
    for (char c : s)
        m += c == 'A';
    cout << (m * 2 > n ? 'A' : 'B') << endl;

    return 0;
}
