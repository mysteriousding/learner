/*(16)h0029. 数组排序

//给定一个长度为n的数组a以及两个整数 l 和 r，请你编写一个函数，void sort(int a[], int l, int r)，将a[l] ~ a[r]从小到大排序。
//
//输出排好序的数组a。
//
//输入格式:
//第一行包含三个整数n，l，r。0≤l≤r<n≤1000
//
//第二行包含n个整数，表示数组a。
//
//输出格式:
//共一行，包含n个整数，表示排序完成后的数组a。
//
//输入样例:
//5 2 4
//4 5 1 3 2
//输出样例:
//4 5 1 2 3

#include<iostream>
using namespace std;
void sort(int m[],int l,int r)
{
    int h;
    for(int i=l;i<r;i++)
        for(int j=l;j<r+l-i;j++)
            if(m[j]>m[j+1])
                h=m[j],m[j]=m[j+1],m[j+1]=h;
}
int main()
{
    int n,l,r,m[1000];
    cin>>n>>l>>r;
    for(int i=0;i<n;i++)
        cin>>m[i];
    sort(m,l,r);
    for(int j=0;j<n;j++)
        cout<<m[j]<<" ";

    return 0;
}
*/

/*(17)最值交换

//有一个长度为n的整数序列。请写一个程序，先把序列中的最小值与第一个数交换，再把最大值与最后一个数交换。输出转换好的序列。 
//分别编写两个函数MinIndex()和MaxIndex()来计算最小值下标和最大值下标。
//
//int MinIndex(int a[], int n);  //函数返回数组a中最小元素的下标
//
//int MaxIndex(int a[], int n);  //函数返回数组a中最大元素的下标
//数组元素的输出调用函数PrintArr()。
//
//输入格式:
// 输入包括两行。
//第一行为正整数n（1≤n≤10）。
//第二行为n个正整数组成的序列，保证没有重复元素。
//
//输出格式:
//输出转换好的序列。数据之间用空格隔开。
//
//输入样例:
//在这里给出一组输入。例如：
//
//5
//5 4 1 2 3
//输出样例:
//在这里给出相应的输出。例如：
//
//1 4 3 2 5

#include<iostream>
using namespace std;
void MinIndex(int m[],int n)
{
    int min=m[0],k=0;
    for(int i=0;i<n;i++)
        if(m[i]<min)min=m[i],k=i;
    min=m[0],m[0]=m[k],m[k]=min;
}
void MaxIndex(int m[],int n)
{
    int max=m[0],k=0;
    for(int j=0;j<n;j++)
        if(m[j]>max)max=m[j],k=j;
    max=m[n-1],m[n-1]=m[k],m[k]=max;
}
int main()
{
    int n,m[10];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>m[i];
    MinIndex(m,n);
    MaxIndex(m,n);
    for(int j=0;j<n;j++)
        cout<<m[j]<<" ";

    return 0;
}
*/

/*(18)求1!+2!+...+n!

//已知求阶乘的函数如下，利用这个函数，编程计算并输出1!+2!+...+n!的值。其中n由用户从键盘输入。
//
//输入格式:
//用户从键盘输入正整数n的值。
//
//输出格式:
//按输出样例的形式输出计算的结果。
//函数接口定义：
//unsigned long  Fact(unsigned int  n);
//其中，n是用户输入的正整数
//函数返回n!的值
//
//主程序样例：
//这里给出主函数及对Fact函数的调用样例：
//unsigned long  Fact(unsigned int  n);
//int main(void)
//{
//    unsigned int m;
//    unsigned long s=0;
//    int i;
//    scanf("%d",&m);
//    for (i=1;i<=m;i++)
//        s=s+Fact(i);
//    printf("%u",s);
//    return 0;
//}
///* 请在这里完成 Fact函数*
//
//输入样例:
//在这里给出一组输入。例如：
//
//5
//输出样例 :
//在这里给出相应的输出。例如：
//
//153

#include<iostream>
unsigned long  Fact(unsigned int  n);
int main(void)
{
    unsigned int m;
    unsigned long s=0;
    int i;
    scanf("%d",&m);
    for (i=1;i<=m;i++)
        s=s+Fact(i);
    printf("%u",s);
    return 0;
}
unsigned long Fact(unsigned int n)
{
    static int m=1;
    m*=n;
    return m;
}
*/

/*(19)学生信息的输入输出与求各门课的总分

//用数据结构定义学生信息学号、姓名、5门课程的成绩,编一程序，输入n（n<=100)个学生成绩，求出总分最高的学生姓名并输出结果。
//要求编写3个函数，它们的功能分别为：
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
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
struct stu
{
    int xh;
    string name;
    int cj[6];
};
void zf(int m[])
{
    int sum=0;
    for(int i=0;i<5;i++)
        sum+=m[i];
    m[5]=sum;
}
void tj(stu&x)
{
    cin>>x.xh>>x.name;
    for(int j=0;j<5;j++)
        cin>>x.cj[j];
    zf(x.cj);
}
void sc(stu y)
{
    cout<<setw(5)<<y.xh<<setw(10)<<y.name;
    for(int i=0;i<5;i++)
        cout<<setw(5)<<y.cj[i];
    cout<<setw(10)<<y.cj[5]<<endl;
}
int main()
{
    int n;
    cin>>n;
    vector<stu>m(n);
    for(int i=0;i<n;i++)
        tj(m[i]);
    for(int j=0;j<n;j++)
        sc(m[j]);

    return 0;
}
*/

//完数判断
//分数 10
//作者 罗德宁
//单位 成都信息工程大学
//一个正整数如果恰好等于它除自身外的因数之和，这个数称为“完数”。例如，6的因数有1、2和3，且6=1+2+3，因此6是“完数”。
//编写判别完数的函数wanshu (int x)：判断x是否为完数，如果是，则返回1，不是，则返回0。
//在主函数main()输出1-1000内的所有完数。
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
using namespace std;
bool wanshu(int n)
{
    // if(n==1)return 0;
    int sum = 0;
    for (int j = 1; j * j <= n; j++)
        if (n % j == 0)
        {
            sum += j;
            if (j * j != n)sum += n / j;
        }
    return (sum == 2 * n) ? 1 : 0;
}
int main()
{
    for (int i = 1; i <= 1000; i++)
        if (wanshu(i))cout << i << "是完数" << endl;

    return 0;
}
