﻿/*奇怪的数列

题目描述
从 X 星截获一份电码，是一些数字，如下：

13

1113

3113

132113

1113122113

⋯
⋯

YY 博士经彻夜研究，发现了规律：

第一行的数字随便是什么，以后每一行都是对上一行"读出来"

比如第 2 行，是对第 1 行的描述，意思是：1 个 1，1 个 3，所以是：1113

第 3 行，意思是：3 个 1,1 个 3，所以是：3113

请你编写一个程序，可以从初始数字开始，连续进行这样的变换。

输入描述
第一行输入一个数字组成的串，不超过 100 位。

第二行，一个数字n，表示需要你连续变换多少次，
n 不超过 20。

输出描述
输出一个串，表示最后一次变换完的结果。

输入输出样例
示例
输入

5
7

输出

13211321322115
*/

//第一次一遍通过！:）

#include <iostream>
#include<string>
using namespace std;
int main()
{
    int n, j, k;
    string m, m0;
    char u;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        j = 0, u = m[0];
        while (m[j] != '\0')
        {
            k = 0;
            while (m[j] == u)
                k++, j++;
            m0 += char(k + 48), m0 += u;
            u = m[j];
        }
        m = m0, m0 = "";
    }

    cout << m << endl;

    return 0;
}