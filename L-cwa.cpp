/*
井水注满的最小桶数

问题描述
乐乐负责为村庄的 N 口井注水，每口井需要一定量的水。乐乐有无限多桶水，每桶水的容量都是 100 单位。
现在，乐乐想知道至少需要多少桶水才能至少为 K 口井注满水。

输入格式
第一行包含两个整数 N 和 K。

第二行包含 N 个整数，表示每口井所需水的容量。

输出格式
输出一个整数，表示至少需要的桶水数量。

样例输入
5 4
1 2 3 2 1

样例输出
1

评测数据规模
1≤K≤N≤100
井的容量为介于 1 和 1000 的整数
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, k, m = 0;
    cin >> n >> k;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < k; i++)
        m += a[i];
    cout << m / 100 + (m % 100 != 0) << endl;

    return 0;
}
