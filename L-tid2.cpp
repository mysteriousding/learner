/*
洁净数

题目描述
小明非常不喜欢数字 2，包括那些数位上包含数字 2 的数。
如果一个数的数位不包含数字 2，小明将它称为洁净数。

请问在整数 1 至 n 中，洁净数有多少个？

输入描述
输入的第一行包含一个整数 n(1≤n≤10^6)。

输出描述
输出一行包含一个整数，表示答案。

输入输出样例
示例
输入
30

输出
18
*/
#include <iostream>
using namespace std;
int main()
{
    int n, h, num = 0, k;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        h = i, k = 1;
        while (h)
        {
            if (h % 10 == 2)
            {
                k = 0;
                break;
            }
            h /= 10;
        }
        num += k;
    }
    cout << num << endl;

    return 0;
}
