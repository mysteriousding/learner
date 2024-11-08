/*(6)和与平均 - 《C++编程基础及应用》- 习题3-4

//编程从键盘读入3个整数，输出它们的和与平均值。其中，平均值保留2位小数。
//
//输入格式:
//整数1
//整数2
//整数3
//
//输出格式:
//和,平均值
//
//输入样例:
//1
//2
//3
//输出样例:
//6,2.00

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << a + b + c << ",";
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << (a + b + c) / 3.0 << endl;

    return 0;
}
*/

/*(7)菲姐游泳 - 《C++编程基础及应用》- 习题3-5

//游泳奥运冠军菲姐刻苦训练，从早上a时b分开始下水训练，直到当天的c时d分结束。请编程计算：菲姐当天一共训练多少小时多少分钟？
//
//输入格式:
//一行之内输入以空格分隔的4个非负整数，分别对应a,b,c,d。其中，0 ≤a<c ≤24；b和d均不大于60。
//
//输出格式:
//h:m。其中，整数h表示小时数，整数m表示分钟数,m应小于60。
//
//输入样例:
//6 30 23 20
//输出样例:
//16:50

#include<iostream>
using namespace std;
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b <= d)
    {
        a = c - a;
        b = d - b;
    }
    else
    {
        a = c - a - 1;
        b = d + 60 - b;
    }

    cout << a << ":" << b << endl;

    return 0;
}
*/

/*(8)对角线 - 《C++编程基础及应用》- 习题3-6

//编写程序，实现下述功能：
//
//从键盘读入矩形的长，以厘米为单位，应为小数；
//从键盘读入矩形的宽，以厘米为单位，应为小数；
//使用勾股定理计算对角线的长度并输出，保留1位小数。
//
//输入格式:
//长
//宽
//
//输出格式:
//参见输出样例
//
//输入样例:
//5.1
//4.3
//输出样例:
//The diagonal legnth is: 6.7 cm.

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    float a, b, c;
    cin >> a >> b;
    c = pow(pow(a, 2) + pow(b, 2), 1.0 / 2);

    cout << setiosflags(ios::fixed) << setprecision(1);
    cout << "The diagonal legnth is: " << c << " cm." << endl;

    return 0;
}
*/

/*(9)L1-2的n次幂

//给定一个正整数 n，按照格式输出 2 的 n 次幂，例如 n=5,则输出 2 ^ 5 = 32。
//
//输入格式：
//一行一个整数 n(1≤n≤30)。
//
//输出格式：
//按照格式输出 2 的 n 次幂。
//
//输入样例：
//5
//输出样例：
//2 ^ 5 = 32

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;

    cout << "2 ^ " << n << " = " << (long long)pow(2, n) << endl;

    return 0;
}
*/

//统计0和1的个数
//
//现在请你输入一个只含0、1和 * 的字符串，其中 * 是结束标志，统计其中0和1的个数。例如：0100100 *
//输入格式:
//输入只含0和1的字符串，结尾必须是 *
//
//输出格式 :
//输出0和1的个数
//
//输入样例 :
//00110101 *
//输出样例 :
//card(0) = 4
//card(1) = 4

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string n;
    char m;
    int x = 0, y = 0;
    cin >> n;
    for (int i = 0;; i ++)
    {
        m = n[i];
        if (m =='0') { x += 1; }
           else if (m == '1') { y += 1; }
              else { break; }
    }

    cout << "card(0)=" << x << endl;
    cout << "card(1)=" << y << endl;

    return 0;
}
