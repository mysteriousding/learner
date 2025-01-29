/*(6)ZigZagging on a Tree

//Suppose that all the keys in a binary tree are distinct positive integers.  
//A unique binary tree can be determined by a given pair of postorder and inorder traversal sequences. 
//And it is a simple standard routine to print the numbers in level-order.  
//However, if you think the problem is too simple, then you are too naive.  
//This time you are supposed to print the numbers in "zigzagging order" -- that is, starting from the root, print the numbers level-by-level, alternating between left to right and right to left. 
//For example, for the following tree you must output: 1 11 5 8 17 12 20 15.
//
//https://images.ptausercontent.com/337cbfb0-a7b2-4500-9664-318e9ffc870e.jpg
//
//Input Specification:
//Each input file contains one test case. 
//For each case, the first line gives a positive integer N (≤30), the total number of nodes in the binary tree.  
//The second line gives the inorder sequence and the third line gives the postorder sequence.  
//All the numbers in a line are separated by a space.
//
//Output Specification:
//For each test case, print the zigzagging sequence of the tree in a line.  
//All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.
//
//Sample Input:
//8
//12 11 20 17 1 15 8 5
//12 20 17 11 15 8 5 1
//Sample Output:
//1 11 5 8 17 12 20 15

/*
在树上之字形

假设二叉树中的所有键都是不同的正整数。
唯一的二叉树可以由给定的一对后序和中序遍历序列来确定。
按级别顺序打印数字是一个简单的标准例程。
但是，如果你认为问题太简单，那你就太天真了。
这一次，您应该以 “之字形顺序” 打印数字 -- 即从根开始，逐级打印数字，在左到右和从右到左之间交替。
例如，对于以下树，您必须输出：1 11 5 8 17 12 20 15。

https://images.ptausercontent.com/337cbfb0-a7b2-4500-9664-318e9ffc870e.jpg

输入规格：
每个输入文件都包含一个测试用例。
对于每种情况，第一行给出一个正整数 N （≤30），即二叉树中的节点总数。
第二行给出中序序列，第三行给出后序序列。
一行中的所有数字都用空格分隔。

输出规格：
对于每个测试用例，将树的 之字形 序列打印成一行。
一行中的所有数字必须用一个空格分隔，并且行尾不能有多余的空格。

示例输入：
8
12 11 20 17 1 15 8 5
12 20 17 11 15 8 5 1
示例输出：
1 11 5 8 17 12 20 15
*
#include<iostream>
#include<stack>
using namespace std;
#define N 35
struct tree
{
    int num;
    tree* left = NULL;
    tree* right = NULL;
};
void dg(tree*& p, int n[], int m[], int a, int b, int c, int d)
{
    if (a > b)return;
    p = new tree;
    p->num = m[d];
    if (a == b)return;
    int x, y;
    for (int i = a; i <= b; i++)if (n[i] == m[d]) { x = i; break; }
    y = x - a;
    dg(p->left, n, m, a, x - 1, c, c + y - 1);
    dg(p->right, n, m, x + 1, b, c + y, d - 1);
}

int main()
{
    int n[N], m[N], k;
    stack<tree*>s[2];
    cin >> k;
    for (int i = 1; i <= k; i++)
        cin >> n[i];
    for (int i = 1; i <= k; i++)
        cin >> m[i];
    tree* T, * p, * q[2];
    dg(T, n, m, 1, k, 1, k);
    s[0].push(T);
    int a = 0, b = 1, h;
    bool u = 0;
    while (!s[0].empty() || !s[1].empty())
    {
        p = s[a].top();
        s[a].pop();
        q[0] = p->left;
        q[1] = p->right;
        if (u)cout << " ";
        cout << p->num;
        u = 1;
        if (q[b])s[b].push(q[b]);
        if (q[a])s[b].push(q[a]);
        delete p;
        if (s[a].empty())h = a, a = b, b = h;
    }

    return 0;
}
*/

