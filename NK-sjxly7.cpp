#include <iostream>
using namespace std;
int main()
{
    long long n, t, s, u, m = 0;
    cin >> n;
    for (long long b = 1; b * b <= n; ++b)
    {
        t = 0;
        while (1)
        {
            s = b * b + t * b * (b + 1);
            if (s > n)
                break;
            u = n - s + 1;
            if (u > b)
                u = b;
            m += u;
            ++t;
        }
    }
    cout << m << endl;
    return 0;
}