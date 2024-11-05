


/*(37)
#include<iostream>
using namespace std;
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (d >= b)
    {
        a = c - a;
        b = d - b;
    }
    else
    {
        a = c - 1 - a;
        b = d + 60 - b;
    }

    cout << a << ":" << b << endl;

    return 0;
}
*/ 

/*(38)
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, m, n0;
    int p1, p2, k;
    p1 = p2 = k = 0;
    cin >> n >> m;
    n0 = n + 1;
    vector<int>a(n0);
    for (int i = 0; i < n0; i++) { a[i] = i; }
    while (1)
    {
        if (k == n0)k = 1;

        if (a[k] != 0)p1++;

        if (p1 == m)
        {
            if (p2 != 0)cout << " ";
            cout << k;
            p1 = 0; p2++;
            a[k] = 0;
        }
        k++;
        if (p2 == n)break;
    }

    return 0;
*/

/*(39）
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, h;
    while (cin >> n)
    {
        vector<int>m(n);
        for (int i = 0; i < n; i++) { cin >> m[i]; }
        int y;
        cin >> y;
        vector<int>x(y);
        for (int j = 0; j < y; j++) { cin >> x[j]; }
        for (int j = 0; j < n - 1; j++)
        {
            for (int i = 0; i < n - 1 - j; i++)
            {
                if (m[i] > m[i + 1]) { h = m[i]; m[i] = m[i + 1]; m[i + 1] = h; }
            }
        }
        for (int l = 0; l < n; l++)
        {
            if (l != 0)cout << " ";
            cout << m[l];
            if (l == n - 1)cout << endl;
        }

        for (int i = 0; i < y; i++)
        {
            //if(n<0||n>100||m<0||m>100)break;
            int k1 = 0, k2 = n - 1, k3, l = 0;
            while (k1 <= k2)
            {
                k3 = (k1 + k2) / 2;
                if (x[i] == m[k3])
                {
                    if (i != 0)cout << " ";
                    cout << k3 + 1;
                    l = 1;

                    for (int v = k3 + 1; v < n; v++)
                    {
                        if (x[i] == m[v])cout << " " << v + 1;
                    }

                    break;
                }
                else if (x[i] > m[k3]) { k1 = k3 + 1; }
                else { k2 = k3 - 1; }
            }
            if (l == 0)
            {
                if (i != 0)cout << " ";
                cout << 0;
            }
        }
        cout << endl;
    }

    return 0;
}
*/
