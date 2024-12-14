/*(1)部分排序

//对于一组数据，我们可以只对原先处在中间位置的那些元素进行排序。
//
//输入格式:
//在一行内输入n r a1 a2 ... an
//
// 其中，不大于200的正整数n表示该组数据的个数；不大于200的非负整数r表示该组数据两端各自留有r个数不参与排序，若r+r>=n，则该组数据无需排序。
//
// 整数a1 a2 ... an是该组的n个数据，且都在8位以内。
//
//输出格式:
//排序之后的序列，元素之间用一个空格间隔，最后一个元素之后不加空格。
//
//输入样例:
//5 1 6 5 4 3 2
//输出样例:
//6 3 4 5 2

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,r;
    cin>>n>>r;
    vector<long long>m(n);
     for(int i=0;i<n;i++)
        cin>>m[i];
    if(r*2<n)
    {
        // for(int i=r;i<n-r-1;i++)   //错误
        // {
        //     long long sum=m[i],k=i;
        //     for(int j=i;j<n-i;j++)
        //         if(sum>m[j]){sum=m[j];k=j;}
        //     m[k]=m[i];
        //     m[i]=sum;
        // }


        // for(int i=r;i<n-r-1;i++)   //冒泡
        // {
        //     long long sum=m[i];
        //     for(int j=r;j<n-i-1;j++)
        //         if(m[j]>m[j+1]){sum=m[j];m[j]=m[j+1];m[j+1]=sum;}
        // }

        for(int i=r;i<n-r-1;i++)   //选择
        {
            long long sum=m[i],k=i;
            for(int j=i;j<n-r;j++)
                if(sum>m[j]){sum=m[j];k=j;}
            m[k]=m[i];
            m[i]=sum;
        }
    }
    for(int j=0;j<n;j++)
    {
        if(j!=0)cout<<" ";
        cout<<m[j];
    }
    cout<<endl;

    return 0;
}
*/

/*(2)h0351. 一般排序

//给定你一个长度为 n的整数数列，请你对这个数列按照从小到大进行排序，并将排好序的数列按顺序输出。
//
//输入格式:
//输入共两行，第一行包含整数 n（1≤n≤100000）。
//
//第二行包含 n个整数（所有整数均在 1∼10^9 范围内），表示整个数列。
//
//输出格式:
//输出共一行，包含 n个整数，表示排好序的数列。
//
//输入样例:
//在这里给出一组输入。例如：
//
//5
//3 1 2 4 5
//输出样例:
//在这里给出相应的输出。例如：
//
//1 2 3 4 5

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    vector<long long>m(n);
    for(long long i=0;i<n;i++)
        cin>>m[i];
    for(long long i=0;i<n;i++)
    {
        long long sum=m[i],k=i;
        for(long long j=i;j<n;j++)
            if(sum>m[j]){sum=m[j];k=j;}
        m[k]=m[i];
        m[i]=sum;
    }
    for(long long j=0;j<n;j++)
    {
        if(j!=0)cout<<" ";
        cout<<m[j];
    }
    cout<<endl;

    return 0;
}
*/

/*(3)通讯录排序

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

/*(4)判断能否形成等差数列

//作者 yzx
//单位 兰州交通大学
//给你一个数字数组 arr 。
//
//如果一个数列中，任意相邻两项的差总等于同一个常数，那么这个数列就称为 等差数列 。
//
//如果可以重新排列数组形成等差数列，请返回 true ，并输出公差；否则，返回 false 。
//
//当返回false时，默认公差为0.
//
//要求用函数进行判断，否则不得分。
//
//输入格式:
//第一行输入数组长度。
//
//第二行输入数组元素。
//
//样例解释：对数组重新排序得到 [1,3,5] 或者 [5,3,1] (升序即可)，任意相邻两项的差分别为 2 或 -2 ，可以形成等差数列。
//
//输出格式:
//true,2。
//
//输入样例:
//在这里给出一组输入。例如：
//
//3
//3 5 1
//输出样例:
//在这里给出相应的输出。例如：
//
//true,2

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    vector<long long>m(n);
    for(long long i=0;i<n;i++)
        cin>>m[i];
    for(long long i=0;i<n;i++)
    {
        long long sum=m[i],k=i;
        for(long long j=i;j<n;j++)
            if(sum>m[j]){sum=m[j];k=j;}
        m[k]=m[i];
        m[i]=sum;
    }
    int d=m[1]-m[0],u=1;
    for(long long j=0;j<n-1;j++)
        if(m[j+1]-m[j]!=d){cout<<"false,0";u=0;break;}

    if(u)cout<<"true,"<<d<<endl;

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
