/*(56)LX705 点圆关系

//题目背景
//《C/C++简明双链教程》
//
//知识点：T741
//
//题目描述
//这是一个程序填充题，填充后提交完整代码。
//
//输入平面上的一个点的坐标，以及一个圆的圆心坐标和半径，输出该点到原点的距离，并判断该点在圆内，圆外还是在圆周上。
//
//下面已经给出了点类Point的部分定义，请将其函数定义补充完整，并添加对圆类Circle的完整定义。
//
//#include <iostream>
//#include <cmath>
//#include <iomanip>
//using namespace std;
//class Point{
//    private:
//        double x,y;
//    public:
//        Point();
//        Point(double x_,double y_);
//        double distance();
//        double distance(const Point &p);
//        double getX(){return x;}
//        double getY(){return y;}
//        void setX(double x_);
//        void setY(double y_);
//};
///* 请将代码填写在这里 *
//int main()
//{
//    double x1, y1, x2, y2, r;
//    cin >> x1 >> y1 >> x2 >> y2 >> r;
//    Point p(x1, y1);
//    Point ctr(x2, y2);
//    Circle c(ctr, r);
//    cout << setprecision(3) << p.distance() << " " << c.judge(p) << endl;
//}
//输入格式
//格式如下：
//点的x坐标 点的y坐标 圆心的x坐标 圆心的y坐标 圆的半径
//
//输出格式
//第一行输出点到原点的距离
//第二行输出点和圆的关系，在圆外时，将输出“outside"，在圆内时，输出"inside"，在圆周上时，输出“on"。
//
//样例 #1
//样例输入 #1
//2 3 1 1 3
//样例输出 #1
//3.61 inside
//提示
//本题目主要考察面向对象
//
//复制主程序代码，完成缺失部分后将完整的代码提交进行测评！除了填充部分，已给定的代码不要做任何修改。

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Point{
    private:
        double x,y;
    public:
        Point();
        Point(double x_,double y_);
        double distance();
        double distance(const Point &p);
        double getX(){return x;}
        double getY(){return y;}
        void setX(double x_);
        void setY(double y_);
};
Point::Point(){setX(0);setY(0);}
Point::Point(double x_,double y_){setX(x_);setY(y_);}
double Point::distance()
{
    double L;
    L=pow(x*x+y*y,1/2.0);
    return L;
}
double Point::distance(const Point& p)
{
    double R;
    R=pow(pow(x-p.x,2)+pow(y-p.y,2),1.0/2);
    return R;
}
void Point::setX(double x_){x=x_;}
void Point::setY(double y_){y=y_;}
class Circle
{
public:
    Circle(Point x,double y):O(x),R(y){}
    string judge(Point p)
    {
        double R0;
        string m;
        R0=O.distance(p);//pow(pow(p.getX()-O.getX(),2)+pow(p.getY()-O.getY(),2),1.0/2);
        if(abs(R-R0)<1e-5)m="on";
        else if(R0>R)m="outside";
        else m="inside";
        return m;
    }
private:
    Point O;
    double R;
};
int main()
{
   double x1,y1,x2,y2,r;
   cin>>x1>>y1>>x2>>y2>>r;
   Point p(x1,y1);
   Point ctr(x2,y2);
   Circle c(ctr,r);
   cout<<setprecision(3)<<p.distance()<<" "<<c.judge(p)<<endl;
}
*/

/*(57)LX706 Car类

//题目背景
//《C/C++简明双链教程》
//
//知识点：T741
//
//题目描述
//这是一个程序填充题，填充后提交完整代码。
//
//本题要求声明和实现一个Car类，包括实现其成员函数。
//
//类和函数接口定义：
//声明一个Car类;
//
//三个public成员函数:
//
//(1) **disp_welcomemsg()**，无返回类型;
//
//(2) **get_wheels()**，返回一个Car类的数据成员m_nWheels的值；
//
//(3) **set_wheels(int)**，用指定的形参初始化数据成员m_nWheels的值；
//
//一个私有数据成员m_nWheels，整数类型，代表汽车的车轮数量。
//其中，成员函数disp_welcomemsg()显示一条欢迎信息“Welcome to the car world!”。
//成员函数get_wheels()返回Car类的私有数据成员m_nWheels。
//
//成员函数set_wheels(int)用指定的形参初始化数据成员m_nWheels。
//
//裁判测试程序样例：
//#include <iostream>
//using namespace std;
//
///* 请在这里填写答案 *
//
//int main()
//{
//    int n;
//    cin >> n;
//    Car myfstcar, myseccar;    //定义类对象
//    myfstcar.disp_welcomemsg();//访问成员函数，显示欢迎信息
//    myfstcar.set_wheels(n);    //访问成员函数，设置车轮数量
//    myseccar.set_wheels(n + 4);  //访问成员函数，设置车轮数量
//    //访问成员函数，显示车轮数量
//    cout << "my first car wheels num = " << myfstcar.get_wheels() << endl;
//    cout << "my second car wheels num = " << myseccar.get_wheels() << endl;
//    return 0;
//}
//输入格式
//一个整数n，表示车轮的数量，2≤n≤10
//
//输出格式
//见样例
//
//样例 #1
//样例输入 #1
//4
//样例输出 #1
//Welcome to the car world!
//my first car wheels num = 4
//my second car wheels num = 8
//提示
//本题目主要考察面向对象
//
//复制主程序代码，完成缺失部分后将完整的代码提交进行测评！除了填充部分，已给定的代码不要做任何修改

#include <iostream>
using namespace std;

class Car
{
public:
    void disp_welcomemsg(){cout<<"Welcome to the car world!"<<endl;}
    int get_wheels(){return m_nWheels;}
    void set_wheels(int n){m_nWheels=n;}
private:
    int m_nWheels;
};

int main()
{
    int n;
    cin >> n;
    Car myfstcar, myseccar;    //定义类对象
    myfstcar.disp_welcomemsg();//访问成员函数，显示欢迎信息
    myfstcar.set_wheels(n);    //访问成员函数，设置车轮数量
    myseccar.set_wheels(n+4);  //访问成员函数，设置车轮数量
    //访问成员函数，显示车轮数量
    cout << "my first car wheels num = " << myfstcar.get_wheels() << endl;
    cout << "my second car wheels num = " << myseccar.get_wheels() << endl;
    return 0;
}
*/

