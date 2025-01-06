/*交换瓶子

题目描述
有N 个瓶子，编号 1 ~N，放在架子上。

比如有 5 个瓶子：

2 1 3 5 4

要求每次拿起 2 个瓶子，交换它们的位置。

经过若干次后，使得瓶子的序号为：

1 2 3 4 5

对于这么简单的情况，显然，至少需要交换 2 次就可以复位。

如果瓶子更多呢？你可以通过编程来解决。

输入描述
输入格式为两行：

第一行: 一个正整数N (N<10^4), 表示瓶子的数目

第二行：
N 个正整数，用空格分开，表示瓶子目前的排列情况。

输出描述
输出数据为一行一个正整数，表示至少交换多少次，才能完成排序。

输入输出样例
示例
输入
5
3 1 2 5 4

输出
3
*/
#include <iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    int n, j = 0, h;
    cin >> n;
    vector<int>m(n);
    for (int i = 0; i < n; i++)
        cin >> m[i];

    for (int i = 0; i < n; i++)
        if (m[i] != i + 1)
        {
            h = m[m[i] - 1];
            m[m[i] - 1] = m[i];
            m[i--] = h;
            j++;
        }

    cout << j << endl;

    return 0;
}
