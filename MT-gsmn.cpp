/*
1、四大名著-三国签到
*
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cout << (n % 3 ? "NO" : "YES") << endl;

    return 0;
}
*/

/*
2、元音字母统计
*
#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
    int n, m = 0;
    string s;
    set<char>c = { 'a', 'e', 'i', 'o', 'u' };
    getline(cin, s);
    n = s.size();
    for (char i : s)
        if (c.count(i))
            m++;
    cout << m << endl;

    return 0;
}
*/

/*
3、回文子序列
*
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
#define N 998244353
int main()
{
    int n, m = 0;
    string s;
    getline(cin, s);
    n = s.size();
    map<char,vector<int>>a;
    map<char, int>b;
	for (int i = 0; i < n; i++)
		a[s[i]].push_back(i), b[s[i]]++;
	for (auto i : b)
		m = ;

    return 0;
}
*/

/*
5、子序列匹配
*
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int k, n, l;
    string s, t;
    bool v, u;
    getline(cin, s);
    n = s.size();
    map<char, vector<int>>a;
    map<char, int>b;
    for (int i = 0; i < n; i++)
        a[s[i]].push_back(i), b[s[i]]++;
    cin >> k;
    cin.ignore();
    while (k--)
    {
        v = 1;
        map<char, int>c;
        getline(cin, t);
        n = t.size();
        for (int i = 0; i < n; i++)
            c[t[i]]++;
        for (auto i : c)
            if (i.second > b[i.first])
            {
                v = 0;
                break;
            }
        if (v)
        {
            l = -1;
            for (int i = 0; i < n; i++)
            {
                u = 1;
                for (int j : a[t[i]])
                    if (j > l)
                    {
                        l = j;
                        u = 0;
                        break;
                    }

                if (u)
                {
                    v = 0;
                    break;
                }
            }
        }
        cout << (v ? "YES" : "NO") << endl;
    }

    return 0;
}
*/

/*
6、相同元素
*
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int>a(n);
    map<int, int>b;
    for (int i = 0; i < n; i++)
        cin >> a[i], b[a[i]]++;
    for (int i = 0; i < n; i++)
        cout << b[a[i]] - 1 << ' ';

    return 0;
}
*/

/*
8、序列排名
*
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int>a(n), b(n);
    map<int, int>c;
    for (int i = 0; i < n; i++)
        cin >> a[i], b[i] = a[i];
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++)
        if (c[b[i]] == 0)
            c[b[i]] = i + 1;
    for (int i = 0; i < n; i++)
        cout << c[a[i]] << ' ';

    return 0;
}
*/

/*
9、矩阵奇阵
*
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int n, m, k, v, x, y;
    cin >> n >> m;
    vector<vector<int>>a(n, vector<int>(m));
    map<int, int>b;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    cin >> k;
    while (k--)
    {
        cin >> v >> x >> y, x--;
        b[x] += (v == 1 ? y : -y) % m;
    }
    for (int i = 0; i < n; i++)
    {
        b[i] %= m;
        if (b[i] < 0)
            b[i] += m;
        v = b[i] + m;
        for (int j = b[i]; j < v; j++)
            cout << a[i][j % m] << ' ';
        cout << endl;
    }

    return 0;
}
*/

/*
10、数字相乘
*
#include <iostream>
using namespace std;
int main()
{
    long long n, m = 1, h;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h;
        while (!(h % 10))
            h /= 10;
        m *= h % 1000000000;
        while (!(m % 10))
            m /= 10;
        m %= 1000000000;
    }
    cout << m % 10 << endl;

    return 0;
}
*/

/*
12、姓名分数
*
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    int n, m, v;
    string s;
    bool u;
    cin >> n;
    map<string, int>a;
    for (int i = 0; i < n; i++)
        cin >> s, a[s] = 0;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> v >> s;
        u = a.count(s);
        if (v == 1)
        {
            cin >> v;
            if (u)
                a[s] += v;
        }
        else
            cout << (u ? a[s] : -1) << endl;
    }

    return 0;
}
*/

/*
13、符号统计
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int n, m, x, y, k;
    string s;
    cin >> n >> m;
    cin.ignore();
    getline(cin, s);
    vector<vector<short>>a(26, vector<short>(n + 1, 0));
    for (int i = 0; i < n; i++)
        a[s[i] - 'a'][i + 1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 26; j++)
            a[j][i] += a[j][i - 1];
    while (m--)
    {
        cin >> x >> y;
        k = 0;
        for (int i = 0; i < 26; i++)
        {
            k += (a[i][y] - a[i][x - 1]) % 2;
        }
        cout << 26 - k << ' ' << k << endl;
    }

    return 0;
}