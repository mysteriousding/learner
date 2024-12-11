/*(41)通讯录排序

//输入n个朋友的信息，包括姓名、生日、电话号码，本题要求编写程序，按照年龄从大到小的顺序依次输出通讯录。题目保证所有人的生日均不相同。
//
//输入格式:
//
//输入第一行给出正整数n（<10）。随后n行，每行按照“姓名 生日 电话号码”的格式给出一位朋友的信息，其中“姓名”是长度不超过10的英文字母组成的字符串，“生日”是yyyymmdd格式的日期，“电话号码”是不超过17位的数字及+、-组成的字符串。
//
//输出格式:
//
//按照年龄从大到小输出朋友的信息，格式同输出。
//
//输入样例:
//在这里给出一组输入。例如：
//
//3
//zhang 19850403 13912345678
//wang 19821020 +86-0571-88018448
//qian 19840619 13609876543
//输出样例:
//在这里给出相应的输出。例如：
//
//wang 19821020 +86-0571-88018448
//qian 19840619 13609876543
//zhang 19850403 13912345678

#include<iostream>
using namespace std;
struct stu
{
    string name;
    long sr;
    string dh;
    stu*next=NULL;
};
int main()
{
    int n;
    cin>>n;
    stu*head=NULL,*p;
    for(int i=0;i<n;i++)
    {
        stu*node=new stu;
        cin>>node->name
            >>node->sr
            >>node->dh;
        if(head==NULL)head=node;
        else
        {
            p=head;
            if(node->sr<head->sr)
            {
                node->next=head;
                head=node;
            }
            else
            {
                while(p->next!=NULL)
                {
                    if(node->sr<p->next->sr)break;
                    p=p->next;
                }
                node->next=p->next;
                p->next=node;
            }
        }
    }
    while(head!=NULL)
    {
        cout<<head->name<<" "
            <<head->sr<<" "
            <<head->dh<<endl;
        p=head;
        head=head->next;
        delete p;
    }

    return 0;
}
*/

/*(42)军事体能成绩统计（统计补考人员）

//某学员队军事体能考试结束后统计需要参加补考的学员。
//学员队人数不超过100人，每名学员的信息包括姓名（中间无空格）、学号、性别（M表示男，F表示女），引体向上/曲臂悬垂成绩（男生为引体向上、女生为曲臂悬垂）、蛇形跑成绩、3000米跑成绩、仰卧起坐成绩。
//输出需要补考的学员姓名、学号、性别，并输出需要补考的总人数，如果没有补考学员，输出没有需要补考的学员。注意：每一项60分为及格。
//提示：
//1.这里的冒号是中文。
//2.输入时候%c表示性别，要在输入的scanf里多加一个空格，否则%c会无条件接收空格当作输入。
//
//输入格式:
//学员人数
//
//姓名 学号 性别 引体向上/曲臂悬垂成绩 30*2蛇形跑成绩 3000米跑成绩  仰卧起坐成绩
//
//……
//
//输出格式:
//如果有学员需要补考，输出：
//需要补考的学员为：
//
//姓名 学号 性别
//
//……
//
//需要补考的学员数总计为：X人
//
//没有学员需要补考，输出：
//没有需要补考的学员
//
//输入样例1:
//3
//jim 2001 F 60 55 90 80
//tom 2002 M 70 80 60 60
//layri 2003 M 55 50 60 65
//输出样例1:
//需要补考的学员为：
//jim 2001 F
//layri 2003 M
//需要补考的学员数总计为：2
//
//输入样例2:
//3
//jim 2001 F 60 70 80 90
//Tom 2002 M 60 80 90 100
//bob 2003 M 70 90 65 90
//输出样例2:
//没有需要补考的学员

#include<iostream>
using namespace std;
struct stu
{
    string name;
    int xh;
    char xb;
    int cj[4];
    bool u=0;
    stu*next=NULL;
};
int main()
{
    int n,u0=1;
    cin>>n;
    stu*head=NULL,*p=head;
    for(int i=0;i<n;i++)
    {
        stu*node=new stu;
        cin>>node->name
            >>node->xh
            >>node->xb;
        for(int j=0;j<4;j++)
        {
            cin>>node->cj[j];
            if(node->cj[j]<60){node->u=1;u0=0;}
        }
        if(head==NULL)p=head=node;
        else
        {
            p->next=node;
            p=p->next;
        }
    }
    if(u0)cout<<"没有需要补考的学员"<<endl;
    else
    {
        int k=0;
        cout<<"需要补考的学员为："<<endl;
        while(head!=NULL)
        {
            if(head->u)
            {
                cout<<head->name<<" "
                <<head->xh<<" "
                <<head->xb<<endl;
                k++;
            }
            p=head;
            head=head->next;
            delete p;
        }
        cout<<"需要补考的学员数总计为："<<k<<endl;
    }

    return 0;
}
*/

