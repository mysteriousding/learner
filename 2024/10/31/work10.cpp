/*(26)两整数的加法

//本题目要求读入2个整数A和B，然后输出它们的和。
//
//输入格式:
//在一行中输入2个绝对值不超过1000的整数A和B。
//
//输出格式:
//在一行中输出A+B的值。
//
//输入样例:
//100   64
//输出样例:
//164

#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;

    cout<<n+m;

    return 0;
}
*/

/*(27)求多少对相反数

//有N个非零且各不相同的整数。请你编一个程序求出它们中有多少对相反数（a和-a为一对相反数）。
//
//输入格式:
//第一行包含一个正整数 N（1≤N≤500）。第二行为N个用单个空格隔开的非零整数，每个数的绝对值不超过1000，保证这些整数各不相同。
//
//输出格式:
//只输出一个整数，即这N个数中包含多少对相反数。
//
//输入样例:
//5
//1 2 3 -1 -2
//输出样例:
//2

#include<iostream>
using namespace std;
int main()
{
    int n, k = 0;
    int m[500];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
    }
    for (int j = 0; j < n; j++)
    {
        for (int l = n; l > 0; l--)
        {
            if (m[j] == -m[l])k++;
            if (j > l)break;
        }
    }

    cout << k;

    return 0;
}
*/

/*(28)求n个整数的最小值

//用一个函数实现求n个整数的最小值，函数原型如下：
//int Min(int a[],int n)
//
//输入格式:
//在一行中输入n，例如10
//在另一行中依次输入a[n]，以空格间隔，例如
//10 12 9 8 7 23 48 59 0 1
//
//输出格式:
//输出最小值，例如 0
//
//输入样例:
//在这里给出一组输入。例如：
//
//3
//12 23 9
//输出样例:
//在这里给出相应的输出。例如：
//
//9

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int min(int a[], int n);
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++) { cin >> a[i]; }
    int m = min(a.data(), n);

    cout << m;

    return 0;
}

int min(int x[], int y)
{
    int h;
    for (int i = 0; i < y - 1; i++)
    {
        if (x[i] < x[i + 1]) { h = x[i]; x[i] = x[i + 1]; x[i + 1] = h; }
    }
    return(x[y - 1]);
}
*/

/*(29)输出斐波那契数列第 n 项

//斐波那契数列第一项和第二项都是 1,此后各项满足：Fn=Fn-1+Fn-2。编写程序，输入整数 n，输出斐波那契数列第 n 项。
//
//输入格式:
//在一行中给出不超过100的整数n.
//
//输出格式:
//在一行中输出斐波那契数列第 n 项。
//
//输入样例:
//3
//输出样例:
//2
//输入样例:
//5
//输出样例:
//5

#include<iostream>
using namespace std;
int main()
{
    int n, m = 2;
    int a = 1, b = 1;
    cin >> n;
    if (n == 1 || n == 2) { cout << 1; }
       else
       {
           for (;;)
           {
               a = a + b;
               m++;
               if (m == n) { cout << a; break; }
               b = b + a;
               m++;
               if (m == n) { cout << b; break; }
           }
       }

    return 0;
*/

//计算三角形面积
//
//从键盘输入三个数，用来表示三角形的三条边长。如果能构成三角形就输出三角形的面积，否则就输出No。
//
//输入格式:
//请在这里写输入三角形的三条边长，例如：
//3.1   4.2   5.3
//
//输出格式:
//请在这里输出三角形的面积，例如：
//
//6.50661
//
//输入样例:
//3.0 4.0 5.0
//输出样例:
//6

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    float a, b, c, p;
    cin >> a >> b >> c;
    if (a + b > c && b + c > a && a + c > b)
    {
        p = (a + b + c) / 2;
        p = pow(p * (p - a) * (p - b) * (p - c), 1.0 / 2);
        cout << p << endl;
    }
    else cout << "No";

    return 0;
}
