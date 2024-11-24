/*(1)jmu-c-6.1

//请输入整数 n（n≤10）, 输出n行如下所示的杨辉三角 (每个数据占6个位置):
//
//     1
//     1     1
//     1     2     1
//     1     3     3     1
//     1     4     6     4     1
//     1     5    10    10     5     1
//     1     6    15    20    15     6     1
//      …
//输入样例:
//6
//输出样例:
//     1
//     1     1
//     1     2     1
//     1     3     3     1
//     1     4     6     4     1
//     1     5    10    10     5     1

//作答:
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>N(n,vector<int>(n,1));
    for(int i=2;i<n;i++)
        for(int j=1;j<i;j++)
            N[i][j]=N[i-1][j-1]+N[i-1][j];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
            cout<<setw(6)<<N[i][j];
        cout<<endl;
    }

    return 0;
}
*/

/*(2)输出鞍点的行列下标

//一个矩阵元素的“鞍点”是指该位置上的元素值在该行上最大、在该列上最小。
//
//本题要求编写程序，求一个给定的n阶方阵的鞍点的行列值。
//
//输入格式:
//输入第一行给出一个正整数n（1≤n≤6），随后n行，每行给出n个整数，其间以空格分隔。
//
//输出格式:
//输出在一行中按照“行下标 列下标”（下标从0开始）的格式输出鞍点的位置。如果鞍点不存在，则输出“NONE”。题目保证给出的矩阵至多存在一个鞍点。
//
//输入样例1:
//4
//1 9 4 1
//4 7 3 6
//1 9 3 2
//0 8 8 9
//输出样例1:
//1 1
//输入样例2:
//4
//7   7  4  1
//14  8  3  6
//6   6  7  2
//10  7  8  9
//输出样例2:
//NONE

////作答:
//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//    int n,m1=-1,m2=-1;
//    cin>>n;
//    vector<vector<int>>N(n,vector<int>(n));
//    for(int i=0;i<n;i++)
//        for(int j=0;j<n;j++)
//            cin>>N[i][i];
//    for(int i=0;i<n;i++)
//    {
//        int max=N[i][0],k=1,l=0;
//
//        for(int j=0;j<n;j++)
//            if(N[i][j]>max){max=N[i][j];l=j;}
//
//        for(int j=0;j<n;j++)
//            if(max>N[j][l]){k=0;break;}
//
//        if(k==0){m1=i+1;m2=l+1;break;}
//    }
//    if(m1==-1)cout<<"NONE"<<endl;
//    else cout<<m1<<" "<<m2<<endl;
//
//    return 0;
//}

//改正:
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, m1 = -1, m2 = -1;
    cin >> n;
    vector<vector<int>>N(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> N[i][j];
    for (int i = 0; i < n; i++)
    {
        int max = N[i][0], k = 1, l = 0;

        for (int j = 0; j < n; j++)
            if (N[i][j] > max) { max = N[i][j]; l = j; }

        for (int j = 0; j < n; j++)
            if (max > N[j][l]) { k = 0; break; }

        if (k == 1) { m1 = i ; m2 = l ; break; }
    }
    if (m1 == -1)cout << "NONE" << endl;
    else cout << m1 << " " << m2 << endl;

    return 0;
}
*/

/*(3)平均分

//一个学习小组有6名同学，每人有3门必修课（数学、语文和英语），求每门课的平均分和每个人的平均分。
//
//输入格式:
//第1行输入6名同学的数学成绩。
//第2行输入6名同学的语文成绩。
//第3行输入6名同学的英语成绩。
//
//输出格式:
//在第1行分别输出数学、语文、英语3门课程的平均分，要求保留小数点后2位小数，数字之间用空格分隔。
//在第2行分别输出6名同学的平均分，保留小数点后2位小数，数字之间用空格分隔。
//
//输入样例:
//在这里给出一组输入。例如：
//
//85 93 84 85 95 86
//79 95 95 80 100 98
//80 91 93 75 97 90
//输出样例:
//在这里给出相应的输出。例如：
//
//88.00 91.17 87.67
//81.33 93.00 90.67 80.00 97.33 91.33

//作答:
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int N[3][6];
    for(int i=0;i<3;i++)
        for(int j=0;j<6;j++)
            cin>>N[i][j];
    double k[9]={0},sum;
    int j=0;
    while(j<9)
    {
        sum=0;
        if(j<3)
        {
            for(int i=0;i<6;i++)
                sum+=N[j][i];
            k[j]=sum/6.0;
        }
        else
        {
            for(int i=0;i<3;i++)
                sum+=N[i][j-3];
            k[j]=sum/3.0;
        }
        j++;
    }
    cout<<setiosflags(ios::fixed)<<setprecision(2);
    for(int i=0;i<9;i++)
    {
        cout<<k[i]<<" ";
        if(i==2)cout<<endl;
    }

    return 0;
}
*/

