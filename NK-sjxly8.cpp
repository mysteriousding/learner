#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
const int N = 5005;

ll C[N][N];

ll calc(ll n, ll m) {
    if (m < 0 || m > n) return 0;
    ll res = 1;
    for (ll i = 1; i <= m; ++i) {
        res = res * ((n - m + i) % MOD) % MOD;
        ll inv = 1, x = i, p = MOD - 2;
        while (p) {
            if (p & 1) inv = inv * x % MOD;
            x = x * x % MOD;
            p >>= 1;
        }
        res = res * inv % MOD;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < N; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> a(m);
        for (int i = 0; i < m; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        ll ans = 1;
        for (int i = 0; i < m; ++i) {
            int v = a[i];
            int need = v - i - 1;
            int can = v - 1;
            if (need > can) { ans = 0; break; }
            ans = ans * C[can][need] % MOD;
        }
        int used = a.back();
        int rem = n - m;
        if (rem > 0) {
            ans = ans * calc(1000000000 - used, rem) % MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}