/*(7)Universal Travel Sites

//After finishing her tour around the Earth, CYLL is now planning a universal travel sites development project.  
//After a careful investigation, she has a list of capacities of all the satellite transportation stations in hand.  
//To estimate a budget, she must know the minimum capacity that a planet station must have to guarantee that every space vessel can dock and download its passengers on arrival.
//
//Input Specification:
//Each input file contains one test case. For each case, the first line contains the names of the source and the destination planets, and a positive integer N (≤500).  
//Then N lines follow, each in the format: source[i] destination[i] capacity[i] 
//where source[i] and destination[i] are the names of the satellites and the two involved planets, and capacity[i] > 0 is the maximum number of passengers that can be transported at one pass from source[i] to destination[i]. 
//Each name is a string of 3 uppercase characters chosen from {A-Z}, e.g., ZJU.
//
//Note that the satellite transportation stations have no accommodation facilities for the passengers. 
//Therefore none of the passengers can stay.  
//Such a station will not allow arrivals of space vessels that contain more than its own capacity.  
//It is guaranteed that the list contains neither the routes to the source planet nor that from the destination planet.
//
//Output Specification:
//For each test case, just print in one line the minimum capacity that a planet station must have to guarantee that every space vessel can dock and download its passengers on arrival.
//
//Sample Input:
//EAR MAR 11
//EAR AAA 300
//EAR BBB 400
//AAA BBB 100
//AAA CCC 400
//AAA MAR 300
//BBB DDD 400
//AAA DDD 400
//DDD AAA 100
//CCC MAR 400
//DDD CCC 200
//DDD MAR 300
//Sample Output:
//700


/*
宇宙旅行站点

完成地球环球旅行后，CYLL 现在正在规划一个宇宙旅行站点开发项目。
经过仔细调查，她手中有一份所有卫星运输站的容量清单。
为了估算预算，她必须知道一个行星站必须具备的最小容量，以确保每艘宇宙飞船到达时都能停靠并让乘客下船。

输入规格：
每个输入文件都包含一个测试用例。对于每种情况，第一行包含源行星和目标行星的名称，以及一个正整数 N （≤500），表示路线数量。
接下来的 N 行，每行包含一条路线的信息，格式为：源[i],目的地[i]和容量[i]，
源[i] 和 目的地[i] 是涉及的卫星和两个行星的名称。
容量[i] 是从 源[i] 到 目的地[i] 的单次运输的最大乘客数，且 容量[i] > 0。
每个名称是一个由 3 个大写字母组成的字符串，例如 ZJU。

注意：
卫星运输站没有乘客住宿设施，因此乘客不能停留。
这样的站点不会允许超过其自身容量的宇宙飞船到达。
输入保证不会包含通往源行星的路线，也不会包含从目标行星出发的路线。

输出规格：
对于每个测试用例，输出一个整数，表示行星站必须具备的最小容量，以确保每艘宇宙飞船到达时都能停靠并让乘客下船。

示例输入：
EAR MAR 11
EAR AAA 300
EAR BBB 400
AAA BBB 100
AAA CCC 400
AAA MAR 300
BBB DDD 400
AAA DDD 400
DDD AAA 100
CCC MAR 400
DDD CCC 200
DDD MAR 300
示例输出：
700
*
// #include<iostream>
// #include<algorithm>
// #include<string>
// #include<vector>
// using namespace std;
// struct V
// {
//     bool l=1;
//     bool s=1;
//     string g;
//     string q;
//     int d;
// }v[15];
// struct E
// {
//     string f[2];
//     int r;
//     int num=0;
// };
// int main()
// {
//     int n,m,k=0;
//     bool u;
//     string C,R;
//     cin>>C>>R>>n;
//     v[k].g=C,v[k++].d=1e7;
//     vector<E>e(n);
//     for(int i=0;i<n;i++)
//     {
//         cin>>e[i].f[0]>>e[i].f[1]>>e[i].r;
//         u=1;
//         for(int j=0;j<k;j++)
//             if(v[j].g==e[i].f[0]||R==e[i].f[0]){u=0;break;}
//         if(u)v[k++].g=e[i].f[0];
//         u=1;
//         for(int j=0;j<k;j++)
//             if(v[j].g==e[i].f[1]||R==e[i].f[1]){u=0;break;}
//         if(u)v[k++].g=e[i].f[1];
//     }
//     v[k++].g=R;
//     u=1;
//     string p=v[0].g;
//     while(u)
//     {
//         u=0;
//         while(p!=R)
//         {
//             for(int i=0;i<n;i++)
//                 if(e[i].f[0]==p)
//                     if(e[i].f[1])
//         }

//     }



//     return 0;
// }



#include <iostream>
#include <vector> 
#include <cmath>
#include <queue>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;
int to_int(string str)
{
    int ans = 0;
    for (int i = 0; i < str.size(); i++) {
        ans = ans * 26 + str[i] - 'A';
    }
    return ans;
}
int s, t;
struct Line {
    int r, w;
    Line() = default;
    Line(int r, int w) : r(r), w(w) {	}
}line[1005];
vector<int> g[30000];
int deep[30000];
bool bfs()
{
    queue<int> que;
    memset(deep, 0, sizeof(deep));
    que.push(s);
    deep[s] = 1;
    while (!que.empty()) {
        int top = que.front();
        que.pop();
        for (int i = 0; i < g[top].size(); i++) {
            int z = g[top][i];
            if (!deep[line[z].r] && line[z].w) {   //分层 
                deep[line[z].r] = deep[top] + 1;
                que.push(line[z].r);
                if (deep[t])
                    return true;
            }
        }
    }
    return false;
}
int dfs(int x, int mix)
{
    if (x == t || !mix)
        return mix;
    int ap = 0;
    for (int i = 0; i < g[x].size(); i++) {
        int z = g[x][i];
        if (deep[x] < deep[line[z].r] && line[z].w) {    //从低层到高层，要进过非饱和弧 
            int p = dfs(line[z].r, min(mix, line[z].w));
            ap += p;
            mix -= p;
            line[z].w -= p;
            line[z ^ 1].w += p;
            if (!mix)
                return ap;
        }
    }
    return ap;
}
int dinic()
{
    int ans = 0;
    while (bfs()) {
        ans += dfs(s, INF);
    }
    return ans;
}
int main()
{
    string str1, str2;
    int m;
    while (cin >> str1 >> str2 >> m) {
        s = to_int(str1);
        t = to_int(str2);
        for (int i = 0; i < m; i++) {
            string strx, stry;
            int w;
            cin >> strx >> stry >> w;
            line[2 * i] = Line(to_int(stry), w);
            line[2 * i + 1] = Line(to_int(strx), 0);
            g[to_int(strx)].push_back(2 * i);
            g[to_int(stry)].push_back(2 * i + 1);
        }
        cout << dinic() << endl;
        for (int i = 0; i <= 30000; i++)
            g[i].clear();
    }
    return 0;
}
*/

