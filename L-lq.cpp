/*]]]]]]
判断蓝桥

问题描述
输入一个字符串，请判断这个字符串是否正好是 lanqiao 。
在输入时如果只是大小写不同也算作相同。

输入格式
输入一行包含一个字符串。

输出格式
如果是 lanqiao ，输出全小写的字符串 yes ，否则输出全小写的字符串 no 。

样例输入
LanQiao

样例输出
yes

样例输入
QiaoLan

样例输出
no

评测用例规模与约定
对于所有评测用例，输入的字符串由大写或小写英文字母组成，长度至少为 1 个字符，不超过 20 个字符。
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    for (int i = 0; s[i]; i++)
        if (s[i] < 'a')
            s[i] += 32;
    cout << (s == "lanqiao" ? "yes" : "no") << endl;

    return 0;
}
