/*(1)英文字母 - 《C++编程基础及应用》- 习题2-2

//在计算机内部，英文字母依ASCII码分别由连续的整数来表示。比如，大写的英文字母A的ASCII码值为65，B的码值为66，然后依次递增，Z的码值为90。
//
//请编程计算：
//
//从键盘读取大写字母Q（代号，其值由具体输入确定），请问Q所代表的大写字母是字母表中的第几个字母（从1开始计数，即A为第1个字母）？
//从键盘读取整数N，求字母表中的第N个字母（从1开始计数）是什么？
//
//输入格式:
//Q
//N
//
//说明：是一个字符的大写字母；N的取值范围为1~26。
//
//输出格式:
//请参考输出样例。
//
//输入样例:
//B
//3
//输出样例:
//2
//C

#include<iostream>
using namespace std;
int main()
{
    char n;
    int m;
    cin >> n >> m;
    n = n - 64;
    m = m + 64;

    cout << (int)n << endl << (char)m;

    return 0;
}
*/

/*(2)温度单位转换 - 《C++编程基础及应用》- 习题3-1

//从键盘读取华氏温度，转换成摄氏温度并输出，保留1位小数。
//转换公式为：c=5/9*(f-32), 其中，f为华氏温度，c为摄氏温度。
//
//输入格式:
//华氏温度
//
//输出格式:
//摄氏温度
//
//输入样例:
//100
//输出样例:
//37.8

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    float n;
    cin >> n;
    n = 5.0 / 9 * (n - 32);

    cout << setiosflags(ios::fixed) << setprecision(1) << n << endl;

    return 0;
}
*/

/*(3)分苹果 - 《C++编程基础及应用》- 习题3-2

//现有n个苹果，均分给5位同学，剩下的苹果交还老师。请编写程序，解决下述问题：
//
//每位同学能分得几个苹果？
//一共分出去多少个苹果？
//交还老师的苹果有几个？
//输入样例:
//17
//输出样例:
//Everyone have 3 apples.
//15 apples have been taken in total.
//returned 2 apples to the teacher.

#include<iostream>
using namespace std;
int main()
{
    int n, x, y, z;
    cin >> n;
    z = n % 5;
    y = n - z;
    x = n / 5;

    cout << "Everyone have " << x << " apples." << endl;
    cout << y << " apples have been taken in total." << endl;
    cout << "returned " << z << " apples to the teacher.";

    return 0;
}
*/

/*(4)绩点计算 - 《C++编程基础及应用》- 习题3-3

//某大学的GPA(绩点)计算规则如下：
//
//课程百分制成绩90分对应绩点4.0，超过90分的，按90分计；如不足90分，则课程绩点 = 4.0 * 分数/90。
//学生综合绩点按该生已修的各门课程绩点结合学分加权平均而得。
//现有步步同学入学后的已修课程（共5门）成绩表如下，请编程计算其GPA。
//
//输入格式:
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
//输出格式:
//请参考输出样例。其中，GPA值保留两位小数。
//
//输入样例:
//78 3
//91 5
//65 4
//95 3
//60 2
//输出样例:
//GPA:3.49

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n, m;
    int a[10];
    float x = 0, y = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> n >> m;
        a[i] = n;
        a[i + 5] = m;
        x += m;
    }
    for (int j = 0; j < 5; j++)
    {
        if (a[j] >= 90) { y += 4.0 * a[j + 5] / x; }
        else { y += 4.0 * a[j] / 90.0 * a[j + 5] / x; }
    }

    cout << "GPA:" << setiosflags(ios::fixed) << setprecision(2) << y << endl;

    return 0;
}
*/

//绩点计算 - 《C++编程基础及应用》- 习题3-3
//
//某大学的GPA(绩点)计算规则如下：
//
//课程百分制成绩90分对应绩点4.0，超过90分的，按90分计；如不足90分，则课程绩点 = 4.0 * 分数/90。
//学生综合绩点按该生已修的各门课程绩点结合学分加权平均而得。
//现有步步同学入学后的已修课程（共5门）成绩表如下，请编程计算其GPA。
//
//输入格式:
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
//输出格式:
//请参考输出样例。其中，GPA值保留两位小数。
//
//输入样例:
//78 3
//91 5
//65 4
//95 3
//60 2
//输出样例:
//GPA:3.49

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int x,y,z;
    cin>>x>>y>>z;
    x=x+y+z;

    cout<<x<<","<<setiosflags(ios::fixed)<<setprecision(2)<<x/3.0<<endl;

    return 0;
}
