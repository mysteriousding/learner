/*(6)求五边形面积

//下面的程序输入五边形的五条边和两条对角线的长度，计算并输出五边形的面积。
//
//输入格式
//a、b、c、d、e、f 和 g
//
//输出格式
//s
//
//注：保留 4 位小数，末尾自动四舍五入。
//
//输入样例
//3.18 4.11 3.89 2.75 4.02 5.86 5.76
//
//输出样例
//21.8925
//
//相关习题：三角形面积(海伦公式)。

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    double a,b,c,d,e,f,g,p1,p2,p3;
    cin>>a>>b>>c>>d>>e>>f>>g;
    p1=(a+f+e)/2;
    p2=(f+b+g)/2;
    p3=(g+d+c)/2;
    cout<<setiosflags(ios::fixed)<<setprecision(4);
    cout<<pow(p1*(p1-a)*(p1-f)*(p1-e),0.5)+pow(p2*(p2-f)*(p2-b)*(p2-g),0.5)+pow(p3*(p3-g)*(p3-d)*(p3-c),0.5)<<endl;

    return 0;
}
*/

/*(7)从1到n之间所有奇数的阶乘值

//已知求阶乘的函数如下，利用这个函数，编程计算并输出1到n之间所有奇数的阶乘值。
//
//其中n由用户从键盘输入。
//
//long  Fact(int  n)
//{
//    int  i;
//    long result = 1;
//    for (i=2; i<=n; i++)
//        result *= i;
//    return result;
//}
//输入格式:
//用户从键盘输入正整数n的值（不超过12）。
//
//输出格式:
//按输出样例的形式输出计算的结果。
//
//输入样例:
//10
//输出样例:
//1! = 1
//3! = 6
//5! = 120
//7! = 5040
//9! = 362880

#include<iostream>
using namespace std;
long F(int n)
{
    long j=1;
    for(int i=2;i<=n;i++)
        j*=i;
    return j;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i+=2)
        cout<<i<<"! = "<<F(i)<<endl;

    return 0;
}
*/

/*(8)分段函数

//输入x，输出相应的y值。要求定义和调用函数fun，实现下面的分段函数。
//
//   ⎧ −x  x<0
//y= ⎨ x   x>0
//   ⎩ 0   x=0
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
#include<cmath>
using namespace std;
int m(int n){return abs(n);}
int main()
{
    int n;
    cin>>n;
    cout<<"y = "<<m(n)<<endl;

    return 0;
}
*/

/*(9)求完全数的个数

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
int main()
{
    int x[100]={0};
    int n,m=0;
    cin>>n;
    for(int i=2;i<=n;i++)
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
        if(y==2*i)m++;
    }
    cout<<m<<endl;

    return 0;
}
*/

//复合函数求值
//
// 求复合函数F(G(x))，其中函数F(x)=∣x−3∣+∣x+1∣，函数G(x)=x
//2
// −3x。要求编写函数funF()和funG()分别求F(x)和G(x)，其余功能在main()中实现。
//
//double funF(double x)
//{
////函数返回F(x)的值；
//}
//double funG(double x)
//{
////函数返回G(x)的值；
//}
//输入格式:
//输入一个实数x。
//
//输出格式:
//输出复合函数的值，结果保留2位小数。输出占一行。
//
//输入样例:
//在这里给出一组输入。例如：
//
//10.2
//输出样例:
//在这里给出相应的输出。例如：
//
//144.88

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double F(double y)
{
    return(abs(y - 3) + abs(y + 1));
}
double G(double x)
{
    return(x * (x - 3));
}
int main()
{
    double n;
    cin >> n;
    cout << setiosflags(ios::fixed) << setprecision(2) << F(G(n));

    return 0;
}
