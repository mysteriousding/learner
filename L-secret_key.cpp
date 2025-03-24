/*
格式化许可证密钥

题目描述
实现一个算法格式化许可证密钥。
介绍如下：

许可证密钥由字符串表示 ，字符串由字母，数字，破折号 - 构成。
破折号将字母和数字分成不同的组。

给定要求的字符数 K，将密钥进行重新分组，除第一组之外，其他组的长度均为 K，而第一组至少包含一个字符。

例如给定密钥 2-4-A0r7-4k 以及 K=3，重新分组后的结果为 24-A0R-74K。

输入描述
第一行输入字符串，为给定密钥，字符串长度不超过 1000。

第二行输入 K （1≤K≤100），含义见题干。

输出描述
输出一行字符串，为重新分组后的结果。

输入输出样例
示例

输入
2-4-A0r7-4k
3

输出
24-A0R-74K
*/
#include <iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
    string n;
    stack<char>m;
    int a, j = 0;
    cin >> n >> a;
    for (int i = n.size() - 1; i >= 0; i--)
    {
        if (n[i] == '-')continue;
        if (n[i] >= 'a' && n[i] <= 'z')n[i] -= 32;
        m.push(n[i]);
        j++;
        if (j == a && i)
        {
            m.push('-');
            j = 0;
        }
    }
    while (!m.empty())
    {
        cout << m.top();
        m.pop();
    }

    return 0;
}