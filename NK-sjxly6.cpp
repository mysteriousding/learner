#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, m, u, v;
    long long k, x;
    bool f;
    queue<int> q;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        vector<vector<int>> e(n + 1);
        vector<int> c(n + 1, -1);
        vector<long long> d(n + 1, -1);
        for (int i = 0; i < m; ++i)
        {
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        f = 1;
        d[1] = 0;
        c[1] = 0;
        q.push(1);

        while (!q.empty())
        {
            u = q.front();
            q.pop();
            for (int v : e[u])
                if (d[v] == -1)
                {
                    d[v] = d[u] + 1;
                    c[v] = c[u] ^ 1;
                    q.push(v);
                }
                else if (c[v] == c[u])
                    f = 0;
        }

        for (int i = 1; i <= n; ++i)
        {
            if (d[i] == -1)
                cout << -1;

            else
            {
                x = ((d[i] + k - 1) / k) * k;
                if (f && (x % 2) != (d[i] % 2))
                    if (k % 2 == 0)
                        x = -1;
                    else
                        x += k;
                cout << x;
            }
            if (i < n)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}