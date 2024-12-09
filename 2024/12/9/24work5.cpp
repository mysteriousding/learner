/*(21)h0029. 数组排序

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
#include<vector>
using namespace std;
void sort(vector<int>&a,int b,int c)
{
    int h;
    for(int i=b;i<c;i++)
        for(int j=b;j<c-(i-b);j++)
        if(a[j]>a[j+1]){h=a[j];a[j]=a[j+1];a[j+1]=h;}
}
int main()
{
    int n,l,r;
    cin>>n>>l>>r;
    vector<int>N(n);
    for(int i=0;i<n;i++)
        cin>>N[i];
    sort(N,l,r);
    for(int i=0;i<n;i++)
        cout<<N[i]<<" ";


    return 0;
}
*/

/*(22)最值交换

//有一个长度为n的整数序列。请写一个程序，先把序列中的最小值与第一个数交换，再把最大值与最后一个数交换。
//输出转换好的序列。 分别编写两个函数MinIndex()和MaxIndex()来计算最小值下标和最大值下标。
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
#include<vector>
using namespace std;
int min(vector<int>a,int n)
{
    int k=0;
    for(int i=0;i<n;i++)
        if(a[i]<a[k])k=i;
    return k;
}
int max(vector<int>a,int n)
{
    int k=0;
    for(int i=0;i<n;i++)
        if(a[i]>a[k])k=i;
    return k;
}

int main()
{
    int n,h;
    cin>>n;
    vector<int>m(n);
    for(int i=0;i<n;i++)
        cin>>m[i];
    int ax,in;
    ax=max(m,n);
    h=m[n-1];m[n-1]=m[ax];m[ax]=h;
    in=min(m,n);
    h=m[0];m[0]=m[in];m[in]=h;
    for(int i=0;i<n;i++)
        cout<<m[i]<<" ";

    return 0;
}
*/

/*(23)从1到n之间所有偶数的阶乘值

//已知求阶乘的函数如下，利用这个函数，编程计算并输出1到n之间所有偶数的阶乘值。
//
//其中n由用户从键盘输入。
//
//double  Fact(int  n)
//{
//    int  i;
//    double result = 1;
//    for (i=2; i<=n; i++)
//        result *= i;
//    return result;
//}
//输入格式:
//用户从键盘输入正整数n的值。
//
//输出格式:
//按输出样例的形式输出计算的结果。
//
//输入样例:
//9
//
//输出样例:
//2! = 2
//4! = 24
//6! = 720
//8! = 40320


*/

/*(24)从1到n之间所有奇数的阶乘值

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
long  Fact(int  n)
{
    int  i;
    long result = 1;
    for (i=2; i<=n; i++)
        result *= i;
    return result;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i+=2)
        cout<<i<<"! = "<<Fact(i)<<endl;

    return 0;
}
*/

//求1!+2!+...+n!
//分数 25
//作者 张江
//单位 合肥师范学院
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
//
//输出样例 :
//在这里给出相应的输出。例如：
//
//153

#include<iostream>
unsigned long  Fact(unsigned int n);
int main(void)
{
    unsigned int m;
    unsigned long s=0;
    int i;
    scanf("%d",&m);
    for (i=1;i<=m;i++)
        s=s+Fact(i);
    printf("%lu",s);
    return 0;
}
unsigned long Fact(unsigned int n)
{
    int  i;
    unsigned long result = 1;
    for (i=2; i<=n; i++)
        result *= i;
    return result;
}
