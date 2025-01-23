/*(1)阅览室

//天梯图书阅览室请你编写一个简单的图书借阅统计程序。
//当读者借书时，管理员输入书号并按下S键，程序开始计时；
//当读者还书时，管理员输入书号并按下E键，程序结束计时。
//书号为不超过1000的正整数。
//当管理员将0作为书号输入时，表示一天工作结束，你的程序应输出当天的读者借书次数和平均阅读时间。
//
//注意：由于线路偶尔会有故障，可能出现不完整的纪录，即只有S没有E，或者只有E没有S的纪录，系统应能自动忽略这种无效纪录。
//另外，题目保证书号是书的唯一标识，同一本书在任何时间区间内只可能被一位读者借阅。
//
//输入格式：
//输入在第一行给出一个正整数N（≤10），随后给出N天的纪录。
//每天的纪录由若干次借阅操作组成，每次操作占一行，格式为：
//
//书号（[1, 1000]内的整数） 键值（S或E） 发生时间（hh:mm，其中hh是[0,23]内的整数，mm是[0, 59]内整数）
//
//每一天的纪录保证按时间递增的顺序给出。
//
//输出格式：
//对每天的纪录，在一行中输出当天的读者借书次数和平均阅读时间（以分钟为单位的精确到个位的整数时间）。
//
//输入样例：
//3
//1 S 08:10
//2 S 08:35
//1 E 10:00
//2 E 13:16
//0 S 17:00
//0 S 17:00
//3 E 08:10
//1 S 08:20
//2 S 09:00
//1 E 09:20
//0 E 17:00
//输出样例：
//2 196
//0 0
//1 60

#include<iostream>
using namespace std;
struct Time
{
    int s;
    int f;
    friend istream& operator>>(istream& in,Time& T);
    int operator-(Time& b)
    {
        int c;
        if(b.f>f)c=f+60-b.f,s--;
        else c=f-b.f;
        c+=(s-b.s)*60;
        return c;
    }
};
istream& operator>>(istream& in,Time& T)
{
    char o;
    in>>T.s>>o>>T.f;
    return in;
}
struct book
{
    bool l=0;
    Time T[2];
    int jian()
    {
        return T[1]-T[0];
    }
}B[1001];
int main()
{
    int n,x,num=0,sum=0;
    char y;
    cin>>n;
    while(n)
    {
        cin>>x>>y;
        if(x==0)
        {
            for(int i=1;i<=1000;i++)
                B[i].l=0;
            if(num!=0)sum=sum*1.0/num+0.5;
            cout<<num<<" "<<sum<<endl;
            num=sum=0,n--;
            cin>>B[0].T[0];
            continue;
        }
        if(y=='S'&&!B[x].l)
        {
            B[x].l=1;
            cin>>B[x].T[0];
        }
        else
        {
            cin>>B[x].T[1];
            if(B[x].l)
            {
                B[x].l=0;
                num++;
                sum+=B[x].jian();
            }
        }
    }

    return 0;
}
*/

/*(2)求前缀表达式的值

//算术表达式有前缀表示法、中缀表示法和后缀表示法等形式。
//前缀表达式指二元运算符位于两个运算数之前，例如2+3*(7-4)+8/4的前缀表达式是：+ + 2 * 3 - 7 4 / 8 4。
//请设计程序计算前缀表达式的结果值。
//
//输入格式:
//输入在一行内给出不超过30个字符的前缀表达式，只包含+、-、*、/以及运算数，不同对象（运算数、运算符号）之间以空格分隔。
//
//输出格式:
//输出前缀表达式的运算结果，保留小数点后1位，或错误信息ERROR。
//
//输入样例:
//+ + 2 * 3 - 7 4 / 8 4
//输出样例:
//13.0

#include<iostream>
#include<iomanip>
#include<string>
#include<stack>
using namespace std;
int main()
{
    string x;
    double y,z;
    stack<string>n;
    stack<double>m;
    while(cin>>x)
        n.push(x);
    while(!n.empty())
    {
        x=n.top();
        n.pop();
        if(x[0]>='0'&&x[0]<='9'||x[1]>='0'&&x[1]<='9')
        {
            y=stod(x);
            m.push(y);
        }
        else
        {
            y=m.top();
            m.pop();
            z=m.top();
            m.pop();
            switch(x[0])
            {
                case '+':
                    y+=z;break;
                case '-':
                    y-=z;break;
                case '*':
                    y*=z;break;
                case '/':
                    if(z!=0)y/=z;
                    else
                    {
                        cout<<"ERROR"<<endl;
                        return 0;
                    }
                default:;
            }
            m.push(y);
        }
    }
    cout<<setiosflags(ios::fixed)<<setprecision(1);
    y=m.top();m.pop();
    cout<<y<<endl;

    return 0;
}
*/

