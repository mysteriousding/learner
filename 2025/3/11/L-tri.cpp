/*
上三角方阵

题目描述
方阵的主对角线之上称为"上三角"。

请你设计一个用于填充 n 阶方阵的上三角区域的程序。
填充的规则是：使用 1，2，3.... 的自然数列，从左上角开始，按照顺时针方向螺旋填充。

例如：当 n=3 时，输出：

1 2 3

6 4

5

当 n=4 时，输出：

1 2 3 4

9 10 5

8 6

7

当 n=5 时，输出：

1 2 3 4 5

12 13 14 6

11 15 7

10 8

9

输入描述
要求用户输入整数 n （3≤n≤20）。

输出描述
输出方阵的上三角部分。

要求每个数据宽度为 4，右对齐。

输入输出样例
示例

输入
9

输出
1 2 3 4 5 6 7 8 9
24 25 26 27 28 29 30 10
23 39 40 41 42 31 11
22 38 45 43 32 12
21 37 44 33 13
20 36 34 14
19 35 15
18 16
17
*/
#include <iostream>
using namespace std;
int a[21][21] = { {0},{0,1} };
int main()
{
    int n, j = 1;
    cin >> n;
    for (int i = 1; i <= n / 2; i++)
    {
        for (int k = i; k <= n - 2 * i + 2; k++)
            a[i][k] = j++;
        for (int k = n - 2 * i + 1; k >= i; k--)
            a[n - i + 2 - k][k] = j++;
        for (int k = n - 2 * i + 1; k > i; k--)
            a[k][i] = j++;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= n - i + 1; k++)
        {
            if (k - 1)cout << " ";
            cout << a[i][k];
        }
        cout << endl;
    }

    return 0;
}
