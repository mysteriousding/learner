/*(6)对角线 - 《C++编程基础及应用》- 习题3-6

//编写程序，实现下述功能：
//
//从键盘读入矩形的长，以厘米为单位，应为小数；
//从键盘读入矩形的宽，以厘米为单位，应为小数；
//使用勾股定理计算对角线的长度并输出，保留1位小数。
//
//输入格式:
//长
//宽
//
//输出格式:
//参见输出样例
//
//输入样例:
//5.1
//4.3
//输出样例:
//The diagonal legnth is: 6.7 cm.

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    float n,m;
    cin>>n>>m;
    n=pow(n*n+m*m,1.0/2);

    cout<<"The diagonal legnth is: "<<setiosflags(ios::fixed)<<setprecision(1)<<n<<" cm."<<endl;

    return 0;
}
*/

/*(7）编写一个程序，输入 3 个整数，输出他们的平均数。

//编写一个程序，输入 3 个整数，输出他们的平均数。。
//
//输入样例:
//输入 3 个整数。例如
//
//4 5 6
//输出样例:
//在这里给出相应的输出,结果不保留小数。例如：
//
//5

#include<iostream>
using namespace std;
int main()
{
    int n,m=0;
    for(int i=0;i<3;i++)
    {
        cin>>n;
        m+=n;
    }

    cout<<m/3;

    return 0;
}
*/

/*(8)转义序列

C++课程又讲到了字符串中的转义序列，和Java的规则很相似（喂，是Java学的C++，而C++又沿袭了C好吧？）这个转换感觉我也能实现，试试看。

仿照C++的定义对可能含有转义序列的字符串进行转换，输出转换后的结果。

只需实现：\n, \t, \?, \', \", \\即可。其他\a \b \f \v输出来也不容易看效果，咱就不考虑了。

另外\?好象很无聊，字符串里直接写?貌似也没问题。于是我上网搜了下，惊奇地发现古时候C/C++曾经支持过一种叫trigraph的特性，例如在当时??(三连会被替换成[字符，原因是某些国家的键盘缺少[ ] { } # \ ^ | ~等重要字符，好在现已弃用了这个特性，我长舒了一口气。

输入规格
每行一个待转换的字符串，请整行读取并处理，直到EOF为止。

输出规格
依次输出转换后的字符串。行数可能有变化（\n）。

样例输入
new\nline
T\tAB
\?\'\"\\
样例输出
new
line
T    AB
?'"\
样例解释
第1行的\n替换为换行符，使两个单词输出到了不同行。
第2行的\t替换为制表符，放在"T"与"AB"中间。
第3行是其他转义序列的连续替换
*/

/*(8)错
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string x, y, z, m;
    char k[10];
    int h;
    cin >> x >> y >> z;
    for (int j = 0; j < 3; j++)
    {
        if (j == 0) { m = x; }
        else if (j == 1) { m = y; }
        else { m = z; }
        h = m.size();
        for (int i = 0; i < h; i++)
        {
            k[i] = m[i];
            k[i + 1] = m[i + 1];
            if ((int)k[i] == 92)
            {
                if (k[i + 1] == 'n') { cout << "\n"; }
                if (k[i + 1] == 't') { cout << "\t"; }
                if (k[i + 1] == '?') { cout << "\?"; }
                if ((int)k[i + 1] == 39) { cout << "\'"; }
                if (k[i + 1] == '"') { cout << "\""; }
                if ((int)k[i + 1] == 92) { cout << "\\"; }
                if (k[i + 1] == 'a') { cout << "\a"; }
                if (k[i + 1] == 'b') { cout << "\b"; }
                if (k[i + 1] == 'f') { cout << "\f"; }
                if (k[i + 1] == 'v') { cout << "\v"; }
                if (k[i + 1] == 'r') { cout << "\r"; }
                if (k[i + 1] == '0') { cout << "\0"; }
                i += 1;
            }
            else { cout << k[i]; }
        }
        if (j != 2)cout << endl;
    }


    return 0;
}
*/

/*(8)错
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string x, y, z, m;
    char k[10];
    int i,h;
    cin >> x >> y >> z;
    for (int j = 0; j < 4; j++)
    {
        if (j == 0) { m = x; }
        else if (j == 1) { m = y; }
        else { m = z; }
        h = m.size();
        for (i = 0; i < h; i++)
        {
            k[i] = m[i];
            k[i + 1] = m[i + 1];
            if ((int)k[i] == 92)
            {
                if (k[i + 1] == 'n') { cout << "\n"; }
                if (k[i + 1] == 't') { cout << "\t"; }
                if (k[i + 1] == '?') { cout << "\?"; }
                if ((int)k[i + 1] == 39) { cout << "\'"; }
                if (k[i + 1] == '"') { cout << "\""; }
                if ((int)k[i + 1] == 92) { cout << "\\"; }
                if (k[i + 1] == 'a') { cout << "\a"; }
                if (k[i + 1] == 'b') { cout << "\b"; }
                if (k[i + 1] == 'f') { cout << "\f"; }
                if (k[i + 1] == 'v') { cout << "\v"; }
                if (k[i + 1] == 'r') { cout << "\r"; }
                if (k[i + 1] == '0') { cout << "\0"; }
                i += 1;
            }
            else { cout << k[i]; }
        }
        if (j != 2)cout << endl;
        if ((int)k[i] == '^' && k[i + 1] == 'z') { goto end; }
    }

end:

    return 0;
}
*/

