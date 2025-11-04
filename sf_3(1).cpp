/*
1、用代码实现矩阵连乘问题。
给定n个矩阵{A1,A2,…,An}，其中Ai与Ai+1是可乘的，i=1,2,…,n-1。
考察这n个矩阵的连乘积A1A2…An。
由于矩阵乘法满足结合律，故计算矩阵的连乘积可以有许多不同的计算次序，这种计算次序可以用加括号的方式来确定。
若一个矩阵连乘积的计算次序完全确定，则可以依此次序反复调用2个矩阵相乘的标准算法，计算出矩阵连乘积。
确定一个计算顺序，使得需要的乘法次数最少。
*/
#include <iostream>
#include <vector>
using namespace std;

// 递归函数，用于打印最优的括号化方案
void sc(const vector<vector<int>>& s, int i, int j)
{
    if (i == j) // 如果只有一个矩阵
        cout << "A" << i + 1; // 直接输出矩阵名称
    else // 如果有多个矩阵
    {
        cout << "("; // 输出左括号
        sc(s, i, s[i][j]); // 递归打印左子链
        sc(s, s[i][j] + 1, j); // 递归打印右子链
        cout << ")"; // 输出右括号
    }
}

int main()
{
    int n, q, k; // n为矩阵数量，q为临时变量，k为链的结束位置
    cin >> n;    // 输入矩阵的数量
    vector<int> p(n + 1); // 存储矩阵的维度
    vector<vector<int>> m(n, vector<int>(n, 0)), s(n, vector<int>(n, 0)); // m存储最小乘法次数，s存储最优分割点
    for (int i = 0; i <= n; ++i) // 输入每个矩阵的维度
        cin >> p[i];

    // 动态规划计算最小乘法次数和最优分割点
    for (int i = 2; i <= n; i++) // 链的长度从2到n
        for (int j = 0; j <= n - i; j++) // 链的起始位置
        {
            k = j + i - 1; // 链的结束位置
            m[j][k] = INT_MAX; // 初始化为最大值
            for (int l = j; l < k; l++) // 可能的分割点
            {
                q = m[j][l] + m[l + 1][k] + p[j] * p[l + 1] * p[k + 1]; // 计算分割点的乘法次数
                if (q < m[j][k]) // 如果找到更小的乘法次数
                    m[j][k] = q, s[j][k] = l; // 更新最小乘法次数和最优分割点
            }
        }

    cout << m[0][n - 1] << endl; // 输出最小乘法次数
    sc(s, 0, n - 1); // 打印最优的括号化方案
    cout << endl;

    return 0;

}