/*(8)计算物体自由下落的距离

//一个物体从100米的高空自由落下。编写程序，求它在前3秒内下落的垂直距离。
//设重力加速度为10米/秒^2。
//
//输入格式:
//本题目没有输入。
//
//输出格式:
//按照下列格式输出
//
//height = 垂直距离值
//结果保留2位小数。

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    float h,g=10,t=3;
    h=0.5*g*t*t;
    cout<<setiosflags(ios::fixed)<<setprecision(2);
    cout<<"height = "<<h<<endl;

    return 0;
}
*/

/*(9)求奇数分之一序列前N项和

//本题要求编写程序，计算序列 1 + 1/3 + 1/5 + ... 的前N项之和。
//
//输入格式:
//输入在一行中给出一个正整数N。
//
//输出格式:
// 在一行中按照“sum = S”的格式输出部分和的值S，精确到小数点后6位。
//题目保证计算结果不超过双精度范围。
//
//输入样例:
//23
//输出样例:
//sum = 2.549541

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n;
    double sum;
    cin>>n;
    for(int i=1;i<=n;i++)
        sum+=1.0/(2*i-1);
    cout<<setiosflags(ios::fixed)<<setprecision(6);
    cout<<"sum = "<<sum<<endl;

    return 0;
}
*/

//监控
//
//某国的安全部门监控了全国的数据流，该部门的程序员接到一个任务，恐怖组织会给手下发送一个数字序列A，其中由n个正整数组成，
//而其中任何两个值Ai和Aj都可以求它们的余数 x=Ai mod Aj ，（其中1<=i,j<=n，Ai>= Aj）。
//
//所有x中，最大的x就是破译机密的秘钥。程序员的任务就是找到这个最大的x。
//
//输入格式:
//第一行是一个正整数n，第二行由n个小于等于10
//6
// 的正整数组成
//1 ≤ n ≤ 2·10
//5
//
//
//输出格式:
//输出找到的最大值。
//
//输入样例:
//3
//1 3 10
//
//输出样例:
//1

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    //sync_with_stdio(false);
    int n, max = 0;
    cin >> n;
    vector<int>m(n);
    for (int i = 0; i < n; i++)
        cin >> m[i];
    sort(m.begin(), m.end());
    for (int i = n - 1; m[i] > 1; i--)
        for (int j = i - 1; m[j] > 1; j--)
            if (max < m[i] % m[j])
                max = m[i] % m[j];
    cout << max << endl;

    return 0;
}
