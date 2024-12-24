/*(1)求两点之间距离

//定义一个Point类，有两个数据成员：x和y, 分别代表x坐标和y坐标，并有若干成员函数。
//定义一个函数Distance(), 用于求两点之间的距离。
//
//输入格式:
//输入有两行：
//第一行是第一个点的x坐标和y坐标；
//第二行是第二个点的x坐标和y坐标。
//
//输出格式:
//输出两个点之间的距离，保留两位小数。
//
//输入样例:
//0 9
//3 -4
//
//输出样例:
//13.34

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class point
{
    public:
    point(int x,int y):x(x),y(y){}
    float distance(point m)
    {
        return pow(pow(x-m.x,2)+pow(y-m.y,2),0.5);
    }
    private:
    int x;
    int y;
};
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    point n(a,b),m(c,d);
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<n.distance(m)<<endl;

    return 0;
}

*/

/*(2)复数类的操作

//1、声明一个复数类Complex（类私有数据成员为double型的real和image）
//
//2、定义构造函数，用于指定复数的实部与虚部。
//
//3、定义取反成员函数，调用时能返回该复数的相反数（实部、虚部分别是原数的相反数）。
//
//4、定义成员函数Print()，调用该函数时，以格式(real, image)输出当前对象。
//
//5、编写加法友元函数，以复数对象c1，c2为参数，求两个复数对象相加之和。
//
//6、主程序实现：
//
//（1）读入两个实数，用于初始化对象c1。
//
//（2）读入两个实数，用于初始化对象c2。
//
//（3）计算c1与c2相加结果，并输出。
//
//（4）计算c2的相反数与c1相加结果，并输出。
//
//输入格式:
//输入有两行：
//
//第一行是复数c1的实部与虚部，以空格分隔；
//
//第二行是复数c2的实部与虚部，以空格分隔。
//
//输出格式:
//输出共三行:
//
//第一行是c1与c2之和；
//
//第二行是c2的相反数与c1之和；
//
//第三行是c2 。
//
//输入样例:
//在这里给出一组输入。例如：
//
//2.5 3.7
//4.2 6.5
//输出样例:
//在这里给出相应的输出。例如：
//
//(6.7, 10.2)
//(-1.7, -2.8)
//(4.2, 6.5)

#include<iostream>
using namespace std;
class complex
{
    public:
    complex(){}
    complex(double x,double y):real(x),image(y){}
    void fan(){real=-real;image=-image;}
    void sc(){cout<<"("<<real<<", "<<image<<")"<<endl;}
    void add(complex n,complex m){real=n.real+m.real;image=n.image+m.image;}
    private:
    double real;
    double image;
};
int main()
{
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    complex c1(a,b),c2(c,d),c3;
    c3.add(c1,c2);
    c3.sc();
    c2.fan();
    c3.add(c1,c2);
    c3.sc();
    c2.fan();
    c2.sc();

    return 0;
}
*/

/*(3)立方体类

//定义立方体类Box，数据成员有长宽高且都是整数，构造函数初始化数据成员，成员函数计算体积，主函数中输入长宽高，输出立方体体积。
//
//输入格式:
//输入立方体的长宽高，中间用空格分隔。
//
//输出格式:
//输出体积并换行。
//
//输入样例:
//在这里给出一组输入。例如：
//
//1 2 3
//输出样例:
//在这里给出相应的输出。例如：
//
//6

#include<iostream>
using namespace std;
class T
{
    public:
    T(int x,int y,int z):x(x),y(y),z(z){}
    int suan(){return x*y*z;}
    private:
    int x;
    int y;
    int z;
};
int main()
{
    int x,y,z;
    cin>>x>>y>>z;
    T n(x,y,z);
    cout<<n.suan()<<endl;

    return 0;
}
*/

/*(4)定义一个时间类Time

//本题目要求定义一个类Time，实现相关的成员函数的定义：
//class Time
//{
//private:
//      int days;
//    int hours;
//    int minutes;
//public:
//    Time(int d,int h, int m );
//    Time Sum(const Time & t);
//    void Show() const;
//};
//在main（）函数中从键盘读入6个整数值分别为2个类Time对象赋值，然后输出2个Time对象的和。
//
//输入格式:
//输入，在一行中给出两组整数（每组3个，含义为：日、小时、分钟），共6个数值，数值间用空格分隔。
//
//输出格式:
//在一行中输出2个Time对象累加之后的值，格式为：xx  xx xx（其中xx 为整数值，3个整数含义依次为日 小时 分钟）
//
//输入样例:
//2 10 40 3 20 30
//输出样例:
//6 7 10

#include<iostream>
using namespace std;
class Time
{
private:
    int days;
    int hours;
    int minutes;
public:
    Time(int d,int h, int m );
    Time Sum(const Time & t);
    void Show() const;
};
Time::Time(int d,int h,int m):days(d),hours(h),minutes(m){}
Time Time::Sum(const Time& t)
{
     Time T=t;
    int m,n;
    m=minutes+T.minutes;
    T.minutes=m%60;
    n=m/60;
    m=hours+T.hours+n;
    T.hours=m%24;
    n=m/24;
    T.days=days+T.days+n;
    return T;
}
void Time::Show()const{cout<<days<<" "<<hours<<" "<<minutes<<endl;}
int main()
{
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    Time n(a,b,c),m(d,e,f);
    n=n.Sum(m);
    n.Show();

    return 0;
}
*/

//设计一个类CRectangle
//
//设计一个类CRectangle，要求如下所述：
//(1) 该类中的私有成员变量存放CRectangle的长和宽，并且设置它们的默认值为1.
//(2) 通过成员函数设置其长和宽，并确保长和宽都在（0，50）范围之内。
//(3) 求周长Perimeter
//
//输入格式:
//输入在一行中给出2个绝对值不超过50的浮点数A和B。
//
//输出格式:
//在一行中输出周长的值。
//
//输入样例:
//在这里给出一组输入。例如：
//
//25 15
//输出样例:
//在这里给出相应的输出。例如：
//
//80

#include<iostream>
using namespace std;
class crectangle
{
    public:
    crectangle(float x0,float y0)
    {
        x=y=1;
        if(x0>0&&x0<50)x=x0;
        if(y0>0&&y0<50)y=y0;
    }
    float Sum(){return (x+y)*2;}
    private:
    float x;
    float y;
};
int main()
{
    float a,b;
    cin>>a>>b;
    crectangle n(a,b);
    float sum=n.Sum();
    cout<<sum;

    return 0;
}