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

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct p
{
    int s;
    char h;
    char c;
};
bool pd(p&a,p&b)
{
    return a.c<b.c;
}
int main()
{
    int n,m;
    char a,b;
    cin>>n;
    vector<p>x(n);
    for(int i=0;i<n;i++)
    {
        cin>>x[i].c>>a>>b;
        if(a!='-')x[a-'0'].s=i;
        if(b!='-')x[b-'0'].s=i;
    }
    for(int i=0;i<n;i++)
        x[i].h=x[x[i].s].c;
    cin>>m;
    if(n!=m)
    {
        cout<<"No"<<endl;
        return 0;
    }
    vector<p>y(m);
    for(int i=0;i<m;i++)
    {
        cin>>y[i].c>>a>>b;
        if(a!='-')y[a-'0'].s=i;
        if(b!='-')y[b-'0'].s=i;
    }
    for(int i=0;i<n;i++)
        y[i].h=y[y[i].s].c;
    sort(x.begin(),x.end(),pd);
    sort(y.begin(),y.end(),pd);
    for(int i=0;i<n;i++)
        if(!i&&x[i].c==y[i].c);
        else if(x[i].h!=y[i].h||x[i].c!=y[i].c)
        {
            cout<<"No"<<endl;
            return 0;
        }
    cout<<"Yes"<<endl;

    return 0;
}
*/

/*(9)列出连通集

//给定一个有 n 个顶点和 m 条边的无向图，请用深度优先遍历（DFS）和广度优先遍历（BFS）分别列出其所有的连通集。
//假设顶点从 0 到 n−1 编号。
//进行搜索时，假设我们总是从编号最小的顶点出发，按编号递增的顺序访问邻接点。
//
//输入格式:
//输入第 1 行给出 2 个整数 n (0<n≤10) 和 m，分别是图的顶点数和边数。
//随后 m 行，每行给出一条边的两个端点。
//每行中的数字之间用 1 空格分隔。
//
//输出格式:
//按照"{ v1 v2 ... vk }"的格式，每行输出一个连通集。
//先输出 DFS 的结果，再输出 BFS 的结果。
//
//输入样例:
//8 6
//0 7
//0 1
//2 0
//4 1
//2 4
//3 5
//输出样例:
//{ 0 1 4 2 7 }
//{ 3 5 }
//{ 6 }
//{ 0 1 2 7 4 }
//{ 3 5 }
//{ 6 }

#include<iostream>
#include<queue>
using namespace std;
#define N 12
bool t[N][N],l[N];
int n,m;
void dfs(int x,bool u)
{
    if(u)cout<<"{ ";
    cout<<x<<" ";
    l[x]=1;
    for(int i=0;i<n;i++)
        if(!l[i]&&t[x][i])
            dfs(i,0);
    if(u)cout<<"}\n";
}
int main()
{
    int a,b,x;
    queue<int>c;
    cin>>n>>m;

    for(int j=0;j<m;j++)
    {
        cin>>a>>b;
        t[a][b]=t[b][a]=1;
    }
    for(int i=0;i<n;i++)
        if(!l[i])
            dfs(i,1);
    for(int i=0;i<n;i++)
        l[i]=0;

    for(int i=0;i<n;i++)
        if(!l[i])
        {
            c.push(i);
            l[i]=1;
            cout<<"{ ";
            while(!c.empty())
            {
                x=c.front();
                c.pop();
                cout<<x<<" ";
                for(int j=0;j<n;j++)
                    if(!l[j]&&t[x][j])
                    {
                        c.push(j);
                        l[j]=1;
                    }
            }
            cout<<"}\n";
        }

    return 0;
}
*/

//Saving James Bond - Hard Version
//
//This time let us consider the situation in the movie "Live and Let Die" in which James Bond, the world's most famous spy, was captured by a group of drug dealers. 
//He was sent to a small piece of land at the center of a lake filled with crocodiles.  
//There he performed the most daring action to escape -- he jumped onto the head of the nearest crocodile!  
//Before the animal realized what was happening, James jumped again onto the next big head...  
//Finally he reached the bank before the last crocodile could bite him (actually the stunt man was caught by the big mouth and barely escaped with his extra thick boot).
//
//Assume that the lake is a 100 by 100 square one.  
//Assume that the center of the lake is at (0,0) and the northeast corner at (50,50).  
//The central island is a disk centered at (0,0) with the diameter of 15.  
//A number of crocodiles are in the lake at various positions.  
//Given the coordinates of each crocodile and the distance that James could jump, you must tell him a shortest path to reach one of the banks.  
//The length of a path is the number of jumps that James has to make.
//
//Input Specification:
//Each input file contains one test case.  
//Each case starts with a line containing two positive integers N (≤100), the number of crocodiles, and D, the maximum distance that James could jump.  
//Then N lines follow, each containing the (x,y) location of a crocodile.  
//Note that no two crocodiles are staying at the same position.
//
//Output Specification:
//For each test case, if James can escape, output in one line the minimum number of jumps he must make. 
//Then starting from the next line, output the position (x,y) of each crocodile on the path, each pair in one line, from the island to the bank.  
//If it is impossible for James to escape that way, simply give him 0 as the number of jumps.  
//If there are many shortest paths, just output the one with the minimum first jump, which is guaranteed to be unique.
//
//Sample Input 1:
//17 15
//10 -21
//10 21
//-40 10
//30 -50
//20 40
//35 10
//0 -10
//-25 22
//40 -40
//-30 30
//-10 22
//0 11
//25 21
//25 10
//10 10
//10 35
//-30 10
//Sample Output 1:
//4
//0 11
//10 21
//10 35
//Sample Input 2:
//4 13
//-12 12
//12 12
//-12 -12
//12 -12
//Sample Output 2:
//0

