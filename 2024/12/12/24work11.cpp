/*(51)统计

//输入两个整数n和x，在输入n个整数，创建不带头结点的逆序单链表，统计某个整数x在链表中的出现次数。
//
//输入格式:
//测试数据有多组，处理到文件尾。每组测试数据输入两个整数n和x，再输入n个整数。
//
//输出格式:
//对于每组测试，输出2行，第一行是所创建的逆序链表，第二行是x的出现次数。
//
//输入样例:
//5 1
//1 2 3 1 5
//输出样例:
//5 1 3 2 1
//2

#include<iostream>
using namespace std;
struct sum
{
    int sz;
    sum*next=NULL;
};
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        sum*head=NULL,*p;
        for(int i=0;i<n;i++)
        {
            sum*node=new sum;
            cin>>node->sz;
            node->next=head;
            head=node;
        }
        bool u=0;
        int g=0;
        while(head!=NULL)
        {
            if(u)cout<<" ";
            cout<<head->sz;
            if(head->sz==m)g++;
            p=head;
            head=head->next;
            delete p;
            u=1;
        }
        cout<<endl<<g<<endl;
    }

    return 0;
}
*/

/*(52)设计一个类CRectangle

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
class CR
{
public:
    CR(){x=1;y=1;}
    void sr()
    {
        float n,m;
        cin>>n>>m;
        if(n<50)x=n;
        if(m<50)y=m;
    }
    void js(){C=(x+y)*2;}
    void sc(){cout<<C;}
private:
    float x;
    float y;
    float C;
};
int main()
{
    CR d;
    d.sr();
    d.js();
    d.sc();

    return 0;
}
*/

/*(53) 定义一个时间类       ---SB

//定义一个时间类Time，能提供和设置由时、分、秒组成的时间，并编写应用程序，定义时间对象，设置时间和输出该对象提供的时间。
//
//输入格式:
//以24h制，依次输入Time所需的时、分、秒，中间以空格间隔
//
//输出格式:
//以24h制，依次输出Time时、分、秒，中间已‘-’间隔，小于10的数字前面补‘0’
//
//输入样例:
//在这里给出一组输入。例如：
//
//12 6 48
//8 12 23
//输出样例:
//在这里给出相应的输出。例如：
//
//08-23-11
//12-09-08
//20-11-09

#include<iostream>
using namespace std;
class Time
{
public:
    bool sr(){return scanf("%d%d%d",&h,&m,&s)==3;}
    void sc(){printf("%02d-%02d-%02d\n",h,m,s);}
private:
    int h;
    int m;
    int s;
};

int main()
{
    Time d;
    while(d.sr())
        d.sc();

    return 0;
}
*/

/*(54)定义一个Date类

//定义一个满足如下要求的Date类
//用下列的数据输出数据
//年-月-日
//
//输入格式:
//年 月 日
//例如 1978 5 2
//2020 12 12
//
//输出格式:
//1978-05-02
//2020-12-12
//
//输入样例:
//在这里给出一组输入。例如：
//
//2020 12 1
//输出样例:
//在这里给出相应的输出。例如：
//
//2020-12-01

#include<iostream>
using namespace std;
class Data
{
public:
    bool sr(){return scanf("%d%d%d",&n,&y,&r)==3;}
    void sc(){printf("%d-%02d-%02d\n",n,y,r);}
private:
    int n;
    int y;
    int r;
};

int main()
{
    Data d;
    while(d.sr())
        d.sc();

    return 0;
}
*/

//定义一个Time类
//
//定义一个时间类，能够提供和设置由时、分、秒组成的时间，并按照如下的格式输出时间：
//08-09-24
//12-23-59
//
//输入格式:
//请在这里写输入格式。例如：
//12 8 9
//8 24 59
//
//输出格式:
//请在这里描述输出格式。例如：
//12-08-09
//08-24-59
//
//输入样例:
//在这里给出一组输入。例如：
//
//8 9 24
//输出样例:
//在这里给出相应的输出。例如：
//
//08-09-24

#include<iostream>
using namespace std;
class Time
{
public:
    bool sr(){return scanf("%d%d%d",&h,&m,&s)==3;}
    void sc(){printf("%02d-%02d-%02d\n",h,m,s);}
private:
    int h;
    int m;
    int s;
};

int main()
{
    Time d;
    while(d.sr())
        d.sc();

    return 0;
}
