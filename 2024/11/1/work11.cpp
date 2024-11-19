/*(31)字符统计

//程序实现的功能是从键盘读入一行字符（包括空格），统计输出该行字符串的数字字符个数n1、大写字母字符个数n2、小写字母字符个数n3,空格字符的个数n4,其他字符n5;
//例如：输入  :       I Am A Student. I Have 20 Years Old！
//            输出：       n1=2  n2=8  n3=16  n4=8  n5=3
//。
//
//输入格式:
//输入一行字符串（可能含有空格字符串），以回车键为结束符。
//
//输出格式:
//输出一行n1,n2,n3,n4,n5的值。例如：各个数之间有两个空格。
//
//输入样例:
//在这里给出一组输入。例如：
//
//Are You 20 Years Old? No,No......
//
//输出样例:
//在这里给出相应的输出。例如：
//
//n1=2  n2=6  n3=12  n4=5  n5=8

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string n;
    int n1, n2, n3, n4, n5, a, b;
    n1 = n2 = n3 = n4 = n5 = 0;
    getline(cin, n);
    a = n.size();
    for (int i = 0; i < a; i++)
    {
        b = (int)n[i];
        if (b >= 48 && b <= 57) { n1++; }
        else if (b >= 65 && b <= 90) { n2++; }
        else if (b >= 97 && b <= 122) { n3++; }
        else if (b == 32) { n4++; }
        else { n5++; }
    }

    cout << "n1=" << n1 << "  n2=" << n2 << "  n3=" << n3 << "  n4=" << n4 << "  n5=" << n5 << endl;

    return 0;
}
*/

/*(32)用类实现输入输出时间

//本题要求运行时效果如下：
//先输入时间对像t1的时间（时 分 秒）
//再输入时间对像t2的时间（时 分 秒）
//
//输入格式:
//时 分 秒
//时 分 秒
//
//输出格式:
//t1 is:
//时:分:秒
//t2 is:
//时:分:秒
//
//输入样例:
//在这里给出一组输入。例如：
//
//10 30 0
//12 10 0
//输出样例:
//在这里给出相应的输出。例如：
//
//t1 is:
//10:30:0
//t2 is:
//12:10:0

#include<iostream>
using namespace std;
int main()
{
    int x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;

    cout << "t1 is:" << endl << x << ":" << y << ":" << z << endl;
    cout << "t2 is:" << endl << a << ":" << b << ":" << c << endl;

    return 0;
}
*/

/*(33)用指针比较3个整数大小

//这是一个编程题模板。请在这里写题目描述。例如：输入3个整数，按由小到大的顺序输出。编译一个函数，用指针变量作为参数。
//
//输入格式:
//请在这里写输入格式。例如：输入在一行中给出3个不超过1000的整数a,b,c。
//
//输出格式:
//请在这里描述输出格式。例如：由小到大的顺序输出3个整数。
//
//输入样例:
//在这里给出一组输入。例如：
//
//25 45 -12
//输出样例:
//在这里给出相应的输出。例如：
//
//-12   25   45

#include<iostream>
using namespace std;
void PX(int *x,int *y,int *z)
{
    int h;
    if(*x>*y){h=*x;*x=*y;*y=h;}
    if(*y>*z){h=*y;*y=*z;*z=h;}
    if(*x>*y){h=*x;*x=*y;*y=h;}
}
int main()
{
    int a,b,c,*x,*y,*z;
    cin>>a>>b>>c;
    x=&a;
    y=&b;
    z=&c;
    PX(x,y,z);
    cout<<a<<"   "<<b<<"   "<<c<<endl;

    return 0;
}
*/

/*(34)print函数打印学生成绩结构体数组

//编写一个pirnt函数，打印学生成绩数组，该数组中有5名学生，每个学生数据有学号num、姓名name、成绩score[3]。主函数输入5名学生数据，printf函数输出
//
//输入格式:
//此处为结构参考。具体格式复制样例中格式使用！
//
//学生1学号 学生1姓名 学生1成绩1 学生1成绩2 学生1成绩3
//学生2学号 学生2姓名 学生2成绩1 学生2成绩2 学生2成绩3
//。。。。。。
//学生5学号 学生5姓名 学生5成绩1 学生5成绩2 学生5成绩3
//
//输出格式:
//此处为结构参考。具体格式复制样例中格式使用！
//
//学生1学号 学生1姓名 学生1成绩1 学生1成绩2 学生1成绩3
//学生2学号 学生2姓名 学生2成绩1 学生2成绩2 学生2成绩3
//。。。。。。
//学生5学号 学生5姓名 学生5成绩1 学生5成绩2 学生5成绩3
//
//输入样例:
//在这里给出一组输入。例如：
//
//1 zhao 98 54 34
//2 qian 87 100 79
//3 sun 76 85 94
//4 li 98 75 82
//5 zhou 100 98 94
//输出样例:
//在这里给出相应的输出。例如：
//
//1 zhao 98 54 34
//2 qian 87 100 79
//3 sun 76 85 94
//4 li 98 75 82
//5 zhou 100 98 94

#include<iostream>
#include<string>
using namespace std;
int print(int num);
int print(int num0, int a);
int print(string str);
int print(char a);
int main()
{
    int a[10][4];
    string b[10];
    int i0 = 0;
    while (cin >> a[i0][0])
    {
        cin >> b[i0];
        for (int j = 1; j <= 3; j++)cin >> a[i0][j];
        i0++;
    }

    for (int i = 0; i < i0; i++)
    {
        print(a[i][0]);
        print(b[i]);
        for (int j = 1; j <= 2; j++)print(a[i][j]);
        print(a[i][3], 1);
        if (i != i0)print('\n');
    }

    return 0;
}
int print(int num)
{
    cout << num << " ";
    return 1;
}
int print(int num0, int a)
{
    cout << num0;
    return 1;
}
int print(string str)
{
    cout << str << " ";
    return 1;
}
int print(char a)
{
    cout << endl;
    return 1;
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
//807-35 设计一个类CRectangle
//分数 10
//作者 Yan Guo
//单位 浙江大学
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
class CRectangle
{
private:
    float a = 1;
    float b = 1;
public:
    void setdata()
    {
        cin >> a;
        if (a <= 0 || a >= 50)a = 1;
        cin >> b;
        if (b <= 0 || b >= 50)b = 1;
    }
    void display()
    {
        cout << (a + b) * 2;
    };
};
CRectangle CR;
int main()
{
    CR.setdata();
    CR.display();

    return 0;
}
