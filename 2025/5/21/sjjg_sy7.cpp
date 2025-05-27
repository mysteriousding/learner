#include<iostream>
#include<stack>
#include<queue>
using namespace std;
#define N 100

typedef int a3[3];

struct arr
{
    int r[2];
    arr* next = NULL;
};

void sr(a3 b[], int& n, int& m)
{
    cout << "请输入结点个数:" << endl;
    cin >> n;
    cout << "请输入边的个数:" << endl;
    cin >> m;
    cout << "请依次输入各边:" << endl;
    for (int i = 0; i < m; i++)
        cin >> b[i][0] >> b[i][1] >> b[i][2];
}

void jl_1(int a[][N], a3 b[], int m)
{
    for (int i = 0; i < m; i++)
        a[b[i][0]][b[i][1]] = a[b[i][1]][b[i][0]] = b[i][2];
}

void sc(int a[][N], int n)
{
    cout << "邻接矩阵:" << endl; 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void jl_2(arr* c[], a3 b[], int m)
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
    queue<arr*>Q;
    arr* q = NULL;
    for (int i = 1; i <= n; i++)
        c0[i] = 0;
    cout << "广度优先遍历:" << endl;
    for (int i = 1; i <= n; i++)
    {
        if (c0[i])continue;
        q = c[i];
        c0[i] = 1;
        cout << i << " ";
        while (q)
        {
            if (!c0[q->r[0]])Q.push(q);
            q = q->next;
        }
        while (!Q.empty())
        {
            q = Q.front();
            Q.pop();
            if (c0[q->r[0]])continue;

            cout << q->r[0] << " ";
            c0[q->r[0]] = 1;

            q = c[q->r[0]];

            while (q)
            {
                if (!c0[q->r[0]])Q.push(q);
                q = q->next;
            }
        }
    }
    cout << endl;
}

void S_sc(arr* c[], bool c0[], int n)
{
    stack<arr*>S;
    arr* q = NULL;
    for (int i = 1; i <= n; i++)
        c0[i] = 0;
    cout << "深度优先遍历:" << endl;
    for (int i = 1; i <= n; i++)
    {
        if (c0[i])continue;
        q = c[i];
        c0[i] = 1;
        cout << i << " ";
        while (q)
        {
            if (!c0[q->r[0]])S.push(q);
            q = q->next;
        }
        while (!S.empty())
        {
            q = S.top();
            S.pop();
            if (c0[q->r[0]])continue;

            cout << q->r[0] << " ";
            c0[q->r[0]] = 1;

            q = c[q->r[0]];
            
            while (q)
            {
                if(!c0[q->r[0]])S.push(q);
                q = q->next;
            }
        }
    }
    cout << endl;
}

void jh(a3& a,a3& b)
{
    a3  h;
    h[0] = a[0];
    h[1] = a[1];
    h[2] = a[2];

    a[0] = b[0];
    a[1] = b[1];
    a[2] = b[2];

    b[0] = h[0];
    b[1] = h[1];
    b[2] = h[2];
}

int ys(int d[], int n)
{
    if (n == d[n])return n;
    d[n] = ys(d, d[n]);
    return d[n];
}

void Kru(a3 b[], int d[], int n, int m)
{
    int e[N], k = 0, num = 0, h;
    for (int i = 0; i < m; i++)
    {
        h = b[i][2], k = i;
        for (int j = i + 1; j < m; j++)
            if (h > b[j][2])
                h = b[j][2], k = j;
        jh(b[k], b[i]);
    }
    for (int i = 1; i <= n; i++)
        d[i] = i;
    k = 0;
    for (int j = 0; j < m; j++)
    {
        d[b[j][0]] = ys(d, d[b[j][0]]);
        d[b[j][1]] = ys(d, d[b[j][1]]);
        if (d[b[j][0]] != d[b[j][1]])
            d[d[b[j][1]]] = d[b[j][0]], num += b[j][2], e[k++] = j; 
    }
    cout << "线路的最低造价为:" << endl;
    cout << num << endl;
    cout << "规划的线路有:" << endl;
    for (int i = 0; i < k; i++)
        cout << b[e[i]][0] << " " << b[e[i]][1] << " " << b[e[i]][2] << " " << endl;

}

int main()
{
    int a[N][N] = { 0 },d[N], n, m;
    a3 b[N];
    arr* c[N] = {NULL};
    bool c0[N] = { 0 };
    sr(b, n, m);
    jl_1(a, b, m);
    sc(a, n);
    jl_2(c, b, m);
    S_sc(c, c0, n);
    G_sc(c, c0, n);
    Kru(b,d ,n,m);

    return 0;
}
