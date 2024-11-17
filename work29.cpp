﻿/*(16)散步

//小土豆在公园里按一定规律散步。
//为了确定自己的位置，小土豆在地图上画出了坐标系，并规定自己初始位置是（x,y)=(0,0）点，
//向东 x坐标增加，向北 y坐标增加，1米为1单位长度。
//一开始小土豆面朝东方，第 i 个阶段会向前走 i 米，并向左转。
//请帮助小土豆计算经过 n 个阶段小土豆会在什么位置。
//
//【输入输出样例】
//样例输入1    样例输出1
//1              1 0
//样例输入2    样例输出2
//5              3 -2
//样例输入3    样例输出3
//100           -50 -50
//【样例解释】
//样例1：向东走 1 米到达（1,0)。
//
//样例2：向东走 1 米到达（1,0);
//       向北走 2 米到达（1,2)。
//       向西走 3 米到达（-2,2)。
//       向南走 4 米到达（-2,-2)。
//       向东走 5米到达（3,-2)。
//【数据范围约定】
//对于10％的数据，n≤5;
//对于20％的数据，n≤20;
//对于40％的数据，n ≤50;
//对于60％的数据，n≤103;
//对于90％的数据，n≤106;
//对于所有数据，1≤n≤2*10^9。
//
//输入格式:
//一行一个整数 n，代表小土豆行动的阶段数。
//
//输出格式:
//一行两个整数，代表小土豆最终位置的 x 坐标和 y坐标。
//
//输入样例:
//100
//输出样例:
//-50 -50

#include<iostream>
using namespace std;
//版一
//int main()
//{
//    int a=0,b=0,n;
//    cin>>n;
//    for(int i=0;i<n;i++)
//    {
//        switch(i%4)
//        {
//            case 0:a+=i+1;break;
//            case 1:b+=i+1;break;
//            case 2:a-=i+1;break;
//            case 3:b-=i+1;break;
//        }
//    }
//    cout<<a<<" "<<b<<endl;
//
//    return 0;
//}



// 3 -2    5
// 3  4    6
//-4  4    7
//-4 -4    8
int main()
{
    long long a, b, n;
    cin >> n;
    a = n % 4;
    b = n / 2;
    switch (a)
    {
    case 1:cout << b + 1 << " " << b * -1 << endl; break;
    case 2:cout << b << " " << b + 1 << endl; break;
    case 3:cout << (b + 1) * -1 << " " << b + 1 << endl; break;
    case 0:cout << b * -1 << " " << b * -1 << endl; break;
    }

    return 0;
}
*/

/*（17）一元二次方程的根

//利用公式x1 = (-b + sqrt(b*b-4*a*c))/(2*a), x2 = (-b - sqrt(b*b-4*a*c))/(2*a)求一元二次方程ax2+ bx + c =0的根，其中a不等于0。
//
//输入格式:
//输入一行，包含三个浮点数a, b, c（它们之间以一个空格分开），分别表示方程ax2 + bx + c =0的系数。
//
//输出格式:
//输出一行，表示方程的解。
//若b2 = 4 * a * c,则两个实根相等，则输出形式为：x1=x2=...。
//若b2 > 4 * a * c,则两个实根不等，则输出形式为：x1=...;x2 = ...，其中x1>x2。
//若b2 < 4 * a * c，则有两个虚根，则输出：x1=实部+虚部i; x2=实部-虚部i，即x1的虚部系数大于等于x2的虚部系数，实部为0时不可省略。
//实部 = -b / (2*a), 虚部 = sqrt(4*a*c-b*b) / (2*a)
//
//所有实数部分要求精确到小数点后5位，数字、符号之间没有空格。
//
//输入样例1:
//1 0 1
//输出样例1:
//x1=0.00000+1.00000i;x2=0.00000-1.00000i
//输入样例2:
//1.0 2.0 8.0
//输出样2:
//x1=-1.00000+2.64575i;x2=-1.00000-2.64575i

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    double a,b,c,n;
    cin>>a>>b>>c;
    b=0-b;
    n=b*b-4*a*c;
    cout<<setiosflags(ios::fixed)<<setprecision(5);
    if(n==0)cout<<"x1=x2="<<b/(2*a)<<endl;
    else if(n>0)cout<<"x1="<<(b+sqrt(n))/(2*a)<<";x2="<<(b-sqrt(n))/(2*a)<<endl;
    else cout<<"x1="<<b/(2*a)<<"+"<<sqrt(-1*n)/(2*a)<<"i;x2="<<b/(2*a)<<"-"<<sqrt(-1*n)/(2*a)<<"i"<<endl;

    return 0;
}
*/

