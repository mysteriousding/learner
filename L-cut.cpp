/*
剪格子

题目描述
如下图所示，3 x 3 的格子中填写了一些整数。

https://doc.shiyanlou.com/courses/uid1580206-20210202-1612250769606

我们沿着图中的红色线剪开，得到两个部分，每个部分的数字和都是 60。

本题的要求就是请你编程判定：对给定的 m×n 的格子中的整数，是否可以分割为两个部分，使得这两个区域的数字和相等。

如果存在多种解答，请输出包含左上角格子的那个区域包含的格子的最小数目。

如果无法分割，则输出 0。

输入描述

程序先读入两个整数 m,n 用空格分割 (m,n<10)，表示表格的宽度和高度。

接下来是 n 行，每行 m 个正整数，用空格分开。每个整数不大于 10^4 。

输出描述
在所有解中，包含左上角的分割区可能包含的最小的格子数目。

输入输出样例
示例

输入
3 3
10 1 52
20 30 1
1 2 3

输出
3
*/
#include <iostream>
using namespace std;
int n, m, sum = 0, q = 10000, N[1010][1010];
bool M[1010][1010] = { 0 };
void dfs(int x, int num)
{
    if (num > sum)return;
    if (num == sum)
    {
        if (x < q)q = x;
        return;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!M[i][j])
            {
                M[i][j] = 1;
                dfs(x + 1, num + N[i][j]);
                M[i][j] = 0;
            }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> N[i][j];
            sum += N[i][j];
        }
    sum /= 2;
    dfs(0, 0);
    cout << (q == 10000 ? 0 : q) << endl;

    return 0;
}