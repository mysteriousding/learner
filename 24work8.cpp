/*(36)数组指针作函数参数

//本题要求使用数组指针作函数参数，进行学生成绩统计。要求如下：
//输入m个学生（最多30人）n门课程（最多5门）的成绩，然后计算并打印每个学生各门课的总分和平均分。其中，m和n的值由用户从键盘输入。
//
//输入格式：
//学生个数m 课程数n
//学生1课程1分数 学生1课程2分数 ... 学生1课程n分数
//学生2课程1分数 学生2课程2分数 ... 学生2课程n分数
//...
//学生m课程1分数 学生m课程2分数 ... 学生m课程n分数
//输出格式:
//每个学生总分（整数） 平均分（实数，保留1位小数）
//输入样例:
//2 3
//61 62 70
//75 82 90
//输出样例:
//193 64.3
//247 82.3

#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
void gn(vector<vector<float>>&N,int m,int n);
int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<float>>N(m,vector<float>(n+2));
    gn(N,m,n);
    cout<<setiosflags(ios::fixed)<<setprecision(1);
    for(int i=0;i<m;i++)
        cout<<int(N[i][n])<<" "<<N[i][n+1]<<endl;


    return 0;
}
void gn(vector<vector<float>>&N,int m,int n)
{
    int sum;
    for(int i=0;i<m;i++)
    {
        sum=0;
        for(int j=0;j<n;j++)
        {
            cin>>N[i][j];
            sum+=N[i][j];
        }
        N[i][n]=sum;
        N[i][n+1]=sum/float(n);
    }
}
*/

/*(37)统计字符串中空格数

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
int main()
{
    string n;
    int m=0,i=0;
    getline(cin,n,'\n');
    while(n[i]!='\0')
        if(n[i++]==' ')m++;
    cout<<n<<"\n"<<m<<endl;

    return 0;
}
*/

/*(38)矩阵转置

//定义一个3X3的整形矩阵，函数void move(int *pointer)采用指针方式实现矩阵转置。
//
//
//输入格式：
//例如定义一个二维数组接受3X3的整形矩阵数据。
//
//int a[3][3]={1,2,3,4,5,6,7,8,9};
//
//输入样例:
//例如：
//
//1 2 3 4 5 6 7 8 9
//输出样例:
//例如：
//
//1 4 7
//2 5 8
//3 6 9

#include<iostream>
using namespace std;
int main()
{
    int N[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin>>N[j][i];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(j!=0)cout<<" ";
            cout<<N[i][j];
        }
        if(i!=3-1)cout<<endl;
    }

    return 0;
}
*/

/*(39)删除字符

//输入一个字符串和一个字符ch，将字符串中所有的ch字符删除后输出该字符串。要求用指针实现。
//要求定义和调用函数 delchar(char * s, char ch);
//
//输入格式:
//第一行输入一个字符。
//第二行输入一个字符串
//
//输出格式:
//输出删除后的字符串。
//
//输入样例:
//在这里给出一组输入。例如：
//
//o
//helloworld!
//输出样例:
//在这里给出相应的输出。例如：
//
//hellwrld!

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string n;
    char m;
    int i=0;
    cin>>m;
    cin.ignore();
    getline(cin,n,'\n');
    while(n[i]!='\0')
    {
        if(n[i]==m)n[i]='~';
        i++;
    }
    i=0;
    while(n[i]!='\0')
    {
        if(n[i]!='~')cout<<n[i];
        i++;
    }

    return 0;
}
*/

//成绩管理（六）
//
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
#include<string>
#include<vector>
using namespace std;
struct stu
{
    string name;
    int cj[3];
};
int main()
{
    int n;
    cin>>n;
    vector<stu>m(n);
    for(int i=0;i<n;i++)
    {
        cin>>m[i].name;
        for(int j=0;j<3;j++)
            cin>>m[i].cj[j];
    }
    int sum;
    for(int j=0;j<3;j++)
    {
        sum=0;
        for(int i=0;i<n;i++)
            if(sum<m[i].cj[j])sum = m[i].cj[j];
        for (int i=0;i<n;i++)
            if(m[i].cj[j]==sum)
            {
                cout<<m[i].name<<" "
                    <<m[i].cj[0]<<" "
                    <<m[i].cj[1]<<" "
                    <<m[i].cj[2]<<endl;
            }
    }

    return 0;
}