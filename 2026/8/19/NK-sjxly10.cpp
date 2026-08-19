//#include <iostream>
//#include <iomanip>	
//using namespace std;
//int main()
//{
//	int t, m, r, c, n;
//	double d;
//	cin >> t;
//	while (t--)
//	{
//		cin >> m >> r >> c;
//		if (c < r)
//		{
//			d = m * 1.0 / c;
//			d = (d > 1) ? 1 : d;
//		}
//		else
//		{
//			n = (c - m) / (m + r);
//			n = (c <= m) ? 0 : (n == 0) ? 1 : n;
//			d = (n + 1) * m * 1.0;
//			d = d / (d + n * r);
//		}
//
//		cout << fixed << setprecision(12) << d << endl;
//	}
//
//	return 0;
//}
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int t, m, r, c;
    long long n, s, v;
    double a;
    cin >> t;
    while (t--)
    {
        cin >> m >> r >> c;

        a = m * 1.0 / (m + r);
        a = a > 0 ? a : 0;

        for (long long i = 0; i <= 1000; i++)
        {
            s = (i + 1) * m;
            n = (i + 1) * m + i * r;
            v = n;
            if (n < c)
                v = c;
            a = max(a, s * 1.0 / v);

            if (n > c + m + r)
                break;
        }

        cout << fixed << setprecision(12) << a << endl;
    }

    return 0;
}
