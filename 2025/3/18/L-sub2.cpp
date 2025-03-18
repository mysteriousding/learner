/*
最多有 k 个字符的最长子字符串

题目描述
实现一个算法找到一个字符串中最多有 k 个字符的最长子字符串，并得到它的长度。
介绍如下：

例如字符串 abcabcdefgghighij，最多有 3 个字符的最长子字符串为 gghighi 它的长度为 7。
输入描述
第一行为一串字符串，长度不超过 100。

第二行为数字 k，含义见题干。

输出描述
输出一个数字，为最多有 k 个字符的最长子字符串的长度。

输入输出样例
示例

输入
abcabcdefgghighi
3

输出
7
*/
#include <iostream>
#include<string>
using namespace std;
int main()
{
    string n;
    char a[100] = { 0 };
    int sum = 0, num, i = 0, j = 0, u, h = 0, t;
    cin >> n >> t;
    for (; i < n.size();)
    {
        u = 1;
        for (int k = 0; k < t; k++)
            if (a[k] == n[i])
            {
                if (k == 0)h = i;
                u = 0;
                break;
            }
        if (u)
            if (j < t)a[j++] = n[i];
            else
            {
                for (int k = 0; k < t - 1; k++)
                    a[k] = a[k + 1];
                a[t - 1] = n[i];
                sum = i - h;
                break;
            }
        i++;
    }

    for (; i < n.size();)
    {
        for (; i < n.size();)
        {
            u = 1;
            for (int k = 0; k < t; k++)
                if (a[k] == n[i])
                {
                    if (k == 0)h = i;
                    u = 0;
                    break;
                }
            if (u)
            {
                for (int k = 0; k < t - 1; k++)
                    a[k] = a[k + 1];
                a[t - 1] = n[i];
                num = i - h;
                break;
            }
            i++;
        }
        if (sum < num)sum = num;
    }
    cout << sum << endl;

    return 0;
}
