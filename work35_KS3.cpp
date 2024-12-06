/*(1)字符串排序--string类的使用

//先输入你要输入的字符串的个数。然后换行输入该组字符串。每个字符串以回车结束，每个字符串不多于一百个字符。
//如果在输入过程中输入的一个字符串为“stop”，也结束输入。
//然后将这输入的该组字符串按每个字符串的长度，由小到大排序，按排序结果输出字符串。如果存在多个字符串长度相同，则按照原始输入顺序输出。
//
//输入格式:
//字符串的个数，以及该组字符串。每个字符串以‘\n’结束。如果输入字符串为“stop”，也结束输入.
//
//输出格式:
//可能有多组测试数据，对于每组数据，
//将输入的所有字符串按长度由小到大排序输出(如果有“stop”，不输出“stop”)。
//
//输入样例:
//4
//faeruhyytrjh tjytj
//hsrthts   hjnshtgfhs
//stop
//3
//htrskbns
//bsartanjsf tyjndyt
//nsr jj jtey
//输出样例:
//faeruhyytrjh tjytj
//hsrthts   hjnshtgfhs
//htrskbns
//nsr jj jtey
//bsartanjsf tyjndyt
//###提示：
//根据输入的字符串个数来动态分配存储空间（采用new()函数）。每个字符串会少于100个字符。
//测试数据有多组，注意使用while()循环输入。
//
//###来源：
//数据结构高分笔记

#include <iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int n,i;
    string h;
    vector<string>m(10);
    while(cin>>n)
    {
    m.resize(n);
    cin.ignore();
    for(i=0;m[i-1]!="stop"&&i<n;i++)
        getline(cin,m[i]);
    if(m[i-1]=="stop")i--;
    for(int j=0;j<i-1;j++)
        for(int k=0;k<i-j-1;k++)
            if(m[k].size()>m[k+1].size()){h=m[k];m[k]=m[k+1];m[k+1]=h;}
    for(int j=0;j<i;j++)
    {
        cout<<m[j]<<endl;
        m[j]="";
    }
    }


    return 0;
}
*/

/*(2)查找指定字符

//本题要求编写程序，从给定字符串中查找某指定的字符。
//
//输入格式：
//输入的第一行是一个待查找的字符。第二行是一个以回车结束的非空字符串（不超过80个字符）。
//
//输出格式：
//如果找到，在一行内按照格式“index = 下标”输出该字符在字符串中所对应的最大下标（下标从0开始）；否则输出"Not Found"。
//
//输入样例1：
//m
//programming
//输出样例1：
//index = 7
//输入样例2：
//a
//1234
//输出样例2：
//Not Found

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string n;
    char m;
    int i=0,k=-1;
    cin>>m;
    cin.ignore();
    getline(cin,n,'\n');
    while(n[i]!='\0')
    {
        if(n[i]==m)k=i;
        i++;
    }
    if(k==-1)cout<<"Not Found"<<endl;
    else cout<<"index = "<<k<<endl;

    return 0;
}
*/

/*(3)查找书籍

//给定n本书的名称和定价，本题要求编写程序，查找并输出其中定价最高和最低的书的名称和定价。
//
//输入格式:
//输入第一行给出正整数n（<10），随后给出n本书的信息。每本书在一行中给出书名，即长度不超过30的字符串，随后一行中给出正实数价格。题目保证没有同样价格的书。
//
//输出格式:
//在一行中按照“价格, 书名”的格式先后输出价格最高和最低的书。价格保留2位小数。
//
//输入样例:
//3
//Programming in C
//21.5
//Programming in VB
//18.5
//Programming in Delphi
//25.0
//输出样例:
//25.00, Programming in Delphi
//18.50, Programming in VB

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
struct book
{
    string name;
    double jg;
};
int main()
{
    int n;
    cin>>n;
    vector<book>m(n);
    for(int i=0;i<n;i++)
    {
        cin.ignore();
        getline(cin,m[i].name,'\n');
        cin>>m[i].jg;
    }
    cout<<setiosflags(ios::fixed)<<setprecision(2);
    double sum=0,k=0;
    for(int i=0;i<n;i++)
        if(sum<m[i].jg){sum = m[i].jg;k=i;}
    cout<<m[k].jg<<", "<<m[k].name<<endl;
    sum=m[0].jg,k=0;
    for(int i=0;i<n;i++)
        if(sum>m[i].jg){sum = m[i].jg;k=i;}
    cout<<m[k].jg<<", "<<m[k].name<<endl;

    return 0;
}
*/

/*(4)头插法创建单链表、遍历链表、删除链表

//输入一系列自然数（0和正整数），输入-1时表示输入结束。按照输入的顺序，用头插法建立单链表，并遍历所建立的单链表，输出这些数据。注意 -1 不加入链表。
//
//输入格式:
//第一行是一个正整数k，表示以下会有k组测试数据。
//
//每组测试数据是一系列以空格隔开的自然数（0和正整数）。数列末尾的 -1 表示本组测试数据结束。按照输入的顺序，用头插法建立单链表，并遍历所建立的单链表，输出这些数据。注意 -1 不加入链表。
//
//输出格式:
//对于每组测试数据，输出链表中各节点的数据域。每个数据后有一个空格。每组测试数据的输出占1行。
//
//输入样例:
//3
//1 2 3 4 5 -1
//30 20 10 -1
//4 2 2 1 1 2 0 2 -1
//
//输出样例:
//在这里给出相应的输出。例如：
//
//5 4 3 2 1
//10 20 30
//2 0 2 1 1 2 2 4

#include<iostream>
using namespace std;
struct list
{
    int sz;
    list*next=NULL;
};
int main()
{
    int n,k;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        list*head=NULL,*p;
        while(cin>>k,k!=-1)
        {
            list*node=new list;
            node->sz=k;
            node->next=head;
            head=node;
        }
        p=head;
        while(p!=NULL)
        {
            cout<<p->sz<<" ";
            p=p->next;
        }
        cout<<endl;
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

//输入2个整数，输出这两个数之间的素数
//
//输入两个3位正整数(大数可以是第1个，也可以是第2个），输出这两个数之间的所有素数，一行最多5个素数，数与数之间用“,”进行分隔
//
//输入样例1:
//101 151
//输出样例1:
//101,103,107,109,113
//127,131,137,139,149
//151
//输入样例2:
//122 121
//输出样例2:
//There is no prime number between 121 and 122 !

#include<iostream>
using namespace std;
int main()
{
    int n, m, h, k = 0;
    cin >> n >> m;
    if (n > m) { h = n; n = m; m = h; }
    for (int i = n; i <= m; i++)
    {
        bool p = 1;
        for (int j = 2; j <= i / 2; j++)
            if (i % j == 0) { p = 0; break; }
        if (p)
        {
            if (k % 5 == 0) { if (k != 0)cout << endl; }
            else cout << ",";
            cout << i;
            k++;
        }
    }
    if (k == 0)cout << "There is no prime number between " << n << "and " << m << " !" << endl;

    return 0;
}