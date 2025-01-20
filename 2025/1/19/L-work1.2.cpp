/*(6)用扑克牌计算24点

//一副扑克牌的每张牌表示一个数（J、Q、K 分别表示 11、12、13，两个司令都表示 6）。
//任取4 张牌，即得到 4 个 1~13 的数，请添加运算符（规定为加+ 减- 乘* 除/ 四种）使之成为一个运算式。
//每个数只能参与一次运算，4 个数顺序可以任意组合，4 个运算符任意取 3 个且可以重复取。
//运算遵从一定优先级别，可加括号控制，最终使运算结果为 24。
//请输出一种解决方案的表达式，用括号表示运算优先。
//如果没有一种解决方案，则输出 -1 表示无解。
//
//输入格式：
//输入在一行中给出 4 个整数，每个整数取值在 [1, 13]。
//
//输出格式：
//输出任一种解决方案的表达式，用括号表示运算优先。如果没有解决方案，请输出 -1。
//
//输入样例：
//2 3 12 12
//输出样例：
//((3-2)*12)+12


*/

/*(7)互评成绩

//学生互评作业的简单规则是这样定的：
//每个人的作业会被k个同学评审，得到k个成绩。
//系统需要去掉一个最高分和一个最低分，将剩下的分数取平均，就得到这个学生的最后成绩。
//本题就要求你编写这个互评系统的算分模块。
//
//输入格式：
//输入第一行给出3个正整数N（3 < N ≤10^4 ，学生总数）、k（3 ≤ k ≤ 10，每份作业的评审数）、M（≤ 20，需要输出的学生数）。
//随后N行，每行给出一份作业得到的k个评审成绩（在区间[0, 100]内），其间以空格分隔。
//
//输出格式：
//按非递减顺序输出最后得分最高的M个成绩，保留小数点后3位。分数间有1个空格，行首尾不得有多余空格。
//
//输入样例：
//6 5 3
//88 90 85 99 60
//67 60 80 76 70
//90 93 96 99 99
//78 65 77 70 72
//88 88 88 88 88
//55 55 55 55 55
//输出样例：
//87.667 88.000 96.000

#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
struct stu
{
    stu(int k):num(0)
    {
        sc.resize(k);
    }
    vector<int>sc;
    int max;
    int min;
    float num;
};
int main()
{
    int n,k,m;
    cin>>n>>k>>m;
    vector<stu>arr(n,stu(k));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            //arr[i].resize(k);
            cin>>arr[i].sc[j];
            arr[i].num+=arr[i].sc[j];
            if(!j||arr[i].max<arr[i].sc[j])arr[i].max=arr[i].sc[j];
            if(!j||arr[i].min>arr[i].sc[j])arr[i].min=arr[i].sc[j];
        }
        arr[i].num=(arr[i].num-arr[i].min-arr[i].max)/(k-2.0);
    }
    float h=arr[0].num,q=0;
    vector<float>e(m);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            if(h<arr[j].num)
                h=arr[j].num,q=j;
        e[i]=h;
        h=arr[q].num=0;
    }
    cout<<setiosflags(ios::fixed)<<setprecision(3);
    for(int i=m-1;i>=0;i--)
    {
        if(i!=m-1)cout<<" ";
        cout<<e[i];
    }
    cout<<endl;

    return 0;
}
*/

/*（8）银行业务队列简单模拟

//设某银行有A、B两个业务窗口，且处理业务的速度不一样，
//其中A窗口处理速度是B窗口的2倍 —— 即当A窗口每处理完2个顾客时，B窗口处理完1个顾客。
//给定到达银行的顾客序列，请按业务完成的顺序输出顾客序列。
//假定不考虑顾客先后到达的时间间隔，并且当不同窗口同时处理完2个顾客时，A窗口顾客优先输出。
//
//输入格式:
//输入为一行正整数，其中第1个数字N(≤1000)为顾客总数，后面跟着N位顾客的编号。
//编号为奇数的顾客需要到A窗口办理业务，为偶数的顾客则去B窗口。数字间以空格分隔。
//
//输出格式:
//按业务处理完成的顺序输出顾客的编号。数字间以空格分隔，但最后一个编号后不能有多余的空格。
//
//输入样例:
//8 2 1 3 9 4 11 13 15
//输出样例:
//1 3 2 9 11 4 13 15

#include<iostream>
using namespace std;
int main()
{
    int n,a[1000],b[1000],c,x=0,y=0,f=0,g=0;
    bool u=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>c;
        if(c%2)a[x++]=c;
        else b[y++]=c;
    }
    for(int i=0;i<n;i++)
    {
        if(f<x)
        {
            if(u)cout<<" ";
            cout<<a[f++];
            u=1;
        }
        if(f<x)
        {
            if(u)cout<<" ";
            cout<<a[f++];
        }
        if(g<y)
        {
            if(u)cout<<" ";
            cout<<b[g++];
            u=1;
        }
    }

    return 0;
}
*/

