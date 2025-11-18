/*
1、用贪心算法解决活动安排问题。
设有n个活动的集合E={1, 2, …, n}，其中每个活动都要求使用同一资源，而在同一时间内只有一个活动能使用这一资源。
每个活动i都有一个要求使用该资源的起始时间si和一个结束时间fi,且si <fi 。
如果选择了活动i，则它在半开时间区间[si, fi)内占用资源。
若区间[si, fi)与区间[sj, fj)不相交，则称活动i与活动j是相容的。
也就是说，当si≥fj或sj≥fi时，活动i与活动j相容。
活动安排问题就是要在所给的活动集合中选出最大的相容活动子集合。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct d 
{    
    int s, e;
};
bool cmp(const d& a, const d& b) 
{
    return a.e < b.e;
}
int main()
{
    int n;
    cin >> n;
    vector<d> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i].s >> a[i].e;
    
    sort(a.begin(), a.end(), cmp); 
    int last = -1;  // 上一个结束时间
    int count = 0;  // 选中数量

    cout << "选中的活动时间：" << endl;
    for (auto& l : a)
        if (l.s >= last)
        {
            cout << "[" << l.s << "," << l.e << ")" << endl;
            last = l.e;
            count++;
        }
    cout << "共选中 " << count << " 个活动" << endl;

    return 0;

}


