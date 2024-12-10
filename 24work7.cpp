/*(31)完数判断

//一个正整数如果恰好等于它除自身外的因数之和，这个数称为“完数”。例如，6的因数有1、2和3，且6=1+2+3，因此6是“完数”。编写判别完数的函数wanshu (int x)：判断x是否为完数，如果是，则返回1，不是，则返回0。在主函数main()输出1-1000内的所有完数。
//
//
//输入样例:
//无输入
//
//
//输出样例:
//例如：
//
//6是完数
//28是完数
//496是完数

#include<iostream>
#include<cmath>
using namespace std;
bool wanshu(int n);
int main()
{
    for(int i=1;i<=1000;i++)
        if(wanshu(i))cout<<i<<"是完数"<<endl;

    return 0;
}
bool wanshu(int n)
{
    int sum=0;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            sum+=i;
            if(n/i!=i)sum+=n/i;
        }
    }
    if(sum==2*n)return 1;
    else return 0;
}
*/

/*(32)分段函数

//输入x，输出相应的y值。要求定义和调用函数fun，实现下面的分段函数。
//
//  ⎧ −x  x<0
//y=⎨  x  x>0
//  ⎩  0  x=0
//
//输入样例:
//例如：
//
//-5
//输出样例:
//例如：
//
//y = 5

#include<iostream>
using namespace std;
void fun(int& n)
{
    if(n<0)n*=-1;
}
int main()
{
    int n;
    cin>>n;
    fun(n);
    cout<<"y = "<<n<<endl;

    return 0;
}
*/

/*(33)编写一个函数用于计算高于平均分的人数。

//编写一个函数int fun(float s[],int n)，用于计算高于平均分的人数，并作为函数值返回，其中数组s中存放n位学生的成绩。
//再编写一个主函数，从键盘输入一批分数（用-1来结束输入），调用fun函数计算并输出高于平均分的人数。
//
//输入格式:
//输入一批浮点数，用-1来结束输入。
//
//输出格式:
//一个整数。
//
//输入样例:
//在这里给出一组输入。例如：
//
//10.0 20.0 30.0 40.0 50.0 -1
//输出样例:
//在这里给出相应的输出。例如：
//
//2

#include<iostream>
using namespace std;
float sr(float x[])
{
    float sum=0;
    for(int i=0;;i++)
    {
        cin>>x[i];
        if(x[i]!=-1)sum+=x[i];
        else return sum/i;
    }
}
int js(float y[],float k)
{
    int l=0,i=0;
    while(y[i]!=-1)
        if(y[i++]>k)l++;
    return l;
}
int main()
{
    float cj[100];
    float sum=sr(cj);
    cout<<js(cj,sum)<<endl;

    return 0;
}
*/

/*(34)求完全数的个数

//一个大于1的正整数若等于全部因子的和，则称此数为完全数。例如：6 有因子 1，2，3。同时 1+2+3=6所以6 是完全数。
//
//输入格式:
//一个正整数n（<10000）
//
//输出格式:
//小于等于n的完全数的个数。
//
//输入样例:
//在这里给出一组输入。例如：
//
//10
//输出样例:
//在这里给出相应的输出。例如：
//
//1

#include<iostream>
#include<cmath>
using namespace std;
bool wanshu(int n);
int main()
{
    int n,m=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        if(wanshu(i))m++;
    cout<<m<<endl;

    return 0;
}
bool wanshu(int n)
{
    int sum=0;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            sum+=i;
            if(n/i!=i)sum+=n/i;
        }
    }
    if(sum==2*n)return 1;
    else return 0;
}
*/

//斐波那契趣事
//
//有一个有趣的实验，假如你有一大袋1分或者2分的硬币，你要把它们放入存钱罐中。
//
//如果你想存入1分钱，只有1种放法，只能放入1枚1分钱硬币。
//
//如果想存入2分钱，有2种放法，放入2枚1分硬币，或者放入1枚2分硬币。
//
//如果想存入3分钱，有3种放法，放入3枚1分硬币，或者放入1枚2分硬币，然后放入1枚1分硬币，又或者先放入1枚1分硬币，然后放入1枚2分硬币。
//
//如果你想存入4分钱或者5分钱，则可以看如下表格：
//
//
//存入钱的总数	放入方法总数	不同的方法
//1	             1	             1
//2	             2	             1+1          2
//3	             3	             1+1+1        2+1        1+2
//4	             5	             1+1+1+1      2+1+1        1+2+1      1+1+2         2+2
//5	             8	             1+1+1+1+1    1+2+1+1    1+1+2+1     1+1+1+2       2+1+1+1      2+2+1       2+1+2     1+2+2
//。。。	         。。。	         。。。
//
//输入格式:
//输入为一个不超过100的整数n。n表示要存入的钱数。单位为分。（注意，当n为100的时候，输出会非常大）
//
//输出格式:
//输出放入的方法总数。
//
//输入样例:
//在这里给出一组输入。例如：
//
//5
//输出样例:
//在这里给出相应的输出。例如：
//
//8

// #include<iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     int n;
//     cin>>n;
//     vector<long long>m(n+2,1);
//     for(int i=2;i<n+2;i++)
//         m[i]=m[i-1]+m[i-2];
//     cout<<m[n]<<endl;

//     return 0;
// }

#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string m[3]={"1xxxxxxxxxxxxxxxxxxxxxxxxx","1xxxxxxxxxxxxxxxxxxxxxxxxxx","1xxxxxxxxxxxxxxxxxxxxxxxxxx"};
    for(int i=2;i<n+1;i++)
    {
        int j=0,k=0;
        while(m[0][j]!='x'||m[1][j]!='x'||k!=0)
        {
            m[2][j]=((m[0][j]-((m[0][j]=='x')?'x':'0'))+(m[1][j]-((m[1][j]=='x')?'x':'0'))+k)%10+'0';
            k=((m[0][j]-((m[0][j]=='x')?'x':'0'))+(m[1][j]-((m[1][j]=='x')?'x':'0'))+k)/10;
            j++;
        }
        m[0]=m[1];
        m[1]=m[2];
    }
    m[2]="";
    int i=0;
    while(m[1][i]!='x')
        m[2]=m[1][i++]+m[2];
    if(n==0)cout<<0<<endl;
    else cout<<m[2]<<endl;

    return 0;
}