/*(58)LX707 角度的加法

//题目背景
//《C/C++简明双链教程》
//
//知识点：T741
//
//题目描述
//请设计角度类 ANGLE，实现角度的输入、输出和加法运算。
//
//#include <iostream>
//#include <iomanip>
//using namespace std;
//
///* 将代码补充在这里 *
//
//int main()
//{
//    ANGLE a, b, c;
//    a.Input();
//    b.Input();
//    c = a.Add(b);
//    c.Output();
//    cout << endl;
//    return 0;
//}
//设计输入和输出函数，达到以下效果。
//ANGLE a;
//
//a.Input();  // 输入: 28 36 47
//
//a.Output(); // 输出: 28 36 47
//
//设计加法函数，达到以下效果。
//有 ANGLE a(16, 28, 57), b(32, 49, 15), c;
//
//则 c = a.Add(b); // c 变为 49 度 18 分 12 秒
//
//输入格式
//通过.Input()输入角度的度 分 秒
//
//输出格式
//通过.Output()输出角度的度 分 秒
//
//样例 #1
//样例输入 #1
//16 28 57
//32 49 15
//样例输出 #1
//49 18 12
//
//提示
//完成类和函数的定义即可，并将完整的代码提交测评

#include <iostream>
#include <iomanip>
using namespace std;

class ANGLE
{
public:
    void Input(){cin>>a>>b>>c;}
    ANGLE Add(ANGLE x)
    {
        ANGLE y;
        int n,m;
        y.c=(x.c+c)%60;
        n=(x.c+c)/60;
        y.b=(x.b+b+n)%60;
        m=(x.b+b+n)/60;
        y.a=x.a+a+m;
        return y;
    }
    void Output()
    {
        cout<<a<<" "<<b<<" "<<c;
    }
private:
    int a;
    int b;
    int c;
};

int main()
{
    ANGLE a, b, c;
    a.Input();
    b.Input();
    c = a.Add(b);
    c.Output();
    cout << endl;
    return 0;
}
*/

/*(59)LX708 派生类构造

//题目背景
//《C/C++简明双链教程》
//
//知识点：T751
//
//题目描述
//裁判测试程序样例中展示的是一段定义基类People、派生类Student以及测试两个类的相关C++代码，其中缺失了部分代码，请补充完整，以保证测试程序正常运行。
//
//函数接口定义：
//提示：
//观察类的定义和main方法中的测试代码，补全缺失的代码。
//
//裁判测试程序样例：
//注意：真正的测试程序中使用的数据可能与样例测试程序中不同，但仅按照样例中的格式调用相关函数。
//
//#include <iostream>
//using namespace std;
//class People{
//private:
//    string id;
//    string name;
//public:
//    People(string id, string name){
//        this->id = id;
//        this->name = name;
//    }
//    string getId(){
//        return this->id;
//    }
//    string getName(){
//        return name;
//    }
//};
//class Student : public People{
//private:
//    string sid;
//    int score;
//public:
//    Student(string id, string name, string sid, int score)
//        /** 补充您的代码 **
//
//    }
//    friend ostream& operator <<(ostream& o, Student& s);
//};
//ostream& operator <<(ostream& o, Student& s) {
//    o << "(Name:" << s.getName() << "; id:"
//        << s.getId() << "; sid:" << s.sid
//        << "; score:" << s.score << ")";
//    return o;
//}
//int main() {
//    string id, name, sid;
//    int score;
//    getline(cin, id);
//    getline(cin, name);
//    cin >> sid >> score;
//    Student zs(id, name, sid, score);
//    cout << zs << endl;
//    return 0;
//}
//输入格式
//4行，分别表示id, name, sid和score
//
//输出格式
//见样例输出
//
//样例 #1
//样例输入 #1
//370202X
//Zhang San
//1052102
//96
//样例输出 #1
//(Name:Zhang San; id:370202X; sid : 1052102; score:96)
//
//提示
//本题目主要考察面向对象
//
//复制主程序代码，完成缺失部分后将完整的代码提交进行测评！除了填充部分，已给定的代码不要做任何修改。


*/

//定义基类Point和派生类Circle，求圆的周长.
//
//定义基类Point（点）和派生类Circle（圆），求圆的周长。Point类有两个私有的数据成员float x,y;Circle类新增一个私有的数据成员半径float r和一个公有的求周长的函数getCircumference();主函数已经给出，请编写Point和Circle类。
//
//#include <iostream>
//#include<iomanip>
//using namespace std;
////请编写你的代码
//int main()
//{
//    float x,y,r;
//    cin>>x>>y>>r;
//    Circle c(x,y,r);
//    cout<<fixed<<setprecision(2)<<c.getCircumference()<<endl;
//    return 0;
//}
//输入格式:
//输入圆心和半径，x y r中间用空格分隔。
//
//输出格式:
//输出圆的周长，小数点后保留2位有效数字。
//
//输入样例:
//1 2 3
//输出样例:
//在这里给出相应的输出。例如：
//
//Point constructor called
//Circle constructor called
//18.84
//Circle destructor called
//Point destructor called


/**/