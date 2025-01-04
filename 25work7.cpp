/*(21)分段函数

//输入x，输出相应的y值。要求定义和调用函数fun，实现下面的分段函数。
//
//  ⎧−x	 x<0
//y=⎨ x	 x>0
//  ⎩ 0	 x=0
//
//输入样例:
//例如：
//
//-5
//输出样例:
//例如：
//
//y = 5

#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n<0)n=-1*n;
    cout<<"y = "<<n<<endl;

    return 0;
}
*/

/*(22)统计字符串中空格数

//输入一个字符串，统计其空格的数量。
//要求编写函数
//
//int count_sp(const char *s);
//统计并返回字符串 s 中空格的数量。
//
//输入格式:
//在一行中输入一个长度不超过 80 的字符串，其中可能含有多个空格。
//
//输出格式:
//输出共 2 行：第一行打印输入的原字符串，第二行是该字符串中空格的数量。
//
//输入样例:
//在这里给出一组输入。例如：
//
//Hello world
//
//输出样例:
//在这里给出相应的输出。例如：
//
//Hello world
//1
//
//程序样例
//#include<stdio.h>
//#define STRLEN 80
//
//// 返回字符串 s 中空格的数量
//int count_sp(const char *s);
//
//int main (void)
//{
//    char s[STRLEN + 1];
//    // 输入字符串
//    gets(s);
//    // 输出字符串及其空格数
//    printf("%s\n%d\n", s, count_sp(s));
//    return 0;
//}
//
///***  在此实现 count_sp 函数 ***

#include<iostream>
#include<string>
using namespace std;
int count_sp(string s);
int main()
{
    string s;
    getline(cin,s);
    cout<<s<<"\n"<<count_sp(s)<<endl;

    return 0;
}
int count_sp(string s)
{
    int i=0,k=0;
    while(s[i]!='\0')
        if(s[i++]==' ')k++;
    return k;
}
*/

/*(23)成绩管理（六）

//有 n 位学生，一个学生信息对应四种数据：姓名、语文成绩、数学成绩和英语成绩，整数。请使用结构体数组对以上数据进行存储，并输出每门科目成绩最高的学生信息。
//
//输入格式:
//第一行输入一个偶数 n(1≤n≤10)。
//接下来输入 n 行，每行包含一个字符串 str，三个非负整数 a,b,c，用空格分隔。(3≤str.length≤10, 0≤a,b,c≤100)。
//
//输出格式:
//输出每门科目中最高成绩学生的完整信息。（若出现多个最高成绩学生，按照输入先后一并输出）
//
//输入样例:
//input01:
//
//4
//bob 60 70 80
//alice 70 80 90
//wade 90 90 70
//hali 89 78 67
//输出样例:
//output01:
//
//wade 90 90 70
//wade 90 90 70
//alice 70 80 90

#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct stu
{
    string name;
    int cj[3]={0};
};
int main()
{
    int n;
    cin>>n;
    vector<stu>m(n+1);
    for(int i=0;i<n;i++)
    {
        cin>>m[i].name;
        for(int j=0;j<3;j++)
        {
            cin>>m[i].cj[j];
            if(m[n].cj[j]<m[i].cj[j])
                m[n].cj[j]=m[i].cj[j];
        }
    }
    for(int i=0;i<3;i++)
        for(int j=0;j<n;j++)
            if(m[j].cj[i]==m[n].cj[i])
            {
                cout<<m[j].name<<" ";
                for(int k=0;k<3;k++)
                {
                    if(k!=0)cout<<" ";
                    cout<<m[j].cj[k];
                }
                cout<<endl;
            }

    return 0;
}
*/

/*(24)军事体能成绩统计（统计总成绩）

//体能考试结束后，输入n名男生(不超过40名)的姓名和军事体能成绩，包括引体向上、蛇形跑、3公里和仰卧起坐，
//输出每名学生的姓名和总成绩，并输出引体向上最高分学生姓名和成绩（如果成绩相同，输出按原先顺序排列的第一个最高分）。
//
//输入格式:
//人数
//
//姓名1 引体向上成绩  蛇形跑成绩 3公里成绩 仰卧起坐成绩
//姓名2 引体向上成绩  蛇形跑成绩 3公里成绩 仰卧起坐成绩
//
//……
//
//输出格式:
//姓名1:总成绩
//
//姓名2:总成绩
//
//……
//
//引体向上最高分:姓名 成绩
//
//输入样例:
//4
//张三 60 70 80 90
//李四 80 88 98 90
//王五 58 70 70 89
//朱六 70 80 88 94
//
//输出样例:
//张三:300
//李四:356
//王五:287
//朱六:332
//引体向上最高分:李四 80

#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct stu
{
    string name;
    int cj[5]={0};
};
int main()
{
    int n,max=0,k=0;
    cin>>n;
    vector<stu>m(n);
    for(int i=0;i<n;i++)
    {
        cin>>m[i].name;
        for(int j=0;j<4;j++)
        {
            cin>>m[i].cj[j];
            m[i].cj[4]+=m[i].cj[j];
            if(j==0)
                if(max<m[i].cj[0])
                    max=m[i].cj[0],k=i;
        }
    }
    for(int j=0;j<n;j++)
        cout<<m[j].name<<":"<<m[j].cj[4]<<endl;
    cout<<"引体向上最高分:"<<m[k].name<<" "<<m[k].cj[0]<<endl;

    return 0;
}
*/

//单向链表的创建与输出
//
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
//
//输入格式:
//第一行：从键盘输入n的值
//第二行： 从键盘输入n干个正整数（空格分隔）
//输出格式:
//依次输出链表中各个节点的数据元素值，元素间以->分隔。
//如果链表为空，则输出NULL。
//输入样例:
//5
//1 3 5 7 9
//
//输出样例:
//1->3->5->7->9
//
//输入样例:
//0
//
//输出样例:
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
    int   n;
    Link  head;
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
        Link node=new struct link;
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
    int u=0;
    if(head==NULL)printf("NULL\n");
    else
        while(head!=NULL)
        {
            if(u)printf("->");
            printf("%d",head->data);
            u=1;
            p=head;
            head=head->next;
            delete p;
        }
}