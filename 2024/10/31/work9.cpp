/*(21)输入3个字符串，按由小到大顺序输出(使用函数和指针实现)

//本题目要求读入3个字符串，然后按由小到大排序后输出三个字符串。具体输入、输出格式看“样例”
//
//输入格式:
//字符串1
//字符串2
//字符串3
//
//输出格式:
//排序后的：
//字符串1
//字符串2
//字符串3
//
//输入样例:
//在这里给出一组输入。例如：
//
//abeedg
//ageegtg
//abegrwww
//输出样例:
//在这里给出相应的输出。例如：
//
//abeedg
//abegrwww
//ageegtg

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string x, y, z;
    cin >> x >> y >> z;
    string n[3];
    char a, b, c;
    int A, B, C;
    A = B = C = 2;
    for (int i = 0;; i++)
    {
        a = x[i]; b = y[i];
        if (a == b) { continue; }
        ((int)a < (int)b) ? A-- : B--;
        break;
    }
    for (int i = 0;; i++)
    {
        b = y[i]; c = z[i];
        if (b == c) { continue; }
        ((int)b < (int)c) ? B-- : C--;
        break;
    }
    for (int i = 0;; i++)
    {
        a = x[i]; c = z[i];
        if (a == c) { continue; }
        ((int)a < (int)c) ? A-- : C--;
        break;
    }
    n[A] = x; n[B] = y; n[C] = z;
    for (int j = 0; j < 3; j++)
    {
        cout << n[j] << endl;
    }


    return 0;
}
*/

/*(22)使用结构体数组求10个学生三门课总平均成绩，及最高分学生信息

//学生结构体数组管理10名学生的信息，分别是学号、姓名、3门课的成绩(double型)，从键盘输入10名学生的全部信息，打印出总的平均成绩与最高分学生信息
//
//输入格式:
//依次输入10名学生的信息，包括学号char num[6]、姓名char name[8]、三门课分数 double score[3]
//
//输出格式:
//输出10名学生总的平均成绩，与3门课程总成绩最高的学生分数，所有成绩输出保留小数点后2位小数
//
//输入样例:
//在这里给出一组输入。例如：
//
//101 wang 93 89 87
//102 li 86 80 78
//103 zhao 76 40 98
//104 ma 77 70 84
//105 han 70 67 60
//106 zhang 99 97 95
//107 zhou 88 89 88
//108 chen 87 88 85
//109 yang 72 70 69
//110 liu 78 80 83
//输出样例:
//在这里给出相应的输出。例如：
//
//80.77
//106 zhang 99.00 97.00 95.00

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
    string name[10];
    int num[10];
    float x[10], y[10], z[10], n[10], n0[10];
    float h, m = 0;
    int k = 0;
    for (int i = 0; i < 10; i++) { cin >> num[i] >> name[i] >> x[i] >> y[i] >> z[i]; }
    for (int j = 0; j < 10; j++)
    {
        n[j] = x[j] + y[j] + z[j];
        n0[j] = n[j];
        m += n[j];
    }
    m /= 30.0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (n0[j] > n0[j + 1]) { h = n0[j]; n0[j] = n0[j + 1]; n0[j + 1] = h; }
        }
    }
    for (int i = 0; i < 10; i++) { if (n[i] == n0[9]) { k = i; break; } }

    cout << fixed << setprecision(2);
    cout << m << endl;
    cout << num[k] << " " << name[k] << " " << x[k] << " " << y[k] << " " << z[k] << endl;


    return 0;
}
*/