/*
拯救詹姆斯·邦德 - 高级版

在电影《生死关头》（Live and Let Die）中，詹姆斯·邦德被一群毒贩抓住，并被扔到了一个充满鳄鱼的湖中央的小岛上。
为了逃脱，他做出了一个大胆的举动：他跳到了最近的一只鳄鱼的头上！
在鳄鱼还没反应过来之前，他又跳到了下一只更大的鳄鱼头上……
最终，他在最后一只鳄鱼咬到他之前成功到达了湖岸（实际上，替身演员被鳄鱼的大嘴咬住了，但幸运的是他穿着特制的厚靴子才勉强脱险）。
现在，假设这个湖是一个边长为100的正方形区域。
湖的中心位于坐标 (0, 0)，东北角位于 (50, 50)。
湖中央的小岛是一个直径为15的圆盘，圆心位于 (0, 0)。
湖中有许多鳄鱼，它们分布在不同的位置。
给定每只鳄鱼的坐标以及詹姆斯能够跳跃的最大距离，你需要告诉他一条最短的路径，以便他能够到达湖岸。
路径的长度定义为詹姆斯需要跳跃的次数。

输入格式：
每个输入文件包含一个测试用例。
每个测试用例以一行包含两个正整数 N（≤100，表示鳄鱼的数量）和 D（表示詹姆斯能够跳跃的最大距离）开始。
接下来的 N 行，每行包含一个鳄鱼的坐标 (x, y)。
注意：没有两只鳄鱼位于同一个位置。

输出格式：
对于每个测试用例，如果詹姆斯能够逃脱，输出一行表示他必须跳跃的最小次数。
从下一行开始，按从岛到岸的顺序，输出路径上每只鳄鱼的坐标 (x, y)，每对坐标占一行。
如果詹姆斯无法通过这种方式逃脱，只需输出 0 作为跳跃次数。
如果存在多条最短路径，只需输出第一次跳跃距离最小的路径，保证该路径是唯一的。

示例输入1：
17 15
10 -21
10 21
-40 10
30 -50
20 40
35 10
0 -10
-25 22
40 -40
-30 30
-10 22
0 11
25 21
25 10
10 10
10 35
-30 10

示例输出1：
4
0 11
10 21
10 35

示例输入2：
4 13
-12 12
12 12
-12 -12
12 -12

示例输出2：
0
*/
# include<stdio.h>
# include<stdbool.h>
# include<stdlib.h> 
# define MaxVertemNum 101
# define MaxDistance 5001
# define Radius 7.5

// 鳄鱼的结构
typedef struct VertemNode* Vertem;
struct VertemNode {
    int X;		// 横坐标 
    int Y;		// 纵坐标 
    int Layer;	// 记录被广度搜索到的轮数 
    Vertem Parent;
};

// 广度搜索时存放鳄鱼的队列
typedef struct QueueNode* Queue;
struct QueueNode {
    Vertem Array[MaxVertemNum];
    int Head;
    int Rear;
};

// 存放逃生路线的堆栈
typedef struct StackNode* Stack;
struct StackNode {
    Vertem Array[MaxVertemNum];
    int Rear;
};

bool IsEscape(Vertem V, int D);
bool IsRange(Vertem V1, Vertem V2, int D);
bool IsFirstRange(Vertem V, int D);
bool IsEmptyQueue(Queue Q);
bool IsEmptyStack(Stack S);
Vertem LastVertem(Queue Q, int D, Vertem PtrArray[], int N);


