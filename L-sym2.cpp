/*
对称矩阵

问题描述
给定一个 n×n 的矩阵 H，若对于任意 1≤i,j≤n，有 Hij = Hji ，则称矩阵 H 为对称矩阵。
问，矩阵 H 是否为对称矩阵？

输入格式
第一行包含一个整数 n，含义与问题描述中相同。

接下来 n 行，每行包含 n 个整数，第 i+1 行的第 j 个整数表示 Hij。

输出格式
输出共一行，若矩阵 H 是对称矩阵则输出 1，否则输出 0。

样例输入
3
1 2 3
2 4 5
3 5 5

样例输出
1

评测数据规模
1≤n≤10^3。
1≤Hij≤10^9。
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    bool v = 1;
    cin >> n;
    vector<vector<int>>a(n, vector<int>(n));
    for (int i = 0; i < n && v; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (i && j < i && a[i][j] != a[j][i])
            {
                v = 0;
                break;
            }
        }
    cout << v << endl;

    return 0;
}