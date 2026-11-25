/*】】
卓卓的奇数数对和

问题描述
卓卓有一个 N 个整数的数组。她希望消除最小数量的元素，以便在结果数组中，任意两个相邻值的和都是奇数。

输入格式
第一行包含一个整数 N。

第二行包含数组的 N 个元素 ai。

输出格式
输出一个整数，表示需要消除的最小元素数量。

样例输入
5
1 3 5 4 2

样例输出
3

评测数据规模
1≤N≤10^5 ，0≤ai≤10^9 。
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m = 0;
    bool b;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    b = a[0] % 2;
    for (int i = 1; i < n; i++)
        if (b == a[i] % 2)
            m++;
        else
            b = !b;
    cout << m << endl;

    return 0;
}
