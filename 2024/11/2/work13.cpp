/*(1)
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, k = 0;
    cin >> n;
    vector<int>m(n);
    for (int i = 0; i < n; i++)cin >> m[i];
    for (int j = 0; j < n - 1; j++)
    {
        if (k != 0)cout << " ";
        cout << m[j + 1] - m[j];
        k++;
        if (k == 3)
        {
            k = 0;
            cout << endl;
        }

    }

    return 0;
*/

/*(2)
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, a, b;
    cin >> n;
    vector<int>m(n);
    for (int i = 0; i < n; i++)cin >> m[i];
    a = m[0]; b = 0;
    for (int j = 0; j < n; j++)
    {
        if (m[j] > a)
        {
            a = m[j];
            b = j;
        }
    }

    cout << a << " " << b << endl;

    return 0;
}
*/

/*(3)
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, m, h;
    cin >> n >> m;
    vector<int>x(n);
    for (int i = 0; i < n; i++)cin >> x[i];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            h = x[0];
            for (int l = 0; l < n - 1; l++) x[l] = x[l + 1];
            x[n - 1] = h;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i != 0)cout << " ";
        cout << x[i];
        if (i == n - 1)cout << endl;
    }

    return 0;
}
*/

/*(4)
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, m, h;
    cin >> n >> m;
    vector<int>x(n);
    for (int i = 0; i < n; i++)cin >> x[i];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            h = x[n - 1];
            for (int l = n - 1; l > 0; l--)x[l] = x[l - 1];
            x[0] = h;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i != 0)cout << " ";
        cout << x[i];
        if (i == n - 1)cout << endl;
    }

    return 0;
}
*/

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, h1, i1, h2, i2;
    cin >> n;
    vector<int>m(n);
    for (int i = 0; i < n; i++)cin >> m[i];

    h1 = m[0]; i1 = 0;
    for (int i = 0; i < n; i++) { if (m[i] < h1) { h1 = m[i]; i1 = i; } }
    m[i1] = m[0]; m[0] = h1;

    h2 = m[0]; i2 = 0;
    for (int j = 0; j < n; j++) { if (m[j] > h2) { h2 = m[j]; i2 = j; } }
    m[i2] = m[n - 1]; m[n - 1] = h2;

    for (int j = 0; j < n; j++)
    {
        cout << m[j] << " ";
    }

    return 0;
}
