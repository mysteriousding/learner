/*(6)立方体类的实现

//立方体类Box的实现，完成计算体积、计算表面积、输出结果等功能。其中给定的主函数为：
//
//int  main( ){
//    float ab;
//    cin>>ab;
//    Box  obj;
//    obj.seta( ab );
//    obj.getvolume( );
//    obj.getarea( );
//    obj.disp( );
//    return 0;
//}
//输入格式:
//立方体的边长，可以是float类型的数据。
//
//输出格式:
//立方体的体积和表面积，中间用一个空格隔开，末尾换行。
//
//输入样例:
//3
//输出样例:
//27 54

#include<iostream>
using namespace std;
class Box
{
    public:
    void seta(int x0){x=x0;}
    void getvolume(){V=x*x*x;}
    void getarea(){S=x*x*6;}
    void disp(){cout<<V<<" "<<S<<endl;}
    private:
    float x;
    float V;
    float S;
};
int  main( ){
    float ab;
    cin>>ab;
    Box  obj;
    obj.seta( ab );
    obj.getvolume( );
    obj.getarea( );
    obj.disp( );
    return 0;
}
*/

/*(7)又一个 A*B problem

//输入两个分数的分子和分母，程序将计算并输出他们的乘积，结果以最简分数形式给出。
//提示：定义一个 Fraction 类，用于表示分数。该类包括两个私有成员变量：分子和分母。A和B都是该分数类的对象，求A*B。
//
//输入格式:
//输入有两行，第一行是用空格隔开的两个整数，代表一个分数的分子和分母，第二行也是用空格隔开的两个整数，代表另一个分数的分子和分母。
//
//输出格式:
// 分数1 * 分数2 = 结果，其中分数1、分数2和结果都是分数形式。
//
//输入样例1:
//1 2
//1 3
//输出样例1:
//1/2 * 1/3 = 1/6
//输入样例2:
//3 4
//1 6
//输出样例2:
//3/4 * 1/6 = 1/8
//输入样例3:
//2 0
//1 5
//输出样例3:
//分母不能为0
//输入样例4:
//1000000000 2000000000
//3000000000 4000000000
//输出样例4:
//1000000000/2000000000 * 3000000000/4000000000 = 3/8

#include<iostream>
using namespace std;
class fraction
{
    public:
    fraction(){}
    fraction(long long x,long long y):x(x),y(y){}
    fraction chen(fraction n)
    {
        long long i,j,a,b,c;
        a=i=x*n.x,b=j=y*n.y;
        while(j!=0)
        {
            c=j;
            j=i%j;
            i=c;
        }
        return fraction(a/i,b/i);
    }
    void sc(){cout<<x<<"/"<<y;}
    private:
    long long x;
    long long y;
};
int main()
{
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    if(b==0||d==0)cout<<"分母不能为0"<<endl;
    else
    {
    fraction n(a,b),m(c,d),h;
    h=n.chen(m);
    n.sc();
    cout<<" * ";
    m.sc();
    cout<<" = ";
    h.sc();
    cout<<endl;
    }

    return 0;
}
*/

/*(8)设计一个People类

//设计一个People 类，该类的数据成员有姓名、年龄、身高、体重和人数，其中人数为静态数据成员，成员函数有构造函数、显示和显示人数。
//其中构造函数由参数姓名、年龄、身高和体重来构造对象；显示函数用于显示人的姓名、年龄、身高和体重；显示人数函数为静态成员函数，用于显示总的人数。
//
//输入格式:
//按姓名、年龄、身高和体重依次输入每个人的信息
//已exit结束
//zhang 18 180 70
//li 20 160 50
//exit
//
//输出格式:
//输出总人数，例如
//2
//
//输入样例:
//在这里给出一组输入。例如：
//
//zhang 18 180 70
//li 20 160 50
//exit
//输出样例:
//在这里给出相应的输出。例如：
//
//2

#include<iostream>
#include<string>
using namespace std;
class people
{
    public:
    people(string w,int x,int y,int z):name(w),age(x),cm(y),kg(z){sum++;}
    void sc(){cout<<name<<" "<<age<<" "<<cm<<" "<<kg<<endl;}
    static void sumsc(){cout<<sum;}
    private:
    string name;
    int age;
    int cm;
    int kg;
    static int sum;
};
int people::sum=0;
int main()
{
    string w;
    int x,y,z;
    while(1)
    {
        cin>>w;
        if(w=="exit"){people::sumsc();break;}
        cin>>x>>y>>z;
        people ai(w,x,y,z);
    }

    return 0;
}
*/

/*(9)Car类

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
//复制主程序代码，完成缺失部分后将完整的代码提交进行测评！除了填充部分，已给定的代码不要做任何修改。

#include <iostream>
using namespace std;

class Car
{
    public:
    void disp_welcomemsg(){cout<<"Welcome to the car world!"<<endl;}
    void set_wheels(int n){m_nWheels=n;}
    int get_wheels(){return m_nWheels;}
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

//类的定义和使用
//
//定义一个日期类Date，内有数据成员year、month和day，分别代表年、月、日，并若干有成员函数：构造函数用于初始化数据成员，isLeap函数用于闰年的判断。
//编写主函数：创建日期对象，判断该年是否是闰年。
//
//输入格式:
//每组测试数据仅包含一个测试用例，每个测试用例占一行包括三个数，分别表示年、月、日。
//
//输出格式:
//如果是闰年则输出yes，不是则输出no。
//
//输入样例:
//2006 3 5
//输出样例:
//no

#include<iostream>
using namespace std;
class date
{
    public:
    date(int x,int y,int z):year(x),month(y),day(z){}
    void pd()
    {
        if((year%4==0&&year%100!=0)||year%400==0)cout<<"yes";
        else cout<<"no";
        cout<<endl;
    }
    private:
    int year;
    int month;
    int day;
};
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    date n(a,b,c);
    n.pd();

    return 0;
}
