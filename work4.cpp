/*（6）
#include<iostream>
using namespace std;
int main()
{
    int n, x = 0, y = 0, p = 0, k = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                p = 1;
                break;
            }
        }
        if (p == 0)
        {
            y = x; x = i;
            if (k == 2)k = 1;
        }
        p = 0;
        if (x - y == 2 && k != 2)
        {
            if (k == 1)cout << endl;
            cout << y << " " << x;
            k = 2;
        }
    }

    if (k == 0) { cout << "empty" << endl; }

    return 0;
}
*/

/*(7)
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double m = 1, x = 0, y = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1) { x += 2; }
        else { y += 2; }
        m *= x / y;
    }

    cout << setiosflags(ios::fixed) << setprecision(4) << 2 * m << endl;

    return 0;
}
*/

/*(8)
#include<iostream>
using namespace std;
int main()
{
    int n, m, num = 0;
    cin >> n >> m;
    for (int i = n; i <= m; i++)
    {
        num += i;
    }

    cout << num << endl;

    return 0;
}
*/

/*(9)
#include<iostream>
using namespace std;
int main()
{
    int n = 0;
    for (int i = 1980; i <= 2050; i++)
    {
        if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
        {
            if (n != 0) { cout << endl; }
            cout << i;
            n = 1;
        }
    }

    return 0;
}
*/


#include<iostream>
#include<string>
using namespace std;
int main()
{
    string n;
    char m;
    int j, x = 0, y = 0, z = 0;
    cin >> n;
    j = n.size();
    for (int i = 0; i < j; i++)
    {
        m = n[i];
        if ((65 <= m && m <= 90) || (97 <= m && m <= 122))
        {
            x += 1;
        }
        else if (48 <= m && m <= 57)
        {
            y += 1;
        }
        else { z += 1; }
    }

    cout << x << "," << y << "," << z << endl;

    return 0;
}