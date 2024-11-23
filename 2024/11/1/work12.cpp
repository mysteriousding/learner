/*(36)定义一个时间类

定义一个时间类Time，能提供和设置由时、分、秒组成的时间，并编写应用程序，定义时间对象，设置时间和输出该对象提供的时间。

输入格式:
以24h制，依次输入Time所需的时、分、秒，中间以空格间隔

输出格式:
以24h制，依次输出Time时、分、秒，中间已‘-’间隔，小于10的数字前面补‘0’

输入样例:
在这里给出一组输入。例如：

12 6 48
8 12 23
输出样例:
在这里给出相应的输出。例如：

08-23-11
12-09-08
20-11-09
*/


/*(37)菲姐游泳 - 《C++编程基础及应用》- 习题3-5

//游泳奥运冠军菲姐刻苦训练，从早上a时b分开始下水训练，直到当天的c时d分结束。请编程计算：菲姐当天一共训练多少小时多少分钟？
//
//输入格式:
//一行之内输入以空格分隔的4个非负整数，分别对应a,b,c,d。其中，0 ≤a<c ≤24；b和d均不大于60。
//
//输出格式:
//h:m。其中，整数h表示小时数，整数m表示分钟数,m应小于60。
//
//输入样例:
//6 30 23 20
//输出样例:
//16:50

#include<iostream>
using namespace std;
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (d >= b)
    {
        a = c - a;
        b = d - b;
    }
    else
    {
        a = c - 1 - a;
        b = d + 60 - b;
    }

    cout << a << ":" << b << endl;

    return 0;
}
*/ 

/*(38)约瑟夫问题

//n 个人围成一圈，从第一个人开始报数,数到 m 的人出列，再由下一个人重新从 1开始报数，数到 m的人再出圈，依次类推，直到所有的人都出圈，请输出依次出圈人的编号。
//备注：1≤m,n≤100
//
//输入格式:
//输入两个整数 n,m。
//
//输出格式:
//输出一行 n个整数，按顺序输出每个出圈人的编号。
//
//输入样例:
//在这里给出一组输入。例如：
//
//10 3
//输出样例:
//在这里给出相应的输出。例如：
//
//3 6 9 2 7 1 8 5 10 4

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, m, n0;
    int p1, p2, k;
    p1 = p2 = k = 0;
    cin >> n >> m;
    n0 = n + 1;
    vector<int>a(n0);
    for (int i = 0; i < n0; i++) { a[i] = i; }
    while (1)
    {
        if (k == n0)k = 1;

        if (a[k] != 0)p1++;

        if (p1 == m)
        {
            if (p2 != 0)cout << " ";
            cout << k;
            p1 = 0; p2++;
            a[k] = 0;
        }
        k++;
        if (p2 == n)break;
    }

    return 0;
*/

/*(39）二分查找

//对于输入的n个整数，先进行升序排序，然后进行二分查找。
//
//输入格式:
//测试数据有多组，处理到文件尾。每组测试数据第一行输入一个整数n(1≤n≤100)，第二行输入n个各不相同的待排序的整数，第三行是查询次数m（1≤m≤100），第四行输入m个待查找的整数。
//
//输出格式:
//对于每组测试，分2行输出，第一行是排序后的升序的结果，每两个数据之间留一个空格；第二行是查找的结果，若找到则输出排序后元素的位置（从1开始，每两个数据之间留一个空格），否则输出0。
//
//输入样例:
//9
//4 7 2 1 8 5 9 3 6
//5
//10 9 8 7 -1
//输出样例:
//1 2 3 4 5 6 7 8 9
//0 9 8 7 0

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, h;
    while (cin >> n)
    {
        vector<int>m(n);
        for (int i = 0; i < n; i++) { cin >> m[i]; }
        int y;
        cin >> y;
        vector<int>x(y);
        for (int j = 0; j < y; j++) { cin >> x[j]; }
        for (int j = 0; j < n - 1; j++)
        {
            for (int i = 0; i < n - 1 - j; i++)
            {
                if (m[i] > m[i + 1]) { h = m[i]; m[i] = m[i + 1]; m[i + 1] = h; }
            }
        }
        for (int l = 0; l < n; l++)
        {
            if (l != 0)cout << " ";
            cout << m[l];
            if (l == n - 1)cout << endl;
        }

        for (int i = 0; i < y; i++)
        {
            //if(n<0||n>100||m<0||m>100)break;
            int k1 = 0, k2 = n - 1, k3, l = 0;
            while (k1 <= k2)
            {
                k3 = (k1 + k2) / 2;
                if (x[i] == m[k3])
                {
                    if (i != 0)cout << " ";
                    cout << k3 + 1;
                    l = 1;

                    for (int v = k3 + 1; v < n; v++)
                    {
                        if (x[i] == m[v])cout << " " << v + 1;
                    }

                    break;
                }
                else if (x[i] > m[k3]) { k1 = k3 + 1; }
                else { k2 = k3 - 1; }
            }
            if (l == 0)
            {
                if (i != 0)cout << " ";
                cout << 0;
            }
        }
        cout << endl;
    }

    return 0;
}
*/

