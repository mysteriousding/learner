#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
bool ok(const vector<int>& a, int k, double m)
{
    int n = a.size();
    vector<double>s(n + 1);
    double mn = 0;
    for (int i = 1; i <= n; ++i)
        s[i] = s[i - 1] + a[i - 1] - m;
    for (int i = k; i <= n; ++i)
    {
        mn = min(mn, s[i - k]);
        if (s[i] - mn >= 0)
            return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int>a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    double l = 1, r = 1e6;
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (ok(a, k, mid))l = mid;
        else r = mid;
    }
    cout << fixed << setprecision(6) << l << '\n';
    return 0;

}

