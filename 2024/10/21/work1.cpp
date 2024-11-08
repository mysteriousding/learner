/*(1)以四舍五入的方式输出车费的整数部分

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
    float m, w;4

    cin >> n >> m;
    if (m >= 3) { m -= 3; }
    else { m = 0; }
    if (n == 'A') { w = 20 + m * 5; }
    else if (n == 'B') { w = 15 + m * 4; }
    else { w = 10 + m * 3; }
    cout << "车费的整数部分：" << (int)(w + 0.5) << endl;

    return 0;
}
*/

/*(2)多分支结构编程

//按照考试分数分档，90-100为A，80-89为B，70-79为C，60-69为D，0-59为E。假设分数均为整数，跟输入的分数，输出分档结果。
//
//输入格式:
//输入0-100之间的整数
//
//输出格式:
//输出相应的分档结果,若输入0-100以外的数字，则输出error
//
//输入样例:
//在这里给出一组输入。例如：
//
//75
//输出样例:
//在这里给出相应的输出。例如：
//
//C

#include<iostream>
using namespace std;
int main()
{
    int a;
    cin>>a;
    a/=10;
    switch(a)
    {
        case 10:
        case 9 : cout<<"A\n";break;
        case 8 : cout<<"B\n";break;
        case 7 : cout<<"C\n";break;
        case 6 : cout<<"D\n";break;
        case 5 :
        case 4 :
        case 3 :
        case 2 :
        case 1 :
        case 0 : cout<<"E\n";break;
        default :cout<<"error\n";break;
    }

    return 0;
}
*/

/*(3)不同类型数据间的混合运算

//根据输入字母的大小写类型计算输出值。计算规则如下：
//如果输入字母为大写字母，先计算输入字母与大写字母A的差，再将差放大10倍。输出计算结果的整数部分；
//如果输入字母为小写字母，先计算输入字母与小写字母z的差，再将差缩小3倍。输出计算结果保留两位小数；
//
//例如：
//输入B，先计算B-A（等于1），再将差放大100倍（等于100）。输出10
//输入b，先计算b-z（等于-24），再将差缩小3倍（等于-8）。输出-8.00
//
//输入格式:
//输入大写或小写字母
//
//输出格式:
//输入计算结果
//
//输入样例1:
//B
//输出样例1:
//10
//输入样例2:
//b
//输出样例:2
//-8.00

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    char n;
    cin>>n;
    if(65<=n&&n<=90){cout<<((int)n-65)*10<<endl;}
       else{cout<<setiosflags(ios::fixed)<<setprecision(2)<<((float)n-122)/3<<endl;}

    return 0;
}
*/

/*(4)分段函数求值

//计算下面分段函数的值
//    { (x/3)+1,   x < -2
//y = { 2x+(1/3),  -2 <= x < 2
//    { (x/7)-1,   x >= 2
//
//输入变量x的值，然后输出对应的函数值y（输出4位小数）。
//
//输入格式:
//变量x的值。
//
//输出格式:
//对应的函数值y。
//
//输入样例:
//例如：
//
//3
//输出样例:
//-0.5714

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    float x,y;
    cin>>x;
    if(x<-2){y=x/3+1;}
       else if(-2<=x&&x<2){y=2*x+1/3.0;}
          else{y=x/7-1;}
    cout<<setiosflags(ios::fixed)<<setprecision(4);
    cout<<y<<endl;

    return 0;
}
*/

//绩点计算 - 《C++编程基础及应用》 - 习题3 - 3
//
//某大学的GPA(绩点)计算规则如下：
//
//课程百分制成绩90分对应绩点4.0，超过90分的，按90分计；如不足90分，则课程绩点 = 4.0 * 分数 / 90。
//学生综合绩点按该生已修的各门课程绩点结合学分加权平均而得。
//现有步步同学入学后的已修课程（共5门）成绩表如下，请编程计算其GPA。
//
//输入格式 :
//第1门课程百分制分数 学分
//
//第2门课程百分制分数 学分
//
//第3门课程分制分数 学分
//
//第4门课程百分制分数 学分
//
//第5门课程百分制分数 学分
//
//说明：百分制分数和学分均为整数。
//
//输出格式 :
//请参考输出样例。其中，GPA值保留两位小数。
//
//输入样例 :
//78 3
//91 5
//65 4
//95 3
//60 2
//输出样例 :
//GPA : 3.49

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    float n, m, m0 = 0, v = 0;
    float arr[10];
    for (int i = 0; i < 5; i++) 
    { 
        cin >> n >> m;
        m0 += m;
        arr[i] = n;
        arr[i + 5] = m;
    }
    for (int i = 0; i < 5; i++)
    {
        n = arr[i];
        m = arr[i + 5];
        cout << m << endl;
        if (n >= 90) { v += 4.0 * (m / m0); }
           else { v += (4.0 * n / 90.0)* (m / m0); }
        cout << v << endl;
    }

    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << "GPA:" << v << endl;

    return 0;
}
