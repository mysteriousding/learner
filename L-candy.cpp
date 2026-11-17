/*】]]
拥有糖果最多的小朋友

问题描述
有 n 个小朋友，编号为 1 到 n。
有 m 颗糖果，编号为 1 到 m。
第 i 颗糖果将分给编号为 ai 的小朋友。
问，哪个小朋友获得的糖果最多？

输入格式
第一行包含两个整数 n,m，含义与问题描述中相同。

第二行包含 m 个整数，依次表示 a1 到 am。

输出格式
输出共一行，包含一个整数，表示获得糖果最多的小朋友的编号。
若获得糖果最多的小朋友不止一个，则输出其中编号最小的。

样例输入
3 5
1 2 3 2 1

样例输出
1

评测数据规模
1≤n≤10^5。
1≤m≤10^5。
1≤ai≤n。
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m, h, k;
    cin >> n >> m;
    vector<int>a(n + 1, 0);
    for (int i = 0; i < m; i++)
        cin >> h, a[h]++;
    h = k = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] > h)
            h = a[i], k = i;
    cout << k << endl;

    return 0;
}
