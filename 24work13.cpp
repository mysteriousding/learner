/*(61)用虚函数计算各种图形的面积

//定义抽象基类Shape，由它派生出五个派生类：
//Circle（圆形）、Square（正方形）、Rectangle（ 长方形）、Trapezoid （梯形）和Triangle （三角形），
//用虚函数分别计算各种图形的面积，输出它们的面积和。要求用基类指针数组，每一个数组元素指向一个派生类的对象。
//PI=3.14159f，单精度浮点数计算。
//
//输入格式:
//输入在一行中，给出9个大于0的数，用空格分隔，分别代表圆的半径，正方形的边长，矩形的宽和高，梯形的上底、下底和高，三角形的底和高。
//
//输出格式:
//输出所有图形的面积和，小数点后保留3位有效数字。
//
//输入样例:
//12.6 3.5 4.5 8.4 2.0 4.5 3.2 4.5 8.4
//输出样例:
//578.109

#include<iostream>
#include<iomanip>
using namespace std;
#define pi 3.14159f
class Shape
{
    public:
    Shape(float x):x(x){}
    virtual float mj();
    protected:
    float x;
};

class Circle:public Shape
{
    public:
    Circle(float x):Shape(x){}
    float mj()
    {
    return pi*x*x;
    }
};

class Square:public Shape
{
    public:
    Square(float x):Shape(x){}
    float mj()
    {
    return x*x;
    }
};

class Rectangle:public Shape
{
    public:
    Rectangle(float x,float y):Shape(x),y(y){}
    float mj()
    {
    return x*y;
    }
    protected:
    float y;
};

class Trapezoid:public Shape
{
    public:
    Trapezoid(float x,float y,float z):Shape(x),y(y),z(z){}
    float mj()
    {
    return (x+y)*z*0.5;
    }
    protected:
    float y;
    float z;
};

class Triangle:public Shape
{
    public:
    Triangle(float x,float y):Shape(x),y(y){}
    float mj()
    {
    return x*y*0.5;
    }
    protected:
    float y;
};

int main()
{
    float a,b,c,d,e,f,g,h,i;
    float sum=0;
    cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
    Shape*p;
    Circle A(a);
    Square B(b);
    Rectangle C(c,d);
    Trapezoid D(e,f,g);
    Triangle E(h,i);
    p=&A;
    sum+=p->mj();
    p=&B;
    sum+=p->mj();
    p=&C;
    sum+=p->mj();
    p=&D;
    sum+=p->mj();
    p=&E;
    sum+=p->mj();
    cout<<setiosflags(ios::fixed)<<setprecision(3)<<sum<<endl;

    return 0;
}
*/

/*(62)车辆计费

//现在要开发一个系统，管理对多种汽车的收费工作。 给出下面的一个基类框架
//class Vehicle
//{ protected:
//string NO;//编号
//public:
//virtual void display()=0;//输出应收费用
//}
//以Vehicle为基类，构建出Car、Truck和Bus三个类。
//Car的收费公式为： 载客数8+重量2
//Truck的收费公式为：重量5
//Bus的收费公式为： 载客数3
//生成上述类并编写主函数，要求主函数中有一个基类Vehicle指针数组，数组元素不超过10个。
//Vehicle *pv[10];
//主函数根据输入的信息，相应建立Car,Truck或Bus类对象，对于Car给出载客数和重量，Truck给出重量，Bus给出载客数。假设载客数和重量均为整数
//输入格式：每个测试用例占一行，每行给出汽车的基本信息，每一个为当前汽车的类型1为car，2为Truck，3为Bus。
//接下来为它的编号，接下来Car是载客数和重量，Truck给出重量，Bus给出载客数。最后一行为0，表示输入的结束。
//要求输出各车的编号和收费。
//
//提示：应用虚函数实现多态
//
//输入格式:
//每个测试用例占一行，每行给出汽车的基本信息，每一个为当前汽车的类型1为car，2为Truck，3为Bus。
//接下来为它的编号，接下来Car是载客数和重量，Truck给出重量，Bus给出载客数。
//最后一行为0，表示输入的结束。
//
//输出格式:
//输出各车的编号和收费。
//
//输入样例:
//在这里给出一组输入。例如：
//
//1 001 20 5
//2 002 20
//3 003 25
//0
//输出样例:
//在这里给出相应的输出。例如：
//
//001 170
//002 100
//003 75

#include<iostream>
#include<string>
using namespace std;
class Vehicle
{
    protected:
    string NO;//编号
    public:
    Vehicle(string NO):NO(NO){}
    virtual void display()=0;//输出应收费用
    virtual ~Vehicle(){}
};

class Car:public Vehicle
{
public:
Car(string NO,int num,int kg):Vehicle(NO),num(num),kg(kg){}
void display()
{
int sum=num*8+kg*2;
cout<<NO<<" "<<sum<<endl;
}
protected:
int num;
int kg;
};

class Truck:public Vehicle
{
public:
Truck(string NO,int kg):Vehicle(NO),kg(kg){}
void display()
{
int sum=kg*5;
cout<<NO<<" "<<sum<<endl;
}
protected:
int kg;
};

class Bus:public Vehicle
{
public:
Bus(string NO,int num):Vehicle(NO),num(num){}
void display()
{
int sum=num*3;
cout<<NO<<" "<<sum<<endl;
}
protected:
int num;
};

int main()
{
    int n,b,c,i=0;
    string a;
    Vehicle*pv[10];
    while(1)
    {
        cin>>n;
        if(!n)break;
        switch(n)
        {
            case 1:
                cin>>a>>b>>c;
                pv[i]=new Car(a,b,c);
                break;
            case 2:
                cin>>a>>c;
                pv[i]=new Truck(a,c);
                break;
            case 3:
                cin>>a>>b;
                pv[i]=new Bus(a,b);
        }
        pv[i]->display();
        delete pv[i];

        i++;
    }

    return 0;
}
*/

