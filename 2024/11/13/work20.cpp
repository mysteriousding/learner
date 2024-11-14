/*(11)计算长方形的周长和面积

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
    long long n,m;
    cin>>n>>m;

    cout<<"周长 = "<<(n+m)*2<<endl<<"面积 = "<<n*m;

    return 0;
}
*/

/*(12)体重

//小 A 一觉醒来发现时空发生了穿越，来到了秦始皇一统天下后的时代。
//
//小 A 想进城逛逛，但是守城人要求必须报上自己的身高体重。 但是当时的秤是十六两一斤，小A只知道自己用十两一斤的秤称重时的斤两。
//
//请你帮他算算应该如何上报数据。
//
//输入格式:
//输入十两一斤的重量数，输入有两行。
//
//第一行是斤数。 第二行是两数。
//
//输出格式:
//输出对应十六两一斤秤的重量数，输出有两行。
//
//第一行是斤数。
//
//第二行是两数。
//
//输入样例:
//2
//1
//输出样例:
//1
//5
//输入样例:
//10
//9
//输出样例:
//6
//13
//输入样例:
//100
//8
//输出样例:
//63
//0
//说明
//样例 1 说明
//在十两一斤的称重下，有 2 斤 1 两，共 21 两。
//
//因此换算为十六两一斤的称重下，有 1 斤 5 两。
//
//数据范围
//对于 100% 的数据，满足读入的斤数，在 [0,1000] 的范围，读入的两数，在 [0,9] 的范围。

#include<iostream>
using namespace std;
int main()
{
    int n,m,ai;
    cin>>n>>m;
    ai=n*10+m;
    n=ai/16;
    m=ai%16;
    cout<<n<<endl<<m;

    return 0;
}
*/

/*(13)数学公式

//chuck 酷爱数学，最近新学了一个公式 1/x + 1/y =1 。目前已知 x ，现在需要求解 y 。
//
//输入格式:
//第一行一个正整数 x（2<=x<=10^5） ，含义如上。
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
    long long x;
    double y;
    cin>>x;
    y=x*1.0/(x-1);

    cout<<setiosflags(ios::fixed)<<setprecision(2);
    cout<<y<<endl;

    return 0;
}
*/

/*(14)实验2-2两个数的和差积商

//输入两个数num1和num2,计算并输出它们的和、差、积、商与余数。
//
//输入格式:
//a b
//
//输出格式:
//每次输出后换行
//a与%d和为
//
//输入样例:
//在这里给出一组输入。例如：
//
//11 22
//输出样例:
//在这里给出相应的输出。例如：
//
//11与22和为33
//11与22差为-11
//11与22积为242.000000
//11与22商为0
//11与22余为11

#include<iostream>
#include<string>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    string x[5] = { "和","差","积","商","余" };
    long long y[5] = { a + b,a - b,a * b,a / b,a % b };
    for (int i = 0; i < 5; i++)
    {
        cout << a << "与" << b << x[i] << "为";
        cout << y[i];
        if (i == 2)cout << ".000000";
        if (i != 4)cout << endl;
    }

    return 0;
}
*/

//大写字母转换为小写字母
//
//从键盘输入一个小写英文字母，将其转换为大写英文字母，将转换后的大写英文字母及其十进制的ASCII码值显示到屏幕上。
//
//输入格式:
//从键盘输入一个小写的英文字母，以回车结束。
//
//输出格式:
//转换后的大写字母和ASCII码在同一行输出，中间以逗号分隔。参看下面输出样例。
//
//输入样例:
//在这里给出一组输入。例如：
//
//b
//输出样例:
//在这里给出相应的输出。例如：
//
//B,66

#include<iostream>
using namespace std;
int main()
{
    char n;
    cin >> n;
    cout << (char)(n - 32) << "," << n - 32 << endl;

    return 0;
}
