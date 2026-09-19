//B
// #include <iostream>]]
//#include <queue>
//using namespace std;
//using ll = long long;
//struct V {
//    double f;
//    ll a, b;
//    bool operator<(const V o)const {
//        return f < o.f;
//    }
//}v;
//int main()
//{
//    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    ll arr[7] = { 0 }, brr[7] = { 0 }, sum, num = 0, h;
//    bool u = 1;
//    for (ll i = 1; i <= 6; i++)
//        cin >> arr[i];
//    cin >> sum;
//    for (ll i = 1; i < 6 && u; i++)
//    {
//        u = 0;
//        for (ll j = 1; j < 7 - i; j++)
//            if (arr[j] > arr[j + 1])
//                h = arr[j], arr[j] = arr[j + 1], arr[j + 1] = h, u = 1;
//    }
//    priority_queue<V>q;
//    for (ll i = 1; i <= 6; i++)
//    {
//        v.a = i;
//        v.b = arr[i] + 1;
//        v.f = v.a * 1.0 / v.b;
//        q.push(v);
//    }
//    for (ll k = 0, i; k < 6; k += i)
//    {
//        v = q.top();
//        q.pop();
//        i = (sum - 6 + k) / (v.b - 1);
//        if (i > 6 - k)
//            i = 6 - k;
//        sum -= i * v.b;
//        num += i * v.a;
//        brr[v.a] = i;
//        if (sum == 6 - k - i)
//        {
//            brr[0] = 6 - k - i;
//            sum = 0;
//            break;
//        }
//    }
//    if (num < 19)cout << "NO" << endl;
//    else
//    {
//        u = 0, h = 1;
//        cout << "YES" << endl;
//        for (ll i = 0; i <= 6; i++)
//            for (ll j = 0; j < brr[i]; j++)
//            {
//                if (u)
//                    cout << ' ';
//                cout << arr[i] + 1 + (h == 6 ? sum : 0);
//                u = 1, h++;
//            }
//    }
//
//    return 0;
//}
/*
9856 1 85888888 1 1 898
99999999999999
*/
//B
//#include <iostream>
//#include <queue>
//using namespace std;
//using ll = long long;
//int main()
//{
//    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    ll arr[7] = { 0 }, brr[7] = { 0 }, sum, num = 0, h;
//    bool u = 1;
//    for (ll i = 1; i <= 6; i++)
//        cin >> arr[i];
//    cin >> sum;
//    for (ll i = 1; i < 6 && u; i++)
//    {
//        u = 0;
//        for (ll j = 1; j < 7 - i; j++)
//            if (arr[j] > arr[j + 1])
//                h = arr[j], arr[j] = arr[j + 1], arr[j + 1] = h, u = 1;
//    }
//    u = 0;
//    for (int i = 0; i <= 6; i++)
//        for (int j = 0; j <= 6 - i; j++)
//            for (int k = 0; k <= 6 - i - j; k++)
//                for (int x = 0; x <= 6 - i - j - k; x++)
//                    for (int y = 0; y <= 6 - i - j - k - x; y++)
//                        for (int z = 0; z <= 6 - i - j - k - x - y; z++)
//                            if (i + j * 2 + k * 3 + x * 4 + y * 5 + z * 6 > 18)
//                                if (i * arr[1] + j * arr[2] + k * arr[3] + x * arr[4] + y * arr[5] + z * arr[6] + 6 <= sum)
//                                {
//                                    sum -= i * arr[1] + j * arr[2] + k * arr[3] + x * arr[4] + y * arr[5] + z * arr[6] + 6;
//                                    brr[0] = 6 - i - j - k - x - y - z;
//                                    brr[1] = i;
//                                    brr[2] = j;
//                                    brr[3] = k;
//                                    brr[4] = x;
//                                    brr[5] = y;
//                                    brr[6] = z;
//                                    h = 1;
//                                    cout << "YES" << endl;
//                                    for (ll i = 0; i <= 6; i++)
//                                        for (ll j = 0; j < brr[i]; j++)
//                                        {
//                                            if (u)
//                                                cout << ' ';
//                                            cout << arr[i] + 1 + (h == 6 ? sum : 0);
//                                            u = 1, h++;
//                                        }
//                                    return 0;
//                                }
//    if (u == 0)
//        cout << "NO" << endl;
//
//    return 0;
//}

#include <iostream>
#include <string>
#include <map>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    map<string, string>p;
    string s, t, w;
    int arr[2010], n;
    while (cin >> s)
    {
        cin >> n;
        int a, b, q, sum = 0;
        bool v = 1;
        t = "";
        if (s == "first")
        {
            for (int i = 0; i < n; i++)
            {
                cin >> b;
                arr[i] = b;
                if (!i)
                    q = a = b;
                else
                {
                    v ^= a > b;
                    sum += abs(b - a);
                    t += to_string(a) + ' ';
                    a = b;
                }
            }
            v ^= b > q;
            sum += abs(q - b);
            t += to_string(b);
            w = to_string(n) + ' ' + to_string(sum) + ' ' + (v ? '+' : '-');
            p[w] = t;
            for (int i = n; i > 0; i--)
            {
                for (int j = 0; j < n; j++)
                {
                    if (j)cout << ' ';
                    cout << arr[(i + j) % n];
                }
                cout << endl;
            }
        }
        else if (s == "second")
        {
            for (int j = 0; j < n; j++)
            {
                for (int i = 0; i < n; i++)
                {
                    cin >> b;
                    if (!j)
                    {
                        if (!i)
                            q = a = b;
                        else
                        {
                            v ^= a > b;
                            sum += abs(b - a);
                            a = b;
                        }
                    }
                }
                if (!j)
                {
                    v ^= b > q;
                    sum += abs(q - b);
                    w = to_string(n) + ' ' + to_string(sum) + ' ' + (v ? '+' : '-');
                    cout << p[w] << endl;
                }
            }
        }
    }

    return 0;
}
