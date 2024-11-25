/*(1)用指针比较3个整数大小

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
void px(int*,int*,int*);
int main()
{
    int a,b,c,*x,*y,*z;
    cin>>a>>b>>c;
    x=&a;
    y=&b;
    z=&c;
    px(x,y,z);

    return 0;
}
void px(int*x,int*y,int*z)
{
    int h;
    if(*x>*y){h=*x;*x=*y;*y=h;}
    if(*y>*z){h=*y;*y=*z;*z=h;}
    if(*x>*y){h=*x;*x=*y;*y=h;}
    cout<<*x<<"   "<<*y<<"   "<<*z<<endl;
}
*/

/*(2)输入3个字符串，按由小到大顺序输出(使用函数和指针实现)

//本题目要求读入3个字符串，然后按由小到大排序后输出三个字符串。具体输入、输出格式看“样例”
//
//输入格式:
//字符串1
//字符串2
//字符串3
//
//输出格式:
//排序后的：
//字符串1
//字符串2
//字符串3
//
//输入样例:
//在这里给出一组输入。例如：
//
//abeedg
//ageegtg
//abegrwww
//输出样例:
//在这里给出相应的输出。例如：
//
//abeedg
//abegrwww
//ageegtg

#include<iostream>
#include<string>
using namespace std;
void px(string n[]);
int main()
{
    string n[3];
    int i=3;
    while(i>0,i--)getline(cin,n[i]);
    px(n);
    while(i<2){i++;cout<<n[i]<<endl;}

    return 0;
}

void px(string*n)
{
    string h;
    for(int i=0;i<2;i++)
        for(int j=0;j<2-i;j++)
            if(*(n+j)>*(n+j+1)){h=*(n+j);*(n+j)=*(n+j+1);*(n+j+1)=h;}
}
*/

/*(2)利用指针返回多个函数值

//读入n个整数，调用max_min()函数求这n个数中的最大值和最小值。
//
//输入格式:
//输入有两行：
//第一行是n值；
//第二行是n个数。
//
//输出格式:
//输出最大值和最小值。
//
//输入样例:
//在这里给出一组输入。例如：
//
//5
//8 9 12 0 3
//输出样例:
//在这里给出相应的输出。例如：
//
//max = 12
//min = 0

#include<iostream>
#include<vector>
using namespace std;
void max_min(vector<int>*x,int y);
int main()
{
    int n,max,min,i;
    cin>>n;
    i=n;
    vector<int>m(n);
    while(i--)cin>>m[i];
    max_min(&m,n);
    cout<<"max = "<<m[n-1]<<"\nmin = "<<m[0]<<endl;

    return 0;
}

void max_min(vector<int>*x,int y)
{
    int h;
    for(int i=0;i<y-1;i++)
        if((*x)[i]>(*x)[i+1]){h=(*x)[i];(*x)[i]=(*x)[i+1];(*x)[i+1]=h;}
    for(int j=y-2;j>0;j--)
        if((*x)[j]<(*x)[j-1]){h=(*x)[j];(*x)[j]=(*x)[j-1];(*x)[j-1]=h;}
}
*/

/*(4)冒泡

//鸿鸿哥最近学习了指针，感觉这个知识点有点难以理解，于是想要通过编程实践来掌握它。鸿鸿哥以前学习数组（第7章）的时候已经掌握了冒泡排序的一般写法，现在他想用指针来实现排序的功能函数。但是他遇到了困难，你能帮帮他吗？
//
//指针实现冒泡排序函数，函数名统一用void bubbleSort(int *p,int c)。
//具体方法自己实现。
//
//输入格式:
//一组输入，第一行是待排数据个数n， 第二行是数据的具体值。
//
//输出格式:
//输出排序后的数，两个数之间以空格间开，最后一个数字末尾有空格
//
//输入样例:
//在这里给出一组输入。例如：
//
//5
//503 87 512 61 908
//输出样例:
//在这里给出相应的输出。例如：
//
//61 87 503 512 908

#include<iostream>
#include<vector>
using namespace std;

void px(vector<int>*n,int m);
int main()
{
    int k, i;
    cin >> k;
    i = k;
    vector<int>m(k);
    while(i--)cin >> m[i];
    px(&m,k);
    for (i = 0; i < k; i++)
        cout << m[i] << " ";
    cout<<endl;

    return 0;
}

void px(vector<int>*n, int m)
{
    int h;
    for (int i = 0; i < m - 1; i++)
        for (int j = 0; j < m - 1 - i; j++)
            if ((*n)[j] > (*n)[j + 1]) { h = (*n)[j]; (*n)[j] = (*n)[j+1]; (*n)[j+1] = h; }
}
*/

/*(5)用指针方法求10个数最大和最小值之差

//请使用指针的方法编写程序，程序的功能是从键盘输入10个数，求其最大值和最小值的差。
//
//输入格式:
//输入10个整数，每个整数之间用空格分隔。
//
//输出格式:
//同样例。
//
//输入样例:
//1 2 3 4 5 6 7 8 9 10
//输出样例:
//difference value = 9

#include<iostream>
using namespace std;
void max_min(int x[],int y);
int main()
{
    int max,min,i=10;
    int m[10];
    while(i--)cin>>m[i];
    max_min(m,10);
    cout<<"difference value = "<<m[9]-m[0]<<endl;

    return 0;
}

void max_min(int x[],int y)
{
    int h;
    for(int i=0;i<y-1;i++)
        if(*(x+i)>*(x+i+1)){h=*(x+i);*(x+i)=*(x+i+1);*(x+i+1)=h;}
    for(int j=y-2;j>0;j--)
        if(*(x+j)<*(x+j-1)){h=*(x+j);*(x+j)=*(x+j-1);*(x+j-1)=h;}
}
*/

//循环移动
//
//输入两个正整数 n 和 m (1<m<n<=10)，再输入 n 个整数，将这些数排成一行，向右循环移动 m 个位置（从右边移出的数再从左边移入），最后输出移动后的n个整数。
//
//要求定义并调用函数 mov(x,n,m) 实现上述循环移动的功能，函数形参x的类型是整型指针，形参n和m的类型是int，函数的类型是void。
//
//输出格式：数据之间以空格分隔，最后一个数据集后面没有空格
//
//输入输出示例：括号内为说明
//
//输入样例:
//5 3            (n=5,m=3)
//1 2 3 4 5      (5个整数)
//输出样例:
//After move: 3 4 5 1 2

#include<iostream>
#include<vector>
using namespace std;
void yd(vector<int>*, int, int);
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int>a(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    yd(&a, m % n, n);
    cout << "After move:";
    for (int j = 0; j < n; j++)
        cout << " " << a[j];

    return 0;
}

void yd(vector<int>* x, int y, int z)
{
    int h;
    for (int i = 0; i < y; i++)
    {
        h = (*x)[z - 1];
        for (int j = z - 1; j > 0; j--)(*x)[j] = (*x)[j - 1];
        (*x)[0] = h;
    }
}