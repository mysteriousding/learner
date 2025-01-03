/*(1)使用链表进行逆置

//对于输入的若干学生的信息，利用链表进行储存，并将学生的信息逆序输出。
//要求将学生的完整信息存放在链表的结点中。通过链表的操作完成信息的逆序输出。
//
//输入格式:
//首先输入一个正整数T，表示测试数据的组数，然后是T组测试数据。
//每组测试数据首先输入一个正整数n，表示学生的个数；然后是n行信息，分别表示学生的姓名（不含空格且长度不超过10的字符串）和年龄（正整数）。
//
//输出格式:
//对于每组测试，逆序输出学生信息（参看输出样例）。
//
//输入样例:
//1
//3
//Zhangsan 20
//Lisi 21
//Wangwu 20
//输出样例:
//Wangwu 20
//Lisi 21
//Zhangsan 20

#include<iostream>
using namespace std;
struct stu
{
    string name;
    int nl;
    stu*next=0;
};
int main()
{
    int n,m;
    cin>>n;
    for(int k=0;k<n;k++)
    {
        cin>>m;
        stu*head,*p;
        for(int i=0;i<m;i++)
        {
            stu*node=new stu;
            cin.ignore();
            cin>>node->name>>node->nl;
            node->next=head;
            head=node;
        }
        p=head;
        for(int i=0;i<m;i++)
        {
            cout<<p->name<<" "<<p->nl<<endl;
            p=p->next;
        }
        while(head!=NULL)
        {
            p=head;
            head=head->next;
            delete p;
        }
    }

    return 0;
}
*/

/*(2)链表排序

//请以单链表存储n个整数，并实现这些整数的非递减排序。
//
//输入格式:
//测试数据有多组，处理到文件尾。每组测试输入两行，第一行输入一个整数n，第二行输入n个整数。
//
//输出格式:
//对于每组测试，输出排序后的结果，每两个数据之间留一个空格。
//
//输入样例:
//6
//3 5 1 2 8 6
//输出样例:
//1 2 3 5 6 8

//#include<iostream>
//using namespace std;
//struct sum
//{
//    int sz;
//    sum*next=NULL;
//};
//int main()
//{
//    int n,m;
//    while(cin>>n)
//    {
//        sum*head=NULL,*p;
//        for(int i=0;i<n;i++)
//        {
//            cin>>m;
//            sum*node=new sum;
//            node->sz=m;
//            if(head==NULL)head=node;
//            else
//            {
//                if(m<head->sz)
//                {
//                    node->next=head;
//                    head=node;
//                }
//                else
//                {
//                    p=head;
//                    if(p->next!=NULL)
//                        while(p->next!=NULL)
//                        {
//                            if(m<p->next->sz)break;
//                            p=p->next;
//                        }
//                    if(p->next==NULL)p->next=node;
//                    else
//                    {
//                        node->next=p->next;
//                        p->next=node;
//                    }
//                }
//            }
//        }
//        p=head;
//        for(int i=0;i<n;i++)
//        {
//            if(i!=0)cout<<" ";
//            cout<<p->sz;
//            p=p->next;
//        }
//        while(head!=NULL)
//        {
//            p=head;
//            head=head->next;
//            delete p;
//        }
//        cout<<endl;
//    }
//
//    return 0;
//}


#include<iostream>                                                      
using namespace std;
struct stu
{
    int num;
    stu* next = NULL;
};
int main()
{
    int n, m;
    cin >> n;
    stu* head = NULL, * p;
    for (int i = 0; i < n; i++)
    {
        stu* node = new stu;
        cin >> m;
        node->num = m;
        if (head == NULL)head = node;
        else
        {
            if (m < head->num)
            {
                node->next = head;
                head = node;
            }
            else
            {
                p = head;
                while (p->next != NULL)
                {
                    if (m < p->next->num)
                        break;
                    p = p->next;
                }
                node->next = p->next;
                p->next = node;
            }
        }
    }
    while (head != NULL)
    {
        cout << head->num << " ";
        p = head;
        head = head->next;
        delete p;
    }

    return 0;
}
*/

