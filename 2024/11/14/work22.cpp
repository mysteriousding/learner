/*(1)完数

//编程求出1000之内的所有完数。一个数如果恰好等于它的因子(除自身外)之和，这个数就称为"完数"。比如6=1+2+3,因此6是完数。
//
//输出格式:
// 在一行输出所有完数，每个完数输出占5列。没有其它任何附加字符。
//
//输出样例:
//    6   28  496

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    int x[50]={0};
    for(int i=2;i<=1000;i++)
    {
        int k=0,y=0;
        for(int j=1;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                x[k++]=j;
                if(j!=i/j)x[k++]=i/j;
            }
        }
        for(int l=0;x[l]!=0;l++)
        {
            y+=x[l];
            x[l]=0;
        }
        if(y==2*i)cout<<setw(5)<<i;
    }

    return 0;
}
*/

/*(2)完数

//毕达哥拉斯曾说：“6象征着完满的婚姻以及健康和美丽，因为它的部分是完整的，并且其和等于自身。” 在中国文化里：有六谷、六畜、战国时期的六国、秦始皇以六为国数、六常（仁、义、礼、智、信、孝）、天上四方有二十八宿等等，6和28，在中国历史长河中，之所以熠熠生辉，是因为它是一个完全数。中国发现完全数比西方还早呢。
//
//要求：求指定区间内的所有完数。说明：一个数如果恰好等于它的因子之和（自身除外），则称该数为完数，例如6=1+2+3，则6为完数。
//
//输入格式:
//两个正整数x和y（x<=y）
//
//输出格式:
//每行输出1个完数及其所有因数（不包括自身的因数）的等式，如没有完数则不输出。
//
//输入样例1:
//1 50
//输出样例1:
//6=1+2+3
//28=1+2+4+7+14
//输入样例2:
//50 100
//输出样例2:
//

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    int n,m,h,p=0;
    cin>>n>>m;
    vector<int>x(m/2,0);
    for(int i=n;i<=m;i++)
    {
        int k=0,y=0,l=0;
        for(int j=1;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                x[k++]=j;
                if(j!=i/j)x[k++]=i/j;
            }
        }
        for(;x[l]!=0;l++)y+=x[l];
        if(y==2*i)
        {
            if(p!=0)cout<<endl;
            cout<<i<<"=1";p=1;
            for(int a=0;a<l-1;a++)
                for(int b=0;b<l-1-a;b++)
                    if(x[b]>x[b+1]){h=x[b];x[b]=x[b+1];x[b+1]=h;}
        }
        if(y==2*i)for(l=1;x[l]!=i;l++)cout<<"+"<<x[l];

        for(int c=0;x[c]!=0;c++)x[c]=0;


    }

    return 0;
}
*/

/*(3)输出N以内的所有完数

//所谓完数，是指它的因子之和刚好是其本身的正整数。如6的因子是1,2,3，而1+2+3=6，所以6是完数，且是最小的完数。
//现在，用户输入N，请输出N以内的所有完数。
//
//输入格式:
//一个正整数N（6<=N<=10000）。
//
//输出格式:
//输出N以内的所有完数，一个完数占一行。
//
//输入样例1:
//100
//输出样例1:
//6
//28

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>x(n/2,0);
    for(int i=6;i<=n;i++)
    {
        int k=0,y=0;
        for(int j=1;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                x[k++]=j;
                if(j!=i/j)x[k++]=i/j;
            }
        }
        for(int l=0;x[l]!=0;l++)
        {
            y+=x[l];
            x[l]=0;
        }
        if(y==2*i)cout<<i<<endl;
    }

    return 0;
}
*/

/*(4)输出完数

//一个数如果恰好等于它的因子之和，这个数就称为“完数”。例如：6的因子为1，2，3，而6=1+2+3，因此6是完数。输入整数n，编程找出2-n(包括n)之内的所有完数，并按下列格式输出其因子：6 its factors are 1 2 3。
//
//输入格式:
//输入整数n(n在2-10000之间)
//
//输出格式:
//每行输出一个完数，格式如下：因子间有一个空格隔开，每行结束后也有一空格。
//6 its factors are 1 2 3
//......
//
//
//输入样例:
//10
//输出样例:
//6 its factors are 1 2 3

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    int m,h;   //,p=0;
    cin>>m;
    vector<int>x(m/2,0);
    for(int i=2;i<=m;i++)
    {
        int k=0,y=0,l=0;
        for(int j=1;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                x[k++]=j;
                if(j!=i/j)x[k++]=i/j;
            }
        }
        for(;x[l]!=0;l++)y+=x[l];
        if(y==2*i)
        {
               //if(p!=0)cout<<endl;
            cout<<i<<" its factors are ";   //p=1;
            for(int a=0;a<l-1;a++)
                for(int b=0;b<l-1-a;b++)
                    if(x[b]>x[b+1]){h=x[b];x[b]=x[b+1];x[b+1]=h;}
        }
        if(y==2*i)
        {
            for(l=0;x[l]!=i;l++)cout<<x[l]<<" ";
            cout<<endl;
        }

        for(int c=0;x[c]!=0;c++)x[c]=0;

    }

    return 0;
}
*/

//求简单交错序列前N项和
//
//本题要求编写程序,计算序列 1 - 1/4 + 1/7 - 1/10 + ... 的前N项之和。
//
//输入格式:
//输入在一行中给出一个正整数N。
//
//输出格式:
//在一行中按照“sum = S”的格式输出部分和的值S，精确到小数点后三位。题目保证计算结果不超过双精度范围。
//
//输入样例:
//在这里给出一组输入。例如：
//
//10
//输出样例:
//在这里给出相应的输出。例如：
//
//sum = 0.819

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n;
    double sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)sum += 1.0 / (1 + i * 3);
        else sum -= 1.0 / (1 + i * 3);
    }

    cout << setiosflags(ios::fixed) << setprecision(3);
    cout << "sum = " << sum << endl;

    return 0;
}
