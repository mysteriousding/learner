/*(11)矩阵对角线互换

//本题目要求读入1个n×n的矩阵A，然后输出该矩阵正对角线与反对角线互换后的矩阵。具体过程如下图所示：
//
//图片1.jpg       //额，是根据y轴对称置换
//
//输入格式:
//输入在一行中给出1个不超过1000的正整数n。
//
//输出格式:
//输出对角线互换后的矩阵。
//
//输入样例:
//3
//16 5 7
//30 2 3
//-8 0 5
//输出样例:
//在这里给出相应的输出。例如：
//
//7 5 16
//30 2 3
//5 0 -8

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,h;
    cin>>n;
    vector<vector<int>>N(n,vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>N[i][j];
    for(int i=0;i<n;i++){h=N[i][i];N[i][i]=N[i][n-1-i];N[i][n-1-i]=h;}
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j!=0)cout<<" ";
            cout<<N[i][j];
        }
        if(i!=n-1)cout<<endl;
    }

    return 0;
}
*/

/*(12)计算矩阵的转置并输出

//本题要求编写程序，将一个给定的 m行n列矩阵进行转置，即行列互换后输出。
//
//输入格式:
//第一行给出两个正整数m,n(1<=m,n<=6)，以空格分隔；
//
//
//第二行给出m∗n个整数作为矩阵各元素输入，其间以空格分隔。
//
//输出格式:
//输出转置前的m行n列矩阵，及转置后的n行m列矩阵，每个数占4位。
//
//输入样例:
//2 3
//1 2 3 4 5 6
//输出样例:
//Before:
//   1   2   3
//   4   5   6
//After:
//   1   4
//   2   5
//   3   6


*/

/*(13)矩阵中的鞍点

//如果矩阵A中存在元素A[i][j]满足下列条件：A[i][j]是第i行中值最大的元素，且又是第j列中值最小的元素，则称之为该矩阵的鞍点。请编写程序判断矩阵是否存在鞍点，并输出。
//
//输入格式:
//首先输入一个正整数T，表示矩阵个数，然后输入各个矩阵的元素。
//对于每个矩阵，首先输入2个正整数m、n（均大于1、小于10），分别表示矩阵的行数和列数，然后依次输入矩阵的各元素，均为整数。假定矩阵在行、列的方向上均无重复元素，而且矩阵最多有一个鞍点。
//
//输出格式:
//对于每个矩阵，如果存在鞍点，则输出其所在的行、列和鞍点值，如：(0,3)6，否则输出“NONE”。
//
//输入样例:
//2
//4 4
//4 2 5 6
//7 8 9 10
//11 12 13 14
//15 16 17 18
//3 4
//67 3 9 23
//4 78 7 0
//47 90 32 8
//
//输出样例:
//(0,3)6
//NONE


#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    vector<vector<int>>N(10,vector<int>(10));
    for(int u=0;u<t;u++)
    {
       int n,n0,m1=-1,m2=-1,max;
       cin>>n>>n0;
        N.resize(n);
        for(int i=0;i<n;i++)
            N[i].resize(n0);

       for(int i=0;i<n;i++)
           for(int j=0;j<n0;j++)
               cin>>N[i][j];
       for(int i=0;i<n;i++)
       {
           max=N[i][0];
           int k=0,p=0;
           for(int j=0;j<n;j++)
               if(N[i][j]>max){max=N[i][j];k=j;}
           for(int j=0;j<n0;j++)
               if(max>N[j][k]){p=1;break;}
           if(p==0){m1=i;m2=k;break;}
       }
       if(m1==-1)cout<<"NONE"<<endl;
       else cout<<"("<<m1<<","<<m2<<")"<<max<<endl;
    }

    return 0;
}
*/

/*(14)二维数组

//作者 yzx
//单位 兰州交通大学
//存在一个二维数组a[10][10],每个元素的值为该元素下标的平方和，求该矩阵主对角线元素的和及平均值。
//
//输出格式:
//如 45 4.5
//
//输入样例:
//
//输出样例:



*/

//矩阵乘法
//
//计算两个矩阵的乘法。n*m阶的矩阵A乘以m*k阶的矩阵B得到的矩阵C 是n*k阶的，且C[i][j] = A[i][0]*B[0][j] + A[i][1]*B[1][j] + …… +A[i][m-1]*B[m-1][j](C[i][j]表示C矩阵中第i行第j列元素)。
//
//输入格式:
//第一行为n, m, k，表示A矩阵是n行m列，B矩阵是m行k列，n, m, k均小于20
//然后先后输入A和B两个矩阵，A矩阵n行m列，B矩阵m行k列，矩阵中每个元素的绝对值不会大于5000。
//
//输出格式:
//输出矩阵C，一共n行，每行k个整数，整数之间以一个空格分开。
//
//输入样例:
//在这里给出一组输入。例如：
//
//3 2 3
//1 1
//1 1
//1 1
//1 1 1
//1 1 1
//输出样例:
//在这里给出相应的输出。例如：
//
//2 2 2
//2 2 2
//2 2 2

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>N(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>N[i][j];
    vector<vector<int>>M(m,vector<int>(k));
    for(int i=0;i<m;i++)
        for(int j=0;j<k;j++)
            cin>>M[i][j];
    vector<vector<int>>K(n,vector<int>(k,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<k;j++)
        {
            for(int h=0;h<m;h++)
            {
                K[i][j]+=N[i][h]*M[h][j];
                if(h==m-1)
                {
                    if(j!=0)cout<<" ";
                    cout<<K[i][j];
                }
            }
            if(j==k-1&&i!=n-1)cout<<endl;
        }


    return 0;
}
