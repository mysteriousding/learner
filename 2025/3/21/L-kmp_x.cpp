/*
用杂志拼接信件

题目描述
实现一个算法确定能否由杂志构成信件。
介绍如下：

影视剧中信件大多是从报纸或杂志上的字符剪下来拼接而成的。

杂志和信件均由字符串构成，对于给定的杂志和信件，确定信件是否可以由杂志上的字符构成。

例如杂志为 ab，信件为 aa，则不能构成。
杂志为 aab，信件为 aa，则可以构成。

输入描述
输入两行字符串，长度均不超过 100。

第一行为杂志字符串，第二行为信件字符串。

输出描述
输出一行，若信件可由杂志构成则输出 YES，否则输出 NO。

输入输出样例
示例

输入
ab
aa

输出
NO
*/
#include <iostream>
#include<string>
using namespace std;
int main()
{
    string n, m;
    int h = 0, next[100] = { -1 };
    cin >> n >> m;
    for (int i = 1; i < m.size(); i++)
        if (m[i] == m[h])next[i] = ++h;
        else
        {
            h = 0;
            if (m[i] == m[h])next[i] = ++h;
        }
    int i = 0, j = 0;
    if (n.size() >= m.size())
        while (i <= n.size() - m.size() + 1)
        {
            if (n[i] != m[j])
            {
                j = next[j];
                if (j == -1)i++, j++;
                continue;
            }
            i++, j++;
            if (j >= m.size())
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    cout << "NO" << endl;

    return 0;
}
