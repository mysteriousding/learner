/*(26)用递归法求解Fibonacci数列

//这是一个编程题模板。
//
//已知斐波那契数列公式如下：
//F(n)=F(n−1)+F(n−2),(n>2);
//F(1)=1;F(2)=1。
//
//输入格式:
//输入一个正整数n(1<=n<=50)。
//
//输出格式:
//输出该正整数n对应的斐波那契数列的F(n)。
//如果输入的n<1或者n>50，输出"Wrong Input!"
//
//输入样例:
//在这里给出一组输入。例如：
//
//2
//输出样例:
//在这里给出相应的输出。例如：
//
//F(2)=1
//输入样例:
//在这里给出一组输入。例如：
//
//3
//输出样例:
//在这里给出相应的输出。例如：
//
//F(3)=2
//输入样例:
//在这里给出一组输入。例如：
//
//-7
//输出样例:
//在这里给出相应的输出。例如：
//
//Wrong Input!

#include<iostream>
using namespace std;
int main()
{
    int n,m[50]={1,1};
    cin>>n;
    if(n<1||n>50)cout<<"Wrong Input!"<<endl;
    else
    {
        for(int i=2;i<n+2;i++)
            m[i]=m[i-1]+m[i-2];
        cout<<"F("<<n<<")="<<m[n-1]<<endl;
    }

    return 0;
}
*/

/*(27)计算两整数的最大值

//用函数编程计算两整数的最大值，在主函数中调用该函数计算并输出从键盘任意输入的两整数的最大值。
//
//输入格式:
//在一行上输入两整数，两数之间用空格分隔。
//
//输出格式:
//按输出样例的形式输出两整数中的最大值。
//
//输入样例:
//在这里给出一组输入。例如：
//
//-26 57
//输出样例:
//在这里给出相应的输出。例如：
//
//Max=57
//输入样例:
//在这里给出一组输入。例如：
//
//38 16
//输出样例:
//在这里给出相应的输出。例如：
//
//Max=38
//输入样例:
//在这里给出一组输入。例如：
//
//0 0
//输出样例:
//在这里给出相应的输出。例如：
//
//Max=0

#include<iostream>
using namespace std;
void max(int* x,int* y)
{
    if(*x<*y)*x=*y;
}
int main()
{
    int n,m,*x=&n,*y=&m;
    cin>>n>>m;
    max(x,y);
    cout<<"Max="<<*x<<endl;

    return 0;
}
*/

/*(28)判断闰年

//用函数编程判断某年是否是闰年，如果是闰年，函数返回值为1，否则返回值为0。在主函数中，从键盘任意输入一个年份，调用该函数判断该年是否是闰年。
//
//输入格式:
//从键盘上输入一个年份。
//
//输出格式:
//按输出样例的形式输出。
//主函数和函数声明如下：
//int Year(int n);
//int main(void)
//{
//    int year,flag;
//    scanf("%d",&year);
//    flag=Year(year);
//    if(flag==1)
//        printf("%d is a leap year.",year);
//    else
//        printf("%d is not a leap year.",year);
//    return 0;
//}
///* 函数Year的定义在此处编写 *
//
//输入样例:
//在这里给出一组输入。例如：
//
//2024
//输出样例 :
//在这里给出相应的输出。例如：
//
//2024 is a leap year.
//输入样例 :
//在这里给出一组输入。例如：
//
//2100
//输出样例 :
//在这里给出相应的输出。例如：
//
//2100 is not a leap year.

#include<iostream>
using namespace std;
bool Year(int x)
{
    if((x%4==0&&x%100!=0)||x%400==0)return 0;
    else return 1;
}
int main()
{
    int n;
    cin>>n;
    cout<<n<<" is ";
    if(Year(n))cout<<"not ";
    cout<<"a leap year."<<endl;

    return 0;
}
*/

/*(29)学生信息的输入输出与求各门课的总分

//用数据结构定义学生信息学号、姓名、5门课程的成绩,编一程序，输入n（n<=100)个学生成绩，求出总分最高的学生姓名并输出结果。要求编写3个函数，它们的功能分别为：
//①  输入函数，用于从键盘读入学号、姓名和五门课的成绩;学号和成绩使用int型，姓名长度不超过10个字符。
//②  计算总分函数，以计算每位学生的总分;
//③  输出函数，显示每位学生的学号、总分和分数;
//说明：这三个函数的形式参数均为结构体指针和整型变量，函数的类型均为void。
//
//输入格式:
//第一行输入学生的个数n
//从第二行开始每一行输入一个学生的信息：学号、姓名、5门课程的成绩。
//
//输出格式:
//每一行输出每一个同学的学号、姓名、5门课的成绩及总分。每一个同学的成绩输出完毕后换行。
//其中：学号占5个字符位置，姓名占10个字符位置，每门课占5个字符位置，总分占10个字符位置，均右对齐。
//
//输入样例:
//在这里给出一组输入。例如：
//
//3
//001 zhang 50 60 70 80 90
//002 li 60 70 60 70 80
//003 wang 70 75 80 85 90
//输出样例:
//在这里给出相应的输出。例如：
//
//    1     zhang   50   60   70   80   90       350
//    2        li   60   70   60   70   80       340
//    3      wang   70   75   80   85   90       400

#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;
struct stu
{
    int xh;
    string name;
    int fs[6];
};
void sr(vector<stu>&x,int n);
void sc(vector<stu>&y,int n);
int main()
{
    int n;
    cin>>n;
    vector<stu>m(n);
    sr(m,n);
    sc(m,n);

    return 0;
}
void sr(vector<stu>&x,int n)
{
    int sum;
    for(int i=0;i<n;i++)
    {
        cin>>x[i].xh;
        cin>>x[i].name;
        sum=0;
        for(int j=0;j<5;j++)
        {
            cin>>x[i].fs[j];
            sum+=x[i].fs[j];
        }
        x[i].fs[5]=sum;
    }
}
void sc(vector<stu>&y,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<setw(5)<<y[i].xh
            <<setw(10)<<y[i].name;
        for(int j=0;j<5;j++)
            cout<<setw(5)<<y[i].fs[j];
        cout<<setw(10)<<y[i].fs[5]<<endl;
    }
}

*/

//求1+2+3+4+5+…+n的和值
//
//输入一个整数，写一个函数fun求1+2+3+4+5+…+n的和值，并在main()函数中输出和值。
//
//
//输入样例:
//例如：
//
//5
//输出样例:
//例如：
//
//sum = 15

#include<iostream>
using namespace std;
long long fun(int n)
{
    long long sum =0;
    for (int i=1;i<=n;i++)
       sum +=i;
    return sum;
}
int main()
{
    int n;
    cin>>n;
    cout<<"sum = "<<fun(n)<<endl;

    return 0;
}
