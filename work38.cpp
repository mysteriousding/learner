/*(6)学生信息的那些操作：（2）按学号，查个人

//有一学生成绩表，包括学号、姓名、3门课程成绩。请实现如下查找功能：输入一个学生的学号，输出该学生学号、姓名、3门课程成绩
//
//输入格式:
// 首先输入一个整数n(1<=n<=100)，表示学生人数；
//
//然后输入n行，每行包含一个学生的信息：学号（12位）、姓名（不含空格且不超过20位），以及3个整数，表示3门课成绩，数据之间用空格隔开。
//
//最后一行输入一个学号num
//
//输出格式:
//若学号num存在，输出该学生的学号、姓名、3门课程成绩；若该学号不存在，则输出Not Found。
//
//输入样例:
//在这里给出一组输入。例如：
//
//3
//202016040201 Zhangling 89 78 95
//202016040202 Wangli 85 87 99
//202016040203 Fangfang 85 68 76
//202016040201
//输出样例:
//在这里给出相应的输出。例如：
//
//202016040201 Zhangling 89 78 95

#include<iostream>
#include<string>
using namespace std;
struct stu
{
    string xh;
    string name;
    int sum[3];
    stu*next=NULL;
};
int main()
{
    int n;
    cin>>n;
    stu*head=NULL,*p=NULL;
    for(int i=0;i<n;i++)
    {
        stu*node=new stu;
        cin>>node->xh>>node->name>>node->sum[0]>>node->sum[1]>>node->sum[2];
        node->next=head;
        head=node;
    }
    bool u=1;
    string ss;
    cin>>ss;
    while(head!=NULL)
    {
        if(head->xh==ss)
        {
            cout<<head->xh<<" "<<head->name<<" "<<head->sum[0]<<" "<<head->sum[1]<<" "<<head->sum[2];
            u=0;
        }
        p=head;
        head=head->next;
        delete p;
    }
    if(u)cout<<"Not Found"<<endl;

    return 0;
}
*/

/*(7)学生信息的那些操作：（5）添加记录

//有一学生成绩表，包括学号、姓名、3门课程成绩。已知该成绩表按学号升序排序。请编程实现，添加一个新的学生信息，且使成绩表仍按学号有序；若待添加的学号与已有学号重复，则输出错误信息，拒绝添加。
//
//输入格式:
// 首先输入一个整数n(1<=n<=100)，表示学生人数；
//
//然后输入n行，每行包含一个学生的信息：学号（12位）、姓名（不含空格且不超过20位），以及3个整数，表示3门课成绩，数据之间用空格隔开。
//
//最后一行输入一个待添加的学生信息，包括学号、姓名和3门课成绩
//
//输出格式:
//若待添加的学号与已有学号重复，则输出只有一行“error!”；否则，输出n+1行，即添加后的成绩单信息。
//
//输入样例:
//在这里给出一组输入。例如：
//
//3
//202016040201 Zhangling 78 95 55
//202016040202 Wangli 87 99 88
//202016040204 Fangfang 68 76 75
//202016040203 Lilei 68 79 82
//输出样例:
//在这里给出相应的输出。例如：
//
//202016040201 Zhangling 78 95 55
//202016040202 Wangli 87 99 88
//202016040203 Lilei 68 79 82
//202016040204 Fangfang 68 76 75

#include<iostream>
#include<string>
using namespace std;
struct stu
{
    string xh;
    string name;
    int sum[3];
    stu*next=NULL;
};
int main()
{
    int n;
    cin>>n;
    stu*head=NULL,*p=NULL;
    bool u=1;
    for(int i=0;i<=n;i++)
    {
        stu*node=new stu;
        cin>>node->xh>>node->name;
        for(int j=0;j<3;j++)
            cin>>node->sum[j];
        if(head==NULL)head=node;
        else
        {
            if(node->xh<head->xh)
            {
                node->next=head;
                head=node;
            }
            else
            {
                p=head;
                while(p->next!=NULL)
                {
                    if(p->next->xh>node->xh)break;
                    p=p->next;
                }
                if(p->next==NULL)p->next=node;
                else
                {
                    if(node->xh==p->xh)u=0;
                    node->next=p->next;
                    p->next=node;
                }
            }
        }
    }
    while(head!=NULL)
    {
        if(u)
        {
            cout<<head->xh<<" "<<head->name;
        for(int j=0;j<3;j++)
            cout<<" "<<head->sum[j];
            cout<<endl;
        }
        p=head;
        head=head->next;
        delete p;
    }
    if(!u)cout<<"error!"<<endl;


    return 0;
}
*/

/*(8)学生信息的那些操作：（6） 删除记录

//有一学生成绩表，包括学号、姓名、3门课程成绩。请实现如下删除功能：输入一个学生的学号，删除该学生的所有信息。
//
//输入格式:
// 首先输入一个整数n(1<=n<=100)，表示学生人数；
//
//然后输入n行，每行包含一个学生的信息：学号（12位）、姓名（不含空格且不超过20位），以及3个整数，表示3门课成绩，数据之间用空格隔开。
//
//最后一行输入一个学号num。
//
//输出格式:
//若要删除的学号不存在，则输出error!；否则，输出删除该学生后的所有记录。
//
//输入样例:
//在这里给出一组输入。例如：
//
//3
//202016040201 Zhangling 78 95 55
//202016040202 Wangli 87 99 88
//202016040203 Fangfang 68 76 75
//202016040201
//输出样例:
//在这里给出相应的输出。例如：
//
//202016040202 Wangli 87 99 88
//202016040203 Fangfang 68 76 75

#include<iostream>
#include<string>
using namespace std;
struct stu
{
    string xh;
    string name;
    int sum[3];
    stu*next=NULL;
};
int main()
{
    int n;
    cin>>n;
    stu*head=NULL,*p=NULL;
    for(int i=0;i<n;i++)
    {
        stu*node=new stu;
        cin>>node->xh>>node->name;
        for(int j=0;j<3;j++)
            cin>>node->sum[j];
        if(head==NULL)p=head=node;
        else
        {
            p->next=node;
            p=p->next;
        }
    }
    string h;
    bool u=0;
    cin>>h;
    p=head;
    if(head->xh==h)
    {
        head=head->next;
        delete p;
        u=1;
    }
    else
        while(p->next!=NULL)
        {
            if(p->next->xh==h)
            {
                stu*k=p->next;
                p->next=p->next->next;
                delete k;
                u=1;
            }
            p=p->next;
        }
    while(head!=NULL)
    {
        if(u)
        {
            cout<<head->xh<<" "<<head->name;
            for(int j=0;j<3;j++)
                cout<<" "<<head->sum[j];
            cout<<endl;
        }
        p=head;
        head=head->next;
        delete p;
    }
    if(!u)cout<<"error!"<<endl;


    return 0;
}
*/