//计算正方体、圆柱体的表面积、体积
//
//从立方体、圆柱体抽象出一个公共基类Container，定义抽象类Container，模拟实现一个容器类层次结构，在主函数进行多态机制测试。各派生类要求实现基类的所有纯虚函数。
//
//抽象类class Container {
//    protected:
//        static double pi;
//    public:
//        virtual double area()=0;            //纯虚函数，计算对象的表面积
//        virtual double volume()=0;       //纯虚函数，计算对象的体积
//        static double sumofarea(Container *c[],int n) ;     //静态成员函数，计算所有对象的面积之和
//        static double sumofvolume(Container *c[],int n);  //静态成员函数，计算所有对象的体积之和
//};
//double Container::pi=3.1415926;
//
//Cube类、Cylinder类均继承抽象类Container。
//Cube类(属性：边长double类型)、Cylinder类(属性：底圆半径、高，double类型)。
//
//在主函数用new运算符生成若干容器类的堆对象，定义基类指针数组，其元素分别指向不同容器类对象，实现多态的异质数组，
//通过调用Container::sumofarea、Container::sumofvolume计算所有容器对象的表面积之和、体积之和 。
//
//输入格式:
//第一行n表示对象个数，对象类型用cube、cylinder区分，cube表示立方体对象，后面输入边长，cylinder表示圆柱体对象，后面是底圆半径、高。
//
//输出格式:
//分别输出所有容器对象的表面积之和、体积之和，结果保留小数点后2位。
//
//输入样例:
//在这里给出一组输入。例如：
//
//4
//cube
//15.7
//cylinder
//23.5 100
//cube
//46.8
//cylinder
//17.5 200
//输出样例:
//在这里给出相应的输出。例如：
//
//56771.13
//472290.12

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
class Container
{
protected:
    static double pi;
public:
    virtual double area() = 0;         //纯虚函数，计算对象的表面积
    virtual double volume() = 0;       //纯虚函数，计算对象的体积
    static double sumofarea(Container* c[], int n);   //静态成员函数，计算所有对象的面积之和
    static double sumofvolume(Container* c[], int n);  //静态成员函数，计算所有对象的体积之和
    virtual ~Container() {}
};
double Container::pi = 3.1415926;
double Container::sumofarea(Container* c[], int n)
{
    double N = 0;
    for (int i = 0; i < n; i++)
        N += c[i]->area();
    return N;
}
double Container::sumofvolume(Container* c[], int n)
{
    double M = 0;
    for (int i = 0; i < n; i++)
        M += c[i]->volume();
    return M;
}

class Cube :public Container
{
public:
    Cube(double x) :x(x) {}
    double area()
    {
        return x * x * 6;
    }
    double volume()
    {
        return x * x * x;
    }
private:
    double x;
};

class Cylinder :public Container
{
public:
    Cylinder(double x, double y) :x(x), y(y) {}
    double area()
    {
        return Container::pi * x * x * 2 + 2 * Container::pi * x * y;
    }
    double volume()
    {
        return Container::pi * x * x * y;
    }
private:
    double x;
    double y;
};

int main()
{
    Container* p[100];
    int n;
    string m;
    double a, b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        if (m == "cube")
        {
            cin >> a;
            p[i] = new Cube(a);
        }
        else
        {
            cin >> a >> b;
            p[i] = new Cylinder(a, b);
        }
    }
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << Container::sumofarea(p, n) << endl;
    cout << Container::sumofvolume(p, n) << endl;
    for (int i = 0; i < n; i++)
        delete p[i];

    return 0;
}
