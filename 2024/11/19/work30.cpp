/*(1)两个整数的交换

//本题要求实现一个函数swap，实现两个整数的交换。
//
//函数接口定义：
//void swap ( int &a,  int &b );
//
//
//
//### 裁判测试程序样例：
//#include <iostream>
//using namespace std;
//void swap (  int &a,  int &b );
//
//int main()
//{
//     int x, y;
//     cin>>x>>y;
//     swap(x, y);
//     cout<<x<<' '<<y<<endl;
//     return 0;
//}
//
///* 请在这里填写答案 *
//输入样例：
//3 5
//输出样例：
//5 3

#include <iostream>
using namespace std;
void swap(int& a, int& b);

int main()
{
    int x, y;
    cin >> x >> y;
    swap(x, y);
    cout << x << ' ' << y << endl;
    return 0;
}

//作答
void swap(int& a, int& b)
{
    int h;
    h = a;
    a = b;
    b = h;
}
//结束
*/

/*（2）逆序字符串

//设计一个void类型的函数reverse_string，其功能是将一个给定的字符串逆序。例如，给定字符串为“hello”，逆序后为“olleh”。
//###函数接口定义如下：
//
///* 函数原型参见main函数 *
//###裁判测试程序样例：
//
//#include <iostream>
//#include <string>
//using namespace std;
//
///* 你的代码将嵌在这里 *
//
//int main(int argc, char const* argv[])
//{
//    string str;
//    getline(cin, str);        //输入字符串
//    reverse_string(str);     //逆序字符串str
//    cout << str << endl;    //输出逆序后的字符串
//    return 0;
//}
//###输入样例：
//
//hello
//###输出样例：
//
//olleh

#include <iostream>
#include <string>
using namespace std;

//作答
void reverse_string(string& n)
{
    int m = n.size();
    char h;
    for (int i = 0; i < m / 2; i++) { h = n[i]; n[i] = n[m - 1 - i]; n[m - 1 - i] = h; }
}
//结束

int main(int argc, char const* argv[])
{
    string str;
    getline(cin, str);   
    reverse_string(str);    
    cout << str << endl;    
    return 0;
}
*/

/*（3）教材4 - 4：自定义函数求一元二次方程的根(系数均不为0）

//本题要求实现一个自定义函数，求一元二次方程ax
//2
// +bx+c=0的根（a,b,c均不为0）。
//
//函数返回根的个数，0表示无根，1表示有1个根，2表示有2个根。
//
//提示：函数调用只能得到一个返回值，因此将根的个数作为函数返回值，而根的2个值作为引用型形参
//
//函数接口定义：
//  int GetRoot(double a, double b, double c, double &root1, double &root2);
// a、b、c分别是用户传入的方程系数,是double值；
//
//root1、root2保存方程的根，是用户double型实参变量的引用；
//
//函数调用结束后返回方程根的个数，int型。
//
//裁判测试程序样例：
//函数被调用进行测试的程序如下：
//#include<iostream>
//#include<cmath>
//using namespace std;
//int GetRoot(double a, double b, double c, double &root1, double &root2);
//int main()
//{
//    double a,b,c,root1,root2;
//    cout << "输入方程的系数a，b，c的值：";
//    cin >> a >> b >> c;
//
//    int n = GetRoot(a,b,c,root1,root2);
//    if(n==1)
//       cout << "方程有1个根，值为：" << root1;
//    else if(n==2)
//       cout << "方程有2个根，值为：" << root1 << "," << root2;
//    else
//       cout << "方程无根";
//    return 0;
//}
///* 请在这里填写自定义函数，提交结果时在答题区只提交这部分答案 *
//输入样例1:
//1 2 1
//输出样例1 :
//方程有1个根，值为： - 1
//输入样例2 :
//1 - 3 2
//输出样例2 :
//方程有2个根，值为：2, 1

#include<iostream>
#include<cmath>
using namespace std;
int GetRoot(double a, double b, double c, double& root1, double& root2);
int main()
{
    double a, b, c, root1, root2;
    cout << "输入方程的系数a，b，c的值：";
    cin >> a >> b >> c;

    int n = GetRoot(a, b, c, root1, root2);
    if (n == 1)
        cout << "方程有1个根，值为：" << root1;
    else if (n == 2)
        cout << "方程有2个根，值为：" << root1 << "," << root2;
    else
        cout << "方程无根";
    return 0;
}

//作答
int GetRoot(double a,double b,double c,double &root1,double &root2)
{
    double x=b*b-4*a*c;
    if(x>0)
    {
        root1=(-1*b+sqrt(x))/(2*a);
        root2=(-1*b-sqrt(x))/(2*a);
        return 2;
    }
    else if(x==0)
    {
        root1=root2=-1*b/(2*a);
        return 1;
    }
    else return 0;
}
//结束
*/

