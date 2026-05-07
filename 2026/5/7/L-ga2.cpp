/*
最大

其中，1≤n≤1000，1≤ai≤10^5。

输出描述
输出一个整数，表示序列中最大的间隙值。

输入输出样例
示例 1
输入
5
1 3 8 9 12

输出
5
*/
#include <iostream>
using namespace std;
int main()
{
    int n, x, y, z = 0;
    cin >> n >> y;
    for (int i = 0; i < n; i++)
    {
        x = y;
        cin >> y;
        if (y - x > z)
            z = y - x;
    }
    cout << z << endl;

    return 0;
}
