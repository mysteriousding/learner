/*(1)简化的插入排序

//本题要求编写程序，将一个给定的整数插到原本有序的整数序列中，使结果序列仍然有序。
//
//输入格式：
//输入在第一行先给出非负整数N（<10）；第二行给出N个从小到大排好顺序的整数；第三行给出一个整数X。
//
//输出格式：
//在一行内输出将X插入后仍然从小到大有序的整数序列，每个数字后面有一个空格。
//
//输入样例：
//5
//1 2 4 5 7
//3
//输出样例：
//1 2 3 4 5 7

#include<iostream>
using namespace std;
int main()
{
    int a[12],n,m,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    for(i=n-1;i>=0;i--)
        if(m<a[i])a[i+1]=a[i];
        else break;
    a[i+1]=m;
    for(i=0;i<=n;i++)
        cout<<a[i]<<" ";

    return 0;
}
*/

/*(2)求矩阵的局部极大值

//给定M行N列的整数矩阵A，如果A的非边界元素A[i][j]大于相邻的上下左右4个元素，那么就称元素A[i][j]是矩阵的局部极大值。
//本题要求给定矩阵的全部局部极大值及其所在的位置。
//
//输入格式：
//输入在第一行中给出矩阵A的行数M和列数N（3≤M,N≤20）；
//最后M行，每行给出A在该行的N个元素的值。
//数字间以空格分隔。
//
//输出格式：
//每行按照“元素值 行号 列号”的格式输出一个局部极大值，其中行、列编号从1开始。要求按照行号递增输出；
//若同行有超过1个局部极大值，则该行按列号递增输出。
//若没有局部极大值，则输出“None 总行数 总列数”。
//
//输入样例1：
//4 5
//1 1 1 1 1
//1 3 9 3 1
//1 5 3 5 1
//1 1 1 1 1
//输出样例1：
//9 2 3
//5 3 2
//5 3 4
//输入样例2：
//3 5
//1 1 1 1 1
//9 3 9 9 1
//1 5 3 5 1
//输出样例2：
//None 3 5

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m;
    bool u=1;
    cin>>n>>m;
    vector<vector<int>>a(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=2;i<n;i++)
        for(int j=2;j<m;j++)
            if(a[i][j]>a[i-1][j]&&a[i][j]>a[i][j-1]&&a[i][j]>a[i+1][j]&&a[i][j]>a[i][j+1])
            {
                u=0;
                cout<<a[i][j]<<" "<<i<<" "<<j<<endl;
            }
    if(u)cout<<"None "<<n<<" "<<m<<endl;

    return 0;
}
*/

/*(3)IP地址转换

//一个IP地址是用四个字节（每个字节8个位）的二进制码组成。
//请将32位二进制码表示的IP地址转换为十进制格式表示的IP地址输出。
//
//输入格式：
//输入在一行中给出32位二进制字符串。
//
//输出格式：
//在一行中输出十进制格式的IP地址，其由4个十进制数组成（分别对应4个8位的二进制数），中间用“.”分隔开。
//
//输入样例：
//11001100100101000001010101110010
//输出样例：
//204.148.21.114

#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,b[8]={1};
    string m;
    for(int i=1;i<8;i++)
        b[i]=b[i-1]*2;
    cin>>m;
    for(int j=1;j<=4;j++)
    {
        n=0;
        for(int i=7;i>=0;i--)
            n+=(m[j*8-i-1]-'0')*b[i];
        if(j!=1)cout<<'.';
        cout<<n;
    }

    return 0;
}
*/

/*(4)藏尾诗

//本题要求编写一个解密藏尾诗的程序。
//
//注：在 2023 年 1 月 17 日 15 点 14 分以后，该题数据修改为 UTF-8 编码。
//
//输入格式：
//输入为一首中文藏尾诗，一共四句。
//每句一行，但句子不一定是等长的，最短一个汉字，最长九个汉字。
//注意：一个汉字占三个字节。
//
//输出格式：
//取出每句的最后一个汉字并连接在一起形成一个字符串并输出。同时在末尾输入一个换行符。
//
//输入样例：
//悠悠田园风
//然而心难平
//兰花轻涌浪
//兰香愈幽静
//输出样例：
//风平浪静

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a[20];
    int i=0;
    while(getline(cin,a[i++]));
    for(int j=0;j<i;j++)
        for(int k=0;a[j][k];k++)
            if(a[j][k+1]=='\0')
                cout<<a[j][k-2]<<a[j][k-1]<<a[j][k];

    return 0;
}
*/

//汉诺塔的非递归实现
//
//借助堆栈以非递归（循环）方式求解汉诺塔的问题（n, a, b, c），即将N个盘子从起始柱（标记为“a”）通过借助柱（标记为“b”）移动到目标柱（标记为“c”），并保证每个移动符合汉诺塔问题的要求。
//
//输入格式:
//输入为一个正整数N，即起始柱上的盘数。
//
//输出格式:
//每个操作（移动）占一行，按柱1 -> 柱2的格式输出。
//
//输入样例:
//3
//输出样例:
//a -> c
//a -> b
//c -> b
//a -> c
//b -> a
//b -> c
//a -> c

// #include<iostream>
// using namespace std;
// void hom(int k,char a,char b,char c)
// {
//     if(k==1)
//     {
//         cout<<a<<" -> "<<b<<endl;
//         return ;
//     }
//     hom(k-1,a,c,b);
//     cout<<a<<" -> "<<b<<endl;
//     hom(k-1,c,b,a);
// }
// int main()
// {
//     int n;
//     cin>>n;
//     hom(n,'a','c','b');

//     return 0;
// }



#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;

char tower[3] = { 'a', 'b', 'c' };
stack<int> a[3];

bool move(int before, int after)
{
    if (a[before].empty())
    {
        return false;
    }

    if (!a[after].empty())
    {
        if (a[after].top() - a[before].top() < 0)
        {
            return false;
        }
    }

    a[after].push(a[before].top());
    a[before].pop();

    printf("%c -> %c\n", tower[before], tower[after]);

    return true;
}

int main()
{
    int N, count = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        a[0].push(N - i);
    }

    if (N % 2 == 1)
    {
        tower[1] = 'c';
        tower[2] = 'b';
    }

    while (++count)
    {
        move((count - 1) % 3, count % 3);

        if (!move((count - 1) % 3, (count + 1) % 3))
        {
            if (!move((count + 1) % 3, (count - 1) % 3))
            {
                break;
            }
        }
    }

    return 0;
}