/*(9)学生信息的那些操作：（7）单科成绩排序

//有一学生成绩表，包括学号、姓名、3门课程成绩。请按要求排序输出：若输入1，则按第1门课成绩降序输出成绩表，若输入为i（1<=i<=3)，则按第i门课成绩降序输出成绩表。
//
//输入格式:
// 首先输入一个整数n(1<=n<=100)，表示学生人数；
//
//然后输入n行，每行包含一个学生的信息：学号（12位）、姓名（不含空格且不超过20位），以及3个整数，表示3门课成绩，数据之间用空格隔开。
//
//最后一行输入一个整数i，表示要求按第i门课成绩降序排序输出，若该门课成绩相同，则按学号升序。
//
//输出格式:
//输出按第i门课降序排序的结果，格式见样例。
//
//输入样例:
//在这里给出一组输入。例如：
//
//3
//202016040201 Zhangling 89 78 95
//202016040202 Wangli 85 87 99
//202016040203 Fangfang 85 68 76
//1
//输出样例:
//在这里给出相应的输出。例如：
//
//202016040201 Zhangling 89 78 95
//202016040202 Wangli 85 87 99
//202016040203 Fangfang 85 68 76

#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct stu
{
    string xh;
    string name;
    int sum[3];
    stu*next=NULL;
};
int main()
{
    int n;
    cin>>n;
    vector<stu*>m(n);
    stu*head=NULL,*p=NULL;
    for(int i=0;i<n;i++)
    {
        m[i]=new stu;
        cin>>m[i]->xh>>m[i]->name;
        for(int j=0;j<3;j++)
            cin>>m[i]->sum[j];
    }
    int k;
    stu*h=NULL;
    cin>>k;
    k--;
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(m[j]->sum[k]<m[j+1]->sum[k]||(m[j]->sum[k]==m[j+1]->sum[k]&&m[j]->xh>m[j+1]->xh))
            {
                h=m[j];
                m[j]=m[j+1];
                m[j+1]=h;
            }
    for(int i=0;i<n;i++)
    {
        if(i!=0)cout<<endl;
        cout<<m[i]->xh<<" "<<m[i]->name<<" ";
        for(int j=0;j<3;j++)
            cout<<m[i]->sum[j]<<" ";
        delete m[i];
    }


    return 0;
}
*/

//学生成绩的那些操作：（8）总成绩，排个序
//
//有一学生成绩表，包括学号、姓名、3门课程成绩。请按如下规则排序：按总成绩降序排序，若总成绩相同，则按姓名升序排序。
//
//输入格式:
// 首先输入一个整数n(1<=n<=100)，表示学生人数；
//
//然后输入n行，每行包含一个学生的信息：学号（12位）、姓名（不含空格且不超过20位），以及3个整数，表示3门课成绩，数据之间用空格隔开。
//
//输出格式:
//输出排序后的成绩单，格式见输出样例。
//
//输入样例:
//在这里给出一组输入。例如：
//
//3
//202016040201 Zhangling 89 78 95
//202016040202 Wangli 85 87 99
//202016040203 Fangfang 89 88 85
//输出样例:
//在这里给出相应的输出。例如：
//
//202016040202 Wangli 85 87 99 271
//202016040203 Fangfang 89 88 85 262
//202016040201 Zhangling 89 78 95 262

#include<iostream>
#include<string>
using namespace std;
struct stu
{
    string xh;
    string name;
    int sum[4]={0};
    stu*next=NULL;
};
int main()
{
    int n;
    cin>>n;
    stu*head=NULL,*p=NULL;
    for(int i=0;i<n;i++)
    {
        stu*node=new stu;
        cin>>node->xh>>node->name;
        for(int j=0;j<3;j++)
        {
            cin>>node->sum[j];
            node->sum[3]+=node->sum[j];
        }
        if(head==NULL)p=head=node;
        else
            if(node->sum[3]>head->sum[3]||(node->sum[3]==head->sum[3]&&node->name<head->name))
            {
                node->next=head;
                head=node;
            }
            else
            {
                p=head;
                bool u=1;
                while(p->next!=NULL)
                {
                    if(u&&(node->sum[3]>p->next->sum[3]||(node->sum[3]==p->next->sum[3]&&node->name<p->next->name)))
                    {
                        node->next=p->next;
                        p->next=node;
                        u=0;
                    }
                    p=p->next;
                }
                if(u)p->next=node;
            }
    }
    while(head!=NULL)
    {
        cout<<head->xh<<" "<<head->name;
        for(int j=0;j<4;j++)
            cout<<" "<<head->sum[j];
        cout<<endl;
        p=head;
        head=head->next;
        delete p;
    }

    return 0;
}