/*(1)StrCmp

//请自己编写一个实现字符串的比较功能的函数。
//
//注意：不允许使用C语言标准函数库中相关的字符串函数
//
//函数接口定义：
//
//int MyStrCmp(const char *str1, const char *str2);
//
//说明：str1 和 str2 分别为两个字符串的起始地址。
//按字典排序法，若 str1 串值大于 str2，则函数值为正整数；
//若 str1 串值小于 str2，则函数值为负整数；
//若 str1 串值与 str2 相等，则函数值为0。
//如果str1和str2中较短串的长度范围内字符相等，则字符串长度更长的字符串为大。
//裁判测试程序样例：
//
//#include <stdio.h>
//
//int MyStrCmp(const char *str1, const char *str2);
//
//int main()
//{
//    char a[1024], b[1024];
//    int r;
//    while(~scanf("%s%s",a,b))
//    {
//        r = MyStrCmp(a, b);
//        puts(!r ? "a = b" : r > 0 ? "a > b" : "a < b");
//    }
//    return 0;
//}
//int MyStrCmp(const char *str1, const char *str2){
//
///* 请在这里填写答案 *
///*注意：只需要在此写函数体的语句，不需要写“{”和“ }“*
//
//}
//
//输入样例：
//student
//stackflow
//hello
//helloworld
//helloworld
//helloworld
//输出样例：
//a > b
//a < b
//a = b

#include <stdio.h>

int MyStrCmp(const char *str1, const char *str2);

int main()
{
    char a[1024], b[1024];
    int r;
    while(~scanf("%s%s",a,b))
    {
        r = MyStrCmp(a, b);
        puts(!r ? "a = b" : r > 0 ? "a > b" : "a < b");
    }
    return 0;
}
int MyStrCmp(const char *str1, const char *str2)
{
    //作答
    for (int i = 0;; i++)
    {
        if (*(str1 + i) > *(str2 + i))return 1;
        if (*(str1 + i) < *(str2 + i))return -1;
        if (*(str1 + i) == 0 && *(str2 + i) == 0)return 0;
    }
    //结束
}
*/

/*(2)LX606 指针数据交互
//题目背景
//《C/C++简明双链教程》
//
//知识点：T613
//
//题目描述
//完成函数，从键盘任意输入两个整数，用指针作函数参数，编程实现将其交换后再重新输出。
//
//函数定义接口：
//
//void swap(int *x, int *y);
//请实现该函数，使得下述程序可以正确运行。
//
//裁判测试程序样例：
//
//#include<stdio.h>
//void swap(int *x, int *y);
//
//int main(){
//    int a,b;
//    scanf("%d %d",&a,&b);
//    swap(&a,&b);
//    printf("After swap:%d,%d",a,b);
//    return 0;
//}
//
////答案写在这里
//输入格式
//从键盘输入两个整数，空格分隔
//
//输出格式
//按输出样例的形式输出交换后的两个整数。
//
//样例 #1
//样例输入 #1
//11 22
//样例输出 #1
//After swap:22,11

#include<stdio.h>
void swap(int *x, int *y);

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    swap(&a,&b);
    printf("After swap:%d,%d",a,b);
    return 0;
}

//作答
void swap(int* x, int* y)
{
    int h;
    h = *x;
    *x = *y;
    *y = h;
}
//结束
*/

/*LX607 排序函数            ---sb出题人，一维数组定义错误

//题目背景
//《C/C++简明双链教程》
//
//知识点：T515,T625
//
//题目描述
//完成函数，将给定的n个数从小到大排序。
//
//函数定义接口：
//
//void sort_arr(int n,int* a);
//请实现该函数，使得下述程序可以正确运行。
//
//裁判测试程序样例：
//
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//void sort_arr(int n,int* a);
//
//int main()
//{
//    int k;
//    cin >> k;
//    while (k--)
//    {
//        int n;
//        cin >> n;
//        int a[n];
//        for (int i=0;i<n;++i)
//        {
//            cin >> a[i];
//        }
//        sort_arr(n,a);
//        int i;
//        for (i=0;i<n-1;++i)
//        {
//            cout << a[i] << " ";
//        }
//        cout << a[i] << endl;
//    }
//
//    return 0;
//}
////答案写在这里
//输入格式
//首先是一个整数K，表示有K组数据。
//接下来是以回车分隔的K组数据，每组数据首先以一个整数N开头（1<N<100），表示该组数据中包含的整数个数，然后是以空格分隔的N个整数。
//
//输出格式
//对每组数据按要求从小到大输出，组内整数之间隔一个空格，组与组之间以回车分隔。
//
//样例 #1
//样例输入 #1
//3
//6 1 5 4 3 2 0
//5 8 5 2 10 3
//2 2 2
//样例输出 #1
//0 1 2 3 4 5
//2 3 5 8 10
//2 2

#include <iostream>           // ---sb出题人，我已修改错误
#include <algorithm>
#include<vector>

using namespace std;
void sort_arr(int n, vector<int>& a);

int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        int n;
        cin >> n;
        //int a[n];
        vector<int>a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort_arr(n, a);
        int i;
        for (i = 0; i < n - 1; ++i)
        {
            cout << a[i] << " ";
        }
        cout << a[i] << endl;
    }

    return 0;
}

//作答
void sort_arr(int n, vector<int>& a)
{
    int h;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) { h = a[j]; a[j] = a[j + 1]; a[j + 1] = h; }
}
//结束
*/

//LX608 矩阵每行元素和            ---sb出题人，一维数组定义错误
//题目背景
//《C/C++简明双链教程》
//
//知识点：T515,
//T531,T625
//
//题目描述
//完成函数，使用指针方式求一个给定的m×n矩阵各行元素之和。
//
//函数定义接口：
//
//void row_sum(int m,int n,int a[N][N],int* res);
//请实现该函数，使得下述程序可以正确运行。
//
//裁判测试程序样例：
//
//#include <iostream>
//using namespace std;
//#define N 10
//
//void row_sum(int m,int n,int a[N][N],int* res);
//int main()
//{
//    int m,n;
//    cin >> m >> n;
//    int a[N][N];
//    int b[m];
//    for (int i=0;i<m;++i){
//        for (int j=0;j<n;++j){
//            cin >> a[i][j];
//        }
//    }
//    row_sum(m,n,a,b);
//    for (int i=0;i<m;++i){
//        cout << b[i] << endl;
//    }
//
//    return 0;
//}
//输入格式
//输入第一行给出两个正整数m和n（1≤m,n≤6），再输入m行数据，每行n个整数，每个整数之间用空格分隔。
//
//输出格式
//输出m个整数，每行1个数。
//
//样例 #1
//样例输入 #1
//2 3
//1 2 3
//4 5 6
//样例输出 #1
//6
//15

#include <iostream>           // ---sb出题人，我已修改错误
#include<vector>
using namespace std;
#define N 10

void row_sum(int m, int n, int a[N][N], vector<int>* res);
int main()
{
    int m, n;
    cin >> m >> n;
    int a[N][N];
    //int b[m];
    vector<int>b(m);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    row_sum(m, n, a, &b);
    for (int i = 0; i < m; ++i) {
        cout << b[i] << endl;
    }

    return 0;
}

//指定
void row_sum(int m, int n, int a[N][N], vector<int>* res)
{
    for (int i = 0; i < m; ++i)
    {
        int sum = 0;
        for (int j = 0; j < n; ++j)sum += a[i][j];
        (*res)[i] = sum;
    }
}
//结束