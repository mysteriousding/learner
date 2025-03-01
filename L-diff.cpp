/*
找到给定字符串中的不同字符

题目描述
在不考虑字符排列的条件下，对于相差只有一个字符的两个字符串，实现一个算法来识别相差的那个字符。要求如下：

当传入的字符串为 aad 和 ad 时，结果为 a。

当传入的字符串为 aaabccdd 和 abdcacade 时，结果为 e。

输入描述
输入两行字符串，长度均不超过 100。

输出描述:
输出一行，为相差的那个字符。

输入输出样例
示例

输入
aad
ad

输出
a
*/
#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    char a[105], b[105];
    cin >> a >> b;
    sort(a, a + strlen(a));
    sort(b, b + strlen(b));
    for (int i = 0; i < strlen(a) && i < strlen(b); i++)
        if (a[i] != b[i])
        {
            if (a[i] == b[i + 1])cout << b[i];
            if (b[i] == a[i + 1])cout << a[i];
            break;
        }

    return 0;
}