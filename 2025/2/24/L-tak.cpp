/*
外卖店优先级

题目描述
"饱了么"外卖系统中维护着 N 家外卖店，编号 1 ∼ N。
每家外卖店都有 一个优先级，初始时 (0 时刻) 优先级都为 0。

每经过 1 个时间单位，如果外卖店没有订单，则优先级会减少 1，最低减 到 0；
而如果外卖店有订单，则优先级不减反加，每有一单优先级加 2。

如果某家外卖店某时刻优先级大于 5，则会被系统加入优先缓存中；
如果 优先级小于等于 3，则会被清除出优先缓存。

给定 T 时刻以内的 M 条订单信息，请你计算 T 时刻时有多少外卖店在优先缓存中?

输入描述
第一行包含 3 个整数 N,M,T。

以下 M 行每行包含两个整数 ts,id，表示 ts 时刻编号 id 的外卖店收到一个订单。

其中，1≤N,M,T≤10^5 ，1≤ts≤T，1≤id≤N。

输出描述
输出一个整数代表答案。

输入输出样例
示例

输入
2 6 6
1 1
5 2
3 1
6 2
2 1
6 2

输出
1

样例解释：
6 时刻时，1 号店优先级降到 3，被移除出优先缓存；
2 号店优先级升到 6， 加入优先缓存。
所以是有 1 家店 (2 号) 在优先缓存中。
*/
// #include <iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;
// struct d
// {
//   int x;
//   int y;
// };
// bool pd(d&a,d&b)
// {
//   return a.x<b.x;
// }
// int main()
// {
//   int n,m,t,i,h,r,num=0;
//   cin>>n>>m>>t;
//   vector<d>a(m+1);
//   vector<int>b(n+1,0);
//   vector<bool>c(n+1,1),q(n+1,0);
//   for(i=0;i<m;i++)
//   cin>>a[i].x>>a[i].y;
//   sort(a.begin(),a.end()-1,pd);
//   r=h=a[0].x,i=0;
//   while(i<=m)
//   {
//     for(;i<=m;i++)
//     if(h==a[i].x)
//     {
//       b[a[i].y]+=2,c[a[i].y]=0;
//       if(b[a[i].y]>5)q[a[i].y]=1;
//     }
//     else
//     {
//       for(int j=1;j<=n;j++)
//       {
//         b[j]-=c[j]?r:(r-1);
//         if(b[j]<0)b[j]=0;
//         if(q[j]&&b[j]<=3)q[j]=0;
//         c[j]=1;
//       }
//       r=a[i].x-h,h=a[i].x;
//       if(a[i].y)break;
//     }
//     if(h>t)break;
//   }
//   for(i=1;i<=n;i++)
//   if(q[i])
//   num++;
//   cout<<num<<endl;

//   return 0;
// }



#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct d
{
    int x;
    int y;
};
bool pd(d& a, d& b)
{
    return a.x < b.x;
}
int main()
{
    int n, m, t, i, h, r, num = 0;
    cin >> n >> m >> t;
    vector<d>a(m + 1);
    vector<int>b(n + 1, 0), c(n + 1, 0);
    vector<bool>q(n + 1, 0);
    for (i = 0; i < m; i++)
        cin >> a[i].x >> a[i].y;
    sort(a.begin(), a.end() - 1, pd);
    r = h = a[0].x, i = 0;
    while (i <= m)
    {
        for (; i <= m; i++)
            if (h == a[i].x)c[a[i].y]++;
            else
            {
                for (int j = 1; j <= n; j++)
                {
                    b[j] -= c[j] ? (r - 1) : r;
                    if (b[j] < 0)b[j] = 0;
                    b[j] += 2 * c[j], c[j] = 0;
                    if (b[j] > 5)q[j] = 1;
                    else if (q[j] && b[j] <= 3)q[j] = 0;

                }
                r = a[i].x - h, h = a[i].x;
                if (a[i].y)break;
            }
        if (h > t)break;
    }
    for (i = 1; i <= n; i++)
        if (q[i])
            num++;
    cout << num << endl;

    return 0;
}
