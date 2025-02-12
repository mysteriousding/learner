/*
最大距离

题目描述
在数列 a1,a2,⋯,an 中，定义两个元素 ai 和 aj 的距离为 ∣i−j∣+∣ai−aj∣ ，即元素下标的距离加上元素值的差的绝对值，其中∣x∣表示 x 的绝对值。

给定一个数列，请问找出元素之间最大的元素距离。

输入描述
输入的第一行包含一个整数n。

第二行包含 n 个整数 a1,a2,⋯,an ，相邻的整数间用空格分隔，表示给定的数列。

其中，2≤n≤1000，0≤数列中的数≤10^4。

输出描述
输出一行包含一个整数，表示答案。

输入输出样例

示例

输入
5
9 4 2 4 7

输出
9
*/
#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int n, max = 0, h;
    cin >> n;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            h = abs(i - j) + abs(a[i] - a[j]);
            if (max < h)max = h;
        }
    cout << max << endl;

    return 0;
}