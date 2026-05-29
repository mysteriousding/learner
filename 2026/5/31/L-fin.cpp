/*
查找信息【省模拟赛】

问题描述
小蓝负责管理公司的打卡信息。

每条信息包含员工编号（一个整数）、员工姓名（一个只包含大小写英文字母的字符串）、打卡时间（一个整数）和打卡地点（一个只包含大小写英文字母的字符串）。

现在，小蓝想找到其中一名员工的打卡信息，请帮助他。

输入格式
输入的第一行包含一个整数 n，表示打卡信息的条数。

第二行开始的 n 行，每行包含一条打卡信息，由员工编号、员工姓名、打卡时间和打卡地点组成。

接下来一行包含一个字符串，表示要查找的员工的姓名。

输出格式
输出多行，每行包含一条打卡信息，按输入的顺序输出。
只要该打卡信息中的员工姓名与所查找的员工姓名一致（包括大小写也一致）就要输出。

样例输入
5
1234 XiaoLan 2021 DaSai
2345 LanQiao 123456 DaSai
1234 XiaoLan 202110 XiaoNei
7823 XiaoLan 98765 DaSai
789123 XiaoLanQiao 43091 XiaNei
XiaoLan

样例输出
1234 XiaoLan 2021 DaSai
1234 XiaoLan 202110 XiaoNei
7823 XiaoLan 98765 DaSai

评测用例规模与约定
对于所有评测用例，2≤n≤1000，1≤ 员工编号 ≤100000000，员工姓名长度至少为 1，至多为 20 个字符，1≤ 打卡时间 ≤100000000，打卡地点长度至少为 1，至多为 20 个字符。
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
struct k
{
    int a;
    string b;
    int c;
    string d;
};
int main()
{
    map<string, vector<k>>m;
    int n, h1, h2;
    string s1, s2;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h1 >> s1 >> h2 >> s2;
        m[s1].push_back(k{ h1,s1,h2,s2 });
    }
    while (cin >> s1)
        for (k i : m[s1])
            cout << i.a << ' ' << i.b << ' ' << i.c << ' ' << i.d << endl;

    return 0;
}