int main() {
    // 接收鳄鱼的总条数与跳跃的最大距离
    int N, D;
    scanf("%d %d", &N, &D);
    // 如果能一步跳到岸，则输出结果，程序结束 
    if (D + Radius >= 50) {
        printf("1\n");
        return 0;
    }

    // 用一个结构指针数组PtrArray来接受所有的鳄鱼
    Vertem PtrArray[N];
    int i, X, Y;
    for (i = 0; i < N; i++) {
        scanf("%d %d", &X, &Y);
        Vertem V = (Vertem)malloc(sizeof(struct VertemNode));
        V->X = X;
        V->Y = Y;
        V->Layer = 0;
        V->Parent = NULL;
        PtrArray[i] = V;
    }
    // 创建搜索队列，进行第一轮广度优先搜索，搜索结果依次并加入队列
    Queue Q = (Queue)malloc(sizeof(struct QueueNode));
    Q->Head = Q->Rear = -1;
    for (i = 0; i < N; i++) {
        if (IsFirstRange(PtrArray[i], D)) {
            // 若在第一轮广度搜索的范围内，则将其搜索轮数设置为1 
            PtrArray[i]->Layer = 1;
            Q->Array[++Q->Rear] = PtrArray[i];
        }
    }

    // 寻找逃生路线，并返回逃生前踩的最后一只鳄鱼 
    Vertem LastV = LastVertem(Q, D, PtrArray, N);
    int Count = LastV->Layer;
    Stack S = (Stack)malloc(sizeof(struct StackNode));
    S->Rear = -1;
    // 能否逃生的判断 
    if (Count == -1) {
        // 不能逃生
        printf("0");
    }
    else {
        // 能够逃生
        for (; LastV != NULL; LastV = LastV->Parent) {
            // 将结果加入堆栈方便按逃生路线输出结果 
            S->Array[++S->Rear] = LastV;
        }
        // 输出结果 
        printf("%d\n", Count + 1);
        while (!IsEmptyStack(S)) {
            printf("%d %d\n", S->Array[S->Rear]->X, S->Array[S->Rear]->Y);
            S->Rear--;
        }
    }
    return 0;
}

// 判读是否在第一轮广度搜索的范围内 
bool IsFirstRange(Vertem V, int D) {
    int X = V->X, Y = V->Y;
    int DistanceSqure = X * X + Y * Y;
    if (DistanceSqure > (Radius + D) * (Radius + D))return false;
    else return true;
}

// 核心算法，返回逃生前的最后一只鳄鱼；若没有路径，则返回一只特殊的Layer为-1的鳄鱼
Vertem LastVertem(Queue Q, int D, Vertem PtrArray[], int N) {
    Vertem V, VCopy, Res;
    // ResLayer用来记录逃生前最后一只鳄鱼的Layer，Valid作为是否成功逃生的标志 
    int i, ResLayer = 0, Valid = 0;
    int MinDistance = MaxDistance;
    while (!IsEmptyQueue(Q)) {
        // 出队
        V = Q->Array[++Q->Head];

        // 如果成功逃生，先被急着返回，应该把这一轮判断完，看是否存在离岛更近的layer=1的鳄鱼；直到V->Layer!=ResLayer进行下一轮时才返回 
        if (Valid == 1 && V->Layer != ResLayer) {
            return Res;
        }
        if (IsEscape(V, D)) {
            // 目的是在可能的众多路线中找出离岛更近的layer=1的鳄鱼 
            Valid = 1;
            VCopy = V;
            for (; VCopy->Parent != NULL; VCopy = VCopy->Parent);
            if (VCopy->X * VCopy->X + VCopy->Y * VCopy->Y < MinDistance) {
                MinDistance = VCopy->X * VCopy->X + VCopy->Y * VCopy->Y;
                Res = V;
                ResLayer = V->Layer;
            }
        }

        // 广度搜索 
        for (i = 0; i < N; i++) {
            if (IsRange(V, PtrArray[i], D) && PtrArray[i]->Layer == 0) {
                // 在该鳄鱼V的影响范围内且未被检索 
                PtrArray[i]->Layer = V->Layer + 1;
                PtrArray[i]->Parent = V;
                // 入队 
                Q->Array[++Q->Rear] = PtrArray[i];
            }
        }
    }

    // 因为在上面循环中有可能还没有return Res但又存在了Res，而队列为空即无法持续到V->Layer != ResLayer时也应返回正确结果 
    if (Valid == 1) {
        return Res;
    }
    // 逃生失败,返回一只Layer=-1的特殊的鳄鱼作为失败的标记 
    Vertem W = (Vertem)malloc(sizeof(struct VertemNode));
    W->Layer = -1;
    return W;
}

// 判断一个鳄鱼是否可以作为最后一个逃生点
bool IsEscape(Vertem V, int D) {
    int X = V->X;
    int Y = V->Y;
    if (X + D >= 50 || X - D <= -50 || Y + D >= 50 || Y - D <= -50)return true;
    else return false;
}

// 判读队列是否为空
bool IsEmptyQueue(Queue Q) {
    if (Q->Head == Q->Rear)return true;
    else return false;
}

// 判读堆栈是否为空
bool IsEmptyStack(Stack S) {
    if (S->Rear == -1)return true;
    else return false;
}

// 判读V2是否在V1的辐射范围之内 
bool IsRange(Vertem V1, Vertem V2, int D) {
    int X1 = V1->X, Y1 = V1->Y;
    int X2 = V2->X, Y2 = V2->Y;
    int DistanceSqure = (X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2);
    if (DistanceSqure > D * D)return false;
    else return true;
}
