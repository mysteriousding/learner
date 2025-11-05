/*
2、0-1背包问题。
现有n种物品，对1<=i<=n，已知第i种物品的重量为正整数Wi，价值为正整数Vi，背包能承受的最大载重量为正整数W，现要求找出这n种物品的一个子集，使得子集中物品的总重量不超过W且总价值尽量大。
（注意：这里对每种物品或者全取或者一点都不取，不允许只取一部分）
使用动态规划使得装入背包的物品价值之和最大。
*/
#include <iostream>
#include <vector>
using namespace std;
int main() 
{
    int W, n;
    cin >> W >> n; // 输入背包的最大载重量和物品的数量
    vector<int> w(n), v(n), dp(W + 1, 0); // 分别存储物品的重量、价值和动态规划表
    for (int i = 0; i < n; i++) // 输入每个物品的重量和价值
        cin >> w[i] >> v[i];

    // 动态规划求解
    for (int i = 0; i < n; i++) // 遍历每个物品
        for (int j = W; j >= w[i]; j--) // 逆序遍历背包容量，避免重复使用物品
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);// 更新当前背包容量下的最大价值

    cout << dp[W] << endl; // 输出最大价值

    return 0;

}




