/*
地址转换

题目描述
Excel 是最常用的办公软件。每个单元格都有唯一的地址表示。
比如：第 12 行第 4 列表示为："D12"，第 5 行第 255 列表示为"IU5"。

事实上，Excel 提供了两种地址表示方法，还有一种表示法叫做 RC 格式地址。
第 12 行第 4 列表示为："R12C4"，第 5 行第 255 列表示为"R5C255"。

你的任务是：编写程序，实现从 RC 地址格式到常规地址格式的转换。

输入描述
用户先输入一个整数 n （n<100），表示接下来有 n 行输入数据。

接着输入的 n 行数据是 RC 格式的 Excel 单元格地址表示法。

输出描述
程序则输出 n 行数据，每行是转换后的常规地址表示法。

输入输出样例
示例
输入

用户输入：
2
R12C4
R5C255

输出
D12
IU5
*/
#include <iostream>
#include<stack>
using namespace std;
int main()
{
    int a, b, n;
    char c;
    stack<char>q;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c >> a >> c >> b;
        while (b)
        {
            q.push(char('A' + b % 26 - 1));
            b /= 26;
        }
        while (!q.empty())
        {
            cout << q.top();
            q.pop();
        }
        cout << a << endl;
    }

    return 0;
}