/*(23)加减乘除运算符

//编写程序实现+ - * / 运算符重载，主要功能如下： 1、实现两复数(c1与c2)的加减乘除运算 2、实现复数c1与整数num的加减乘除运算 3、实现整数num与复数c1的加减乘除运算
//
//输入格式:
//c1实部 c1虚部 c2实部 c2虚部 整数num 具体格式见样例。
//
//输出格式:
//c1+c2结果 c1-c2结果 c1c2结果 c1/c2结果 c1+num结果 c1-num结果 c1num结果 c1/num结果 num+c1结果 num-c1结果 num*c1结果 num/c1结果 具体格式见输出样例
//
//输入样例:
//在这里给出一组输入。例如：
//
//1.0 2.0
//3.0 4.0
//5
//输出样例:
//在这里给出相应的输出。例如：
//
//c1+c2=(4.00,6.00i)
//c1-c2=(-2.00,-2.00i)
//c1*c2=(-5.00,10.00i)
//c1/c2=(0.44,0.08i)
//c1+num=(6.00,2.00i)
//c1-num=(-4.00,2.00i)
//c1*num=(5.00,10.00i)
//c1/num=(0.20,0.40i)
//num+c1=(6.00,2.00i)
//num-c1=(4.00,-2.00i)
//num*c1=(5.00,10.00i)
//num/c1=(1.00,-2.00i)

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    float n[6];
    string m[3] = { "c1","c2","num" };
    int k1 = 0, k2 = 1, k3 = 0;
    float C0(float x, float y, float n, float m, int k);
    float C1(float x, float y, float n, float m, int k);
    for (int i = 0; i < 5; i++) { cin >> n[i]; }n[5] = 0;
    for (int j = 0; j < 3; j++)
    {
        cout << fixed << setprecision(2);
        cout << m[k1] << "+" << m[k2] << "=(" << n[2 * k1] + n[2 * k2] << "," << n[2 * k1 + 1] + n[2 * k2 + 1] << "i)" << endl;
        cout << m[k1] << "-" << m[k2] << "=(" << n[2 * k1] - n[2 * k2] << "," << n[2 * k1 + 1] - n[2 * k2 + 1] << "i)" << endl;
        cout << m[k1] << "*" << m[k2] << "=(" << C0(n[2 * k1], n[2 * k1 + 1], n[2 * k2], n[2 * k2 + 1], 0) << "," << C0(n[2 * k1], n[2 * k1 + 1], n[2 * k2], n[2 * k2 + 1], 1) << "i)" << endl;
        cout << m[k1] << "/" << m[k2] << "=(" << C1(n[2 * k1], n[2 * k1 + 1], n[2 * k2], n[2 * k2 + 1], 0) << "," << C1(n[2 * k1], n[2 * k1 + 1], n[2 * k2], n[2 * k2 + 1], 1) << "i)" << endl;
        if (k3 == 1) { break; }
        if (k2 == 2) { k1 = 2; k2 = -1; k3 = 1; }
        k2++;

    }

    return 0;
}

float C0(float x, float y, float n, float m, int k)
{
    float a, b;
    a = x * n - y * m;
    b = x * m + y * n;
    if (k == 0)return(a);
    else return(b);
}
float C1(float x, float y, float n, float m, int k)
{
    float a, b;
    a = (x * n + y * m) / (n * n + m * m);
    b = (y * n - x * m) / (n * n + m * m);
    if (k == 0)return(a);
    else return(b);
}
*/

/*(24)小H的最小正整数

给定一个含n个整数的数组A，请找到数组中从未出现过的最小正整数

输入格式:
第一行输入n(1≤n≤10 
6
 )，第二行输入空格分隔的n个整数A 
i
​
 (−10 
18
 ≤Ai≤10 
18
 )

输出格式:
输出一个整数：数组中从未出现过的最小正整数

输入样例:
4
-5 3 2 3
输出样例:
在这里给出相应的输出。例如：

1
*/

/*(24)待完成
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, p;
    long long k;
    cin >> n;
    vector<long long>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        if (k > 0)arr[i] = k;
    }
    for (int j = 1; j <= n; j++)
    {
        p = 0;
        for (int i = 0; i < n; i++)
        {
            if (j == arr[i]) { p = 1; break; }
        }
        if (p == 0) { cout << j << endl; break; }
    }


    return 0;
*/

//排序
//
//请编写程序对不超过50000个整数递增排序。
//备注：本题不允许使用STL sort()或qsort()等现成的排序库函数。
//
//输入格式:
//输入第一行一个正整数n，表示待排序的元素个数。第二行为n个整数，表示待排序的元素。n不超过50000。
//
//输出格式:
//输出为一行，表示排序结果，每个整数后一个空格。
//
//输入样例:
//5
//5 4 3 2 1
//
//输出样例:
//1 2 3 4 5 

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, h, n0;
    cin >> n;
    vector<int>m(n);
    n0 = n - 1;
    for (int i = 0; i < n; i++) { cin >> m[i]; }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n0; j++)
        {
            if (m[j] > m[j + 1]) { h = m[j]; m[j] = m[j + 1]; m[j + 1] = h; }
        }
        n0--;
    }
    for (int j = 0; j < n; j++)
    {
        cout << m[j] << " ";
        if (j == n - 1)cout << endl;
    }

    return 0;
}
