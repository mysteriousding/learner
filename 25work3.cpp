/*(1)统计成绩

//每次考试或测试后，老师们都要进行成绩统计。假如某次期末考试有语文、数学、英语三门课，现请你编程输出总成绩最高分以及每门学科的最高分。
//
//输入格式:
//输入共n+1行。
//第1行是一个正整数n（1≤n≤100），表示学生人数，从1到n编号。
//接下来n行，每行3个整数，依次表示每个学生的语文、数学、英语成绩（每门课成绩是0到100之间的整数，包括0和100）。
//
//输出格式:
//输出共1行，包含4个整数，分别表示三门课总成绩最高分，语文学科的最高分，数学学科的最高分，英语学科的最高分
//
//输入样例:
//在这里给出一组输入。例如：
//
//3
//80 67 96
//88 71 93
//90 95 80
//输出样例:
//在这里给出相应的输出。例如：
//
//265 90 95 96

#include<iostream>
#include<vector>
using namespace std;
struct stu
{
    int x=0;
    int y=0;
    int z=0;
    int zf=0;
};
int main()
{
    int n;
    cin>>n;
    vector<stu>m(n+1);
    for(int i=0;i<n;i++)
    {
        cin>>m[i].x;
        if(m[i].x>m[n].x)m[n].x=m[i].x;
        cin>>m[i].y;
        if(m[i].y>m[n].y)m[n].y=m[i].y;
        cin>>m[i].z;
        if(m[i].z>m[n].z)m[n].z=m[i].z;
        m[i].zf=m[i].x+m[i].y+m[i].z;
        if(m[i].zf>m[n].zf)m[n].zf=m[i].zf;
    }
    cout<<m[n].zf<<" "<<m[n].x<<" "<<m[n].y<<" "<<m[n].z<<endl;

    return 0;
}
*/

/*(2)一维数组排序

//对数组的元素按从小到大进行排序。
//
//输入格式:
//第一行有一个整数n (<10)；
//
//第二行n有元素,在10^19范围内。
//
//输出格式:
//输出排序后的数组。
//
//输入样例:
//在这里给出一组输入。例如：
//
//8
//1 2 3 6 8 7 4 5
//输出样例:
//在这里给出相应的输出。例如：
//
//1 2 3 4 5 6 7 8

#include<iostream>
#include<vector>
using namespace std;
void sort(vector<long long>&x,int a,int b)
{
    if(a>=b)return;
    int i=a,j=b;
    long long h;
    while(i<j)
    {
        // while(i<j&&x[i]<=x[a])i++;
        while(i<j&&x[j]>=x[a])j--;
        while(i<j&&x[i]<=x[a])i++;
        if(i<j)
        {
            h=x[i];
            x[i]=x[j];
            x[j]=h;
        }
    }
    h=x[a];
    x[a]=x[i];
    x[i]=h;
    sort(x,a,i-1);
    sort(x,i+1,b);
}

int main()
{
    int n;
    cin>>n;
    vector<long long>m(n);
    for(int i=0;i<n;i++)
        cin>>m[i];
    sort(m,0,n-1);

    for(int j=0;j<n;j++)
    {
        if(j!=0)cout<<" ";
        cout<<m[j];
    }

    return 0;
}
*/

/*(#)求矩阵各行最大元素值

//本题要求编写程序，求一个给定的m×n矩阵各行最大的元素值。题目保证给出的矩阵每行至多存在一个最大值。
//
//输入格式:
//输入第一行给出两个正整数m和n（1≤m,n≤6）。随后m行，每行给出n个整数，其间以空格分隔。
//
//输出格式:
//每行按照“元素值 行号 列号”的格式输出该行最大元素，其中行、列编号从1开始。要求按照行号递增输出。
//
//输入样例:
//4 5
//1 8 2 6 5
//2 3 9 7 1
//6 5 3 4 1
//1 3 2 4 5
//输出样例:
//8 1 2
//9 2 3
//6 3 1
//5 4 5

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m,max,k;
    cin>>n>>m;
    vector<vector<int>>N(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        max=k=0;
        for(int j=0;j<m;j++)
        {
            cin>>N[i][j];
            if(max<N[i][j])
            {
                max=N[i][j];
                k=j;
            }
        }

        cout<<max<<" "<<i+1<<" "<<k+1<<endl;
    }

    return 0;
}
*/

/*(4)矩阵对角线互换

//本题目要求读入1个n×n的矩阵A，然后输出该矩阵正对角线与反对角线互换后的矩阵。具体过程如下图所示：
//
//图片1.jpg
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
    vector<vector<int>>m(n,vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>m[i][j];
    for(int i=0;i<n;i++)
    {
        h=m[i][i];
        m[i][i]=m[i][n-1-i];
        m[i][n-1-i]=h;
    }
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(i!=0)cout<<" ";
            cout<<m[j][i];
        }
        cout<<endl;
    }

    return 0;
}
*/

//计算矩阵的转置并输出
//
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

#include<iostream>
#include<vector>
#include<iomanip>
    using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>>N(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> N[i][j];
    //cout<<setiosflags(ios::left);
    cout << "Before:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << setw(4) << N[i][j];
        cout << endl;
    }
    cout << "After:" << endl;
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
            cout << setw(4) << N[i][j];
        cout << endl;
    }

    return 0;
}