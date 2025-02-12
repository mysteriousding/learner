/*(11)关键活动

//假定一个工程项目由一组子任务构成，子任务之间有的可以并行执行，有的必须在完成了其它一些子任务后才能执行。
//“任务调度”包括一组子任务、以及每个子任务可以执行所依赖的子任务集。
//
//比如完成一个专业的所有课程学习和毕业设计可以看成一个本科生要完成的一项工程，各门课程可以看成是子任务。
//有些课程可以同时开设，比如英语和C程序设计，它们没有必须先修哪门的约束；
//有些课程则不可以同时开设，因为它们有先后的依赖关系，比如C程序设计和数据结构两门课，必须先学习前者。
//
//但是需要注意的是，对一组子任务，并不是任意的任务调度都是一个可行的方案。
//比如方案中存在“子任务A依赖于子任务B，子任务B依赖于子任务C，子任务C又依赖于子任务A”，那么这三个任务哪个都不能先执行，这就是一个不可行的方案。
//
//任务调度问题中，如果还给出了完成每个子任务需要的时间，则我们可以算出完成整个工程需要的最短时间。在这些子任务中，有些任务即使推迟几天完成，也不会影响全局的工期；但是有些任务必须准时完成，否则整个项目的工期就要因此延误，这种任务就叫“关键活动”。
//
//请编写程序判定一个给定的工程项目的任务调度是否可行；
//如果该调度方案可行，则计算完成整个工程项目需要的最短时间，并输出所有的关键活动。
//
//输入格式:
//输入第1行给出两个正整数N(≤100)和M，其中N是任务交接点（即衔接相互依赖的两个子任务的节点，例如：
//若任务2要在任务1完成后才开始，则两任务之间必有一个交接点）的数量。
//交接点按1N编号，M是子任务的数量，依次编号为1M。随后M行，每行给出了3个正整数，分别是该任务开始和完成涉及的交接点编号以及该任务所需的时间，整数间用空格分隔。
//
//输出格式:
//如果任务调度不可行，则输出0；
//否则第1行输出完成整个工程项目需要的时间，第2行开始输出所有关键活动，每个关键活动占一行，按格式“V->W”输出，其中V和W为该任务开始和完成涉及的交接点编号。
//关键活动输出的顺序规则是：
//任务开始的交接点编号小者优先，起点编号相同时，与输入时任务的顺序相反。
//
//输入样例:
//7 8
//1 2 4
//1 3 3
//2 4 5
//3 4 3
//4 5 1
//4 6 6
//5 7 5
//6 7 2
//输出样例:
//17
//1->2
//2->4
//4->6
//6->7

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> PII;

const int maxn = 110;
int G[maxn][maxn];
int inDegree[maxn]; //每个顶点的入度
int ve[maxn],vl[maxn];  //每个顶点的最早和最晚开始时间
vector<int> topOrder; //存储拓朴排序序列
vector<PII> crit; //存储关键路径

int Nv,Ne; //顶点和边

void Read()
{
    cin >> Nv >> Ne;
    for(int i=0;i<Ne;++i)
    {
        int u,v,w;
        cin >> u >> v >> w;
        G[u][v] = w;
        inDegree[v]++; //v的入度加1
    }
}

bool topsort()
{
    queue<int> q;
    for(int i=1;i<=Nv;++i)
        if(inDegree[i] == 0)    //把所有入度为0的顶点加入队列
        {
            q.push(i);
            topOrder.push_back(i);
        }

    while(q.size())
    {
        int u = q.front();
        q.pop();
        for(int v = 1;v<=Nv;++v)
        {
            if(G[u][v] > 0)
            {
                inDegree[v]--;
                if(inDegree[v] == 0)    //v的入度被减为0了，就进行入队
                {
                    q.push(v);
                    topOrder.push_back(v);
                }

                ve[v] = max(ve[v] , ve[u] + G[u][v]);
            }
        }
    }

    if(topOrder.size() == Nv)
        return true;
    else
        return false;
}

int craticalPath()  // 求关键路径，返回完成整个工程项目需要的时间
{
    if(topsort() == false)
        return 0;

    int maxval = *max_element(ve+1,ve+1+Nv);    //求ve的最大值，最大值并不一定是ve[Nv];
    fill(vl,vl+maxn,maxval);

    for(auto it = topOrder.rbegin() ; it != topOrder.rend(); ++it)    //逆序处理拓朴排序
    {
        int v = *it;
        for(int u = 1;u<=Nv;++u)
        {
            if(G[u][v] > 0)
                vl[u] = min(vl[u],vl[v] - G[u][v]);
        }
    }

    for(int i = 1;i<=Nv;++i)    //起点小的先输出
    {
        for(auto it = topOrder.rbegin() ; it != topOrder.rend(); ++it)  //起点相同，与输入时
        {                                                   //任务的顺序相反。
            int j = *it;
            if(G[i][j] > 0)
            {
                int e = ve[i];
                int l = vl[j] - G[i][j];
                if(e == l)
                    crit.push_back({i,j});
            }
        }
    }

    return maxval;
}

int main()
{
    Read();
    int v = craticalPath();
    if(v == 0)
        puts("0");
    else
    {
        cout << v << endl;
        for(auto a:crit)
            cout << a.first << "->"  << a.second << endl;
    }
    return 0;
}
*/

