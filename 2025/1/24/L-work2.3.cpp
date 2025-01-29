/*(11)找出不是两个数组共有的元素

//给定两个整型数组，本题要求找出不是两者共有的元素。
//
//输入格式:
//输入分别在两行中给出两个整型数组，每行先给出正整数N（≤20），随后是N个整数，其间以空格分隔。
//
//输出格式:
//在一行中按照数字给出的顺序输出不是两数组共有的元素，数字间以空格分隔，但行末不得有多余的空格。
//题目保证至少存在一个这样的数字。同一数字不重复输出。
//
//输入样例:
//10 3 -5 2 8 0 3 5 -15 9 100
//11 6 4 8 2 6 -5 9 0 100 8 1
//输出样例:
//3 5 -15 6 4 1

#include<iostream>
using namespace std;
typedef struct
{
    int data;
    int cur;
}list[41];
void jian(list& L)
{
    for(int i=0;i<41-1;++i)
        L[i].cur=i+1;
    L[40].cur=0;
}
int fp(list& L)
{
    int i=L[0].cur;
    if(i)L[0].cur=L[i].cur;
    return i;
}
void hs(list& L,int& k)
{
    L[k].cur=L[0].cur;
    L[0].cur=k;
}
int main()
{
    list L;
    int n,m,r,s,x[20],y[20],h;
    jian(L);
    r=s=fp(L);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>x[i];
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(x[i]==x[j])
            {
                for(int k=j;k<n-1;k++)
                    x[k]=x[k+1];
                n--,j--;
            }
    cin>>m;
    for(int j=0;j<m;j++)
        cin>>y[j];
    for(int i=0;i<m;i++)
        for(int j=i+1;j<m;j++)
            if(y[i]==y[j])
            {
                for(int k=j;k<m-1;k++)
                    y[k]=y[k+1];
                m--,j--;
            }
    // for(int i=0;i<n;i++)
    //     cout<<x[i]<<" ";
    // cout<<endl;
    // for(int i=0;i<m;i++)
    //     cout<<y[i]<<" ";
    // cout<<endl;
    for(int i=0;i<n;i++)
    {
        int j=fp(L);
        L[j].data=x[i];
        L[r].cur=j;
        r=j;
    }
    L[r].cur=0;
    int p,k;
    for(int j=m-1;j>=0;--j)
    {
        h=y[j];
        p=s;
        k=L[s].cur;
        while(k!=L[r].cur&&L[k].data!=h)
            p=k,k=L[k].cur;
        if(k==L[r].cur)
        {
            int i=fp(L);
            L[i].data=h;
            L[i].cur=L[r].cur;
            L[r].cur=i;
        }
        else
        {
            L[p].cur=L[k].cur;
            hs(L,k);
            if(r==k)r=p;
        }
    }
    int f=L[s].cur;
    bool u=0;
    while(f!=0)
    {
        if(u)cout<<" ";
        cout<<L[f].data;
        u=1;
        f=L[f].cur;
    }

    return 0;
}
*/

/*(12)子串在母串中出现的次数

//统计一个长度为3的字符串在另一个字符串中出现的次数。。
//
//输入格式:
//在第一行输入长度小于20的长的字符串。在字符串中不要出现换行符，空格，制表符。
//在第二行输入长度为3的字符串。在字符串中不要出现换行符，空格，制表符。
//
//输出格式:
//直接输出结果，没有任何附加字符。
//
//输入样例:
//asdfgasdrfas
//asd
//输出样例:
//2

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string n,m;
    cin>>m>>n;
    int i=0,sum=0;
    while(m[i+2])
    {
        if(m[i]==n[0])
        {
            if(m[i+1]==n[1]&&m[i+2]==n[2])
                sum++;
        }
        i++;
    }
    cout<<sum<<endl;

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
// void dfs(int x,char n,char v,char m)
// {
//     if(x==1)
//     {
//         cout<<n<<" -> "<<m<<endl;
//         return;
//     }
//     dfs(x-1,n,m,v);
//     cout<<n<<" -> "<<m<<endl;
//     dfs(x-1,v,n,m);
// }
// int main()
// {
//     int n;
//     cin>>n;
//     dfs(n,'a','b','c');

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
