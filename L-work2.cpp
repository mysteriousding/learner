#include <iostream>
#include <algorithm> 
#include <vector>

using namespace std;

//int main()
//{
//    int n, q, h, co, mi, k, nu, shu;
//    cin >> n ;
//    vector<int>a(n ), b(n, 1);
//    for (int i = 0; i < n; i++)
//        cin >> a[i];
//    sort(a.begin(), a.end() - 2);
//
//   
//
//    return 0;
//}

//int main()
//{
//    int n, t, v, d, l, q, p, o;
//    cin >> n >> t;
//    vector<int>a(n);
//    for (int i = 0; i < n; i++)
//        cin >> a[i];
//    while (t--)
//    {
//        cin >> v >> d >> l;
//        q = 0, p = n - 1;
//        while (q <= p)
//        {
//            o = q + (p - q) / 2;
//            if (a[o] > d)p = o - 1;
//            else if (a[o] < d)q = o + 1;
//            else break;
//        }
//        if (v == 1)
//        {
//            a[o] += l;
//            for (int i = o + 1; i < n; i++)
//                if (a[i] > a[i - 1])break;
//                else a[i] = a[i - 1] + 1;
//        }
//        else
//        {
//            a[o] -= l;
//            for (int i = o - 1; i >= 0; i--)
//                if (a[i] < a[i + 1])break;
//                else a[i] = a[i + 1] - 1;
//        }
//        for (int i = 0; i < n; i++)
//            cout << a[i] << ' ';
//        cout << endl;
//    }
//
//    return 0;
//}






int main()
{
    int n, m, l, r, h, mi = 1e9, nu = 0, b[2];
    cin >> n >> m;
    vector<int>a(n + 1, 1);
    a[0] = 1e9;
    for (int i = 0; i < n; i++)
    {
        cin >> h;
        if (a[0] > h)
            a[0] = h;
    }
    while (m--)
    {
        cin >> l >> r;
        b[1] = r - l;
        int i = 0;
        for (; i < n; i++)
            if (l > 0)l -= a[i];
            else
            {
                b[0] = i, r = b[1] + l;
                break;
            }
        if (i == n)
            b[0] = b[1] = n+1;
        for (; i < n; i++)
            if (r > 0)r -= a[i];
            else
            {
                b[1] = i;
                break;
            }
        if (i == n)
            b[1] = n+1;
        cout << b[0] << ' ' << b[1] << endl;
        a[0]++, a[b[0] - 1]--, a[b[1]-1]++;
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';

    return 0;
}