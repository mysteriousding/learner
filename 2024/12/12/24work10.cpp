/*(46)输出链表偶数结点

//先输入N个整数，按照输入的顺序建立链表。然后遍历并输出偶数位置上的结点信息。
//
//输入格式:
//首先输入一个正整数T，表示测试数据的组数，然后是T组测试数据。
//每组测试的第一行输入整数的个数N（2≤N）；第二行依次输入N个整数。
//
//输出格式:
//对于每组测试，输出该链表偶数位置上的结点的信息。每两个数据之间留一个空格。
//
//输入样例:
//2
//8
//12 56 4 6 55 15 33 62
//3
//1 2 1
//输出样例:
//56 6 15 62
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
    cin>>n;
    for(int k=0;k<n;k++)
    {
        cin>>m;
        sum*head=NULL,*p;
        for(int i=0;i<m;i++)
        {
            sum*node=new sum;
            cin>>node->sz;
            if(head==NULL)p=head=node;
            else
            {
                p->next=node;
                p=p->next;
            }
        }
        bool b=0,a=0;
        while(head!=NULL)
        {
            if(b)
            {
                if(a)cout<<" ";
                cout<<head->sz;
                a=1;b=0;
            }
            else b=1;
            p=head;
            head=head->next;
            delete p;
        }
        cout<<endl;
    }

    return 0;
}
*/

/*(47)使用链表进行逆置

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
#include<vector>
using namespace std;
struct stu
{
    string name;
    int nl;
    stu*next=NULL;
};
int main()
{
    int n,m;
    cin>>n;
    for(int k=0;k<n;k++)
    {
        cin>>m;
        stu*head=NULL,*p;
        for(int i=0;i<m;i++)
        {
            stu*node=new stu;
            cin>>node->name>>node->nl;
            node->next=head;
            head=node;
        }
        while(head!=NULL)
        {
            cout<<head->name<<" "<<head->nl<<endl;
            p=head;
            head=head->next;
            delete p;
        }
    }

    return 0;
}
*/

/*(48)素数链表

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

/*(49)单向链表的创建与输出

//本题要求补充两个函数，实现如下功能：
//
//输入n个正整数，采取向链表尾部添加节点的方式建立一个单链表，并输出这个单链表。
//
//创建链表函数：
//Link Create(int n);
//
//其中Link结构定义如下：
//typedef struct link
//{
//    int data;
//    struct link *next;
//}*Link;
//n：数据元素个数
//函数返回值：创建完成后的链表头指针
//输出链表函数：
//void Display(Link head);
//
//head ：链表头指针
//
//主函数样例：
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct link
//{
//    int data;
//    struct link *next;
//}*Link;
//
//Link Create(int n);
//void Display(Link head);
//
//int main()
//{
//    int   n;
//    Link  head;
//    scanf("%d",&n);
//    head = Create(n);
//    Display(head);
//    return 0;
//}
//
///*在此实现 Create函数 *
///*在此实现Display函数 *
//输入格式:
//第一行：从键盘输入n的值
//第二行： 从键盘输入n干个正整数（空格分隔）
//输出格式 :
//依次输出链表中各个节点的数据元素值，元素间以->分隔。
//如果链表为空，则输出NULL。
//输入样例 :
//5
//1 3 5 7 9
//
//输出样例 :
//1->3->5->7->9
//
//输入样例 :
//0
//
//输出样例 :
//NULL

#include <stdio.h>
#include <stdlib.h>
typedef struct link
{
    int data;
    struct link *next;
}*Link;
Link Create(int n);
void Display(Link head);

int main()
{
    int n;
    Link head;
    scanf("%d",&n);
    head = Create(n);
    Display(head);
    return 0;
}

Link Create(int n)
{
    Link head=NULL,p;
    for(int i=0;i<n;i++)
    {
        Link node=new link;
        scanf("%d",&node->data);
        if(head==NULL)p=head=node;
        else
        {
            p->next=node;
            p=p->next;
        }
    }
    return head;
}
void Display(Link head)
{
    Link p;
    bool u=1,a=0;
    while(head!=NULL)
    {
        if(a)printf("->");
        printf("%d",head->data);
        p=head;
        head=head->next;
        delete p;
        u=0;
        a=1;
    }
    if(u)printf("NULL\n");
}
*/

//顺序建立链表
//
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
struct sum
{
    int sz;
    sum*next=NULL;
};
int main()
{
    int n;
    cin>>n;
    sum*head=NULL,*p;
    for(int i=0;i<n;i++)
    {
        sum*node=new sum;
        cin>>node->sz;
        if(head==NULL)p=head=node;
        else
        {
            p->next=node;
            p=p->next;
        }
    }
    bool a=0;
    while(head!=NULL)
    {
        if(a)cout<<" ";
        cout<<head->sz;
        p=head;
        head=head->next;
        delete p;
        a=1;
    }

    return 0;
}