/*(3)拆分单链表

//输入若干个整数，先建立单链表A，然后将单链表A分解为两个具有相同结构的链表B、C，其中B链表的结点为A链表中值小于零的结点，而C链表的结点为A链表中值大于零的结点。请尽量利用原有结点空间。测试数据保证每个结果链表至少存在一个元素。
//
//输入格式:
//首先输入一个正整数T，表示测试数据的组数，然后是T组测试数据。每组测试数据在一行上输入数据个数n及n个整数（不含0）。
//
//输出格式:
//对于每组测试，分两行按原数据顺序输出链表B和C，每行中的每两个数据之间留一个空格。
//
//输入样例:
//3
//10 49 53 -26 79 -69 -69 18 -96 -11 68
//5 1 -2 -3 -4 -5
//5 -2 -3 1 2 3
//输出样例:
//-26 -69 -69 -96 -11
//49 53 79 18 68
//-2 -3 -4 -5
//1
//-2 -3
//1 2 3

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
    cin>>n;
    for(int l=0;l<n;l++)
    {
        cin>>m;
        sum*head=NULL,*p;
        for(int k=0;k<m;k++)
        {
            sum*node=new sum;
            cin>>node->sz;
            node->next=head;
            head=node;
        }
        sum*head1=NULL,*head2=NULL;
        while(head!=NULL)
        {
            p=head;
            head=head->next;
            if(p->sz<0)
            {
                p->next=head1;
                head1=p;
            }
            else
            {
                p->next=head2;
                head2=p;
            }
        }
        bool u=0;
        while(head1!=NULL)
        {
            if(u)cout<<" ";
            cout<<head1->sz;
            p=head1;
            head1=head1->next;
            delete p;
            u=1;
        }
        cout<<endl;
        u=0;
        while(head2!=NULL)
        {
            if(u)cout<<" ";
            cout<<head2->sz;
            p=head2;
            head2=head2->next;
            delete p;
            u=1;
        }
        cout<<endl;
    }

    return 0;
}
*/

/*(4)素数链表

//注意：本题要求用链表（或STL之list）做。
//
//给你两个整数m和n，请用[m,n]范围内的所有素数构建成一个链表并按从小到大的顺序输出。
//
//输入格式:
//输入数据首先包含一个整数T(1<=T<=15)，表示测试实例的个数。
//然后是T组测试数据。每组测试输入两个整数m,n(1<=m<n<1000)。
//
//输出格式:
//对于每组测试，在一行上按从小到大的顺序输出该链表中的各个素数，数据之间空一个空格。若[m,n]范围内没有素数，则输出none。
//
//输入样例:
//2
//3 7
//8 10
//输出样例:
//3 5 7
//none

#include<iostream>
using namespace std;
struct sum
{
    int sz;
    sum*next=NULL;
};
int main()
{
    int s,n,m;
    cin>>s;
    for(int k=0;k<s;k++)
    {
        cin>>n>>m;
        if(n==1)n++;
        sum*head=NULL,*p;
        for(int i=m;i>=n;i--)
        {
            bool u=1;
            for(int j=2;j<=i/2;j++)
                if(i%j==0){u=0;break;}
            if(u)
            {
                sum*node=new sum;
                node->sz=i;
                node->next=head;
                head=node;
            }
        }
        bool u=0;
        if(head==NULL)cout<<"none";
        else
            while(head!=NULL)
            {
                if(u)cout<<" ";
                cout<<head->sz;
                p=head;
                head=head->next;
                delete p;
                u=1;
            }
        cout<<endl;
    }

    return 0;
}
*/

/*(5)链表也简单final

//将学生成绩绩点组成一个链表。链表结构如下：
//struct student {
//        string name;   //学生姓名
//        double  gpa;   //绩点
//        student *next;
//};
//
//输入是一组学生的姓名和绩点，以链表形式存储。  删除绩点小于平均绩点的学生结点，成为一个新链表。 后按照输入的顺序，依序输出新链表的学生信息。平均绩点是输入的所有学生绩点取算术平均值。
//
//输入格式:
//输入包括若干行。 每行是一个学生的 姓名和绩点，以空格隔开。
//最后一行是-1。
//
//输出格式:
//输出包括学生姓名。  每个学生姓名一行。
//
//输入样例:
//zhang 3.5
//liu 2.1
//tie 1.9
//-1
//输出样例:
//zhang

#include<iostream>
#include<string>
using namespace std;
struct stu
{
    string name;
    double gpa;
    stu*next=NULL;
};
int main()
{
    string n;
    int k=0;
    double m,h=0;
    stu*head=NULL,*p;
    while(cin>>n&&cin>>m)
    {
        k++;
        stu*node=new stu;
        node->name=n;
        node->gpa=m;
        h+=m;
        if(head==NULL)p=head=node;
        else
        {
            p->next=node;
            p=p->next;
        }
    }
    h/=k;
    stu*q;
    p=head;
    while(p->next!=NULL)
    {
        if(p->next->gpa<h)
        {
            q=p->next;
            p->next=p->next->next;
            delete q;
        }
        else p=p->next;
    }
    if(head!=NULL)
    if(head->gpa<h)
    {
        q=head;
        head=head->next;
        delete q;
    }
    while(head!=NULL)
    {
        cout<<head->name<<endl;
        q=head;
        head=head->next;
        delete q;
    }

    return 0;
}
*/

//统计
//
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
