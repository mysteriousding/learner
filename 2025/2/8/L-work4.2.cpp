/*(6)梅森数

//形如2^n−1的素数称为梅森数（Mersenne Number）。
//例如2^2−1=3、2^3−1=7都是梅森数。
//1722年，双目失明的瑞士数学大师欧拉证明了2^31−1=2147483647是一个素数，堪称当时世界上“已知最大素数”的一个记录。
//
//本题要求编写程序，对任一正整数n（n<20），输出所有不超过2^n−1的梅森数。
//
//输入格式：
//输入在一行中给出正整数n（n<20）。
//
//输出格式：
//按从小到大的顺序输出所有不超过2^n−1的梅森数，每行一个。
//如果完全没有，则输出“None”。
//
//输入样例：
//6
//输出样例：
//3
//7
//31

#include<iostream>
using namespace std;
bool pd(int x)
{
    if(x==1)return 0;
    if(x==2)return 1;
    if(x%2==0)return 0;
    for(int i=3;i*i<=x;i+=2)
        if(x%i==0)return 0;
    return 1;
}
int main()
{
    int n,m=1;
    bool u=1;
    cin>>n;
    for(int i=1;i<=n;i++)
        if(pd((m*=2)-1))
        {
            cout<<m-1<<endl;
            u=0;
        }
    if(u)cout<<"None"<<endl;

    return 0;
}
*/

/*(7)Pop Sequence

//Given a stack which can keep M numbers at most.  
//Push N numbers in the order of 1, 2, 3, ..., N and pop randomly.  
//You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack.  
//For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.
//
//Input Specification:
//Each input file contains one test case.  
//For each case, the first line contains 3 numbers (all no more than 1000): 
//M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked).  
//Then K lines follow, each contains a pop sequence of N numbers.  
//All the numbers in a line are separated by a space.
//
//Output Specification:
//For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.
//
//Sample Input:
//5 7 5
//1 2 3 4 5 6 7
//3 2 1 7 5 6 4
//7 6 5 4 3 2 1
//5 6 4 3 7 2 1
//1 7 6 5 4 3 2
//Sample Output:
//YES
//NO
//NO
//YES
//NO

/*
出栈序列

给定一个最多可以存储 M 个数字的栈。
按照 1, 2, 3, ..., N 的顺序依次将 N 个数字压入栈中，并随机弹出。
你需要判断给定的数字序列是否是该栈的可能出栈序列。
例如，如果 M 为 5，N 为 7，我们可以从栈中依次弹出 1, 2, 3, 4, 5, 6, 7，但无法弹出 3, 2, 1, 7, 5, 6, 4。
输入说明：
每个输入文件包含一个测试用例。
对于每个测试用例，第一行包含 3 个数字（均不超过 1000）：M（栈的最大容量）、N（压栈序列的长度）和 K（需要检查的出栈序列数量）。
接下来的 K 行，每行包含一个长度为 N 的出栈序列，序列中的数字用空格分隔。
输出说明：
对于每个出栈序列，如果它是栈的可能出栈序列，则在一行中输出 “YES”，否则输出 “NO”。

样例输入：
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2

样例输出：
YES
NO
NO
YES
NO
*
// #include<iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     int n,m,k;
//     bool u;
//     cin>>n>>m>>k;
//     vector<int>a(m);
//     while(k--)
//     {
//         u=1;
//         for(int i=0;i<m;i++)
//             cin>>a[i];
//         for(int i=0;i<m;i++)
//         {
//             if(a[i]>i+n)
//             {
//                 u=0;
//                 break;
//             }
//             if(i!=0&&i!=m-1)
//                 if(a[i-1]+a[i]==a[i+1]*2)
//                 {
//                     u=0;
//                     break;
//                 }
//         }
//         cout<<(u?"YES":"NO")<<endl;
//     }


//     return 0;
// }



#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int n, m, k;
vector<int>a;
stack<int>b;
bool u;
void pd()
{
    u = 1;
    int next = 1;
    for (int i = 0; i < m; i++)
    {
        while (b.empty() || b.top() != a[i])
        {
            if (next > m || b.size() >= n)
            {
                u = 0;
                while (!b.empty())
                    b.pop();
                return;
            }
            b.push(next++);
        }
        b.pop();
    }
}
int main()
{
    cin >> n >> m >> k;
    a.resize(m);
    while (k--)
    {
        for (int i = 0; i < m; i++)
            cin >> a[i];
        pd();
        cout << (u ? "YES" : "NO") << endl;
    }


    return 0;
}
*/

/*(8)树的同构

//给定两棵树 T1 和 T2 。
//如果 T1 可以通过若干次左右孩子互换就变成 T2 ，则我们称两棵树是“同构”的。
//例如图1给出的两棵树就是同构的，因为我们把其中一棵树的结点A、B、G的左右孩子互换后，就得到另外一棵树。
//而图2就不是同构的。
//
//https://images.ptausercontent.com/0c8bbacf-d64e-4c6d-8d4e-1249e33fb0b1.jpg
//图1
//https://images.ptausercontent.com/29
//图2
//
//现给定两棵树，请你判断它们是否是同构的。
//
//输入格式:
//输入给出2棵二叉树的信息。
//对于每棵树，首先在一行中给出一个非负整数 n (≤10)，即该树的结点数（此时假设结点从 0 到 n−1 编号）；
//随后 n 行，第 i 行对应编号第 i 个结点，给出该结点中存储的 1 个英文大写字母、其左孩子结点的编号、右孩子结点的编号。
//如果孩子结点为空，则在相应位置上给出 “-”。
//给出的数据间用一个空格分隔。
//注意：题目保证每个结点中存储的字母是不同的。
//
//输出格式:
//如果两棵树是同构的，输出“Yes”，否则输出“No”。
//
//输入样例1（对应图1）：
//8
//A 1 2
//B 3 4
//C 5 -
//D - -
//E 6 -
//G 7 -
//F - -
//H - -
//8
//G - 4
//B 7 6
//F - -
//A 5 1
//H - -
//C 0 -
//D - -
//E 2 -
//输出样例1:
//Yes
//输入样例2（对应图2）：
//8
//B 5 7
//F - -
//A 0 3
//C 6 -
//H - -
//D - -
//G 4 -
//E 1 -
//8
//D 6 -
//B 5 -
//E - -
//H - -
//C 0 2
//G - 3
//F - -
//A 1 4
//输出样例2:
//No


*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct p
{
    int s;
    char c;
};
bool pd(p& a, p& b)
{
    return a.c < b.c;
}
int main()
{
    int n, m;
    char a, b;
    cin >> n;
    vector<p>x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i].c >> a >> b;
        if (a != '-')x[a - '0'].s = i;
        if (b != '-')x[b - '0'].s = i;
    }
    cin >> m;
    if (n != m)
    {
        cout << "No" << endl;
        return 0;
    }
    vector<p>y(m);
    for (int i = 0; i < m; i++)
    {
        cin >> y[i].c >> a >> b;
        if (a != '-')y[a - '0'].s = i;
        if (b != '-')y[b - '0'].s = i;
    }
    sort(x.begin(), x.end(), pd);
    sort(y.begin(), y.end(), pd);
    for (int i = 0; i < n; i++)
        if (x[i].s != y[i].s || x[i].c != y[i].c)
        {
            cout << "No" << endl;
            return 0;
        }
    cout << "Yes" << endl;

    return 0;
}
