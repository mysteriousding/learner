/*
分巧克力

问题描述
儿童节那天有K 位小朋友到小明家做客。小明拿出了珍藏的巧克力招待小朋友们。

小明一共有N 块巧克力，其中第i 块是 Hi×Wi 的方格组成的长方形。为了公平起见，

小明需要从这N 块巧克力中切出 K 块巧克力分给小朋友们。切出的巧克力需要满足：

形状是正方形，边长是整数;
大小相同;

例如一块
6×5 的巧克力可以切出6 块 2×2 的巧克力或者2 块 3×3 的巧克力。

当然小朋友们都希望得到的巧克力尽可能大，你能帮小明计算出最大的边长是多少么？

输入描述
第一行包含两个整数 N,K (1≤N,K≤10^5)。

以下 N 行每行包含两个整数 Hi,Wi (1≤Hi,Wi≤10^5)

输入保证每位小朋友至少能获得一块 1x1 的巧克力。

输出描述
输出切出的正方形巧克力最大可能的边长。

输入输出样例
示例
输入

2 10
6 5
5 6

输出

2
*/
#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int n, m, k = 2, sum;
    cin >> n >> m;
    vector<int>x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    while (1)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += (x[j] / k) * (y[j] / k);
            if (sum >= m)break;
        }
        if (sum < m)
        {
            cout << k - 1 << endl;
            break;
        }
        k++;
    }

    return 0;
}
