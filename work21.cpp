/*(16)A+B

//本题目要求读入2个整数A和B，然后输出它们的和。
//
//输入格式:
//2个不超过长长整型的整数A和B。
//
//输出格式:
//先输出“A+B=”，在输出A+B的值。
//
//输入样例:
//10 1
//输出样例:
//10+1=11

#include<iostream>
using namespace std;
int main()
{
    long long a,b;
    cin>>a>>b;
    cout<<a<<"+"<<b<<"="<<a+b<<endl;

    return 0;
}
*/

/*(17)简单函数

//定义函数为：f(x)=x*2+1
//
//要求编写程序，完成函数
//
//输入格式:
//一个数x
//
//输出格式:
//函数的值
//
//输入样例:
//4
//输出样例:
//9

#include<iostream>
using namespace std;
int main()
{
    long long x;
    cin>>x;

    cout<<x*2+1<<endl;

    return 0;
}
*/

/*(18)等差数列末项计算

//给出一个等差数列的前两项a1，a2，求第n项是多少。
//
//输入格式:
//给出一个等差数列的前两项a1，a2，求第n项是多少。
//
//输出格式:
//一行，包含三个整数a1，a​2，n。
//
//输入样例:
//1 4 100
//输出样例:
//298

#include<iostream>
using namespace std;
int main()
{
    long long a,b,c;
    cin>>a>>b>>c;
    a=a+(b-a)*(c-1);
    cout<<a<<endl;

    return 0;
}
*/

//L-念念不忘，必有回响
//
//当黄子和小齐还在为听到回声，感叹大自然的鬼斧神工时，韬韬、阿蒲和火树却拿出计时器，开始计算远处的山离自己的所在地有多远。
//
//现已知声音在空气中的传播速度为340米/秒，黄子对着远处喊话，从喊话时开始计时，到听到回声计时结束，记录下这个时间长度（以秒计），请你计算远处的山离黄子有多远。
//
//输入格式:
//在一行输入时间长度t。
//
//输出格式:
//在一行输出山离黄子的距离（以公里计，保留小数点后2位）。
//
//输入样例:
//1.2
//输出样例:
//0.20

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    float t;
    cin >> t;

    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << (0.34 * t) / 2 << endl;

    return 0;
}