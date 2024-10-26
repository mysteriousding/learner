/*(1)
#include<iostream>
using namespace std;
int main()
{
    int n;
    long long m = 1;
    cin >> n;
    for (n;; n--)
    {
        if (n == 0)break;
        m *= n;
    }

    cout << "fact = " << m << endl;

    return 0;
}
*/

/*(2)
#include<iostream>
using namespace std;
int main()
{
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 1; i <= n || i <= m; i++)
    {
        if (n % i == 0 && m % i == 0)x = i;
    }
    y = n * m / x;

    cout << x << "," << y << endl;

    return 0;
}
*/

/*(3)
#include<iostream>
#include<iomanip>
#define pi 3.14
using namespace std;
int main()
{
    char n;
    float m, k, x = 0, y = 0;
    while (1)
    {
        cin >> n;
        if (n == 'c')
        {
            cin >> m;
            x += pi * m * m;
        }
        else if (n == 'r')
        {
            cin >> m >> k;
            y += m * k;
        }
        if (n == 'n')break;
    }

    cout << setiosflags(ios::fixed) << setprecision(2) << x + y << endl;

    return 0;
}
*/

/*(4)
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n;
    double m=0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        m += 1.0 / (2 * i + 1);
    }

    cout << "sum = " << setiosflags(ios::fixed) << setprecision(6) << m << endl;

    return 0;
}
*/

#include<iostream>
using namespace std;
int main()
{
    int h;
    cin >> h;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 0; j < h - i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k <= 2 * i; k++)
        {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}