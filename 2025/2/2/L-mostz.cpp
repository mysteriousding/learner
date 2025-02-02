/*
最多个质数【UUST】

问题描述
有一个正整数序列 a，序列包含 n 个元素，分别为 a1,a2, ... ,an ，现在你可以对序列所有元素进行两两相加得到一个包含 2/n 个元素的新序列 b。

已知序列 a 中每个元素至多被相加 1 次，问： b 中最多有多少个质数？

输入格式
输入第 1 行包含一个正整数 n(n∈[2,200])，表示 a 序列元素个数且 n 为偶数。

输入第 2 行包含 n 个正整数 ai​(ai​ ∈[2,5×10^5])，两数之间用空格隔开。

输出格式
输出一行，这一行只包含一个整数，表示答案。

样例输入1
6
3 3 2 9 4 8

样例输出1
3

样例输入2
4
2 2 2 2

样例输出2
0


说明/提示
对于所有评测数据，
2≤n≤200，2≤ai≤5×10^5，n 为偶数。

样例 1​ 中，可以进行如下操作：

b1 = a1 + a3 = 3 + 2 = 5
b2 = a2 + a5 = 3 + 4 = 7
b3 = a4 + a6 = 9 + 8 = 17

因此，生成的新序列 b 里面最多可以有 3 个质数。
*/
#include <iostream>
#include<algorithm>
using namespace std;
int a[210], b[210] = { 0 };
int n, sum = 0;
int dfs(int x)
{
    if (x >= n)return 0;
    for (int i = 0; i < n; i++)
        if (!a[i])
            for (int j = i + 1; j < n; j++)
                if (!a[j])
                {
                    int h = a[i] + a[j], u = 1;
                    b[i] = b[j] = 1;
                    for (int k = 2; k * k <= h; k++)
                        if (h % k == 0) { u = 0; break; }
                    u += dfs(x + 2);
                    b[i] = b[j] = 0;
                    return u;
                }

}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dfs();
    cout << sum < endl;

    return 0;
}
