/*(1)策反加州

//题目描述
//来年一月份，特朗普将再次入主白宫，然而他却花了不少钱，这个时候，小 m 想知道，如果要让特朗普胜选，最少应该花多少钱。
//
//因此，小 m 查询了美国选举制度，发现选举有以下几种形式：
//
//一部分州在拿下一个州的一半及以上选民之后，即获得选票数要大于等于总票数的一半，就可以获得这个州的全部 M 张选举人票。
//
//一部分州在则会按照比例分配，即会获得（选举人票数 N× 自己获得的票数/该州所有选票数）下取整后的票数。
//
//还有一部分州会采取如果选票超过或等于一半，即获得选票数要大于等于总票数的一半，则会获得固定的 M 张选举人票，其余还有 N 张选举人票按照比例分配，与第二种情况类似。
//
//特朗普需要获得 w 的选票，或者获得或者超过 w 张选票，即可当选，而对于每个州而言，我们发现每多花 x 美元就可以使一个选民选择特朗普，
//请问，最小花费是多少，数据保证如果按照比例分配，则选民人数可以被选举人票数整除。
//
//输入格式
//第一行输入两个数个数 t，w，表示美国州的个数和获胜需要的选票数。
//
//接下来 t 行，每行包含 4 个整数 N,M,p,x，分别表示按照一半以上分配的选举人票数，按照比例分配的选举人票数，选民总人数，在该州每收获一个选民需要的费用。
//显然，如果 N=0，则为第一种情况，如果 M=0，则为第二种情况，其余状况均为第三章情况。
//
//输出格式
//输出一行一个数，表示特朗普当选总统所需要的最小花费。
//
//数据范围和约定
//t≤10^3 ,w≤10^4 ,1≤N+M≤10^4 ,N≥0,M≥0,p≤10^5 ,x<=10^9 ,p%N=0。
//
//输入输出样例
//输入样例 1
//5 21
//6 4 12 100
//3 2 9 100
//5 0 5 180
//0 6 10 150
//11 3 99 100
//输出样例 1
//2670
//样例解释 1
//总共有 40 张选票，我们先花 750 美元获得第 4 个州的全部选票 6 张，
//再花 600 美元获得第一个州 3 + 4 张选票，
//再花 720 美元获得第 3 个州的 4 张选票，
//最后耗费 600 美元获得第二个州的 2 + 2 张选票，
//共 21 张选票，花费 2570 元获得总统职位。

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct zhou
{
    int n;
    int m;
    int p;
    int x;
};

int main()
{
    int t,w,s,r,v;
    cin>>t>>w;
    vector<zhou>a(t);
    vector<int>dp(w+1,-1);
    dp[0]=0;
    for(int i=0;i<t;i++)
        cin>>a[i].n>>a[i].m>>a[i].p>>a[i].x;

    for(int k=0;k<t;k++)
    {
        vector<int>new_dp=dp;

        if(a[k].m>0)
            s=(a[k].p+1)/2*a[k].x;
            for(int i=0;i<=w;i++)
            {
                if(dp[i]==-1)continue;
                r=min(i+a[k].m,w);
                if(new_dp[r]==-1||new_dp[r]>dp[i]+s)
                    new_dp[r]=dp[i]+s;
            }

        if(a[k].n>0)
            for(int j=0;j<=a[k].p;j++)
            {
                s=j*a[k].x;
                v=0;
                if(a[k].m>0&&j>=(a[k].p+1)/2)
                    v=a[k].m+(a[k].n*j)/a[k].p;
                else v=(a[k].n*j)/a[k].p;

                if(v==0)continue;

                for(int i=w;i>=0;i--)
                {
                    if(dp[i]==-1)continue;
                    r=min(i+v,w);
                    if(new_dp[r]==-1||new_dp[r]>dp[i]+s)
                        new_dp[r]=dp[i]+s;
                }
            }

        dp.swap(new_dp);
    }
    cout<<dp[w]<<endl;

    return 0;
}
*/