/*(4）区间内的真素数

//找出正整数 M 和 N 之间（ N 不小于 M ）的所有真素数。
//
//真素数的定义：如果一个正整数 P 为素数，且其反序也为素数，那么 P 就为真素数。例如，11,13均为真素数，因为11的反序还是为11,13的反序为31也为素数。
//输入格式
//输入两个数 M 和 N ，空格间隔。
//输出格式
//按从小到大输出 M 和 N 之间（包括 M 和 N ）的真素数，逗号间隔。如果之间没有真素数，则输出 No
//输入样例:：
//10 35
//输出样例:
//11,13,17,31

////作答:
//#include<iostream>
//#include<cmath>
//using namespace std;
//bool PD(int i)
//{
//    for(int j=2;j<=sqrt(i);j++)
//        if(i%j==0)return 0;
//    return 1;
//}
//int DX(int i)
//{
//    int k=0;
//    while(i!=0)
//    {
//        k=k*10+(i%10);
//        i=i/10;
//    }
//    return k;
//}
//
//int main()
//{
//    int n,m;
//    cin>>n>>m;
//    int p=0;
//    for(int i=n;i<=m;i++)
//    {
//        if(PD(i))
//            if(PD(DX(i)))
//            {
//                if(p!=0)cout<<",";
//                cout<<i;
//                p=1;
//            }
//    }
//    if(p==0)cout<<"N0";
//    return 0;
//}

//改正:
#include<iostream>
#include<cmath>
using namespace std;

bool pd(int x)
{
    for(int j=2;j<=(int)sqrt(x);j++)
        if(x%j==0)return 0;
    return 1;
}

int qf(int y)
{
    int z=0;
    while(y!=0)
    {
        z=z*10+y%10;
        y/=10;
    }
    return z;
}

int main()
{
    int m,n,p=0;
    cin>>m>>n;
    for(;m<=n;m++)
        if(pd(m))
            if(pd(qf(m)))
            {
                if(p!=0)cout<<",";
                cout<<m;
                p=1;
            }
    if(p==0)cout<<"No"<<endl;

    return 0;
}
*/

//折半查找
//分数 10
//作者 zy
//单位 安阳工学院
//题目描述
//
//在一个有序的一维数组中，输入一个数，利用折半查找法找到该数是这个数组中的第几个数；如果该数不在数组中，则输出“No data!”
//
//输入格式:
//第一行输入一个整数n(1<=n<=15)，表示该数组有几个数；第二行输入n个整型一维数组；第三行输入要查找的数。
//
//输出格式:
//如果找到该数，输出“It's position is 4!”；如果没有找到，输出“No data!”。
//
//输入样例1:
//在这里给出一组输入。例如：
//
//5
//-3 2 7 15 40
//15
//输出样例1:
//在这里给出相应的输出。例如：
//
//It's position is 4!
//输入样例2:
//在这里给出一组输入。例如：
//
//4
//0 3 6 9
//5
//输出样例2:
//在这里给出相应的输出。例如：
//
//No data!

////作答:
//无

//改正:
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, n0;
    cin >> n;
    vector<int>m(n);
    for (int i = 0; i < n; i++)cin >> m[i];
    cin >> n0;
    int k1 = 0, k2 = n - 1, k3, p = 0;
    while (k1 <= k2)
    {
        k3 = (k1 + k2) / 2;
        if (m[k3] == n0) { cout << "It's position is " << k3 + 1 << "!" << endl; p = 1; break; }
        if (m[k3] > n0)k2 = k3 - 1;
        else k1 = k3 + 1;
    }
    if (p == 0)cout << "No data!" << endl;

    return 0;
}