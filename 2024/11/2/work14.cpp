/*(6)
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int x, y, a, b, p, p0;
    cin >> x;
    vector<int>n(x);
    for (int i = 0; i < x; i++)
    {
        p = 0;
        cin >> a;
        int j = 0;
        while (j < i)
        {
            if (a == n[j]) { p = 1; break; }
            j++;
        }
        if (p == 0)n[i] = a;
    }
    cin >> y;
    vector<int>m(y);
    for (int j = 0; j < y; j++)
    {
        p = 0;
        cin >> b;
        int i = 0;
        while (i < j)
        {
            if (b == m[i]) { p = 1; break; }
            i++;
        }
        if (p == 0)m[j] = b;
    }
    p = 0;
    for (int i = 0; i < x; i++)
    {
        p0 = 0;
        for (int j = 0; j < y; j++)
        {
            if (n[i] == m[j]) { p0 = 1; break; }
        }
        if (p0 == 0)
        {
            if (p != 0)cout << " ";
            cout << n[i];
            p = 1;
        }
    }
    for (int i = 0; i < y; i++)
    {
        p0 = 0;
        for (int j = 0; j < x; j++)
        {
            if (m[i] == n[j]) { p0 = 1; break; }
        }
        if (p0 == 0)
        {
            if (p != 0)cout << " ";
            cout << m[i];
            p = 1;
        }
    }

    return 0;
}
*/

/*(7)
#include<iostream>
using namespace std;
int main()
{
    int n,h,k;
    int x[10]={0,0,0,0,0,0,0,0,0,0};
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>h;
        for(;;)
        {
            x[h%10]++;
            h/=10;
            if(h==0)break;
        }
    }
    k=x[0];
    for(int i=0;i<10;i++)
    {
        if(k<x[i])k=x[i];
    }
    cout<<k<<":";
    for(int i=0;i<10;i++)
    {
        if(x[i]==k)cout<<" "<<i;
    }
    cout<<endl;

    return 0;
}
*/

/*(8)
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, o, p = 0;
    cin >> n >> o;
    vector<int>m(n);
    for (int i = 0; i < n; i++)cin >> m[i];
    for (int j = 0; j < n; j++)
    {
        if (m[j] == o)
        {
            cout << j;
            p = 1;
        }
    }
    if (p == 0)cout << "Not Found";

    return 0;
}
*/

/*(9)
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, k, h;
    cin >> n >> k;
    vector<int>m(n);
    for (int i = 0; i < n; i++)cin >> m[i];
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (m[j] > m[j + 1]) { h = m[j]; m[j] = m[j + 1]; m[j + 1] = h; }
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (j != 0)cout << " ";
        cout << m[j];
    }

    return 0;
*/

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int>m(n);
    for (int i = n - 1; i >= 0; i--)cin >> m[i];
    for (int j = 0; j < n; j++)
    {
        if (j != 0)cout << " ";
        cout << m[j];
    }

    return 0;
