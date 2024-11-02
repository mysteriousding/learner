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
    int x, y, p = 0, h;
    cin >> x;
    vector<int>n(x);
    for (int i = 0; i < x; i++)cin >> n[i];
    cin >> y;
    vector<int>m(y);
    for (int j = 0; j < y; j++)cin >> m[j];
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (n[i] == m[j])
            {
                n[i] = 1e8;
                m[j] = 1e8;
            }
        }
    }
    for (int i = 0; i < x - 1; i++)
    {
        for (int j = 0; j < x - 1; j++)
        {
            if (n[j] > n[j + 1]) { h = n[j]; n[j] = n[j + 1]; n[j + 1] = h; }
            else if (n[j] == n[j + 1]) { n[j] = 1e8; }
        }
    }

    for (int i = 0; i < y - 1; i++)
    {
        for (int j = 0; j < y - 1; j++)
        {
            if (m[j] > m[j + 1]) { h = m[j]; m[j] = m[j + 1]; m[j + 1] = h; }
            else if (m[j] == m[j + 1]) { m[j] = 1e8; }
        }
    }

    /*for (int k = 0; k < x; k++)
    {
        if (n[k] != 1e8)
        {
            if (k != 0)cout << " ";
            cout << n[k];
        }
    }
    for (int l = 0; l < y; l++)
    {
        if (m[l] != 1e8)
        {
            cout << " " << m[l];
        }
    }*/


    return 0;
}