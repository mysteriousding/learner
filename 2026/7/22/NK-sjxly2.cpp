/*
题目描述
给定一个长度为 n 的数组 a，在一次操作中，你可以选择数组中的任意 k 个整数，并将它们缩小为它们的中位数——也就是说，将选出的这 k 个元素都替换为这 k 个元素的中位数。
你必须恰好执行一次这样的缩小操作。求操作后数组中所有元素的最大可能和。
中位数的定义：将选出的 k 个整数按非递减顺序排序为 b1 <= b2 <= ... <= bk。
如果 k 是奇数，则中位数是唯一的中间元素：b((k+1)/2)。
如果 k 是偶数，则中位数是两个中间元素的平均值：(b(k/2) + b(k/2+1))/2。

输入描述
每个测试包含多个测试用例。第一行包含测试用例数 T（1 <= T <= 10^4）。接下来是每个测试用例的描述。
每个测试用例的第一行包含两个整数 n 和 k（1 <= k <= n <= 2*10^5）——数组 a 的元素个数和所选子集的大小。
每个测试用例的第二行包含 n 个整数 a1, a2, ..., an（1 <= ai <= 10^9）——数组 a 的元素。
保证所有测试用例的 n 之和不超过 2*10^5。

输出描述
对于每个测试用例，输出一个整数，表示恰好执行一次操作后数组所有元素的最大和。可以证明答案始终是整数。

示例1
输入
2
6 3
1 1 4 5 1 4
4 2
1 3 6 10
输出
19
20
说明
对于第一个测试用例，我们可以选择 {1,4,4} 并缩小为它们的中位数 4。数组变为 {4,1,4,5,1,4}，元素和为 19。可以证明没有其他缩小操作能得到更大的结果。
对于第二个测试用例，我们可以选择 {1,10} 并缩小为它们的中位数 5.5。数组变为 {5.5,3,6,5.5}，元素和为 20。可以证明没有其他缩小操作能得到更大的结果。
*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    int t, n, k, sum, h, th, tc, tw, m, ma, x[3];
//    bool v, u, p;
//    vector<int>a, b;
//    cin >> t;
//    while (t--)
//    {
//        cin >> n >> k;
//        a.resize(n), b.resize(k);
//        v = k % 2, sum = 0;
//        x[0] = (k + 1) / 2 - 1, x[1] = k / 2 - 1, x[2] = k / 2;
//        for (int i = 0; i < n; i++)
//        {
//            cin >> a[i];
//            sum += a[i];
//            if (i < k)
//                b[i] = a[i];
//        }
//        sort(b.begin(), b.end());
//        ma = -1;
//        for (int j = k; j < n; j++)
//        {
//            if (v)h = b[x[0]];
//            else h = (b[x[1]] + b[x[2]]) / 2;
//            tc = a[j - k], th = a[j], u = 1, p = 1, tw = k-1;
//            m = 0;
//            for (int i = 0; i < k; i++)
//            {
//                m += h - b[i];
//                if (u && th <= b[i])tw = i, u = 0;
//                if (p && tc == b[i])tc = i, p = 0;
//            }
//            if (ma < m)ma = m;
//            h = (tw < tc ? -1 : 1);
//            for (int i = tc; i != tw; i += h)
//                b[i] = b[i + h];
//            b[tw] = th;
//        }
//        cout << sum + ma << endl;
//    }
//
//    return 0;
//}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t, n, k, sum, h, th, tc, tw, m, ma, x[3];
    bool v, u, p;
    vector<int>a, b;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        a.resize(n), b.resize(k);
        v = k % 2, sum = 0;
        x[0] = (k + 1) / 2 - 1, x[1] = k / 2 - 1, x[2] = k / 2;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        sort(a.begin(), a.end());
        ma = -1;
        for (int j = k; j < n; j++)
        {
            if (v)h = b[x[0]];
            else h = (b[x[1]] + b[x[2]]) / 2;
            tc = a[j - k], th = a[j], u = 1, p = 1, tw = k - 1;
            m = 0;
            for (int i = 0; i < k; i++)
            {
                m += h - b[i];
                if (u && th <= b[i])tw = i, u = 0;
                if (p && tc == b[i])tc = i, p = 0;
            }
            if (ma < m)ma = m;
            h = (tw < tc ? -1 : 1);
            for (int i = tc; i != tw; i += h)
                b[i] = b[i + h];
            b[tw] = th;
        }
        cout << sum + ma << endl;
    }

    return 0;
}