/*(2)小游戏2.0

//题目描述
//在刷视频的时候，我们经常会遇到这种情况。
//我们看到一个小游戏广告。它会有 m 排每排 n 个数字，玩家手里有一个初始数字，并且从一个固定的位置出发，只能吃小于等于自己的数字，遇到大于它的数字就会输掉游戏。
//但是还演示的人经常会表现的十分的菜，以至于他经常通关不了游戏，这个时候你就想到能否使用代码能够算出如果每次走最优的情况下能最终能否通关。
//
//现在小 r 正在玩这个游戏，小 r 手速足够快，他可以瞬间碰到这一行的所有可以碰到的数字，但又由于小 r 手速过慢，他下一行只能从这一行最后一个吃到的数字的位置开始。
//
//小 r 想知道他手中的数字最后的值最大是多少。
//
//输入格式
//第一行一个数字 t，表示测试用例个数。
//
//对于每一个测试用例：
//
//第一行输入 4 个数字 n,m,x,p，分别表示每一行数字的个数，行数，初始值和初始位置。
//
//第二行一行输入 n 个数 ai ，表示每一行有哪些数字。
//
//输出格式
//一行一个数，表示答案。
//
//数据范围和约定
//t≤20, n≤2×10^5 ,m≤2×10^8 ,x ,ai≤2×10^5 。
//
//输入输出样例
//输入样例 1
//4
//4 10 1 1
//1 5 30 180
//4 10 1 3
//1 5 30 180
//10 10 1 5
//1000 200 2 6 1 5 2 3 4 400
//10 100 1 5
//1000 200 2 6 1 5 2 3 4 400
//输出样例 1
//136
//1
//165
//143635

#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int t,n,m,x,p,z,y;
    long long num,sum;
    vector<int>a;
    cin>>t;
    for(int k=0;k<t;k++)
    {
        cin>>n>>m>>x>>p;
        sum=x,z=p-1,y=p+1;
        a.resize(n+2,0);
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(a[p]>x){cout<<x<<endl;continue;}
        num=a[p];
        for(int j=0;j<m;j++)
        {
            sum+=num;
            while(z!=0||y!=n+1)
                if(z!=0&&a[z]<=sum)sum+=a[z],num+=a[z],z--;
                else if(y!=n+1&&a[y]<=sum)sum+=a[y],num+=a[y],y++;
                else break;
            if(z==0&&y==n+1)
            {
                sum+=num*(m-j-1);
                break;
            }
        }
        cout<<sum<<endl;
    }

    return 0;
}
*/

/*(3)数列游戏

//小明最近为了锻炼智力，在玩一个数列求和的游戏。设数列的长度为n，每一个数字都是整数，且在［-1000,1000］范围内，即范围是﹣1000~1000。
//游戏规则：小明可以从这个数列里面选一串任意长度的连续子串并求和，小明想知道子串和绝对值的最大值是多少，你能帮帮他吗？
//绝对值：正数的绝对值为本身，负数的绝对值为它的相反数。
//如5的绝对值为5,-7的绝对值为7.
//
//输入格式:
//输入共两行，第一行为一个整数n，第二行为n个整数。
//
//输出格式:
//输出一个数，为数列子串和绝对值的最大值。
//
//输入样例:
//10
//-562 232 969 201-111 378-610 127 245 932
//输出样例:
//2363

// #include<iostream>
// #include<cmath>
// #include<vector>
// using namespace std;
// int n,sum=0;
// vector<int>a;
// vector<bool>b;
// void dfs(int x,int num,int u)
// {
//     if(x>n||u==-1)
//     {
//         if(sum<abs(num))sum=abs(num);
//         return ;
//     }
//     for(int i=1;i<=n;i++)
//         if(b[i])
//         {
//             b[i]=0;
//             dfs(x+1,num+a[i],1);
//             b[i]=1;
//             dfs(x+1,num,u?-1:0);
//         }
// }

// int main()
// {
//     cin>>n;
//     a.resize(n+1);
//     b.resize(n+1,1);
//     for(int i=1;i<=n;i++)
//         cin>>a[i];
//     dfs(1,0,0);
//     cout<<sum<<endl;

//     return 0;
// }



//我的灵感
// #include<iostream>
// #include<vector>
// #include<cmath>
// using namespace std;
// int main()
// {
//     int n,m,h,sum=0;
//     cin>>n;
//     vector<int>a(n+1);
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         if(sum<abs(a[i]))sum=abs(a[i]);
//     }
//     m=a[1]+a[2];
//     if(sum<abs(m))sum=abs(m);
//     for(int i=2;i<n;i++)
//         if(i%2==0)
//         {
//             h=1;
//             while(h+i<=n)
//             {
//                 m+=a[h+i];
//                 m-=a[h++];
//                 if(sum<abs(m))sum=abs(m);
//             }
//             m+=a[--h];
//             if(sum<abs(m))sum=abs(m);
//         }
//         else
//         {
//             h=n;
//             while(h-i>=1)
//             {
//                 m+=a[h-i];
//                 m-=a[h--];
//                 if(sum<abs(m))sum=abs(m);
//             }
//             m+=a[++h];
//             if(sum<abs(m))sum=abs(m);
//         }
//     cout<<sum<<endl;

//     return 0;
// }



//Kadane‘s算法
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    int n,m1,m2,s1,s2;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    s1=s2=m1=m2=a[0];
    for(int i=1;i<n;i++)
    {
        m1=max(m1+a[i],a[i]);
        m2=min(m2+a[i],a[i]);
        s1=max(s1,m1);
        s2=max(s2,abs(m2));
    }
    cout<<(s1>=s2?s1:s2)<<endl;

    return 0;
}

*/

