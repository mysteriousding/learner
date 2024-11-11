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
int PX(vector<vector<int>> x,int y,int k);
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>arr(4,vector<int>(n));
    //int PX(int x[][n],int y,int k);
    for(int i=0;i<n;i++)
    {
        cin>>arr[1][i]>>arr[2][i]>>arr[3][i];
        arr[0][i]=arr[1][i]+arr[2][i]+arr[3][i];
    }
    for(int j=0;j<4;j++)
    {
        if(j!=0)cout<<" ";
        cout<<PX(arr,n,j);
    }
    cout<<endl;

    return 0;
}
int PX(vector<vector<int>> x,int y,int k)
{
    int h;
    vector z=x[k];
    for(int i=0;i<y-1;i++)
    {
        for(int j=0;j<y-1-i;j++)
        {
            if(z[j]<z[j+1]){h=z[j];z[j]=z[j+1];z[j+1]=h;}
        }
    }
    return z[0];
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
int main()
{
    int n;
    long long h;
    cin>>n;
    vector<long long>m(n);
    for(int i=0;i<n;i++)cin>>m[i];
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(m[j]>m[j+1]){h=m[j];m[j]=m[j+1];m[j+1]=h;}
        }
    }
    for(int j=0;j<n;j++)
    {
        if(j!=0)cout<<" ";
        cout<<m[j];
    }
    cout<<endl;

    return 0;
}
*/

/*(3)数组逆序

//给你 n 个整数，将其逆序输出。
//
//输入格式:
//第一行一个整数 n （3<=n<=10) 代表数的个数。
//
//第二行 n 个整数（空格隔开）（这些数在 0~10^6 之间)。
//
//输出格式:
//n 个整数（空格隔开）。
//
//输入样例:
//在这里给出一组输入。例如：
//
//3
//1 7 5
//输出样例:
//在这里给出相应的输出。例如：
//
//5 7 1

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long>m(n);
    for(int i=n-1;i>=0;i--)cin>>m[i];
    for(int j=0;j<n;j++)
    {
        if(j!=0)cout<<" ";
        cout<<m[j];
    }
    cout<<endl;

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
//
//说明／提示
//1≤ M ≤ N ≤100000

#include<iostream>
#include<cmath>
using namespace std;
int S(long long x);
long long D(long long y);
int main()
{
    long long n,m;
    int l=0;
    cin>>n>>m;
    n=(n==1)?2:n;
    for(long long i=n;i<=m;i++)
    {
        if(S(i)==1)
        {
            if(S(D(i))==1)
            {
                if(l!=0)cout<<",";
                cout<<i;
                l++;
            }
        }
    }
    if(l==0)cout<<"No";
    cout<<endl;

    return 0;
}

int S(long long x)
{
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)return 0;
    }
    return 1;
}

long long D(long long y)
{
    int z[7],i;
    for(i=0;;i++)
    {
        z[i]=y%10;
        y/=10;
        if(y==0)break;
    }
    for(int j=0;i>=0;i--,j++)
    {
        y+=z[j]*pow(10,i);
    }
    return y;
}
*/

//小熊的果篮
//
//小熊的水果店里摆放着一排 n 个水果。每个水果只可能是苹果或桔子，从左到右依次用正整数 1,2……,n 编号。连续排在一起的同一种水果称为一个“块”。小熊要把这一排水果挑到若干个果篮里，具体方法是：每次都把每一个“块”中最左边的水果同时挑出，组成一个果篮。重复这一操作，直至水果用完。注意，每次挑完一个果篮后，“块”可能会发生变化。比如两个苹果“块”之间的唯一桔子被挑走后，两个苹果“块”就变成了一个“块”。请帮小熊计算每个果篮里包含的水果。
//
//输入格式:
//第一行，包含一个正整数 n，表示水果的数量。
//
//第二行，包含 n 个空格分隔的整数，其中第 i 个数表示编号为 i 的水果的种类，1 代表苹果，0 代表桔子。
//
//输出格式:
//输出若干行。
//
//第 i 行表示第 i 次挑出的水果组成的果篮。从小到大排序输出该果篮中所有水果的编号，每两个编号之间用一个空格分隔。
//
//输入样例:
//12
//1 1 0 0 1 1 1 0 1 1 0 0
//输出样例:
//1 3 5 8 9 11
//2 4 6 12
//7
//10
//输入样例:
//20
//1 1 1 1 0 0 0 1 1 1 0 0 1 0 1 1 0 0 0 0
//输出样例:
//1 5 8 11 13 14 15 17
//2 6 9 12 16 18
//3 7 10 19
//4 20
//输入样例:
//见附件中的 fruit/fruit3.in。
//输出样例:
//见附件中的 fruit/fruit3.ans。
//说明/提示
//【样例解释 #1】
//
//这是第一组数据的样例说明。
//
//所有水果一开始的情况是 [1,1,0,0,1,1,1,0,1,1,0,0]，一共有 6 个块。
//
//在第一次挑水果组成果篮的过程中，编号为 1,3,5,8,9,11 的水果被挑了出来。
//
//之后剩下的水果是 [1,0,1,1,1,0]，一共 4 个块。
//
//在第二次挑水果组成果篮的过程中，编号为 2,4,6,12 的水果被挑了出来。
//
//之后剩下的水果是 [1,1]，只有 1 个块。
//
//在第三次挑水果组成果篮的过程中，编号为 7 的水果被挑了出来。
//
//最后剩下的水果是 [1]，只有 1 个块。
//
//在第四次挑水果组成果篮的过程中，编号为 10 的水果被挑了出来。
//
//【数据范围】
//
//对于 10% 的数据，n<=5。
//对于 30% 的数据，n<=1000。
//对于 70% 的数据，n<=50000。
//对于 100% 的数据，n<=2∗10
//5
// 。
//
//【提示】
//
//由于数据规模较大，建议 C/C++ 选手使用 scanf 和 printf 语句输入、输出。

#include<iostream>
#include<vector>
using namespace std;
int J(vector<int> x, int y, int z);
int main()
{
    int n, k = 0, p = 0, j0 = 0, p1;
    cin >> n;
    vector<int>a(n), b(2 * n, 0);
    for (int i = 0; i < n; i++)cin >> a[i];

    for (int i = 0;; i++)
    {
        p1 = 0;
        for (int j = 0; j <= n; j++)
        {
            if (p == n) { p = -1; break; }
            if (p1 == 0)
            {
                j0 = J(a, j, n);
                b[k] = j0; k++; p++;//收
                j = j0;             //换
                p1 = 1;
            }
            j = J(a, j, n);
            if (j == n)
            {
                a[j0] = 2;          //封
                b[k] = 2 * n; k++;  //尾
                break;
            }
            if (a[j0] != a[j])
            {
                a[j0] = 2;          //封
                b[k] = j; k++; p++; //收
                j0 = j;             //换

            }
        }
        if (p == -1)break;
    }

    p1 = 0;
    for (int j = 0; j < k; j++)
    {

        if (b[j] == 2 * n) { cout << endl; p1 = 1; }
        else
        {
            if (j != 0 && p1 == 0)cout << " ";
            cout << b[j] + 1;
            p1 = 0;
        }
    }

    return 0;
}

int J(vector<int> x, int y, int z)
{
    while (1)
    {
        if (x[y] == 2)
        {
            y++;
            if (y == z)return z;
        }
        else return y;
    }
}