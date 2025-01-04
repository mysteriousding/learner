/*(26)顺序建立链表

//输入N个整数，按照输入的顺序建立单链表存储，并遍历所建立的单链表，输出这些数据。
//
//输入格式:
//第一行输入整数的个数N；
//第二行依次输入每个整数。
//
//输出格式:
//输出这组整数。
//
//输入样例:
//8
//12 56 4 6 55 15 33 62
//输出样例:
//12 56 4 6 55 15 33 62

#include<iostream>
using namespace std;
struct su
{
    int num;
    su*next=NULL;
};
int main()
{
    int n;
    cin>>n;
    su*head=NULL,*p;
    for(int i=0;i<n;i++)
    {
        su*node=new su;
        cin>>node->num;
        if(head==NULL)p=head=node;
        else
        {
            p->next=node;
            p=p->next;
        }
    }
    bool u=0;
    while(head!=NULL)
    {
        if(u)cout<<" ";
        cout<<head->num;
        u=1;
        p=head;
        head=head->next;
        delete p;
    }

    return 0;
}
*/

/*(27)设计一个类CRectangle

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
public:
    CRectangle(float x_,float y_)
    {
        x=(x_&&x_<50)?x_:1;
        y=(y_&&y_<50)?y_:1;
    }
    void display()
    {
        cout<<(x+y)*2<<endl;
    }
private:
    float x;
    float y;
};
int main()
{
    float n,m;
    cin>>n>>m;
    CRectangle c(n,m);
    c.display();

    return 0;
}
*/

/*(28)定义一个时间类

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
struct Time
{
public:
    bool cin_()
    {
        return scanf("%d%d%d",&h,&m,&s)==3;
    }
    void display()
    {
        printf("%02d-%02d-%02d\n",h,m,s);
    }
private:
    int h;
    int m;
    int s;
};
int main()
{
    Time t;
    while(t.cin_())
        t.display();

    return 0;
}
*/

//定义一个Date类
//
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

//#include<iostream>
//using namespace std;
//struct date
//{
//public:
//    date(){scanf("%d%d%d",&y,&m,&d);}
//    void display(){printf("%d-%02d-%02d\n",y,m,d);}
//private:
//    int y;
//    int m;
//    int d;
//};
//int main()
//{
//    date d;
//    d.display();
//
//    return 0;
//}







//#include<iostream>                                                      
//using namespace std;
//struct stu
//{
//    int num;
//    stu* next = NULL;
//};
//int main()
//{
//    int n, m;
//    cin >> n;
//    stu* head = NULL, * p;
//    for (int i = 0; i < n; i++)
//    {
//        stu* node = new stu;
//        cin >> m;
//        node->num = m;
//        if (head == NULL)head = node;
//        else
//        {
//            if (m < head->num)
//            {
//                node->next = head;
//                head = node;
//            }
//            else
//            {
//                p = head;
//                while (p->next != NULL)
//                {
//                    if (m < p->next->num)
//                        break;
//                    p = p->next;
//                }
//                node->next = p->next;
//                p->next = node;
//            }
//        }
//    }
//    while (head != NULL)
//    {
//        cout << head->num << " ";
//        p = head;
//        head = head->next;
//        delete p;
//    }
//
//    return 0;
//}









//#include<iostream>
//using namespace std;
//struct sum
//{
//    int sz;
//    sum* next = NULL;
//};
//int main()
//{
//    int n, m;
//    while (cin >> n)
//    {
//        sum* head = NULL, * p;
//        for (int i = 0; i < n; i++)
//        {
//            cin >> m;
//            sum* node = new sum;
//            node->sz = m;
//            if (head == NULL)head = node;
//            else
//            {
//                if (m < head->sz)
//                {
//                    node->next = head;
//                    head = node;
//                }
//                else
//                {
//                    p = head;
//                    if (p->next != NULL)
//                        while (p->next != NULL)
//                        {
//                            if (m < p->next->sz)break;
//                            p = p->next;
//                        }
//                    if (p->next == NULL)p->next = node;
//                    else
//                    {
//                        node->next = p->next;
//                        p->next = node;
//                    }
//                }
//            }
//        }
//        p = head;
//        for (int i = 0; i < n; i++)
//        {
//            if (i != 0)cout << " ";
//            cout << p->sz;
//            p = p->next;
//        }
//        while (head != NULL)
//        {
//            p = head;
//            head = head->next;
//            delete p;
//        }
//        cout << endl;
//    }
//
//    return 0;
//}






//类类型投机取巧

//27
#include<iostream>
using namespace std;
int main()
{
    float n, m;
    cin >> n >> m;
    if (n < 0 || n>50)n = 1;
    if (m < 0 || m>50)m = 1;
    cout << (n + m) * 2 << endl;

    return 0;
}

////28
//#include<iostream>
//#include<iomanip>
//using namespace std;
//int main()
//{
//    int x, y, z;
//    
//    cout << setfill('0');
//    while(cin >> x >> y >> z)
//    cout << x << "-" << setw(2) << y << "-" << setw(2) << z << endl;
//
//    return 0;
//}
//
////29
//#include<iostream>
//#include<iomanip>
//using namespace std;
//int main()
//{
//    int x, y, z;
//    
//    cout << setfill('0');
//    cin >> x >> y >> z;
//    cout << x << "-" << setw(2) << y << "-" << setw(2) << z << endl;
//
//    return 0;
//}