/*(4)生成格雷码--分治法

//格雷码是一种包含 2^n 个数串的序列，这种序列：
//
//1不存在重复的元素，
//
//2每个元素都是长度为n的二进制数串，
//
//3相邻元素只有一位不同。
//
//例如，长度为 2^3 的格雷码为：000，001，011，010，110，111，101，100。
//
//请使用分治法构造格雷码。
//
//提示，使用分治法构造格雷码，详见百度百科。
//
//输入格式:
//输入一个正整数n(1<=n<=10)。
//
//输出格式:
//输出 2^n 个n位的格雷码。
//
//输入样例:
//在这里给出一组输入。例如：
//
//4
//输出样例:
//在这里给出相应的输出。例如：
//
//0000
//0001
//0011
//0010
//0110
//0111
//0101
//0100
//1100
//1101
//1111
//1110
//1010
//1011
//1001
//1000

#include<iostream>
#include<string>
using namespace std;
int n;
string m="";
char a='0',b='1';
void fx(int x,bool u)
{
    if(x>=n)
    {
        cout<<m<<endl;
        return;
    }
        m[x]=u?a:b;
        fx(x+1,(u?u:!u));
        m[x]=u?b:a;
        fx(x+1,(!u?u:!u));
}
int  main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        m+='0';
    fx(0,1);

    return 0;
}
*/

//最优装载问题--贪心
//
//有一批集装箱要装上一艘重量为C的轮船。其中集装箱i的重量为wi，最优装载问题要求确定在装载体积不受限制的情况下，尽可能多得将集装箱装上轮船。
//
//输入格式:
//第1行输入1个整数C。为轮船的载重量。(1<=C<=1000)
//
//
//第2行输入1个整数n。为集装箱的数量。(1<=n<=1000)
//
//
//接下来输入n个整数，为每个集装箱的重量wi。(1<=wi<=1000)
//
//输出格式:
//输出1个整数，为最多装上船的集装箱的数量。
//
//输入样例:
//在这里给出一组输入。例如：
//
//500
//3
//300 200 100
//输出样例:
//在这里给出相应的输出。例如：
//
//2

#include<iostream>
#include<algorithm>
using namespace std;
int n, m, a[1010];
bool b[1010];
int dfs(int x, int num)
{
    if (x > n)return 0;
    if (num < a[x])return dfs(x + 1, num);
    else return max(dfs(x + 1, num), dfs(x + 1, num - a[x]) + 1);
}
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int sum = dfs(1, m);
    cout << sum << endl;

    return 0;
}