/*(40)链表操作

对于输入的若干学生的信息（学号、姓名、年龄），要求使用链表完成：
（1）根据学生的信息建立逆序链表，并遍历该链表输出学生的信息；
（2）在第m个结点之后插入一个新学生结点并输出；
（3）删除某个学号的学生结点后输出。

输入格式:
首先输入一个正整数T，表示测试数据的组数，然后是T组测试数据。每组测试数据首先输入一个正整数n表示学生的个数；然后输入n行信息，分别表示学生的学号、姓名（不含空格且长度都不超过10的字符串）和年龄（正整数）；接下来输入整数m（1≤m≤n）和一个新学生的学号、姓名、年龄；最后输入待删学生的学号（可能不存在，此时不需删除）。

输出格式:
对于每组测试，依次输出描述中要求的学生信息（参看输出样例），每两组测试数据之间留一个空行。

输入样例:
2
3
1201 Zhangsan 20
1202 Lisi 21
1204 Wangwu 20
2 1203 Zhaoliu 19
1204
2
1201 Lisi 20
1202 Wangwu 20
2 1203 Zhaoliu 19
1204
输出样例:
1204 Wangwu 20
1202 Lisi 21
1201 Zhangsan 20
1204 Wangwu 20
1202 Lisi 21
1203 Zhaoliu 19
1201 Zhangsan 20
1202 Lisi 21
1203 Zhaoliu 19
1201 Zhangsan 20

1202 Wangwu 20
1201 Lisi 20
1202 Wangwu 20
1201 Lisi 20
1203 Zhaoliu 19
1202 Wangwu 20
1201 Lisi 20
1203 Zhaoliu 19
*/

#include<iostream>
#include<string>
using namespace std;
struct STUDENT
{
    int xuehao;
    string mingzi;
    int nianling;
    STUDENT* next = NULL;
};
STUDENT* chuangli();
void charu(STUDENT*& p);
void xianshi(STUDENT* p);
void tianjia(STUDENT* p, int x);
void shanchu(STUDENT*& p, int y);

int main()
{
    int k, n, m, h;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        STUDENT* p = NULL;
        p = chuangli();
        cin >> n;
        for (int j = 0; j < n; j++)
            charu(p);
        xianshi(p);
        cin >> m;
        tianjia(p, m - 1);
        xianshi(p);
        cin >> h;
        shanchu(p, h);
        xianshi(p);
        if (i != k - 1)cout << endl;
    }

    return 0;
}

STUDENT* chuangli()
{
    STUDENT* head = NULL;
    return head;
}
void charu(STUDENT*& p)
{
    STUDENT* node = new STUDENT;
    cin >> node->xuehao >> node->mingzi >> node->nianling;
    if (p != NULL)node->next = p;
    p = node;
}
void xianshi(STUDENT* p)
{
    while (p != NULL)
    {
        cout << p->xuehao << " " << p->mingzi << " " << p->nianling << endl;
        p = p->next;
    }
}
void tianjia(STUDENT* p, int x)
{
    STUDENT* p0 = p, * h = NULL;
    for (; x > 0; x--)p0 = p0->next;
    STUDENT* node = new STUDENT;
    cin >> node->xuehao >> node->mingzi >> node->nianling;
    //node->next=p0->next;
    h = p0->next;
    p0->next = node;
    //p0=node;
    node->next = h;
}
void shanchu(STUDENT*& p, int y)
{
    STUDENT* p0 = p, * p1 = NULL;
    if (p->xuehao == y)
    {
        p0 = p0->next;
        p->next = NULL;
        delete p;
        p = p0;
    }
    else
    {
        while (p0->next != NULL)
        {
            if ((p0->next)->xuehao == y)
            {
                p1 = (p0->next)->next;
                (p0->next)->next = NULL;
                delete p0->next;
                p0->next = p1;
                break;
            }
            p0 = p0->next;
        }
    }
}
