#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> d;
vector<int> b;
vector<vector<int>> e;
vector<vector<pair<long long, int>>> g;
vector<vector<pair<long long, int>>> k;

void dfs(int u, int p)
{
    for (int v : e[u])
    {
        if (v == p)
            continue;
        dfs(v, u);
    }

    k[u].clear();

    for (auto r : g[u])
        k[u].push_back(r);

    for (int v : e[u])
    {
        if (v == p)
            continue;
        for (auto r : k[v])
        {
            if (b[r.second] == -1)
                continue;
            k[u].push_back(make_pair(r.first + 1, r.second));
        }
        vector<pair<long long, int>>().swap(k[v]);
    }

    sort(k[u].begin(), k[u].end());

    int z = k[u].size();
    for (int i = 0, j; i < z; ++i)
    {
        j = i;
        while (j + 1 < z && k[u][j + 1].first == k[u][i].first)
            ++j;
        if (j > i)
            for (int h = i; h <= j; ++h)
                b[k[u][h].second] = -1;
        i = j;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, u, v, x;
    long long s;
    queue<int> q;

    cin >> n >> m;
    e.assign(n + 1, vector<int>());
    for (int i = 1; i < n; ++i)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    d.assign(n + 1, -1);

    d[1] = 0;
    q.push(1);

    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int v : e[u])
            if (d[v] == -1)
            {
                d[v] = d[u] + 1;
                q.push(v);
            }
    }

    g.assign(n + 1, vector<pair<long long, int>>());
    for (int i = 1; i <= m; ++i)
    {
        cin >> x >> s;
        g[x].push_back(make_pair(s, i));
    }

    b.assign(m + 1, 0);
    k.assign(n + 1, vector<pair<long long, int>>());

    dfs(1, 0);

    for (int i = 1; i <= m; ++i)
        cout << (b[i] == -1 ? '0' : '1');
    cout << endl;

    return 0;
}