/*（9）公路村村通

//现有村落间道路的统计数据表中，列出了有可能建设成标准公路的若干条道路的成本，求使每个村落都有公路连通所需要的最低成本。
//
//输入格式:
//输入数据包括城镇数目正整数 n（≤1000）和候选道路数目 m（≤3n）；
//随后的 m 行对应 m 条道路，每行给出 3 个正整数，分别是该条道路直接连通的两个城镇的编号以及该道路改建的预算成本。
//为简单起见，城镇从 1 到 n 编号。
//
//输出格式:
//输出村村通需要的最低成本。如果输入数据不足以保证畅通，则输出 −1，表示需要建设更多公路。
//
//输入样例:
//6 15
//1 2 5
//1 3 3
//1 4 7
//1 5 4
//1 6 2
//2 3 4
//2 4 6
//2 5 2
//2 6 6
//3 4 6
//3 5 1
//3 6 1
//4 5 10
//4 6 8
//5 6 3
//输出样例:
//12

//普利姆算法
// #include<iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     int v,e,q,p,r;
//     cin>>v>>e;
//     vector<bool>V(v+1,0);
//     vector<vector<int>>E(v+1,vector<int>(v+1,0));
//     for(int i=1;i<=e;i++)
//     {
//         cin>>q>>p>>r;
//         E[q][p]=E[p][q]=r;
//     }
//     int min;
//     q=p=r=0;
//     V[1]=1;
//     for(int k=1;k<v;k++)
//     {
//         min=1000;
//         for(int i=1;i<=v;i++)
//             if(V[i])
//                 for(int j=1;j<=v;j++)
//                     if(i!=j&&!V[j]&&E[i][j]>0)
//                             if(min>E[i][j])
//                                 min=E[i][j],q=i,p=j;
//         r+=min;
//         V[p]=1;
//     }
//     for(int i=1;i<=v;i++)
//         if(!V[i])
//         {
//             cout<<-1<<endl;
//             return 0;
//         }
//     cout<<r<<endl;

//     return 0;
// }



//克鲁斯卡尔算法
#include<iostream>
#include<vector>
using namespace std;
struct Ei
{
    int c;
    int r;
    int d;
};
struct Vi
{
    bool l=0;
    int f;
};
int main()
{
    int v,e,min,k,sum=0;
    cin>>v>>e;
    vector<Vi>V(v+1);
    vector<Ei>E(e+1);
    Ei h;
    for(int i=1;i<=e;i++)
        cin>>E[i].c>>E[i].r>>E[i].d;
    for(int i=1;i<e;i++)
    {
        min=E[i].d,k=i;
        for(int j=i+1;j<=e;j++)
            if(min>E[j].d)
                min=E[j].d,k=j;
        h=E[i],E[i]=E[k],E[k]=h;
    }
    k=1;
    for(int i=1;i<=e;i++)
    {
        if(V[E[i].c].l&&!V[E[i].r].l||!V[E[i].c].l&&V[E[i].r].l)
        {
            sum+=E[i].d;
            if(V[E[i].c].l)V[E[i].r].l=1,V[E[i].r].f=V[E[i].c].f;
            else V[E[i].c].l=1,V[E[i].c].f=V[E[i].r].f;
        }
        else if(!V[E[i].c].l||!V[E[i].r].l)
        {
            sum+=E[i].d;
            V[E[i].c].l=V[E[i].r].l=1;
            V[E[i].c].f=V[E[i].r].f=k++;
        }
        else if(V[E[i].c].f!=V[E[i].r].f)
        {
            sum+=E[i].d;
            int fool=V[E[i].c].f;
            for(int j=1;j<=v;j++)
                if(V[j].l&&V[j].f==fool)
                    V[j].f=V[E[i].r].f;
        }
    }
    k=V[E[1].c].f;
    for(int i=1;i<=v;i++)
        if(!V[i].l||V[i].f!=k)
        {
            cout<<-1<<endl;
            return 0;
        }
    cout<<sum<<endl;

    return 0;
}
*/

//To Fill or Not to Fill
//
//With highways available, driving a car from Hangzhou to any other city is easy.
//But since the tank capacity of a car is limited, we have to find gas stations on the way from time to time. 
//Different gas station may give different price. 
// You are asked to carefully design the cheapest route to go.
//
//Input Specification:
//Each input file contains one test case.  
//For each case, the first line contains 4 positive numbers: 
//Cmax(≤ 100), the maximum capacity of the tank;
//D (≤30000), the distance between Hangzhou and the destination city; 
//Davg(≤20), the average distance per unit gas that the car can run;
//and N (≤ 500), the total number of gas stations.  
//Then N lines follow, each contains a pair of non-negative numbers: 
//Pi, the unit gas price, and Di(≤D), the distance between this station and Hangzhou, for i=1,⋯,N.
//All the numbers in a line are separated by a space.
//
//Output Specification:
//For each test case, print the cheapest price in a line, accurate up to 2 decimal places. 
//It is assumed that the tank is empty at the beginning. 
//If it is impossible to reach the destination, print The maximum travel distance = X
//where X is the maximum possible distance the car can run, accurate up to 2 decimal places.
//
//Sample Input 1:
//50 1300 12 8
//6.00 1250
//7.00 600
//7.00 150
//7.10 0
//7.20 200
//7.50 400
//7.30 1000
//6.85 300
//Sample Output 1:
//749.17
//Sample Input 2:
//50 1300 12 2
//7.10 0
//7.00 600
//Sample Output 2:
//The maximum travel distance = 1200.00

