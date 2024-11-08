/*(6)找出不是两个数组共有的元素

//给定两个整型数组，本题要求找出不是两者共有的元素。
//
//输入格式:
//输入分别在两行中给出两个整型数组，每行先给出正整数N（≤20），随后是N个整数，其间以空格分隔。
//
//输出格式:
//在一行中按照数字给出的顺序输出不是两数组共有的元素，数字间以空格分隔，但行末不得有多余的空格。题目保证至少存在一个这样的数字。同一数字不重复输出。
//
//输入样例:
//10 3 -5 2 8 0 3 5 -15 9 100
//11 6 4 8 2 6 -5 9 0 100 8 1
//输出样例:
//3 5 -15 6 4 1

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int x, y, a, b, p, p0;
    cin >> x;
    vector<int>n(x);
    for (int i = 0; i < x; i++)
    {
        p = 0;
        cin >> a;
        int j = 0;
        while (j < i)
        {
            if (a == n[j]) { p = 1; break; }
            j++;
        }
        if (p == 0)n[i] = a;
    }
    cin >> y;
    vector<int>m(y);
    for (int j = 0; j < y; j++)
    {
        p = 0;
        cin >> b;
        int i = 0;
        while (i < j)
        {
            if (b == m[i]) { p = 1; break; }
            i++;
        }
        if (p == 0)m[j] = b;
    }
    p = 0;
    for (int i = 0; i < x; i++)
    {
        p0 = 0;
        for (int j = 0; j < y; j++)
        {
            if (n[i] == m[j]) { p0 = 1; break; }
        }
        if (p0 == 0)
        {
            if (p != 0)cout << " ";
            cout << n[i];
            p = 1;
        }
    }
    for (int i = 0; i < y; i++)
    {
        p0 = 0;
        for (int j = 0; j < x; j++)
        {
            if (m[i] == n[j]) { p0 = 1; break; }
        }
        if (p0 == 0)
        {
            if (p != 0)cout << " ";
            cout << m[i];
            p = 1;
        }
    }

    return 0;
}
*/

/*(7)求一批整数中出现最多的个位数字

//给定一批整数，分析每个整数的每一位数字，求出现次数最多的个位数字。例如给定3个整数1234、2345、3456，其中出现最多次数的数字是3和4，均出现了3次。
//
//输入格式：
//输入在第1行中给出正整数N（≤1000），在第二行中给出N个不超过整型范围的非负整数，数字间以空格分隔。
//
//输出格式：
//在一行中按格式“M: n1 n2 ...”输出，其中M是最大次数，n1、n2、……为出现次数最多的个位数字，按从小到大的顺序排列。数字间以空格分隔，但末尾不得有多余空格。
//
//输入样例：
//3
//1234 2345 3456
//输出样例：
//3: 3 4

#include<iostream>
using namespace std;
int main()
{
    int n,h,k;
    int x[10]={0,0,0,0,0,0,0,0,0,0};
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>h;
        for(;;)
        {
            x[h%10]++;
            h/=10;
            if(h==0)break;
        }
    }
    k=x[0];
    for(int i=0;i<10;i++)
    {
        if(k<x[i])k=x[i];
    }
    cout<<k<<":";
    for(int i=0;i<10;i++)
    {
        if(x[i]==k)cout<<" "<<i;
    }
    cout<<endl;

    return 0;
}
*/

/*(8)查找整数

//本题要求从输入的N个整数中查找给定的X。如果找到，输出X的位置（从0开始数）；如果没有找到，输出“Not Found”。
//
//输入格式：
//输入在第一行中给出两个正整数N（≤20）和X，第二行给出N个整数。数字均不超过长整型，其间以空格分隔。
//
//输出格式：
//在一行中输出X的位置，或者“Not Found”。
//
//输入样例1：
//5 7
//3 5 7 1 9
//输出样例1：
//2
//输入样例2：
//5 7
//3 5 8 1 9
//输出样例2：
//Not Found

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, o, p = 0;
    cin >> n >> o;
    vector<int>m(n);
    for (int i = 0; i < n; i++)cin >> m[i];
    for (int j = 0; j < n; j++)
    {
        if (m[j] == o)
        {
            cout << j;
            p = 1;
        }
    }
    if (p == 0)cout << "Not Found";

    return 0;
}
*/

/*(9)冒泡法排序

//将N个整数按从小到大排序的冒泡排序法是这样工作的：从头到尾比较相邻两个元素，如果前面的元素大于其紧随的后面元素，则交换它们。通过一遍扫描，则最后一个元素必定是最大的元素。然后用同样的方法对前N−1个元素进行第二遍扫描。依此类推，最后只需处理两个元素，就完成了对N个数的排序。
//
//本题要求对任意给定的K（<N），输出扫描完第K遍后的中间结果数列。
//
//输入格式：
//输入在第1行中给出N和K（1≤K<N≤100），在第2行中给出N个待排序的整数，数字间以空格分隔。
//
//输出格式：
//在一行中输出冒泡排序法扫描完第K遍后的中间结果数列，数字间以空格分隔，但末尾不得有多余空格。
//
//输入样例：
//6 2
//2 3 5 1 6 4
//输出样例：
//2 1 3 4 5 6

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, k, h;
    cin >> n >> k;
    vector<int>m(n);
    for (int i = 0; i < n; i++)cin >> m[i];
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (m[j] > m[j + 1]) { h = m[j]; m[j] = m[j + 1]; m[j + 1] = h; }
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (j != 0)cout << " ";
        cout << m[j];
    }

    return 0;
*/

//将数组中的数逆序存放
//分数 10
//作者 C课程组
//单位 浙江大学
//本题要求编写程序，将给定的n个整数存入数组中，将数组中的这n个数逆序存放，再按顺序输出数组中的元素。
//
//输入格式:
//输入在第一行中给出一个正整数n（1≤n≤10）。第二行输入n个整数，用空格分开。
//
//输出格式:
//在一行中输出这n个整数的处理结果，相邻数字中间用一个空格分开，行末不得有多余空格。
//
//输入样例:
//4
//10 8 1 2
//输出样例:
//2 1 8 10

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int>m(n);
    for (int i = n - 1; i >= 0; i--)cin >> m[i];
    for (int j = 0; j < n; j++)
    {
        if (j != 0)cout << " ";
        cout << m[j];
    }

    return 0;
}
