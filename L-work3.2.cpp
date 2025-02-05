/*(6)背包问题3-多重背包问题 I

//有 N 种物品和一个容量是V 的背包。
//第i种物品最多有si件，每件体积是 vi，价值是Wi。
//求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
//输出最大价值。
//
//输入格式
//第一行两个整数，N,V，用空格隔开，分别表示物品种数和背包容积。
//接下来有N行，每行三个整数 Vi,Wi, Si，用空格隔开，分别表示第i种物品的体积、价值和数量。
//
//输出格式
//输出一个整数，表示最大价值。
//
//数据范围
//0 < N,V ≤ 100
//0 < vi, wi,si ≤100
//
//输入样例:
//4 5
//1 2 3
//2 4 1
//3 4 3
//4 5 2
//
//输出样例:
//10


*/

//#include<iostream>
//#include<vector>
//#define N 105
//using namespace std;
//struct q
//{
//    int v;
//    int w;
//    int s;
//};
//int n, V, dp[N][N];
//vector<q>a;
//int dfs(int x, int num)
//{
//    if (x > n)return 0;
//    if (dp[x][num] != -1)return dp[x][num];
//    int h = 0, r, l;
//    if (num < a[x].v || !a[x].s)h = dfs(x + 1, num);
//    else
//    {
//        r = dfs(x + 1, num);
//        a[x].s--;
//        l = dfs(x, num - a[x].v) + a[x].w;
//        a[x].s++;
//        h = max(r, l);
//    }
//    return dp[x][num] = h;
//}
//
//int main()
//{
//    cin >> n >> V;
//    a.resize(n + 1);
//    for (int i = 1; i <= n; i++)
//        cin >> a[i].v >> a[i].w >> a[i].s;
//    for (int i = 0; i < N; i++)
//        for (int j = 0; j < N; j++)
//            dp[i][j] = -1;
//    int sum = dfs(1, V);
//    cout << sum << endl;
//
//    return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//int n, r, t, num;
//string m;
//bool l[33];
//void dfs(int x, int y)
//{
//    if (x > 2 * r - 1)
//    {
//        cout << m << endl;
//        num++;
//        if (num == t)goto end;
//        return;
//    }
//    for (int i = y; i >= 1; i--)
//        if (!l[i])
//        {
//            m[x] = char(i + '0');
//            l[i] = 1;
//            dfs(x + 2, i - 1);
//            l[i] = 0;
//        }
//}
//int main()
//{
//    while (cin >> n >> r >> t)
//    {
//        num = 0, m = "";
//        for (int i = 0; i <= n + 1; i++)
//            l[i] = 0;
//        for (int i = 0; i < r; i++)
//            m += " 0";
//        dfs(1, n);
//    end:
//    }
//    return 0;
//}


/*(7)排队推荐

//世界顶级艺术品展会，推出A/B/C三种参观票，分别对应参观时间6/4/2小时。
//展会设有E1、E2、E3三个排队安检入口，对应的安检时间分别为1、2、5分钟/人。
//每天的参观人数上限为1500人，展馆工作时间8:00-23:30。
//假设：使用过排队查询的用户，都会遵从系统推荐。
//
//输入格式:
//第1行：已进入的参观者的数量、E1~E3入口处当前排队人数、当前时间、查询排队推荐的用户数量n（查询用户尚未排队）。
//比如：输入“1327 100 48 19 1215 8”，表示已进入1327人，E1口100人排队，E2口48人排队，E3口19人排队，当前时间为12点15分，8名用户正在查询排队推荐。
//
//第2行：输入n个用户的票类别。
//
//输出格式:
//依次输出对应用户的提示信息，包括：
//
//推荐可以最早进入展馆的入口，预计等待时间（若等待时间一致，按E1->E2->E3优先顺序推荐入口）；
//若闭馆前参观时间不足（A票<6小时，B票<4小时，C票<2小时），提示“visit time is insufficient!”，用户将放弃当天参观；
//若(已进入人数+排队人数)>=1500，不再检票，提示“the number of users has reached the upper limit!”，禁止参观者进入；
//若当前时间不在8:00-23:30范围内，输出“Out of service!”；若参观票类型错误，输出“Ticket error!”。
//
//输入样例1:
//1327 100 48 19 1215 8
//CCCBBBAA
//
//输出样例1:
//User 1: the best entrance is E2, expected waiting time is 1:38.
//User 2: the best entrance is E2, expected waiting time is 1:40.
//User 3: the best entrance is E3, expected waiting time is 1:40.
//User 4: the best entrance is E1, expected waiting time is 1:41.
//User 5: the best entrance is E1, expected waiting time is 1:42.
//User 6: the best entrance is E2, expected waiting time is 1:42.
//User 7: the number of users has reached the upper limit!
//User 8: the number of users has reached the upper limit!
//
//输入样例2:
//1000 100 48 19 1715 8
//CCCBBBAA
//
//输出样例2:
//User 1: the best entrance is E2, expected waiting time is 1:38.
//User 2: the best entrance is E2, expected waiting time is 1:40.
//User 3: the best entrance is E3, expected waiting time is 1:40.
//User 4: the best entrance is E1, expected waiting time is 1:41.
//User 5: the best entrance is E1, expected waiting time is 1:42.
//User 6: the best entrance is E2, expected waiting time is 1:42.
//User 7: visit time is insufficient!
//User 8: visit time is insufficient!
//
//输入样例3:
//0 0 0 0 759 8
//
//输出样例3:
//Out of service!
//
//输入样例4:
//0 0 0 0 800 5
//ABCDA
//
//输出样例4:
//User 1: the best entrance is E1, expected waiting time is 0:01.
//User 2: the best entrance is E1, expected waiting time is 0:02.
//User 3: the best entrance is E2, expected waiting time is 0:02.
//User 4: Ticket error!
//User 5: the best entrance is E1, expected waiting time is 0:03.


*/

