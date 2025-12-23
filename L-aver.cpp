/*
子序列平均值
分数 20
作者 mjye
单位 北京师范大学珠海校区
给定一个有 n 个整数的数列 a。
请找出一个长度至少为 k 的连续子序列，使这个子序列的所有数的平均值最大。

输入格式:
输入共 2 行。
第一行输入两个整数 n,k(1≤k≤n≤3×10^5)。
第二行输入 n 个整数 a1 ,a2 ,…,an (1≤ai ≤10^6 )，表示数列 a 的所有数。

输出格式:
输出仅一行，一个实数，表示长度至少为 k 的连续子序列的数的最大平均值。
保留 6 位小数。

输入样例1:
4 1
1 2 3 4
输出样例1:
4.000000
输入样例2:
4 2
2 4 3 4
输出样例2:
3.666666
输入样例3:
6 3
7 1 2 1 3 6
输出样例3:
3.333333
*/
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
const double eps = 1e-7;
bool ok(const vector<int>& a, int k, double m)
{
    int n = a.size();
    vector<double>s(n + 1);
    double mn = 0;
    for (int i = 1; i <= n; ++i)
        s[i] = s[i - 1] + a[i - 1] - m;
    for (int i = k; i <= n; ++i)
    {
        mn = min(mn, s[i - k]);
        if (s[i] - mn >= 0)
            return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int>a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    double l = 1, r = 1e6;
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (ok(a, k, mid))l = mid;
        else r = mid;
    }
    cout << fixed << setprecision(6) << l << '\n';
    return 0;

}

