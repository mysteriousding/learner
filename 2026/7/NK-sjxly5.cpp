#include <iostream>
#include <vector>
using namespace std;

const int N = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    long long l, k, w;
    cin >> n >> c;

    vector<int> a(n + 1);
    vector<int> p;
    vector<bool> u(n + 1, 0);
    a[1] = 0;

    for (int i = 2; i <= n; ++i)
    {
        if (!u[i])
        {
            p.push_back(i);
            a[i] = 1;
        }
        for (int x : p)
        {
            l = 1LL * i * x;
            if (l > n) break;
            u[l] = true;
            a[l] = a[i] + 1;
            if (i % x == 0) break;
        }
    }

    vector<int> z = { 1, 1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
                     31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79 };

    k = 0, w = 1;
    for (int i = 1; i <= n; ++i)
    {
        w = w * c % N;
        int g = z[a[i]];
        k = (k + g * w) % N;
    }
    cout << k << endl;

    return 0;
}
