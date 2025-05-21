/*
（1）邻接矩阵：建立所给无向带权图的邻接矩阵存储并输出该矩阵。
（2）邻接表：建立所给无向图的邻接表，并输出该图的深度优先遍历和广度优先遍历结果。
（3）图的应用：
     以无向网表示n个城市之间通信网络的建设计划，顶点表示城市，边上的权表示该线路的造价，设计一个方案，使这个通信网的总造价最低。
     通过算法设计、实现与分析，树立最优化的科学精神，培养创新探索的职业素养（思政点）。
*/
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
#define N 100

struct arr
{
    int r[2];
    arr* next = NULL;
};

void sr(int b[][3], int& n, int& m)
{
    cout << "请输入结点个数:" << endl;
    cin >> n;
    cout << "请输入边的个数:" << endl;
    cin >> m;
    cout << "请依次输入各边:" << endl;
    for (int i = 0; i < m; i++)
        cin >> b[i][0] >> b[i][1] >> b[i][2];
}

void jl_1(int a[][N], int b[][3], int m)
{
    for (int i = 0; i < m; i++)
        a[b[i][0]][b[i][1]] = a[b[i][1]][b[i][0]] = b[i][2];
}

void sc(int a[][N], int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void jl_2(arr* c[], int b[][3], int m)
{
    arr* q = NULL;
    for (int i = 0; i < m; i++)
    {
        q = new arr;
        q->r[0] = b[i][1];
        q->r[1] = b[i][2];
        q->next = c[b[i][0]];
        c[b[i][0]] = q;

        q = new arr;
        q->r[0] = b[i][0];
        q->r[1] = b[i][2];
        q->next = c[b[i][1]];
        c[b[i][1]] = q;
    }
}

void G_sc(arr* c[],bool c0[], int n)
{
    for (int i = 1; i <= n; i++)
        c0[i] = 1;
    arr* q = NULL;
    for (int i = 1; i <= n; i++)
    {
        q = c[i];
        cout << i<<" ";
        while(1)
        {

            //cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void S_sc(arr* c[], bool c0[], int n)
{
    stack<arr*>S;
    arr* q = NULL;
    for (int i = 1; i <= n; i++)
        c0[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (c0[i])continue;
        q = c[i];
        c0[i] = 1;
        cout << i << " ";
        if (q && q->next)  S.push(q->next);
        while (!S.empty())
        {
            q = S.top();
            S.pop();
            cout << q->r[0] << " ";
            c0[q->r[0]] = 1;
            
            while (q->next)
            {
                if(!c0[q->r[0]])S.push(q->next);
                q = q->next;
            }
        }
    }
}

int main()
{
    int a[N][N] = { 0 }, b[N][3], n, m;
    arr* c[N] = {NULL};
    bool c0[N] = { 0 };
    sr(b, n, m);
    jl_1(a, b, m);
    sc(a, n);
    jl_2(c, b, m);
    S_sc(c, c0,n);



    return 0;
}

/*

1 2 3
2 3 4
3 4 5
4 5 6
5 6 7
6 7 8
7 8 9
6 4 7
8 2 5
5 8 5

*/
