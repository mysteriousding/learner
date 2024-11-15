/*(17)求序列前N项和

//本题要求编写程序，计算序列 1+2/3+3/5+4/7+5/9+6/11+... 的前N项之和。
//
//输入格式:
//在一行中给出一个正整数N。
//
//输出格式:
//在一行中输出部分和的值，结果保留 2 位小数。
//
//输入样例:
//5
//输出样例:
//3.39

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    float n,m=0;
    cin>>n;
    for(int i=0;i<n;i++)m+=(i+1.0)/(2*i+1);

    cout<<setiosflags(ios::fixed)<<setprecision(2)<<m<<endl;

    return 0;
}
*/

/*(18)统计0和1的个数

//现在请你输入一个只含0、1和*的字符串，其中*是结束标志，统计其中0和1的个数。例如：0100100*
//输入格式:
//输入只含0和1的字符串，结尾必须是*
//
//输出格式:
//输出0和1的个数
//
//输入样例:
//00110101*
//输出样例:
//card(0)=4
//card(1)=4

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string n;
    int a=0,b=0;
    getline(cin,n,'\n');
    for(int i=0;n[i]!='*';i++)
    {
        if(n[i]=='0')a++;
        else b++;
    }

    cout<<"card(0)="<<a<<"\ncard(1)="<<b;

    return 0;
}
*/

/*(19)水仙数

//一个三位的十进制整数，如果它的三个数位的数字立方和等于这个数的数值，则称它为一个“水仙数”。编写程序，计算出某一范围内的所有“水仙数”。
//
//输入格式:
//输入两个数，分别代表取值范围的上下限。
//
//输出格式:
//输出所有范围内的水仙数，中间用空格隔开，如果没有，则输出No Answer。
//
//输入样例:
//100 999
//输出样例:
//153 370 371 407

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a,b,n,m,p=0;
    cin>>a>>b;
    for(int i=a+1;i<b;i++)
    {
        m=0;n=i;
        for(int j=0;j<3;j++)
        {
            m+=pow(n%10,3);
            n/=10;
        }
        if(m==i)
        {
            cout<<i<<" ";
            p=1;
        }
    }

    if(p==0)cout<<"No Answer";
    cout<<endl;

    return 0;
}
*/

/*(20)连续整数相加
//
//读入两个整数值 A 和 N，计算从 A 开始的 N 个连续整数的和。
//
//注意，如果读入的 N 为 0 或负数，则继续读取数字直至读入 N 值为正整数为止。
//
//输入格式:
//共一行，包含整数 A 和若干个整数 N（不超过 100 个）。
//
//输出格式:
//一个整数，表示从 A 开始的 N 个连续整数的和。
//
//
//
//数据范围
//
//1≤A≤100,
//−100≤N≤100
//
//输入样例1:
//3 2
//输出样例1:
//7
//输入样例2:
//3 -1 0 -2 2
//输出样例2:
//7

#include<iostream>
using namespace std;
int main()
{
    int a,n,m=0;
    cin>>a>>n;
    while(n<=0)cin>>n;
    for(int i=0;i<n;i++)m+=a+i;
    cout<<m<<endl;

    return 0;
}
*/

/*(21)整除数

//给定两个整数 n,k，请你找到大于 n 且能被 k 整除的最小整数x。
//输入格式
//共一行，包含两个整数n,k。
//输出格式
//输出大于n且能被k 整除的最小整数x。
//数据范围
//前4个测试点满足1≤n,k≤100。
//所有测试点满足1≤n,k≤10。
//输入样例1:
//5 3
//输出样例1:
//6
//输入样例2:
//25 13
//输出样例2:
//26
//输入样例3:
//26 13
//输出样例3:
//39
//
//输入样例:
//5 3
//输出样例:
//6

#include<iostream>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>k;
    m=(n>k)?2*k:k;
    for(int i=m;;i++)if(i%k==0){cout<<i<<endl;break;}

    return 0;
}
*/

//阶乘。
//
//读入n，求阶乘。
//
//输入格式:
//输入整数n。
//
//输出格式:
//每一组输出阶乘结果。
//
//输入样例1:
//5
//输出样例1:
//120
//输入样例2:
//-1
//输出样例2:
//0

#include<iostream>
using namespace std;
int main()
{
    int n, m = 1;
    cin >> n;
    if (n < 0)cout << 0 << endl;
    else if (n == 0)cout << 1 << endl;
    else { for (; n > 0; n--)m *= n; cout << m << endl; }


    return 0;
}
