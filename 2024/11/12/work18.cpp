/*(1)FP18-计算速度和距离

//输入物体匀加速运动的初速度、加速度和移动时间t（整数），计算物体在t秒中移动的距离，t秒后的速度，和t秒中的平均速度。
//
//输入格式:
//输入在一行中给出初速度、加速度和移动时间t，分别用空格分开。
//
//输出格式:
//在一行中t秒中移动的距离，t秒后的速度，和t秒中的平均速度，小数点后面保留2位。
//
//输入样例:
//10.0 20.0 30
//输出样例:
//9300.00,610.00,15.25


*/

/*(2)圆的周长和面积

//请编写程序，输入圆的半径 r，计算并输出三角形的周长 p 和面积 a。
//
//输入格式
//r
//
//输出格式
//p  a
//
//输入样例
//2.8
//
//输出样例
//17.5929 24.6301
//
//要求：输出 4 位小数(末位四舍五入)。

#include<iostream>
#include<iomanip>
using namespace std;
#define pi 3.141592653589793
int main()
{
    double r,c,s;
    cin>>r;
    c=2*pi*r;//+5e-5;
    s=pi*r*r;//+5e-5;
    cout<<setiosflags(ios::fixed)<<setprecision(4);
    cout<<c<<" "<<s<<endl;

    return 0;
}
*/

/*(3)要求在屏幕上输出以下一行信息

//This is a C program.
//
//输入格式:
//无需输入
//
//输出格式:
//This is a C program.
//
//输入样例:
//在这里给出一组输入。例如：
//
//
//输出样例:
//在这里给出相应的输出。例如：
//
//This is a C program.

#include<iostream>
using namespace std;
int main()
{
    cout<<"This is a C program."<<endl;

    return 0;
}
*/

/*(4)求两个整数中的较大者。

例1.3求两个整数中的较大者。

//输入格式:
//输出格式:
//输入样例:
//在这里给出一组输入。例如：
//
//1,2
//输出样例:
//在这里给出相应的输出。例如：
//
//max=2

#include<iostream>
using namespace std;
int main()
{
    int a,b;
    char c;
    cin>>a>>c>>b;

    cout<<"max="<<((a>b)?a:b)<<endl;

    return 0;
}
*/

//梯形面积(误差)
//
//请编写程序，输入梯形的上底 t、下底 b 和高 h，计算并输出梯形的面积 a。
//
//输入格式
//t  b  h
//
//输出格式
//a
//
//输入样例
//4.493 5.507 5.765
//
//输出样例
//28.83
//
//要求：输出 2 位小数(末尾四舍五入)。

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double t, b, h, a;
    cin >> t >> b >> h;
    a = (t + b) * h * 0.5 + 1e-7;

    cout << setiosflags(ios::fixed) << setprecision(2) << a << endl;

    return 0;
}












/*教王
#include<iostream>
#include<string>
using namespace std;
int main()
{
    char ip[33];
    int i, sum = 0;
    cin >>ip;
    for(i = 0; i < 32; i++)
    {
        sum = sum*2 + ip[i] -'0';
        if ((i + 1) % 8 == 0)
        {
            cout << sum;
            if (i != 31)cout << ".";
            sum = 0;
        }
    }
    
    return 0;
}
*/
