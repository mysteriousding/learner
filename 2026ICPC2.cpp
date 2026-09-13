#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
using ll = long long;
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n, q, k, n0;
    cin >> t;
    while (t--)
    {
        int h, ma = 0, sum = 0;
        cin >> n;
        n0 = 2 * n;
        vector<int>a(n0, 0);
        set<int>s;
        map<int, int>p;
        for (int i = 0; i < n; i++)
        {
            cin >> h;
            if (h < n0)
                a[h]++;
            else s.insert(h);
        }
        for (int i = 0; i <= n; i++)
            if (!a[i])
            {
                ma = i;
                break;
            }
        if (ma != n)
        {
            int v = -9, mu, mk = 0;
            for (int u : s)
            {
                if (v == -9)mu = u;
                else if (u - v == 1)
                    mk++;
                else
                {
                    p[mu] = mk;
                    mu = u, mk = 0;
                }
                v = u;
            }
            p[mu] = mk;
        }
        cin >> q;
        while (q--)
        {
            cin >> k;
            int i = ma, j;
            n0 = n;
            if (k < ma)
            {
                sum ^= ma;
                continue;
            }
            else if (k >= 2 * n)
            {
                for (; i <= n; i++)
                    if (!a[i])
                    {
                        j = k - i;
                        if (s.find(j) != s.end())
                        {
                            bool u = 1;
                            for (const auto& pr : p)
                                if (pr.first <= j && j <= pr.first + pr.second)
                                {
                                    u = 0;
                                    i += j - pr.first;
                                    break;
                                }
                            if (u)
                                break;
                        }
                    }
            }
            else
                for (; i < n0; i++)
                    if (!a[i])
                    {
                        j = k - i;
                        if (a[j] > 1);
                        else if (j > i && a[j] > 0)
                            n0 = j;
                        else break;
                    }
            sum ^= i;
        }
        cout << sum << endl;
    }
    return 0;
}
/*
2
3
0 1 3
3
1
2
5
9
0 0 1 1 2 3 3 4 5
7
4
5
6
7
8
9
10
*/
//int main()
//{
//    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    int t, n, q, k;
//    cin >> t;
//    while (t--)
//    {
//        int h, ma = 0, sum = 0;
//        cin >> n;
//        vector<int>a(n + 1, 0), b(n + 1, 0);;
//        set<int>s;
//        map<int, int>p;
//        for (int i = 0; i < n; i++)
//        {
//            cin >> h;
//            if (h <= n)
//                a[h]++;
//            else s.insert(h);
//        }
//        for (int i = 0; i <= n; i++)
//            if (!a[i])
//            {
//                ma = i;
//                break;
//            }
//        if (ma != n)
//        {
//            int v = -9, mu, mk = 0;
//            for (int u : s)
//            {
//                if (v == -9)mu = u;
//                else if (u - v == 1)
//                    mk++;
//                else
//                {
//                    p[mu] = mk;
//                    mu = u, mk = 0;
//                }
//                v = u;
//            }
//            p[mu] = mk;
//        }
//        cin >> q;
//        while (q--)
//        {
//            cin >> k;
//            if (k < ma)
//            {
//                sum ^= ma;
//                continue;
//            }
//            fill(b.begin(), b.end(), 0);
//            int i = ma, j;
//            for (; i <= n; i++)
//                if (!(a[i] - b[i]))
//                {
//                    j = k - i;
//                    if (j > n)
//                    {
//                        if (s.find(j) != s.end())
//                        {
//                            bool u = 1;
//                            for (const auto& pr : p)
//                                if (pr.first <= j && j <= pr.first + pr.second)
//                                {
//                                    u = 0;
//                                    i += j - pr.first;
//                                    break;
//                                }
//                            if (u)
//                                break;
//                        }
//                        // auto it =q.find(j);
//                        // if(it!=q.end())
//                        //     q.erase(j);
//                        // else break;
//                    }
//                    else if (a[j] - b[j] > 1 || (j > i && a[j] - b[j] > 0))
//                        b[j]++;
//                    else break;
//                }
//            sum ^= i;
//        }
//        cout << sum << endl;
//    }
//    return 0;
//}

//using namespace std;
//using ll = long long;
//int main()
//{
//    int t, n, q, k;
//    cin >> t;
//    while (t--)
//    {
//        int h, ma, sum = 0;
//        cin >> n;
//        vector<int>a(n + 1, 0);
//        set<int>s;
//        for (int i = 0; i < n; i++)
//        {
//            cin >> h;
//            if (h <= n)
//                a[h]++;
//            else s.insert(h);
//        }
//        for (int i = 0; i <= n; i++)
//            if (!a[i])
//            {
//                ma = i;
//                break;
//            }
//        cin >> q;
//        while (q--)
//        {
//            cin >> k;
//            if (k < ma)
//            {
//                sum ^= ma;
//                continue;
//            }
//            vector<int>b(n + 1, 0);
//            int i = ma, j;
//            for (; i <= n; i++)
//                if (!(a[i] - b[i]))
//                {
//                    j = k - i;
//                    if (j > n)
//                    {
//                        auto it = s.find(j);
//                        if (it != s.end())
//                            s.erase(j);
//                        else break;
//                    }
//                    else if (a[j] - b[j] > 1 || (j > i && a[j] - b[j] > 0))
//                        b[j]++;
//                    else break;
//                }
//            sum ^= i;
//        }
//        cout << sum << endl;
//    }
//    return 0;
//}