/*(8)逆转卡牌 (Easy Version)

//给定两个正整数 n 和 m。
//
//计算满足以下条件的有序对 (a,b) 的数量：
// 1≤a≤n，1≤b≤m；
//a+b 是 b⋅gcd(a,b) 的倍数。
//
//输入格式:
//输入包含多组测试用例。
//第一行包含一个整数 t 表示测试用例的数量，t<=1000。
//接下来的 t 行中，每行包含两个整数 n 和 m ，n,m<=2000000。
//保证所有测试用例中 n 和 m 的总和不超过 2×10^6 。
//
//输出格式:
//对于每个测试用例，输出一个整数，表示满足条件的有序对数量。
//
//输入样例:
//6
//1 1
//2 3
//3 5
//10 8
//100 1233
//1000000 1145141
//
//输出样例:
//1
//3
//4
//14
//153
//1643498


*/

/*(9)堆中的路径

//将一系列给定数字插入一个初始为空的最小堆 h。
//随后对任意给定的下标 i，打印从第 i 个结点到根结点的路径。
//
//输入格式:
//每组测试第 1 行包含 2 个正整数 n 和 m (≤10^3)，分别是插入元素的个数、以及需要打印的路径条数。
//下一行给出区间 [−10^4 ,10^4 ] 内的 n 个要被插入一个初始为空的小顶堆的整数。
//最后一行给出 m 个下标。
//
//输出格式:
//对输入中给出的每个下标 i，在一行中输出从第 i 个结点到根结点的路径上的数据。
//数字间以 1 个空格分隔，行末不得有多余空格。
//
//输入样例:
//5 3
//46 23 26 24 10
//5 4 3
//输出样例:
//24 23 10
//46 23 10
//26 10

#include <iostream>
#include <new>
#define MaxSize 1001
#define Min -10001
using namespace std;
int Heap[MaxSize];   //用数组建堆
int Size;   //记录下一个添加的位置
void Insert(int p)
{
    int i;
    Size++;
    for( i=Size; Heap[i/2]>p; i=i/2 )   //如果比父节点小，放到父节点位置，再继续，直到根节点
        Heap[i] = Heap[i/2];
    Heap[i] = p;   //将输入的元素插到对应位置
}

int main()
{
    int n, m, i, j;

    cin >> n >> m;
    Heap[0] = Min;

    for( i=1; i<=n; i++ ) {
        cin >> j;
        Insert(j);
    }

    for( i=0; i<m; i++) {
        cin >> j;
        cout << Heap[j];  //先输出自身
        for( j=j/2; j>0; j=j/2 ) {    //输出直到根节点
            cout << " " << Heap[j];
        }
        cout << endl;
    }
    return 0;
}
*/

//哥尼斯堡的“七桥问题”
//
//哥尼斯堡是位于普累格河上的一座城市，它包含两个岛屿及连接它们的七座桥，如下图所示。
//
//https ://images.ptausercontent.com/51
//
//可否走过这样的七座桥，而且每桥只走过一次？
//瑞士数学家欧拉(Leonhard Euler，1707—1783)最终解决了这个问题，并由此创立了拓扑学。
//
//这个问题如今可以描述为判断欧拉回路是否存在的问题。
//欧拉回路是指不令笔离开纸面，可画过图中每条边仅一次，且可以回到起点的一条回路。
//现给定一个无向图，问是否存在欧拉回路？
//
//输入格式:
//输入第一行给出两个正整数，分别是节点数 n （1≤n≤1000）和边数 m；
//随后的 m 行对应 m 条边，每行给出一对正整数，分别是该条边直接连通的两个节点的编号（节点从1到 n 编号）。
//
//输出格式:
//若欧拉回路存在则输出 1，否则输出 0。
//
//输入样例1:
//6 10
//1 2
//2 3
//3 1
//4 5
//5 6
//6 4
//1 4
//1 6
//3 4
//3 6
//输出样例1:
//1
//输入样例2:
//5 8
//1 2
//1 3
//2 3
//2 4
//2 5
//5 3
//5 4
//3 4
//输出样例2:
//0

#include<iostream>
#include<vector>
using namespace std;
const int MAX = 10000;
int N, M, rd[MAX], fa[MAX];      //fa[]并查集数组

//并查集find()函数
int find(int x) {
    if (fa[x] == x) return x;
    else {
        fa[x] = find(fa[x]);
        return fa[x];
    }
}

//并查集关联函数
void add(int a, int b) {
    int f_a = find(a);
    int f_b = find(b);
    fa[f_b] = f_a;
}
int main() {
    cin >> N >> M;
    int a, b;
    for (int i = 1; i <= N; i++) { fa[i] = i; }   //初始化并查集
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        add(a, b);                     //关联结点
        rd[a]++;
        rd[b]++;
    }
    for (int i = 1; i <= N; i++) {
        find(i);                      //缩短并查集路径(统一父结点)
        if (rd[i] % 2 != 0) {               //判断入度是否全为偶数
            cout << 0 << endl;
            return 0;
        }
    }
    int f = fa[1];
    for (int i = 2; i <= N; i++) {          //判断父结点是否一样(图是否连通)
        if (fa[i] != f) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}