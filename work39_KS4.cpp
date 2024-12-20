/*(1)排序

//输入一批未排序的数据，数量不超过30个，请使用选择法或者冒泡法对其排序，并按照规定的要求输出。
//
//输入格式:
//先输入待排序的整形数的个数；然后输入所有的待排序的数据。
//
//输出格式:
//在一行中按照由大到小的顺序输出排序好的数据。注意：最后一个数据后面没有空格。
//
//输入样例:
//在这里给出一组输入。例如：
//
//5
//-2 52 0 192 35
//输出样例:
//在这里给出相应的输出。例如：
//
//192 52 35 0 -2

#include<iostream>
using namespace std;
int main()
{
    int a[30],n,h;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]<a[j+1])
            {
                h=a[j];
                a[j]=a[j+1];
                a[j+1]=h;
            }
     for(int j=0;j<n;j++)
     {
         if(j!=0)cout<<" ";
         cout<<a[j];
     }

    return 0;
}
*/

/*(2)求阶乘累加和

//求解阶乘累加和。计算1到n之间（包括1和n）每个整数的阶乘的累加和。即计算 sum=1!+2!+⋯+n!
//
//输入格式:
//输入一个整数 n(1≤n≤12)。
//
//输出格式:
//1 的阶乘到 n 的阶乘的累加和。
//
//输入样例:
//在这里给出一组输入。例如：
//
//5
//输出样例:
//在这里给出相应的输出。例如：
//
//153

#include<iostream>
int Fact(int n);
int main(void)
{
    int m;
    int s=0;
    int i;
    scanf("%d",&m);
    for (i=1;i<=m;i++)
        s=s+Fact(i);
    printf("%lu",s);

    return 0;
}
int Fact(int n)
{
    int i;
    int result = 1;
    for (i=2; i<=n; i++)
        result *= i;
    return result;
}
*/

/*(3)找商品（结构体）

//小明是一位超市员工，他需要从给出的n个商品中迅速找出重量最大的商品，如果最大重量商品有多个，则需要找出其中价格最高的商品（假设这样商品是唯一的）。
//请你帮他完成该工作。
//
//输入格式:
//输入整数n（n小于20），然后输入n个商品信息，包含：
//商品名称（长度不超过10）
//商品价格（数值在double范围内）
//商品克数（数值在int范围内）
//
//输出格式:
//输出克数最大的商品，如果有多个最大克数商品，则输出价格最高的商品信息，信息包括：名称 价格 克数，各个信息之间空格隔开，价格保留2位小数。
//
//输入样例:
//3
//milk 8.5 1000
//apple 9.9 1000
//egg 11.9 800
//输出样例:
//apple 9.90 1000

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
struct dx
{
    string name;
    double jg;
    int sum;
};

int main()
{
    int n,max=0;
    cin>>n;
    vector<dx*>m(n);
    for(int i=0;i<n;i++)
    {
        m[i]=new dx;
        cin>>m[i]->name>>m[i]->jg>>m[i]->sum;
        if(m[i]->sum>max)max=m[i]->sum;
    }
    int k=0;
    double MAX=0;
    for(int i=0;i<n;i++)
        if(m[i]->sum==max&&m[i]->jg>MAX)
        {
            MAX=m[i]->jg;
            k=i;
        }
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<m[k]->name<<" "<<m[k]->jg<<" "<<m[k]->sum<<endl;

    return 0;
}
*/

/*(4)输出素数之和

//编写程序输出n以内最大的10个素数及其之和；如果n以内最大素数不足10个，则按照实际个数输出。
//
//输入格式:
//输入n的值。
//
//输出格式:
//在第一行中输出最大的10个素数，每个素数后面有个空格。在第二行中输出10个素数之和。
//
//输入样例:
//500
//输出样例:
//499 491 487 479 467 463 461 457 449 443
//sum = 4696

#include<iostream>
using namespace std;
bool pd(int x)
{
    for(int j=2;j*j<=x;j++)
        if(x%j==0)return 0;
    return 1;
}
int main()
{
    int n,j=10,sum=0;
    cin>>n;
    for(int i=n;i>1&&j!=0;i--)
        if(pd(i))
        {
            cout<<i<<" ";
            sum+=i;
            j--;
        }
    cout<<"\nsum = "<<sum<<endl;

    return 0;
}
*/

//复数类的操作
//
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
class Complex
{
public:
    Complex(double x, double y) :real(x), image(y) {}
    void qf(double x, double y)
    {
        real = -x;
        image = -y;
    }
    void add(Complex x, Complex y)
    {
        cout << "(" << x.real + y.real << ", " << x.image + y.image << ")" << endl;
    }
private:
    double real;
    double image;
};

int main()
{
    double x, y;
    cin >> x >> y;
    Complex c1(x, y);
    cin >> x >> y;
    Complex c2(x, y);
    c1.add(c1, c2);
    c2.qf(x, y);
    c1.add(c1, c2);
    cout << "(" << x << ", " << y << ")" << endl;

    return 0;
}