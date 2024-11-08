/*(1)输出数组元素

//本题要求编写程序，对顺序读入的n个整数，顺次计算后项减前项之差，并按每行三个元素的格式输出结果。
//
//输入格式：
//输入的第一行给出正整数n（1<n≤10）。随后一行给出n个整数，其间以空格分隔。
//
//输出格式：
//顺次计算后项减前项之差，并按每行三个元素的格式输出结果。数字间空一格，行末不得有多余空格。
//
//输入样例：
//10
//5 1 7 14 6 36 4 28 50 100
//输出样例：
//-4 6 7
//-8 30 -32
//24 22 50

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, k = 0;
    cin >> n;
    vector<int>m(n);
    for (int i = 0; i < n; i++)cin >> m[i];
    for (int j = 0; j < n - 1; j++)
    {
        if (k != 0)cout << " ";
        cout << m[j + 1] - m[j];
        k++;
        if (k == 3)
        {
            k = 0;
            cout << endl;
        }

    }

    return 0;
*/

/*(2)求最大值及其下标

//本题要求编写程序，找出给定的n个数中的最大值及其对应的最小下标（下标从0开始）。
//
//输入格式:
//输入在第一行中给出一个正整数n（1<n≤10）。第二行输入n个整数，用空格分开。
//
//输出格式:
//在一行中输出最大值及最大值的最小下标，中间用一个空格分开。
//
//输入样例:
//6
//2 8 10 1 9 10
//输出样例:
//10 2

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, a, b;
    cin >> n;
    vector<int>m(n);
    for (int i = 0; i < n; i++)cin >> m[i];
    a = m[0]; b = 0;
    for (int j = 0; j < n; j++)
    {
        if (m[j] > a)
        {
            a = m[j];
            b = j;
        }
    }

    cout << a << " " << b << endl;

    return 0;
}
*/

/*(3)数组元素循环右移问题

//一个数组A中存有N（>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M（≥0）个位置，即将A中的数据由（A0 A1 … AN−1）变换为（AN−M … AN−1 A0 A1 … AN−M−1）（最后M个数循环移至最前面的M个位置）。
//如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？
//
//输入格式:
//每个输入包含一个测试用例，第1行输入N（1≤N≤100）和M（≥0）；第2行输入N个整数，之间用空格分隔。
//
//输出格式:
//在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。
//
//输入样例:
//6 2
//1 2 3 4 5 6
//输出样例:
//5 6 1 2 3 4

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, m, h;
    cin >> n >> m;
    vector<int>x(n);
    for (int i = 0; i < n; i++)cin >> x[i];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            h = x[0];
            for (int l = 0; l < n - 1; l++) x[l] = x[l + 1];
            x[n - 1] = h;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i != 0)cout << " ";
        cout << x[i];
        if (i == n - 1)cout << endl;
    }

    return 0;
}
*/

/*(4)数组循环左移

//本题要求实现一个对数组进行循环左移的简单函数：
//一个数组a中存有n（>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向左移m（≥0）个位置，即将a中的数据由（A0 A1 … AN−1）变换为（AN−M … AN−1 A0 A1 … AN−M−1）（最前面的m个数循环移至最后面的m个位置）。
//如果还需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？
//
//输入格式:
//输入第1行给出正整数n（≤100）和整数m（≥0）；第2行给出n个整数，其间以空格分隔。
//
//输出格式:
//在一行中输出循环左移m位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。
//
//输入样例：
//8 3
//1 2 3 4 5 6 7 8
//输出样例：
//4 5 6 7 8 1 2 3

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, m, h;
    cin >> n >> m;
    vector<int>x(n);
    for (int i = 0; i < n; i++)cin >> x[i];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            h = x[n - 1];
            for (int l = n - 1; l > 0; l--)x[l] = x[l - 1];
            x[0] = h;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i != 0)cout << " ";
        cout << x[i];
        if (i == n - 1)cout << endl;
    }

    return 0;
}
*/

//本题要求编写程序，先将输入的一系列整数中的最小值与第一个数交换，然后将最大值与最后一个数交换，最后输出交换后的序列。
//
//注意：题目保证最大和最小值都是唯一的。
//
//输入格式：
//输入在第一行中给出一个正整数N（≤10），第二行给出N个整数，数字间以空格分隔。
//
//输出格式：
//在一行中顺序输出交换后的序列，每个整数后跟一个空格。
//
//输入样例：
//5
//8 2 5 1 4
//输出样例：
//1 2 5 4 8 

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, h1, i1, h2, i2;
    cin >> n;
    vector<int>m(n);
    for (int i = 0; i < n; i++)cin >> m[i];

    h1 = m[0]; i1 = 0;
    for (int i = 0; i < n; i++) { if (m[i] < h1) { h1 = m[i]; i1 = i; } }
    m[i1] = m[0]; m[0] = h1;

    h2 = m[0]; i2 = 0;
    for (int j = 0; j < n; j++) { if (m[j] > h2) { h2 = m[j]; i2 = j; } }
    m[i2] = m[n - 1]; m[n - 1] = h2;

    for (int j = 0; j < n; j++)
    {
        cout << m[j] << " ";
    }

    return 0;
}
