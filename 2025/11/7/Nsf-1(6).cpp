/*
· 例5-【模板】静态区间和（前缀和）

题目描述
对于给定的长度为 n 的数组 {a1 ,a2 ,…,an } ，你需要构建一个能够维护区间和信息的数据结构，使得其能支持：
∙ 区间和查询：输出 [l,r] 这个区间中的元素之和，即 ∑(r)(i=l)ai 。


输入描述:
第一行输入两个整数 n,q(1≦n,q≦10^6 ) 代表数组中的元素数量、操作次数。
第二行输入 n 个整数 a1 ,a2 ,…,an(−10^9≦ai≦10^9 ) 代表初始数组。
此后 q 行，每行输入两个整数 l,r(1≦l≦r≦n) 代表区间和查询。


输出描述:
对于每一次询问，输出一行一个整数代表区间和。

示例1
输入
3 2
1 2 4
1 2
2 3
输出
3
6
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, m, r, l;
    cin >> n >> m;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> r >> l;
        cout << a[l] - a[r - 1] << endl;
    }

    return 0;

}
