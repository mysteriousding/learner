/*(1)A+B

//本题目要求读入2个整数A和B，然后输出它们的和。
//
//输入格式:
//2个不超过长长整型的整数A和B。
//
//输出格式:
//先输出“A+B=”，在输出A+B的值。
//
//输入样例:
//10 1
//输出样例:
//10+1=11

#include<iostream>
using namespace std;
int main()
{
    long long A, B;
    cin >> A >> B;
    cout << A << "+" << B << "=" << A + B << endl;

    return 0;
}
*/

/*(2)反向输出一个三位数

//将一个三位数反向输出。
//
//输入格式:
//一个三位数n。
//
//输出格式:
//反向输出n（去前导零）。
//
//输入样例:
//123
//输出样例:
//321

#include<iostream>
using namespace std;
int main()
{
    int n, a, i = 0;
    cin >> n;
    while (true)
    {
        a = n % 10;
        n /= 10;
        if (a == 0 && i == 0) {}
        else
        {
            i++;
            cout << a;
        }
        if (n == 0) { break; }
    }
    return 0;
}
*/

/*(3)计算长方形的周长和面积

//输入长方形的长和宽，要求计算长方形的周长和面积。
//
//输入格式:
//在一行中给出两个整数(<=10^5)。
//
//输出格式:
//第一行长方形的周长。
//第二行长方形的面积。
//
//输入样例:
//6 8
//输出样例:
//周长 = 28
//面积 = 48

#include<iostream>
using namespace std;
int main()
{
    long a, b;
    cin >> a >> b;
    cout << "周长 = " << (a + b) * 2 << endl;
    cout << "面积 = " << a * b << endl;

    return 0;
}
*/

/*(4)数学公式

//chuck 酷爱数学，最近新学了一个公式 (1/x)+(1/y)=1 。目前已知 x ，现在需要求解 y 。
//
//输入格式:
//第一行一个正整数 x（2<=x<=10^5) ，含义如上。
//
//输出格式:
//一个小数，表示 y 的具体值（保留小数点两位）。
//
//输入样例:
//3
//输出样例:
//1.50
//输入样例:
//2
//输出样例:
//2.00

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double x, y;
    cin >> x;
    y = 1 / (1 - (1 / x));
    cout << setiosflags(ios::fixed) << setprecision(2) << y << endl;

    return 0;
}
*/

/*(5)去除末尾数字后相加

//输入两个整数，将两个整数的末尾数字去除后，相加求和。
//
//注意，如果整数是个位数，则认为去除末尾数字后为0。
//
//输入格式:
//两个整数a和b。
//
//输出格式:
//输出一个整数，表示相加后的结果。
//
//输入样例:
//123 12
//输出样例:
//13

#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    a/=10;
    b/=10;
    cout<<a+b<<endl;

    return 0;
}
*/

/*(6)华氏温度转摄氏温度

//编写一个程序，提示用户输入一个浮点数表示华氏温度值，然后计算并输出对应的摄氏温度值。
//
//输入格式:
//一个浮点数，表示华氏温度值。
//
//输出格式:
//一个浮点数，表示对应的摄氏温度值，保留两位小数。
//
//输入样例:
//32
//输出样例:
//摄氏温度为：0.00

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    float c;
    cin >> c;
    cout << "摄氏温度为：" << setiosflags(ios::fixed) << setprecision(2) << (c - 32) / 1.80 << endl;

    return 0;
}
*/

/*(7)英文字母 - 《C++编程基础及应用》- 习题2-2

//在计算机内部，英文字母依ASCII码分别由连续的整数来表示。比如，大写的英文字母A的ASCII码值为65，B的码值为66，然后依次递增，Z的码值为90。
//
//请编程计算：
//
//从键盘读取大写字母Q（代号，其值由具体输入确定），请问Q所代表的大写字母是字母表中的第几个字母（从1开始计数，即A为第1个字母）？
//从键盘读取整数N，求字母表中的第N个字母（从1开始计数）是什么？
//
//输入格式:
//Q
//N
//
//说明：是一个字符的大写字母；N的取值范围为1~26。
//
//输出格式:
//请参考输出样例。
//
//输入样例:
//B
//3
//输出样例:
//2
//C

#include<iostream>
using namespace std;
int main()
{
    char a;
    int b;
    cin >> a >> b;
    cout << (int)(a - 64) << endl << (char)(b + 64) << endl;

    return 0;
}
*/

//橡皮泥 - 《C++编程基础及应用》 - 习题3 - 9
//
//将两块球形橡皮泥揉在一起，捏成一个正方体。请编程，完成下述功能：
//
//从键盘读入第1个球形橡皮泥的直径，该直径为浮点数；
//从键盘读入第2个球形橡皮泥的直径，该直径仍为浮点数；
//求正方体的边长，并保留两位小数输出;
//
//输入格式:
//第一个球的直径
//第二个球的直径
//
//输出格式 :
//请参考输出样例。
//
//输入样例 :
//3.2
//5.553
//输出样例 :
//Side length of cube : 4.74
//
//提示：圆球的体积 V = 4 / 3 * π r³

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
#define pi 3.14
int main()
{
    double a, b, c, v1, v2;
    cin >> a >> b;
    v1 = 4 / 3.0 * pi * pow(a / 2, 3);
    v2 = 4 / 3.0 * pi * pow(b / 2, 3);
    c = cbrt(v1 + v2);
    cout << "Side length of cube:" << setiosflags(ios::fixed) << setprecision(2) << c << endl;

    return 0;
}
