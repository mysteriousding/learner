/*
1、以最大子段和问题为例，说明分治法与动态规划的区别，分别设计并实现程序，分析两者的时间复杂度，并比较时间运行时间的差异。
*/
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace chrono;

const int N = 1e6 + 10;
int n, a[N];

int dac(int l, int r)           //分治
{
    if (l == r) return max(a[l], 0);
    int m = (l + r) >> 1, lmax = 0, rmax = 0, sum = 0;
    for (int i = m; i >= l; i--) sum += a[i], lmax = max(lmax, sum);
    sum = 0;
    for (int i = m + 1; i <= r; i++) sum += a[i], rmax = max(rmax, sum);
    int cross = lmax + rmax;
    int left = dac(l, m);
    int right = dac(m + 1, r);
    return max({ cross, left, right });
}

int dp()                        //动态规划
{
    int ans = 0, cur = 0;
    for (int i = 1; i <= n; i++)
    {
        cur = max(a[i], cur + a[i]);
        ans = max(ans, cur);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    auto t1 = high_resolution_clock::now();
    int r1 = dac(1, n);
    auto t2 = high_resolution_clock::now();
    auto d1 = duration_cast<microseconds>(t2 - t1).count();

    auto t3 = high_resolution_clock::now();
    int r2 = dp();
    auto t4 = high_resolution_clock::now();
    auto d2 = duration_cast<microseconds>(t4 - t3).count();

    cout << r1 << ' ' << r2 << '\n';
    cout << "dac " << d1 << "us\ndp  " << d2 << "us\n";
    return 0;
}
/*
100
-61 91 14 -36 83 -17 56 -25 39 -42 68 -81 75 -12 99 -88 45 -94 70 -29 33 -77 50 -65 89 -38 95 -84 11 -59 27 -93 52 -76 84 -98 17 -69 48 -87 66 -99 38 -91 55 -83 22 -97 31 -85 69 -73 44 -67 12 -95 58 -89 25 -79 36 -92 63 -97 18 -88 41 -82 28 -96 54 -90 15 -86 47 -94 32 -99 76 -93 21 -87 64 -98 37 -91 53 -95 19 -89 43 -97 26 -84 71 -99 34 -92 60 -88 13 -85 49 -93 30 -96 67 -94 23 -90 57 -99 16 -83 40 -97 62 -89 35 -95 51 -91 24 -87 69 -98

*/


