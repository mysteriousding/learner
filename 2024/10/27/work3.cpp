/*(1)计算n的阶乘。

//编写程序计算n的阶乘, n 由用户输入,  0 < n <=20。例如：输入5，则输出 fact = 120
//
//输入格式:
//请在这里写输入格式。例如：输入： 5
//
//输出格式:
//请在这里描述输出格式。例如：输出 ：fact = 120 。
//
//输入样例:
//在这里给出一组输入。例如：
//
//5
//输出样例:
//在这里给出相应的输出。例如：
//
//fact = 120

#include<iostream>
using namespace std;
int main()
{
    int n;
    long long m = 1;
    cin >> n;
    for (n;; n--)
    {
        if (n == 0)break;
        m *= n;
    }

    cout << "fact = " << m << endl;

    return 0;
}
*/

/*(2)最大公约数和最小公倍数

//本题目要求读入2个正整数A和B，然后输出它们的最大公约数和最小公倍数。
//
//输入格式:
//输入在一行中给出2个不超过10000的正整数A和B。
//
//输出格式:
//对每一组输入，在一行中输出最大公约数和最小公倍数，用逗号分隔。
//
//输入样例:
//2 3
//输出样例:
//1,6

#include<iostream>
using namespace std;
int main()
{
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 1; i <= n || i <= m; i++)
    {
        if (n % i == 0 && m % i == 0)x = i;
    }
    y = n * m / x;

    cout << x << "," << y << endl;

    return 0;
}
*/

/*(3)图形总面积

//计算n个图形的总面积。
//
//输入格式:
//输入若干行圆形或长方形的图形数据，每行为一个图形，第一个字符表示图形的类别，c表示圆形，r表示长方形，n表示输入结束。圆形在同一行给出半径值，方形则给出长和宽。
//
//输出格式:
//输出所有图形的总面积，保留两位小数。
//
//输入样例:
//c 2.5
//c 3
//r 3 5
//n
//输出样例:
//62.88

#include<iostream>
#include<iomanip>
#define pi 3.14
using namespace std;
int main()
{
    char n;
    float m, k, x = 0, y = 0;
    while (1)
    {
        cin >> n;
        if (n == 'c')
        {
            cin >> m;
            x += pi * m * m;
        }
        else if (n == 'r')
        {
            cin >> m >> k;
            y += m * k;
        }
        if (n == 'n')break;
    }

    cout << setiosflags(ios::fixed) << setprecision(2) << x + y << endl;

    return 0;
}
*/

/*(4)求分数序列前N项和

//本题要求编写程序，计算序列 1 + 1/3 + 1/5 + 1/7 + ... 的前N项之和。
//
//输入格式:
//输入在一行中给出一个正整数N。
//
//输出格式:
//在一行中按照“sum = S”的格式输出部分和的值S，精确到小数点后六位，请注意等号的左右各有一个空格。题目保证计算结果不超过双精度范围。
//
//输入样例1:
//5
//输出样例1:
//sum = 1.787302
//输入样例2:
//1
//输出样例2:
//sum = 1.000000
//输入样例3:
//10
//输出样例3:
//sum = 2.133256

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n;
    double m=0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        m += 1.0 / (2 * i + 1);
    }

    cout << "sum = " << setiosflags(ios::fixed) << setprecision(6) << m << endl;

    return 0;
}
*/

//输出个等腰梯形吧
//分数 10
//作者 ZHANG JIU JIE
//单位 包头师范学院
//小磊正在研究使用编程输出图形，今天小磊在研究使用特定字符（*符号）输出相应尺寸的等腰梯形。
//由于梯形需要上底、下底的长度及位置，还有高度才能确定。所以现在小磊把这个问题简化了。
//等腰梯形上底的长度固定为3个字符，然后根据高度H，再来确定下底的字符数。
//
//输入格式:
//输入一个正整数H代表梯形的高， 3<= H <= 100
//
//输出格式:
//输出等腰梯形，注意，等腰字符梯形的上底固定为3个字符，往下每一行，增加两个字符。
//每一行最后一个字符后面直接回车换行，也就是等腰梯形的右侧不需要空格，详见样例。
//
//输入样例:
//在这里给出一组输入。例如：
//
//5
//输出样例:
//在这里给出相应的输出。例如：
//
//    ***
//   *****
//  *******
// *********
//***********

#include<iostream>
using namespace std;
int main()
{
    int h;
    cin >> h;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 0; j < h - i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k <= 2 * i; k++)
        {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}
