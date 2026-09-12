// #include <bits/stdc++.h>
// using namespace std;]
// using ll=long long;]
// int vis[1e6+1];]
// void dfs(vector<vector<int>>&g,int t){
//     for(auto x:g[t]){
//         if(vis[x])
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int t;
//     cin>>t;
//     while(t--){
//         int n,m;
//         cin>>n>>m;
//         vector<vector<int>>g(n+1);
//         for(int i=0;i<m;i++){
//             int i1,i2;
//             cin>>i1>>i2;
//             if(i1==i2)break;
//             int x,y;
//             cin>>x;
//             for(int i=0;i<i2-i1-1){
//                 int y;
//                 cin>>y;
//                 g[x].push_back(y);
//                 x=y;
//             }
//         }
//         for(int i=1;i<=n;i++){
//             if(!vis[i])
//             dfs(g,i);
//         }
//     }
//     return 0;
// }

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n, m, u, v, q, h, NU = 1e9;
    int s, d;
    bool w;
    vector<int>a, b;
    vector<bool>c;
    cin >> t;
    while (t--)
    {
        w = 1;
        cin >> n >> m;
        a.resize(n + 1, 0);
        c.resize(n + 1, 0);
        for (int i = 0; i < m; i++)
        {
            cin >> v >> u;
            q = -1;
            u = u - v + 1;
            b.resize(u);
            for (int j = 0; j < u; j++)
            {
                cin >> h;
                if (w)
                {
                    b[j] = h;
                    if (c[h])
                    {
                        s = q == -1 ? 0 : a[b[q]];
                        cout << s << " " << a[h] << ' ' << h << endl;
                        if (a[h] < s)
                        {
                            cout << -1 << endl;
                            w = 0;
                            continue;
                        }
                        if (u - q <= 2)
                        {
                            q = j;
                            continue;
                        }
                        d = (a[h] - s) / (j - q);
                        for (int k = q + 1; k < j; k++)
                            a[b[k]] = s + (k - q) * d;
                        q = j;
                    }
                    c[h] = 1;
                }
            }
            if (w && u - q > 2)
            {
                s = q == -1 ? 0 : a[b[q]];
                d = (NU - s) / (u - q - (q == -1));
                for (int k = q + 1; k < u; k++)
                    a[b[k]] = s + (k - q) * d;
            }
        }
        if (w)
        {
            for (int j = 1; j <= n; j++)
                cout << a[j] << ' ';
            cout << endl;
        }
    }

    return 0;
}
/*
3
4 1
2 4 3 2 4
5 2
2 4 4 2 3
2 4 4 2 3
4 2
2 2 2
1 4 2 1 4 3
*/
