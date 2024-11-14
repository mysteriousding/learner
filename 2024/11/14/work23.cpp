/*(6)第n个奇数及其求和

//请输出正整数里的第n个奇数并输出前n个奇数的和。
//
//输入格式:
//输入在一行中给出一个正整数n。
//
//输出格式:
//输出大于0的第n个奇数，并对前n个奇数进行求和。
//
//输入样例:
//在这里给出一组输入。例如：
//
//8
//输出样例:
//在这里给出相应的输出。例如：
//
//第8个奇数为：15
//前8个奇数的和为：64

#include<iostream>
using namespace std;
int main()
{
    int n,m=0;
    cin>>n;
    for(int i=0;i<n;i++)m+=2*i+1;

    cout<<"第"<<n<<"个奇数为："<<2*n-1<<endl;
    cout<<"前"<<n<<"个奇数的和为："<<m;

    return 0;
}
*/

/*(7)计算1!+2!+3!+......

//已知求阶乘的函数如下，利用这个函数，编程计算并输出5*(1!+2!+...+n!)的值。注意函数Fact()返回的类型。
//
//unsigned long  Fact(unsigned int  n)
//{
//    int  i;
//    unsigned long result = 1;
//    for (i=2; i<=n; i++)
//        result *= i;
//    return result;
//}
//
//提示：最后一行输出sum的格式为 printf("sum=%u",sum);//无符号整数
//输入格式:
//输入整数n，n小于13。
//
//输出格式:
//sum=计算结果。
//
//输入样例:
//4
//输出样例:
//sum=165

#include<iostream>
using namespace std;
int main()
{
    long long J(int x);
    int n;
    long long m=0;
    cin>>n;
    for(;n>0;n--)m+=J(n);

    cout<<"sum="<<5*m<<endl;

    return 0;
}

long long J(int x)
{
    long long y=1;
    for(;x>0;x--)y*=x;
    return y;
}
*/

/*(8)素数求和。

//输入两个正整数m和n（1<=m<n<=500）统计并输出m和n之间的素数个数以及这些素数的和。
//
//输入格式:
//输入两个正整数m和n（1<=m<n<=500）。
//
//输出格式:
//输出m和n之间的素数个数以及这些素数的和。
//
//输入样例:
//在这里给出一组输入。例如：
//
//1 10
//输出样例:
//在这里给出相应的输出。例如：
//
//1和10之间有4个素数，这些素数的和是17。

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,m,x=0,y=0;
    cin>>n>>m;
    for(int i=n;i<=m;i++)
    {
        int p=0;
        for(int j=2;j<=sqrt(i);j++)
            if(i%j==0){p=1;break;}
        if(i!=1&&p==0)
        {
            x++;
            y+=i;
        }
    }

    cout<<n<<"和"<<m<<"之间有"<<x<<"个素数，这些素数的和是"<<y<<"。"<<endl;

    return 0;
}
*/

/*(9)计算N以内的正偶数之和

//这是一个编程题模板。
//
//计算2、4、6、8、......、N以内的正偶数之和，N值从键盘输入。
//
//输入格式:
//输入一个正整数N。
//
//输出格式:
//输出累加的正偶数之和。
//
//输入样例:
//11
//输出样例:
//sum = 30

#include<iostream>
using namespace std;
int main()
{
    int n,m=0;
    cin>>n;
    for(int i=0;i<=n;i+=2)m+=i;

    cout<<"sum = "<<m<<endl;

    return 0;
}
*/

//输出一组成绩中的最高分和最低分
//
//第一行输入人数n，第二行输入每个人的成绩，用空格分开。输出所有成绩中的最高分和最低分。
//
//输入格式:
//第一行输入n，大于0的整数；第二行输入n个大于等于0，小于等于100的整数，用空格分开。
//
//输出格式:
//最高分和最低分，用空格分开。
//
//输入样例:
//10
//88 78 92 76 68 55 87 91 78 87
//输出样例:
//92 55

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, h;
    cin >> n;
    vector<int>m(n);
    for (int i = 0; i < n; i++)cin >> m[i];
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (m[j] > m[j + 1]) { h = m[j]; m[j] = m[j + 1]; m[j + 1] = h; }
    cout << m[n - 1] << " " << m[0] << endl;

    return 0;
}