/*(8)
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str(string x, int y);
    string n;
    int m, k = 0;
    do
    {
        getline(cin, n);
        if (cin.eof())k = 1;
        m = n.size();
        string a = str(n, m);
        cout << a;
        if (k == 0)cout << endl;
    } while (k == 0);

    return 0;
}

string str(string x, int y)
{
    string z;
    int i = 0;
    while (i < y)
    {
        if ((int)x[i] == 92)
        {
            i++;
            if (x[i] == 'n') { z += "\n"; }
            if (x[i] == 't') { z += "\t"; }
            if (x[i] == '?') { z += "\?"; }
            if ((int)x[i] == 39) { z += "\'"; }
            if (x[i] == '"') { z += "\""; }
            if ((int)x[i] == 92) { z += "\\"; }
            if (x[i] == 'a') { z += "\a"; }
            if (x[i] == 'b') { z += "\b"; }
            if (x[i] == 'f') { z += "\f"; }
            if (x[i] == 'v') { z += "\v"; }
            if (x[i] == 'r') { z += "\r"; }
        }
        else z += x[i];
        i++;
    }
    return z;
}
*/

/*(9)雪花ID（Snowflake ID）

每片雪花的形状都是独一无二的。

Snowflake ID是种用于分布式计算环境的全局唯一标识格式，最初由Twitter创造，后来被很多互联网大厂推广使用。
国内把生成这种ID的方法称为“雪花算法”，但老师答应过C++作业尽量不涉及算法，所以我们按照原创者的说法称为雪花ID。

Snowflake ID共64位，可用int64_t表示。
最高符号位总是0。
次高41-bit是时间戳，表示了自选定的时期以来的毫秒数。
次低10-bit是节点编号。那么系统内最多可有1024个节点用于生成雪花ID。
最低12-bit是节点生成ID的序列号。从0开始。于是每个节点每毫秒允许生成4096个ID。
系统整体每毫秒最多可生成四百万个唯一ID，每秒四十亿个。足够70亿蓝星人每两秒发一条推文，就算川普附身也不会这么快，所以目前是足足够用的。
本题可能在求职面试中遇到。

输入规格
首行是节点数量N（范围[0, 1024)）、起始时间T。
后续有若干指令：
sync T：全部节点：时间同步到T、序列号重置为0。
next M：获取节点M的下个ID。M范围在0 ~ N-1
无需考虑时间溢出情况。
输出规格
sync T输出ok
next M输出节点T在该时刻产生的雪花ID。
样例输入
5 0
next 0
next 0
sync 1
next 0
next 4
next 0
next 4
样例输出
0
1
ok
4194304
4210688
4194305
4210689
样例解释
第1行：5个节点，起始时间0。
第2行：节点0分配ID。时间=0、节点ID=0、序号=0，生成的ID为0。
第3行：节点0分配ID。时间=0、节点ID=0，序号=1，生成的ID为1。
第4行：时间同步到1。各节点的序列号全部重置为0。
第5行：节点0分配ID。时间=1、节点ID=0、序号=0。
第6行：节点4分配ID。时间=1、节点ID=4、序号=0。
第7行：节点0分配ID。时间=1、节点ID=0、序号=1。
第8行：节点4分配ID。时间=1、节点ID=4、序号=1。
*/

/*(9)错
#include<iostream>
#include<cstdint>
#include<chrono>
#include<thread>
#include<cmath>
#include<string>
using namespace std;
int main()
{
    int64_t num = 0, x = pow(2, 12), y = pow(2, 22);
    int n, m, b, i = 0, h = 0;
    int arr[5];
    arr[0] = 1024;
    cin >> n >> m;
    num += n * x;
    num += m * y;
    string a;
    while (1)
    {
        cin >> a >> b;
        for (int k = 0; k <= i; k++)
        {
            if (arr[k] == b)
            {
                num++;
                for (int j = 0; j <= i; j++)
                {
                    arr[j] = 1024;
                }
                i = 0;
            }
        }
        if (a == "next")
        {
            if (h != 0) { cout << endl; }
            cout << b * x + m * y + num % x;
        }
        if (a == "sync")
        {
            m = b;
            num = (b + num / y) * y;
            num = (num / x) * x;
            cout << endl << "ok";
            arr[i] = 1024;
        }
        i++;
        arr[i] = b;
        if (cin.peek() == istream::traits_type::eof()) { break; }
        h++;
    }

    return 0;
}
*/

//猴子吃桃 - 《C++编程基础及应用》- 习题2-3
//
//一只猴子在树上摘了若干个桃，当即吃了x%，觉得不过瘾，又多吃了一个；第二天它吃了剩下桃子的x%加一个；第三天它又吃了剩下桃子的x%加一个，此时，只剩下一个桃子。请编程求解：猴子第一天从树上摘得多少个桃子？
//
//【解题提示】
//
//1). 使用倒推法，第3天剩余桃数为1;
//
//2). 猴子吐出了最后吃的那个桃，1+1=2，2即为第3天吃桃前全部桃数的(100-x)%，由此推导出第3天吃桃前的桃数；
//
//3). 同理，第3天吃桃前的桃数加1，再除以(100-x)%，即为第2天吃桃前的桃数。
//
//4). 同理，第2天的桃数加1，再除以(100-x)%，即为第1天摘得的桃数。
//
//输入格式:
//x
//
//说明：x为整数且其值可确保第1天的桃数为整数。
//
//输出格式:
//猴子第1天摘得y个桃.
//
//说明：y是整数。
//
//输入样例:
//50
//输出样例:
//The monkey taken 22 peaches at the first day.

#include<iostream>
using namespace std;
int main()
{
    int x, y = 1;
    cin >> x;
    for (int i = 1; i <= 3; i++)
    {
        y = (y + 1) * 100 / (100 - x);
    }

    cout << "The monkey taken " << y << " peaches at the first day." << endl;

    return 0;
}
