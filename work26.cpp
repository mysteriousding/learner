/*(1)练习3-16：输出平年中月份的天数

//编写一个程序，输入一个整数表示月份（1-12），然后输出该月份在平年中的天数。输入的月份范围为1到12之间的整数，若输入无效，则输出输入错误。
//
//输入格式:
//输入一个整数m表示月份（1-12）
//
//输出格式:
//输出该月份在平年中的天数d
//
//输入样例:
//4
//输出样例:
//30

#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    switch(n)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:cout<<31<<endl;break;
        case 2:cout<<28<<endl;break;
        case 4:
        case 6:
        case 9:
        case 11:cout<<30<<endl;break;
        default :cout<<"输入错误"<<endl;
    }

    return 0;
}
*/

/*(2)案例3-11：使用switch完成成绩五等分

//根据百分制成绩，使用switch语句将成绩划分为五个等级。
//
//输入格式:
//一个整数，表示百分制成绩。
//
//输出格式:
//根据成绩划分的等级，输出相应的等级。如果输入成绩有误，则输出"输入成绩有误"。
//
//输入样例:
//85
//输出样例:
//B

#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n==100)n=99;
    n/=10;
    switch(n)
    {
        case 9:cout<<"A";break;
        case 8:cout<<"B";break;
        case 7:cout<<"C";break;
        case 6:cout<<"D";break;
        case 5:
        case 4:
        case 3:
        case 2:
        case 1:
        case 0:cout<<"E";break;
        default :cout<<"输入成绩有误";
    }
    cout<<endl;

    return 0;
}
*/

/*(3)练习3-15：使用switch语句的方式实现月份对应的季度

//输入一个月份（1到12之间的整数），使用switch语句输出对应的季度。
//
//输入格式:
//一个整数，表示月份。
//
//输出格式:
//一个字符串，表示对应的季度（"第一季度"、"第二季度"、"第三季度"、"第四季度"）。
//
//输入样例1:
//3
//输出样例1:
//第一季度
//输入样例2:
//15
//输出样例2:
//输入月份无效

#include<iostream>
using namespace std;
int main()
{
    float n;
    cin>>n;
    n=n/3.0+0.99;
    switch((int)n)
    {
        case 1:cout<<"第一季度"<<endl;break;
        case 2:cout<<"第二季度"<<endl;break;
        case 3:cout<<"第三季度"<<endl;break;
        case 4:cout<<"第四季度"<<endl;break;
        default :cout<<"输入月份无效"<<endl;
    }


    return 0;
}
*/

/*(4)综合3-4：以四舍五入的方式输出车费的整数部分

//某市出租车分为A、B、C三个档次。A档出租车起步价20元，超过3公里每公里按5元计费；B档出租车起步价15元，超过3公里每公里按4元计费；C档出租车起步价10元，超过3公里每公里按3元计费。编写一个程序，用户以字母的形式输入出租车档次，以浮点数形式输入乘坐里程，根据用户的输入，计算车费，并以四舍五入的方式输出车费的整数部分。
//
//输入格式:
//一个字符（A、B、C），表示出租车的档次，和一个浮点数，表示乘坐里程，以空格分隔。
//
//输出格式:
//一个整数，表示根据输入计算的车费的整数部分。
//
//输入样例:
//A 5.5
//输出样例:
//车费的整数部分：33

#include<iostream>
using namespace std;
int main()
{
    char n;
    float m;
    cin>>n>>m;
    cout<<"车费的整数部分：";
    switch(n)
    {
        case 'A':cout<<(int)(20.5+((m<3)?0:(m-3)*5));break;
        case 'B':cout<<(int)(15.5+((m<3)?0:(m-3)*4));break;
        case 'C':cout<<(int)(10.5+((m<3)?0:(m-3)*3));break;
    }
    cout<<endl;

    return 0;
}
*/

//查询课表，输入一个数字，查询当天的课表。
//
//要求输入一个整数，范围在1~5，星期一的课表有《C语言程序设计》， 星期二没课，星期三的课表是《数据结构》，星期四没课，星期五的课表有《python语言程序设计》。根据输入的数字输出对应的课程。如果不在此范围内，则输出 “输入数字需要在1~5之间”。
//
//输入格式:
//一个整数，例如3
//
//输出格式:
//输出《数据结构》
//
//输入样例:
//在这里给出一组输入。例如：
//
//2
//输出样例:
//在这里给出相应的输出。例如：
//
//没课

#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    switch (n)
    {
    case 1:cout << "《C语言程序设计》"; break;
    case 3:cout << "《数据结构》"; break;
    case 5:cout << "《python语言程序设计》"; break;
    case 2:
    case 4:cout << "没课"; break;
    default:cout << "输入数字需要在1~5之间";
    }
    cout << endl;

    return 0;
}