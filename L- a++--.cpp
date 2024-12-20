/*
问题描述
贾母的寿辰即将到来，荣国府为了迎接这个重要的日子，决定将花园布置成贾母最喜欢的样子。

花园中一共摆放了N 块具有特殊属性的玉石，最开始所有玉石的属性值均为0。
贾母会根据自己的喜好进行调整，共会进行Q 次操作，每次操作为以下两种之一：

1 x y：将前x 块玉石的属性值增加y。
2 x y：将后x 块玉石的属性值减少y。

玉石的亮度值由其属性值的绝对值决定。请问在贾母完成所有操作后，玉石中的最大亮度值是多少？

输入格式
第一行输入两个整数 N , Q (1≤N≤10^9),1≤Q≤10^5)表示玉石的数量和贾母的调整次数。
接下来Q 行，每行三个整数tii,xi,yi(1≤ti≤2 , 1≤xi≤N,1≤yi≤10^9) 表示一次操作，
若ti=1 则表示执行操作1，ti=2 则执行操作2。

输出格式
输出一个整数表示答案。

样例输入
6 3
1 1 3
2 2 5
1 5 3
copy
样例输出
6
*/
#include <iostream>
#include<vector>
using namespace std;
// int main()
// {
//   long long x;
//   int y,k,n,m;
//   cin>>x>>y;
//   vector<long long>arr(x,0);
//   for(int i=0;i<y;i++)
//   {
//     cin>>k>>n>>m;
//     if(k==1)
//     for(int j=0;j<n;j++)
//     arr[j]+=m;
//     else
//     for(int j=y-n;j<y;j++)
//     arr[j]-=m;
//   }
//   long long max=arr[0];
//   for(int i=0;i<y;i++)
//   if(arr[i]>max)max=arr[i];
//   cout<<max<<endl;

//   return 0;
// }
int main()
{
    long long x, a1 = 0, a2 = 0;
    int y, k, n, m;
    cin >> x >> y;
    for (int i = 0; i < y; i++)
    {
        cin >> k >> n >> m;
        if (k == 1)
        {
            a1 += m;
            if (n >= x)a2 += m;
        }
        else
        {
            a2 -= m;
            if (n >= x)a1 -= m;
        }
    }
    a2 = -1 * a2;
    cout << ((a1 > a2) ? a1 : a2) << endl;

    return 0;
}