/*】】】
内嵌区间数

问题描述
怂怂有一组线段，总共 N 条。
每条线段 i 由两个整数 li 和 ri 表示，分别代表线段的左端点和右端点。
如果线段 i 的两个端点都严格在线段 j 的内部（即 lj<li 且 ri<rj），我们就称线段 i 被线段 j 内嵌。
怂怂想知道，在这组线段中，有多少条线段至少被另一条线段内嵌。

输入格式
输入的第一行包含一个整数 N。

接下来的 N 行，每行包含两个整数 li 和 ri，代表每条线段的左端点和右端点。

输出格式
输出一行，一个整数，表示至少被一条其他线段内嵌的线段数量。

样例输入
4
0 5
2 6
3 4
0 7

样例输出
2

评测数据规模
2≤N≤100
0≤li≤ri≤100
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m = 0;
    cin >> n;
    vector<int>a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] < a[j] && b[j] < b[i])
                m++, a[j] = b[j] = -1;
            else if (a[i] > a[j] && b[j] > b[i])
                m++, a[i] = b[i] = -1;
    cout << m << endl;

    return 0;
}