/*(18)3的倍数(multiple)

//chuck 有一个正整数 n ，现在他需要把这个正整数拆分为两个正整数 x,y ，使得满足以下条件:
//x+y=n
//(x*y)%3=0
//请找出有多少种不同的( x,y )满足以上条件。
//(1,2) 和 (2,1) 是不同的。
//
//输入格式:
//第一行一个正整数 n(1<=n<=10^17) 。
//
//输出格式:
//一个整数，表示不同的个数。
//
//输入样例:
//6
//输出样例:
//1
//输入样例:
//10
//输出样例:
//6
//数据范围
//对于20%的数据，n<=10^3
//
//对于40%的数据，n<=10^7
//
//对于100%的数据，n<=10^17

#include<iostream>
using namespace std;
//版一
//int main()
//{
//    long long n,m=0,i=1,j;
//    cin>>n;
//    for(j=n-1;i<j;i++,j--)if(i%3==0||j%3==0)m+=2;
//    if(n%6==0)m++;
//    cout<<m<<endl;
//
//    return 0;
//}


int main()
{
    long long n;
    cin >> n;
    switch (n % 3)
    {
    case 0:cout << (n - 1) / 3 << endl; break;
    case 1:
    case 2:cout << n / 3 * 2 << endl; break;
    }

    return 0;
}
*/

/*(18)题正确数据
1 0
2 0
3 0
4 2
5 2
6 1
7 4
8 4
9 2
10 6
11 6
12 3
13 8
14 8
15 4
16 10
17 10
18 5
19 12
20 12
21 6
22 14
23 14
24 7
25 16
26 16
27 8
28 18
29 18
30 9
31 20
32 20
33 10
34 22
35 22
36 11
37 24
38 24
39 12
40 26
41 26
42 13
43 28
44 28
45 14
46 30
47 30
48 15
49 32
50 32
51 16
52 34
53 34
54 17
55 36
56 36
57 18
58 38
59 38
60 19
61 40
62 40
63 20
64 42
65 42
66 21
67 44
68 44
69 22
70 46
71 46
72 23
73 48
74 48
75 24
76 50
77 50
78 25
79 52
80 52
81 26
82 54
83 54
84 27
85 56
86 56
87 28
88 58
89 58
90 29
91 60
92 60
93 30
94 62
95 62
96 31
97 64
98 64
99 32
100 66
*/

//军事基地燃料费计算
//
//为提升军事基地的能源使用效率，军方实施了按燃料消耗量阶梯式计费的策略，以鼓励官兵合理使用燃料。军营应交燃料费 y（元）与月燃料消耗量 x（吨）相关：当 燃料不超过 10 吨时，y=500x；超过后，y=5000+800(x-10)。请编写程序实现燃料费的计算。
//
//输入格式:
//输入在一行中给出非负实数x。
//
//输出格式:
//在一行输出应交的燃料费，精确到小数点后2位。
//
//输入样例:
//5.1
//输出样例:
//2550.00

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    float n, m;
    cin >> n;
    m = (n > 10) ? 5000 + 800 * (n - 10) : 500 * n;
    cout << setiosflags(ios::fixed) << setprecision(2) << m << endl;

    return 0;
}