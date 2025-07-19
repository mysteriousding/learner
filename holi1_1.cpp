/*查找书籍(1)

//给定n本书的名称和定价，本题要求编写程序，查找并输出其中定价最高和最低的书的名称和定价。
//
//输入格式:
//输入第一行给出正整数n（<10），随后给出n本书的信息。
//每本书在一行中给出书名，即长度不超过30的字符串，随后一行中给出正实数价格。
//题目保证没有同样价格的书。
//
//输出格式:
//在一行中按照“价格, 书名”的格式先后输出价格最高和最低的书。
//价格保留2位小数。
//
//输入样例:
//3
//Programming in C
//21.5
//Programming in VB
//18.5
//Programming in Delphi
//25.0
//输出样例:
//25.00, Programming in Delphi
//18.50, Programming in VB

#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
using namespace std;
struct book
{
    double a;
    string b;
};
int main()
{
    int n, max = 0, min = 0;
    cin >> n;
    vector<book>x(n);
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        getline(cin, x[i].b);
        cin >> x[i].a;
    }
    for (int i = 1; i < n; i++)
        if (x[i].a > x[max].a)max = i;
        else if (x[i].a < x[min].a)min = i;
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << x[max].a << ", " << x[max].b << endl;
    cout << x[min].a << ", " << x[min].b << endl;

    return 0;
}
*/

/*逆序的三位数(2)

//程序每次读入一个正3位数，然后输出按位逆序的数字。
//注意：当输入的数字含有结尾的0时，输出不应带有前导的0。
//比如输入700，输出应该是7。
//
//输入格式：
//每个测试是一个3位的正整数。
//
//输出格式：
//输出按位逆序的数。
//
//输入样例：
//123
//输出样例：
//321
//鸣谢安阳师范学院软件学院李康康同学补充数据！

#include<iostream>
using namespace std;
int main()
{
    int n,a,b,c;
    cin>>n;
    a=n/100;
    b=n/10%10;
    c=n%10;
    cout<<c*100+b*10+a<<endl;

    return 0;
}
*/

/*两个有序链表序列的交集(3)

//已知两个非降序链表序列S1与S2，设计函数构造出S1与S2的交集新链表S3。
//
//输入格式:
//输入分两行，分别在每行给出由若干个正整数构成的非降序序列，用−1表示序列的结尾（−1不属于这个序列）。
//数字用空格间隔。
//
//输出格式:
//在一行中输出两个输入序列的交集序列，数字间用空格分开，结尾不能有多余空格；
//若新链表为空，输出NULL。
//
//输入样例:
//1 2 5 -1
//2 4 5 8 10 -1
//输出样例:
//2 5

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<vector<int>>a(3);
    int n;
    for(int i=0;i<2;i++)
    {    while(1)
        {
            cin>>n;
            if(n==-1)break;
            a[i].push_back(n);
        }
     sort(a[i].begin(),a[i].end());
    }
    for(int i=0,j=0;i<a[0].size()&&j<a[1].size();)
        if(a[0][i]==a[1][j])
        {
            a[2].push_back(a[0][i]);
            i++,j++;
        }
        else if(a[0][i]>a[1][j])j++;
        else i++;
    if(a[2].size())
        for(int i=0;i<a[2].size();i++)
        {
            if(i)cout<<" ";
            cout<<a[2][i];
        }
    else cout<<"NULL";
    cout<<endl;

    return 0;
}
*/

/*求e的近似值(4)

//自然常数 e 可以用级数 1+1/1!+1/2!+ ⋯ +1/n!+ ⋯ 来近似计算。
//本题要求对给定的非负整数 n，求该级数的前 n+1 项和。
//
//输入格式:
//输入第一行中给出非负整数 n（≤1000）。
//
//输出格式:
//在一行中输出部分和的值，保留小数点后八位。
//
//输入样例:
//10
//输出样例:
//2.71828180

#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
int main()
{
    int n,a=1;
    double num=1;
    cin>>n;
    if(n>12)n=12;
    for(int i=1;i<=n;i++)
    {
        a*=i;
        num+=1.0/a;
    }
    cout<<setiosflags(ios::fixed)<<setprecision(8)<<num<<endl;

    return 0;
}
*/

/*输出三角形字符阵列(5)

//本题要求编写程序，输出n行由大写字母A开始构成的三角形字符阵列。
//
//输入格式：
//输入在一行中给出一个正整数n（1≤n<7）。
//
//输出格式：
//输出n行由大写字母A开始构成的三角形字符阵列。
//格式见输出样例，其中每个字母后面都有一个空格。
//
//输入样例：
//4
//输出样例：
//A B C D
//E F G
//H I
//J

#include<iostream>
using namespace std;
int main()
{
    int n,a=0;
    cin>>n;
    for(int j=n;j>0;j--)
    {
        if(j!=n)cout<<endl;
        for(int i=0;i<j;i++)
            cout<<char('A'+a++)<<" ";;
    }

    return 0;
}
*/

//数组循环左移
//
//本题要求实现一个对数组进行循环左移的简单函数：
//一个数组a中存有n（>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向左移m（≥0）个位置，即将a中的数据由（a0 a1 ⋯ an−1 ）变换为（am ⋯ an−1 a0 a1 ⋯ am−1 ）（最前面的m个数循环移至最后面的m个位置）。
//如果还需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？
//
//输入格式:
//输入第1行给出正整数n（≤100）和整数m（≥0）；
// 第2行给出n个整数，其间以空格分隔。
//
//输出格式:
//在一行中输出循环左移m位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。
//
//输入样例：
//8 3
//1 2 3 4 5 6 7 8
//输出样例：
//4 5 6 7 8 1 2 3
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, m, h, k, d, t;
    cin >> n >> m;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    m %= n, d = m, t = n;
    while (d)
    {
        h = d;
        d = t % d;
        t = h;
    }
    for (int i = 0; i < t; i++)
    {
        k = i, h = a[i];
        while (1)
        {
            d = (k + m) % n;
            if (d == i)break;
            a[k] = a[d];
            k = d;
        }
        a[k] = h;
    }
    for (int i = 0; i < n; i++)
    {
        if (i)cout << " ";
        cout << a[i];
    }

    return 0;
}