/*（4）教材6-2：自定义函数实现有序数组的插入

//向一个有序数组a中插入一个数据，使其依然保持有序性。如数组a={1,3,5,7,9}，插入4后的a是{1,3,4,5,7,9}。
//
//【提示】
//用户输入一个数值后，从数组最后一个值开始判断，如果输入值小于数组元素，则数组元素值复制到后一个位置（输入值至少要放到数组元素的前面），直到不满足条件为止（数组已到头部，或者输入值大于等于数组元素值），将输入值赋值到该位置。
//
//函数接口定义：
//bool insert(int a[], int &n, int N, int key);
// a 是int型数组，有n个有序元素（由小到大）；
//
// key要插入的值；
//
// N是数组a的最大长度；
//
// 函数返回值为true表示插入成功，同时n的值+1，返回false表示插入失败（数组已满）。
//
//裁判测试程序样例：
//#include<iostream>
//using namespace std;
//void print(int a[], int n);
//bool insert(int a[], int &n, int N, int key);
//
//int main()
//{
//    const int N = 5;
//    int a[N]={11,15,21};
//    int n=3;                //数组n的实际长度
//
//    int key;               //要插入的元素值
//    int t;                 //要插入的元素个数
//    cin >> t;
//    for(int i=1;i<=t;i++)
//    {
//       cin >> key;
//       if(insert(a,n,N,key))
//           print(a,n);
//       else
//       {
//           cout << "insert fail.";
//           break;
//       }
//    }
//
//    return 0;
//}
//
//void print(int a[], int n)
//{
//    for(int i=0; i<n; i++)
//       cout << a[i] << " ";
//    cout << endl;
//}
//
///* 请在这里填写答案 *
//输入样例1:
//2
//15
//5
//
//输出样例1:
//11 15 15 21
//5 11 15 15 21
//
//输入样例2:
//5
//4
//13
//25
//输出样例2:
//4 11 15 21
//4 11 13 15 21
//insert fail.

#include<iostream>
using namespace std;
void print(int a[], int n);
bool insert(int a[], int &n, int N, int key);

int main()
{
    const int N = 5;
    int a[N]={11,15,21};
    int n=3;             

    int key;               
    int t;              
    cin >> t;
    for(int i=1;i<=t;i++)
    {
       cin >> key;
       if(insert(a,n,N,key))
           print(a,n);
       else
       {
           cout << "insert fail.";
           break;
       }
    }

    return 0;
}

//作答
bool insert(int a[],int &n,int N,int key)
{
    if(n==N)return 0;
    for(int i=n-1;i>=0;i--)
    {
        a[i+1]=a[i];
        if(key>=a[i]){a[i+1]=key;break;}
        if(i==0)a[i]=key;
    }
    n++;return 1;
}
//结束
*/

//教材6-3：自定义函数实现有序数组的删除
//
//从一个有序数组（由小到大）中删除一个数据。如数组a={1,3,5,7,9}，删除3后的a是{1,5,7,9}，长度减1（不会释放数组内存）。如果要删除的数据不在数组中，数组不变。
//
//注意：最多只删除第1个找到的数据，如果数组中有多个相同值也只删除一个，如数组a={1,3,5,5}，删除5后的数组a是{1,3,5}。
//
//【提示】查找算法找到要删除数据的位置，如果找到了，从该位置的下一个位置开始直到数组末尾，执行a[i-1] = a[i]运算，将元素前移一个位置。删除后数组长度-1。如果没有找到，数组不变。
//
//函数接口定义：
//   bool del(int a[], int &n, int key);
// a 是int型数组，有n个有序元素（由小到大）；
// n是引用型形参，函数题删除数组key值则n-1修改了实参值，若未删除则不变；
//
// key要删除的值；
//
//  函数返回值为true表示删除成功，同时n的值-1，返回false表示删除失败（没找到要删除的数据）。
//
//裁判测试程序样例：
//#include<iostream>
//using namespace std;
//void input(int a[], int &n);
//void print(int a[], int n);
//bool del(int a[], int &n, int key);
//
//const int N=100;
//int main()
//{
//    int a[N];
//    int n;
//    cin >> n;             //n<N
//    input(a,n);          //输入n个整数
//
//    int key;               //要删除的元素值
//    cin >> key;
//    if(del(a,n,key))
//        print(a,n);
//    else
//        cout << "delete fail.";
//
//    return 0;
//}
//
//void input(int a[], int &n)
//{
//    for(int i=0; i<n; i++)
//        cin >> a[i];
//}
//
//void print(int a[], int n)
//{
//    for(int i=0; i<n; i++)
//       cout << a[i] << " ";
//    cout << endl;
//}
///* 请在这里填写答案 *
//输入格式：
//第一行输入1-100的整数n；
//第二行输入n个整数，用空格分隔；
//第三行输入要删除的整数。
//
//输出格式：
//输出删除5之后数组的值
//
//输入样例1:
//5
//1 3 5 7 9
//5
//输出样例1:
//1 3 7 9
//输入样例2:
//5
//11 13 15 17 19
//10
//输出样例2:
//数组中没有要删除的10
//
//delete fail.


#include<iostream>
using namespace std;
void input(int a[], int &n);
void print(int a[], int n);
bool del(int a[], int &n, int key);

const int N=100;
int main()
{
    int a[N];
    int n;
    cin >> n;          
    input(a,n); 

    int key;        
    cin >> key;
    if(del(a,n,key))
        print(a,n);
    else
        cout << "delete fail.";

    return 0;
}

void input(int a[], int &n)
{
    for(int i=0; i<n; i++)
        cin >> a[i];
}

void print(int a[], int n)
{
    for(int i=0; i<n; i++)
       cout << a[i] << " ";
    cout << endl;
}

//作答
bool del(int a[], int& n, int key)
{
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        if (p == 0 && a[i] == key) { p = 1; n++; }
        if (p == 1)a[i] = a[i + 1];
    }
    if (p == 1) { a[n - 1] = 0; n -= 2; return 1; }
    return 0;
}
//结束
