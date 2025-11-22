//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//int main()
//{
//    string m;
//    vector<int>a;
//    int n = 0, l = 0, k, num;
//    bool v = 1;
//    getline(cin, m, '\n');
//    num = m.size();
//    while (v)
//    {
//        for (int i = 1; i <= 10; i++)
//        {
//            k = 0;
//            if (l + i <= num)
//            {
//                for (int j = 0; j < i; j++)
//                {
//                    k *= 2;
//                    k += m[l++] - '0';
//                }
//                n++;
//                a.push_back(k);
//            }
//            else
//            {
//                v = 0;
//                break;
//            }
//        }
//    }
//
//    cout << n << endl;
//    for (int i = 0; i < n; i++)
//        cout << a[i] << " ";
//
//    return 0;
//}
//// 64 位输出请用 printf("%lld")


//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int main()
//{
//    string m;
//    long long n, l = 1, num = 0, h, k = 0, v;
//    const int N = 10007;
//    vector<int>a;
//    getline(cin, m, '\n');
//    n = m.size();
//    for (int i = 3; i < n; i += 4)
//    {
//        v = m[i - 1] == '-' ? -1 : 1;
//        h = 0;
//        while ('0' <= m[i] && m[i] <= '9')
//            h *= 10, h += m[i++] - '0';
//        h *= v;
//        l *= h;
//        a.push_back(h);
//        k++;
//    }
//    for (int i = 0; i < k; i++)
//    {
//        num += (l / a[i]) % N;
//        num %= N;
//    }
//    cout << num << endl;
//
//    return 0;
//}
//// 64 位输出请用 printf("%lld")


//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    int n, t, q;
//    cin >> n;
//    vector<int>a(n), b(n);
//    for (int i = 0; i < n; i++)
//        cin >> a[i] >> b[i];
//    cin >> t;
//    while (t--)
//    {
//        cin >> q;
//        vector<int>w(q + 1, 0);
//        for (int i = 0; i < n; i++)
//            for (int j = q; j >= a[i]; j--)
//                w[j] = max(w[j], w[j - a[i]] + b[i]);
//        cout << (w[q] ? w[q] : -1) << endl;
//    }
//
//    return 0;
//}
//// 64 位输出请用 printf("%lld")

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct yao
//{
//    int a, b;
//};
//bool pd(const yao& x, const yao& y)
//{
//    return x.b > y.b;
//}
//int main()
//{
//    int n, t, q, w;
//    cin >> n;
//    vector<yao>N(n);
//    for (int i = 0; i < n; i++)
//        cin >> N[i].a >> N[i].b;
//    sort(N.begin(), N.end(), pd);
//    cin >> t;
//    while (t--)
//    {
//        w = -1;
//        cin >> q;
//        for (int i = 0; i < n; i++)
//            if (q >= N[i].a)
//            {
//                w = N[i].b;
//                break;
//            }
//        cout << w << endl;
//    }
//
//    return 0;
//}
//// 64 位输出请用 printf("%lld")


#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int>a;
int js(string& m)//计算同时包含'r'和'e'的子串数量
{
    int n = m.size(), l = -1, h[2] = { 0 };
    int num = a[n];
    for (int i = 0; i < n; i++)
    {
        if (l == -1 && (m[i] == 'r' || m[i] == 'e'))
            l = 0, h[l] = i, h[!l] = 0;
        else if (!l && m[i] == 'e')
            l = 1, num -= a[i - h[1]], h[1] = i;
        else if (l && m[i] == 'r')
            l = 0, num -= a[i - h[0]], h[0] = i;
    }
    num -= a[n - 1 - (l == -1 ? n : h[l])];
    return num;
}
int main()
{
    string m, s = "";
    int num = 0;
    getline(cin, m, '\n');
    a.resize(m.size());
    for (int i = 0; m[i]; i++)
    {
        if (m[i] == 'd')
        {
            num += js(s);
            s = "";
        }
        else s += m[i];
        a[i + 1] = a[i] + i + 1;
    }
    num += js(s);

    cout << num << endl;

    return 0;
}

// 64 位输出请用 printf("%lld")