/*(3)家庭房产

//给定每个人的家庭成员和其自己名下的房产，请你统计出每个家庭的人口数、人均房产面积及房产套数。
//
//输入格式：
//输入第一行给出一个正整数N（≤1000），随后N行，每行按下列格式给出一个人的房产：
//
//编号 父 母 k 孩子1 ... 孩子k 房产套数 总面积
//其中编号是每个人独有的一个4位数的编号；
//父和母分别是该编号对应的这个人的父母的编号（如果已经过世，则显示-1）；
//k（0≤k≤5）是该人的子女的个数；孩子i是其子女的编号。
//
//输出格式：
//首先在第一行输出家庭个数（所有有亲属关系的人都属于同一个家庭）。
//随后按下列格式输出每个家庭的信息：
//
//家庭成员的最小编号 家庭人口数 人均房产套数 人均房产面积
//其中人均值要求保留小数点后3位。
//家庭信息首先按人均面积降序输出，若有并列，则按成员编号的升序输出。
//
//输入样例：
//10
//6666 5551 5552 1 7777 1 100
//1234 5678 9012 1 0002 2 300
//8888 -1 -1 0 1 1000
//2468 0001 0004 1 2222 1 500
//7777 6666 -1 0 2 300
//3721 -1 -1 1 2333 2 150
//9012 -1 -1 3 1236 1235 1234 1 100
//1235 5678 9012 0 1 50
//2222 1236 2468 2 6661 6662 1 300
//2333 -1 3721 3 6661 6662 6663 1 100
//输出样例：
//3
//8888 1 1.000 1000.000
//0001 15 0.600 100.000
//5551 4 0.750 100.000


*/
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
struct man
{
    string h[8];
    int k;
    int f;
    int s;
    int p;
    vector<string>d;
    friend istream& operator>>(istream& in, man& r);
};
istream& operator>>(istream& in, man& r)
{
    int x = 2, y = 0;
    in >> r.h[y++];
    in >> r.h[y];
    if (r.h[y] != "-1")y++, x--;
    in >> r.h[y];
    if (r.h[y] != "-1")y++, x--;

    in >> r.k;
    r.k += y;
    for (int i = y; i < r.k; i++)
        in >> r.h[i];
    sort(r.h, r.h + r.k);
    in >> r.f >> r.s;
    return in;
}
struct jia
{
    string min = "9999";
    int shu = 0;
    vector<string>d;
    double f = 0;
    double s = 0;
};
ostream& operator<<(ostream& out, jia& r)
{
    out << r.min << " " << r.shu << " " << r.f << " " << r.s;
    return out;
}
bool pd(man& a, man& b)
{
    return a.p < b.p;
}
bool pd2(jia& x, jia& y)
{
    if (fabs(x.s - y.s) < 1e-3)return x.min < y.min;
    else return x.s > y.s;
}
int main()
{
    int n, l;
    bool u;
    cin >> n;
    vector<man>m(n);
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
        m[i].p = i;
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (m[i].p != m[j].p)
            {
                u = 0;
                for (int a = 0; a < m[i].k; a++)
                {
                    for (int b = 0; b < m[j].k; b++)
                    {
                        if (m[i].h[a] < m[j].h[b])break;
                        if (m[i].h[a] == m[j].h[b])
                        {
                            u = 1;
                            m[i].d.push_back(m[i].h[a]);
                            m[j].d.push_back(m[j].h[b]);
                        }
                    }
                }
                if (u)
                {
                    l = m[j].p;
                    for (int c = 0; c < n; c++)
                        if (m[c].p == l)
                            m[c].p = m[i].p;
                }
            }
    sort(m.begin(), m.end(), pd);
    l = m[0].p;
    int num = 1;
    vector<jia>v(n / 2);
    for (int i = 0; i < n; i++)
    {
        if (l != m[i].p)
            num++, l = m[i].p;
        for (int j = 0; j < m[i].k; j++)
            if (v[num - 1].min > m[i].h[j])
                v[num - 1].min = m[i].h[j];
        v[num - 1].shu += m[i].k;
        v[num - 1].d.insert(v[num - 1].d.end(), m[i].d.begin(), m[i].d.end());
        v[num - 1].f += m[i].f;
        v[num - 1].s += m[i].s;
    }
    int sum;
    string f;
    for (int i = 0; i < num; i++)
    {
        sort(v[i].d.begin(), v[i].d.end());
        if (!v[i].d.empty())
        {
            sum = 1, f = v[i].d[0];
            for (size_t j = 0; j < v[i].d.size(); j++)
                if (f != v[i].d[j])
                    sum++, f = v[i].d[j];
            v[i].shu -= v[i].d.size() - sum;
        }
        v[i].f /= v[i].shu, v[i].s /= v[i].shu;
    }
    sort(v.begin(), v.begin() + num, pd2);
    cout << num << endl;
    cout << setiosflags(ios::fixed) << setprecision(3);
    for (int i = 0; i < num; i++)
        cout << v[i] << endl;

    return 0;
}
