/*
级数求和

题目描述
已知：

Sn=1＋1/2＋1/3＋⋯＋1/n 。

显然对于任意一个整数 K，当 n 足够大的时候， Sn 大于 K。

现给出一个整数 K（1≤k≤15），要求计算出一个最小的 n ,使得 Sn＞K。

输入描述
输入一个整数 K。

输出描述
输出一个整数 n。

输入输出样例
示例 1
输入
1

输出
2
*/
#include <iostream>
using namespace std;
int main()
{
    double n, m = 0;
    cin >> n;
    for (int i = 1;; i++)
    {
        m += 1.0 / i;
        if (m > n)
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
