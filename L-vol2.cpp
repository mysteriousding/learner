/*
志愿活动分配

问题描述
小蓝和塔里是好朋友。
今天他们决定一起去完成一些志愿活动。
共有 n 个需要完成的志愿活动，每个志愿活动有自己的复杂度，第 i 个志愿活动的复杂度为 hi。

小蓝年纪较大，因此他想要承担那些复杂的志愿活动（hi>x），把较为简单的志愿活动留给塔里（hi≤x）。
两人商量后决定，完成 a 个活动，塔里完成 b 个活动（a+b=n）。

有多少种方法可以让他们选择一个整数 x，使得满足上述条件的情况下，小蓝正好完成 a 个活动，塔里正好完成 b 个活动。

输入格式
输入第一行包含两个整数 n,a,b，含义见上文。

输入第二行包含 n 个整数 h1,h2,…,hn，表示志愿活动的复杂度。

输出格式
输出包含一个整数，表示选择 x 的方法。

样例输入
5 2 3
6 2 3 100 1

样例输出
3

评测数据规模
对于所有评测数据，2≤n≤2000,a+b=n,a≥1,b≥1,1≤hi≤10^9。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    cout << arr[b--] - arr[b] << endl;

    return 0;
}