/*（12）地下迷宫探索

//地道战是在抗日战争时期，在华北平原上抗日军民利用地道打击日本侵略者的作战方式。
//地道网是房连房、街连街、村连村的地下工事，如下图所示。
//
//https://images.ptausercontent.com/52
//
//我们在回顾前辈们艰苦卓绝的战争生活的同时，真心钦佩他们的聪明才智。
//在现在和平发展的年代，对多数人来说，探索地下通道或许只是一种娱乐或者益智的游戏。
//本实验案例以探索地下通道迷宫作为内容。
//
//假设有一个地下通道迷宫，它的通道都是直的，而通道所有交叉点（包括通道的端点）上都有一盏灯和一个开关。
//请问你如何从某个起点开始在迷宫中点亮所有的灯并回到起点？
//
//https://images.ptausercontent.com/53
//
//输入格式:
//输入第一行给出三个正整数，分别表示地下迷宫的节点数N（1<N≤1000，表示通道所有交叉点和端点）、边数M（≤3000，表示通道数）和探索起始节点编号S（节点从1到N编号）。
//随后的M行对应M条边（通道），每行给出一对正整数，分别是该条边直接连通的两个节点的编号。
//
//输出格式:
//若可以点亮所有节点的灯，则输出从S开始并以S结束的包含所有节点的序列，序列中相邻的节点一定有边（通道）；
//否则虽然不能点亮所有节点的灯，但还是输出点亮部分灯的节点序列，最后输出0，此时表示迷宫不是连通图。
//
//由于深度优先遍历的节点序列是不唯一的，为了使得输出具有唯一的结果，我们约定以节点小编号优先的次序访问（点灯）。
//在点亮所有可以点亮的灯后，以原路返回的方式回到起点。
//
//输入样例1:
//6 8 1
//1 2
//2 3
//3 4
//4 5
//5 6
//6 4
//3 6
//1 5
//输出样例1:
//1 2 3 4 5 6 5 4 3 2 1
//输入样例2:
//6 6 6
//1 2
//1 3
//2 3
//5 4
//6 5
//6 4
//输出样例2:
//6 4 5 4 6 0

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, S;
int vis_cnt;
int depth, max_depth;
bool space;

bool vis[10005];
vector<int> v[1005];
void dfs(int s) {
    depth++;
    if (depth > max_depth)
        max_depth = depth;
    vis[s] = true;
    vis_cnt++;
    if (!space)
        space = true;
    else
        cout << ' ';
    cout << s;
    bool flag = true;
    for (int i = 0; i < v[s].size(); ++i) {
        int u = v[s][i];
        if (!vis[u]) {
            dfs(u);
            cout << ' ' << s;
            flag = false;
        }
    }
    if (depth != max_depth && flag) {
        cout << ' ' << s;
    }
    depth--;
}

int main() {
    cin >> N >> M >> S;
    int v1, v2;
    for (int i = 0; i < M; ++i) {
        cin >> v1 >> v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }
    for (int i = 0; i <= N; ++i) {
        sort(v[i].begin(), v[i].end());
    }
    dfs(S);
    if (vis_cnt != N) {
        cout << ' ' << 0;
    }
    return 0;
}

*/

//Self-printable B+ Tree
//
//In this project, you are supposed to implement a B+ tree of order 3, with the following operations: i
//nitialize, insert (with splitting) and search.  
//The B+ tree should be able to print out itself.
//
//Input Specification:
//Each input file contains one test case.  
//For each case, the first line contains a positive number N (≤10^4 ), the number of integer keys to be inserted.  
//Then a line of the N positive integer keys follows.  
//All the numbers in a line are separated by spaces.
//
//Output Specification:
//For each test case, insert the keys into an initially empty B+ tree of order 3 according to the given order. 
//Print in a line Key X is duplicated where X already exists when being inserted.  
//After all the insertions, print out the B+ tree in a top-down lever-order format as shown by the samples.
//
//Sample Input 1:
//6
//7 8 9 10 7 4
//Sample Output 1:
//Key 7 is duplicated
//[9]
//[4,7,8][9,10]
//Sample Input 2:
//10
//3 1 4 5 9 2 6 8 7 0
//Sample Output 2:
//[6]
//[2,4][8]
//[0,1][2,3][4,5][6,7][8,9]
//Sample Input 3:
//3
//1 2 3
//Sample Output 3:
//[1,2,3]

/*
自打印的 B+ 树

在本项目中，你需要实现一个 3阶的 B+ 树，并支持以下操作：
初始化、插入（包含分裂）和搜索。
此外，B+ 树还需要能够打印自身。

输入格式：
每个输入文件包含一个测试用例。
每个测试用例的第一行包含一个正整数 N（≤10,000），表示需要插入的整数键的数量。
接下来的一行包含 N 个正整数键，所有数字之间用空格分隔。

输出格式：
对于每个测试用例，按照给定的顺序将键插入到一个初始为空的 3 阶 B+ 树中。
如果插入的键已经存在，则输出 Key X is duplicated，其中 X 是重复的键。
在所有插入操作完成后，以自上而下的层次遍历格式打印 B+ 树，具体格式见示例。

示例输入1：
6
7 8 9 10 7 4

示例输出1：
Key 7 is duplicated
[9]
[4,7,8][9,10]

示例输入2：
10
3 1 4 5 9 2 6 8 7 0

示例输出2：
[6]
[2,4][8]
[0,1][2,3][4,5][6,7][8,9]

示例输入3：
3
1 2 3

示例输出3：
[1,2,3]
*/
