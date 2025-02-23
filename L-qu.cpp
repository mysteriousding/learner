/*
完全二叉树的权值

题目描述
给定一棵包含  个节点的完全二叉树，树上每个节点都有一个权值，按从 上到下、从左到右的顺序依次是 A1,A2,⋅⋅⋅AN ，如下图所示：

https://doc.shiyanlou.com/courses/uid1580206-20210202-1612250434110

现在小明要把相同深度的节点的权值加在一起，他想知道哪个深度的节点 权值之和最大？
如果有多个深度的权值和同为最大，请你输出其中最小的深度。

注：根的深度是 1。

输入描述
第一行包含一个整数 N（1≤N≤10^5 ）。

第二行包含 N 个整数 A1,A2,⋅⋅⋅AN （−10^5 ≤Ai ≤10^5 ）。

输出描述
输出一个整数代表答案。

输入输出样例
示例

输入
7
1 6 5 4 3 2 1

输出
2
*/
#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int n, h, num, sum = -10000, j = 0;
    cin >> n;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1, k = 1; j <= n; i = 2 * i + 1, k++)
    {
        num = 0;
        for (; j <= i && j <= n; j++)
            num += a[j];
        if (num > sum)sum = num, h = k;
    }
    cout << h << endl;

    return 0;
}