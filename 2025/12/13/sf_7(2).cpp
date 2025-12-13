/*
2、以0-1背包和背包问题对比动态规划与贪心算法，说明哪些问题适合使用动态规划，哪些问题适合使用贪心算法。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

const int N = 1e4 + 10;
int n, C, w[N], v[N];

int dp01()                      // 0-1 背包 动规
{
    static int f[N];
    fill(f, f + C + 1, 0);
    for (int i = 1; i <= n; ++i)
        for (int j = C; j >= w[i]; --j)
            f[j] = max(f[j], f[j - w[i]] + v[i]);
    return f[C];
}

int greedy()                    // 普通背包 贪心（单位价值降序）
{
    vector<int> id(n + 1);
    for (int i = 1; i <= n; ++i) id[i] = i;
    sort(id.begin() + 1, id.end(), [](int a, int b)
        { return v[a] * w[b] > v[b] * w[a]; });
    int rem = C, val = 0;
    for (int i = 1; i <= n && rem; ++i)
    {
        int take = min(rem, w[id[i]]);
        val += take * v[id[i]] / w[id[i]];
        rem -= take;
    }
    return val;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> C;
    for (int i = 1; i <= n; ++i) cin >> w[i] >> v[i];

    auto t1 = high_resolution_clock::now();
    int r1 = dp01();
    auto t2 = high_resolution_clock::now();
    auto d1 = duration_cast<microseconds>(t2 - t1).count();

    auto t3 = high_resolution_clock::now();
    int r2 = greedy();
    auto t4 = high_resolution_clock::now();
    auto d2 = duration_cast<microseconds>(t4 - t3).count();

    cout << "0-1 dp: " << r1 << "  time: " << d1 << "us\n";
    cout << "greedy: " << r2 << "  time: " << d2 << "us\n";
    return 0;
}
/*
100 1000
61 14
91 36
14 17
83 33
56 25
39 42
68 81
75 12
99 88
45 94
70 29
33 77
50 65
89 38
95 84
11 59
27 93
52 76
84 98
17 69
48 87
66 99
38 91
55 83
22 97
31 85
69 73
44 67
12 95
58 89
25 79
36 92
63 97
18 88
41 82
28 96
54 90
15 86
47 94
32 99
76 93
21 87
64 98
37 91
53 95
19 89
43 97
26 84
71 99
34 92
60 88
13 85
49 93
30 96
67 94
23 90
57 99
16 83
40 97
62 89
35 95
51 91
24 87
69 98
29 36
74 68
17 95
96 57
38 82
65 44
91 55
12 99
87 66
94 48
29 70
77 33
65 50
38 89
84 95
59 11
93 27
76 52
98 84
69 17
87 48
99 66
91 38
83 55
97 22
85 31
73 69
67 44
95 12
89 58
79 25
92 36
97 63
88 18
82 41
96 28

*/



