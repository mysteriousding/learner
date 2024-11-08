/*(11)游客检票 - C/C++ 变量及简单数据类型

//题目描述
//假设张家界景区的游客抵达检票口的速度是恒定的。某国庆长假日清晨景区开门时检票口已积聚了一定数量的游客，且随时间流逝，不断有新的游客抵达。如果打开8个检票口，m分钟刚好可以完成全部游客的检票放行；如果使用6个检票口，则需要n (n>m)分钟才能完成。请编程计算：如果使用10个检票口，需要多少时间才能将景区入口的待检票人数清零？
//
//【分析】
//
//这是小学奥数中著名的“牛吃草”问题。现假设每个检票口每分钟可以完成1份游客的检票放行任务。设景区开门时积聚的游客数量为x份，设每分钟有y份游客抵达检票口。然后列出方程组，根据方程组求解x,y。
//
//然后，设使用10个检票口时，需要z分钟清零，根据x,y列方程，求出z。
//
//输入格式:
//m
//n
//
//说明：m,n为整数且n>m，且该输入确保问题有解。
//
//输出格式:
//原有排队游客份数:A, 每分钟新到游客份数:B, 10口同开需C分钟清零待检票游客.
//
//说明：A, B, C均为保留1位小数的浮点数。
//
//输入样例:
//180
//300
//输出样例:
//Original number of visitors: 900.0
//New arriavlas per minute: 3.0
//Check time when 10 gates are opened: 128.6
//注意：从数学角度上看，900.0, 30.0均为份数，不是游客人数。

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int m, n;
    float x, y, z;
    cin >> m >> n;
    x = n * m * 2.0 / (n - m);
    y = (6.0 * n - 8.0 * m) / (n - m);
    z = x / (10.0 - y);

    cout << setiosflags(ios::fixed) << setprecision(1);
    cout << "Original number of visitors: " << x << endl;
    cout << "New arriavlas per minute: " << y << endl;
    cout << "Check time when 10 gates are opened: " << z;

    return 0;
}
*/

/*(12)海伦-秦九韶 - 《C++编程基础及应用》- 习题3-7

//编程序实现功能：输入三角形的三条边边长，求三角形面积，其中面积计算使用用户自定义函数实现。
//输出的面积保留两位小数。
//
//输入格式:
//边长1
//边长2
//边长3
//
//输出格式:
//当三条边可能构成合法的三角形时，输出应为：
//
//面积
//当三条边无法构成合法的三角形时，输出：
//
//Error Input.
//输入样例:
//3.1
//4
//5
//输出样例:
//6.20

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    float x, y, z, p, s;
    cin >> x >> y >> z;
    if (x + y > z && x + z > y && y + z > x)
    {
        p = (x + y + z) / 2.0;
        s = pow(p * (p - x) * (p - y) * (p - z), 1.0 / 2);
        cout << setiosflags(ios::fixed) << setprecision(2) << s << endl;
    }
    else { cout << "Error Input." << endl; }

    return 0;
}
*/

/*(13)最短跑道长度 - 《C++编程基础及应用》- 习题3-8

//假设某飞机的加速度是a，起飞的速度是v，下述公式可以计算出该飞机起飞所需的最短跑道长度: L = v²/(2a)。编写一个程序，提示用户输入起飞速度v(m/s)和加速度a(m/s²)，计算飞机起飞的最短跑道长度，输出时保留2位小数。计算过程宜封装成一个函数，该函数接受参数v和a，返回计算所得的L。
//
//输入样例:
//100.1
//5.0
//输出样例:
//The shortest length of run  way: 1002.00

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    float YD(float x, float y);
    float v, a, L;
    cin >> v >> a;
    L = YD(v, a);

    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << "The shortest length of run  way: " << L << endl;

    return 0;
}

float YD(float x, float y)
{
    float z;
    z = pow(x, 2) / (2.0 * y);
    return(z);
}
*/

/*(14)橡皮泥 -《C++编程基础及应用》- 习题3-9

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
//输出格式:
//请参考输出样例。
//
//输入样例:
//3.2
//5.553
//输出样例:
//Side length of cube: 4.74
//提示：圆球的体积 V = 4/3 * π r³

#include<iostream>
#include<iomanip>
#include<cmath>
#define pi 3.14
using namespace std;
int main()
{
    float v1, v2, l;
    cin >> v1 >> v2;
    v1 = 4.0 / 3 * pi * pow(v1 / 2.0, 3);
    v2 = 4.0 / 3 * pi * pow(v2 / 2.0, 3);
    l = pow(v1 + v2, 1.0 / 3);

    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << "Side length of cube: " << l << endl;

    return 0;
}
*/

//计算圆的面积
//
//从键盘输入圆的半径，计算圆的面积并输出。圆周率PI=3.1415926。
//
//输入格式:
//在这里写输入圆的半径，例如：
//3.6
//
//输出格式:
//在这里输出圆的面积，例如：
//40.715
//
//输入样例:
//1.5
//
//输出样例:
//7.06858

#include<iostream>
#include<cmath>
#define pi 3.1415926
using namespace std;
int main()
{
    float r;
    cin >> r;
    r = pi * pow(r, 2);

    cout << r << endl;

    return 0;
}