/*
填充或不填充

拥有高速公路，驾车从 杭州 到任何其他城市都很方便。
但由于汽车的油箱容量有限，我们不得不不时在路上寻找加油站。
不同的加油站可能会给出不同的价格。
您需要仔细设计最便宜的路线。

输入规格：
每个输入文件都包含一个测试用例。
对于每个 case，第一行包含 4 个正数：
Cmax（≤ 100），油箱的最大容量;
D （≤30000），杭州与目的地城市的距离;
Davg（≤20），汽车每单位汽油可以运行的平均距离;
N （≤ 500） 表示加油站的总数。
然后是 N 行，每行包含一对非负数：
Pi 是 Gas 单价，Di（≤D） 是该站到杭州的距离，其中 i=1，⋯，N。
一行中的所有数字都用空格分隔。

输出规格：
对于每个测试用例，将最便宜的价格打印成一行，精确到小数点后 2 位。
假设油箱在开始时是空的。
如果无法到达目的地，请打印"The maximum travel distance = X"
其中 X 是汽车可以行驶的最大可能距离，精确到小数点后 2 位。

样本输入 1：
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300
示例输出 1：
749.17
样本输入 2：
50 1300 12 2
7.10 0
7.00 600
示例输出 2：
最大行驶距离 = 1200.00
*/

#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
struct D
{
    double jia;
    int d;
};
int main()
{
    int v, s, p, n, k;
    double min, max;
    cin >> v >> s >> p >> n;
    vector<D>m(n + 1);
    D h;
    for (int i = 0; i < n; i++)
        cin >> m[i].jia >> m[i].d;
    m[n].d = s;
    for (int i = 0; i < n; i++)
    {
        max = m[i].d, k = i;
        for (int j = i + 1; j <= n; j++)
            if (max < m[j].d)
                max = m[j].d, k = j;
        h = m[i], m[i] = m[k], m[k] = h;
    }
    double x = 0, y = 0, z = 0;
    int u;
    cout << setiosflags(ios::fixed) << setprecision(2);
    for (int i = n; i > 0; i--)
        if (m[i].d + v * p < m[i - 1].d || m[n].d)
        {
            cout << "The maximum travel distance = " << (!m[n].d ? m[i].d + v * p * 1.0 : 0) << endl;
            return 0;
        }
    while (s)
    {
        u = 0;
        min = 100, k = z;
        for (int i = z + 1; i <= n; i++)
            if (m[z].d - m[i].d <= v * p)
            {
                if (min > m[i].jia)min = m[i].jia, k = i, u++;
            }
            else break;
        if (u)
        {
            y = (m[z].d - m[k].d) * 1.0 / p;
            x += y * m[k].jia;
            if (m[z].jia > m[k].jia)x -= (v - y) * (m[z].jia - m[k].jia);
            s = m[k].d;
            z = k;
        }
    }
    cout << x << endl;

    return 0;
}



// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// const int MAX = 50000 + 10;
// struct node {           //记录每个加油站的距离和油价
//     double D_i;
//     double P_i;
// }Data[MAX];
// int N;
// double C_max,D,D_avg,D_max;      
// double dp[MAX],mi,sum;
// int main(){
//     cin >> C_max >> D >> D_avg >> N;
//     D_max = C_max * D_avg;              //计算汽车最大的行驶距离
//     for (int i = 0; i < N; i++) {       //输入每个加油站
//         cin >> Data[i].P_i >> Data[i].D_i;
//     }
//     for (int i = 0; i < N; i++) {
//         for (int j = Data[i].D_i+1; j <= Data[i].D_i + D_max; j++) {  //更新dp[]数组
//             if (dp[j]) dp[j] = min(dp[j], Data[i].P_i / D_avg);     //如果不为空
//             else dp[j] = Data[i].P_i / D_avg;                       //如果为空
//         }
//     }
//     for (int i = 1; i < 30100; i++) {       //从起点计算花费和到达的距离
//         if (dp[i] && i <= D) {              //如果到达或者dp[]数组为空就break
//             mi += dp[i];
//             sum = i;
//         }
//         else {
//             break;
//         }
//     }
//     if (sum == D)                     //判断输出
//         printf("%.2f", mi);
//     else{
//         printf("The maximum travel distance = %.2f", sum);
//     }
//     return 0;
// }