/*(43)军事体能成绩统计（统计总成绩）

//体能考试结束后，输入n名男生(不超过40名)的姓名和军事体能成绩，包括引体向上、蛇形跑、3公里和仰卧起坐，输出每名学生的姓名和总成绩，并输出引体向上最高分学生姓名和成绩（如果成绩相同，输出按原先顺序排列的第一个最高分）。
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
using namespace std;
struct stu
{
    string name;
    int cj[5];
    stu*next=NULL;
};
int main()
{
    int n;
    cin>>n;
    stu*head=NULL,*p=head;
    int max=0;
    for(int i=0;i<n;i++)
    {
        stu*node=new stu;
        cin>>node->name;
        int sum=0;
        for(int j=0;j<4;j++)
        {
            cin>>node->cj[j];
            if(node->cj[0]>max)max=node->cj[0];
            sum+=node->cj[j];
        }
        node->cj[4]=sum;
        if(head==NULL)p=head=node;
        else
        {
            p->next=node;
            p=p->next;
        }
    }
    p=head;
    while(p!=NULL)
    {
        cout<<p->name<<":"
            <<p->cj[4]<<endl;
        p=p->next;
    }
    cout<<"引体向上最高分:";
    bool u=1;
    while(head!=NULL)
    {
        if(head->cj[0]==max&&u)
        {
            cout<<head->name<<" "
            <<head->cj[0]<<endl;
            u=0;
        }
        p=head;
        head=head->next;
        delete p;
    }


    return 0;
}
*/

/*(44)定义一个表示点坐标的结构体类型，实现下列功能。

//定义一个表示平面直角坐标系下点坐标的结构体类型，输入两个点的坐标，存放在所定义的结构体类型变量中，调用一个自定义函数计算并输出这两个点的中点坐标。
//
//输入格式:
//两个点的坐标。
//
//输出格式:
//中点坐标。
//
//输入样例:
//在这里给出一组输入。例如：
//
//(10.24,5.8)(-10.24,-5.8)
//输出样例:
//在这里给出相应的输出。例如：
//
//(0.00,0.00)

#include<iostream>
#include<iomanip>
using namespace std;
struct sum
{
    float x;
    float y;
}d1,d2;
int main()
{
    char d;
    cin>>d>>d1.x>>d>>d1.y>>d;
    cin>>d>>d2.x>>d>>d2.y>>d;
    cout<<setiosflags(ios::fixed)<<setprecision(2);
    cout<<"("<<(d1.x+d2.x)/2<<","<<(d1.y+d2.y)/2<<")"<<endl;

    return 0;
}
*/

//定义一个存放学生信息的结构体类型，实现下列功能。
//
//定义一个存放学生信息的结构体类型，学生信息包括：学号、姓名、性别、院系。要求输入5个学生的相关信息后，按照学号顺序输出这些学生的信息，然后输入院系名称，统计并输出该院学生人数。
//
//输入格式:
//5个学生信息和1个院系名称。
//
//输出格式:
//按学号排序输出5个学生信息，1个相应学院的学生人数。
//
//输入样例:
//在这里给出一组输入。例如：
//
//03 张三 男 计算机
//01 赵大 男 计算机
//02 钱二 女 机械
//05 王五 男 机械
//04 李四 女 土木
//计算机
//输出样例:
//在这里给出相应的输出。例如：
//
//01 赵大 男 计算机
//02 钱二 女 机械
//03 张三 男 计算机
//04 李四 女 土木
//05 王五 男 机械
//2

#include<iostream>
using namespace std;
struct stu
{
    string xh;
    string name;
    string xb;
    string xy;
    stu*next=NULL;
};
int main()
{
    stu*head=NULL,*p;
    for(int i=0;i<5;i++)
    {
        stu*node=new stu;
        cin>>node->xh
            >>node->name
            >>node->xb
            >>node->xy;
        if(head==NULL)head=node;
        else
        {
            p=head;
            if(node->xh<head->xh)
            {
                node->next=head;
                head=node;
            }
            else
            {
                while(p->next!=NULL)
                {
                    if(node->xh<p->next->xh)break;
                    p=p->next;
                }
                node->next=p->next;
                p->next=node;
            }
        }
    }
    p=head;
    while(p!=NULL)
    {
        cout<<p->xh<<" "
            <<p->name<<" "
            <<p->xb<<" "
            <<p->xy<<endl;
        p=p->next;
    }
    string k;
    int l=0;
    cin>>k;
    while(head!=NULL)
    {
        if(head->xy==k)l++;
        p=head;
        head=head->next;
        delete p;
    }
    cout<<l<<endl;

    return 0;
}