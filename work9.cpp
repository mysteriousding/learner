/*(21)
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string x, y, z;
    cin >> x >> y >> z;
    string n[3];
    char a, b, c;
    int A, B, C;
    A = B = C = 2;
    for (int i = 0;; i++)
    {
        a = x[i]; b = y[i];
        if (a == b) { continue; }
        ((int)a < (int)b) ? A-- : B--;
        break;
    }
    for (int i = 0;; i++)
    {
        b = y[i]; c = z[i];
        if (b == c) { continue; }
        ((int)b < (int)c) ? B-- : C--;
        break;
    }
    for (int i = 0;; i++)
    {
        a = x[i]; c = z[i];
        if (a == c) { continue; }
        ((int)a < (int)c) ? A-- : C--;
        break;
    }
    n[A] = x; n[B] = y; n[C] = z;
    for (int j = 0; j < 3; j++)
    {
        cout << n[j] << endl;
    }


    return 0;
}
*/

/*(22)
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
    string name[10];
    int num[10];
    float x[10], y[10], z[10], n[10], n0[10];
    float h, m = 0;
    int k = 0;
    for (int i = 0; i < 10; i++) { cin >> num[i] >> name[i] >> x[i] >> y[i] >> z[i]; }
    for (int j = 0; j < 10; j++)
    {
        n[j] = x[j] + y[j] + z[j];
        n0[j] = n[j];
        m += n[j];
    }
    m /= 30.0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (n0[j] > n0[j + 1]) { h = n0[j]; n0[j] = n0[j + 1]; n0[j + 1] = h; }
        }
    }
    for (int i = 0; i < 10; i++) { if (n[i] == n0[9]) { k = i; break; } }

    cout << fixed << setprecision(2);
    cout << m << endl;
    cout << num[k] << " " << name[k] << " " << x[k] << " " << y[k] << " " << z[k] << endl;


    return 0;
}
*/

/*(23)
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    float n[6];
    string m[3] = { "c1","c2","num" };
    int k1 = 0, k2 = 1, k3 = 0;
    float C0(float x, float y, float n, float m, int k);
    float C1(float x, float y, float n, float m, int k);
    for (int i = 0; i < 5; i++) { cin >> n[i]; }n[5] = 0;
    for (int j = 0; j < 3; j++)
    {
        cout << fixed << setprecision(2);
        cout << m[k1] << "+" << m[k2] << "=(" << n[2 * k1] + n[2 * k2] << "," << n[2 * k1 + 1] + n[2 * k2 + 1] << "i)" << endl;
        cout << m[k1] << "-" << m[k2] << "=(" << n[2 * k1] - n[2 * k2] << "," << n[2 * k1 + 1] - n[2 * k2 + 1] << "i)" << endl;
        cout << m[k1] << "*" << m[k2] << "=(" << C0(n[2 * k1], n[2 * k1 + 1], n[2 * k2], n[2 * k2 + 1], 0) << "," << C0(n[2 * k1], n[2 * k1 + 1], n[2 * k2], n[2 * k2 + 1], 1) << "i)" << endl;
        cout << m[k1] << "/" << m[k2] << "=(" << C1(n[2 * k1], n[2 * k1 + 1], n[2 * k2], n[2 * k2 + 1], 0) << "," << C1(n[2 * k1], n[2 * k1 + 1], n[2 * k2], n[2 * k2 + 1], 1) << "i)" << endl;
        if (k3 == 1) { break; }
        if (k2 == 2) { k1 = 2; k2 = -1; k3 = 1; }
        k2++;

    }

    return 0;
}

float C0(float x, float y, float n, float m, int k)
{
    float a, b;
    a = x * n - y * m;
    b = x * m + y * n;
    if (k == 0)return(a);
    else return(b);
}
float C1(float x, float y, float n, float m, int k)
{
    float a, b;
    a = (x * n + y * m) / (n * n + m * m);
    b = (y * n - x * m) / (n * n + m * m);
    if (k == 0)return(a);
    else return(b);
}
*/

/*(24)待完成
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, p;
    long long k;
    cin >> n;
    vector<long long>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        if (k > 0)arr[i] = k;
    }
    for (int j = 1; j <= n; j++)
    {
        p = 0;
        for (int i = 0; i < n; i++)
        {
            if (j == arr[i]) { p = 1; break; }
        }
        if (p == 0) { cout << j << endl; break; }
    }


    return 0;
*/


#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, h, n0;
    cin >> n;
    vector<int>m(n);
    n0 = n - 1;
    for (int i = 0; i < n; i++) { cin >> m[i]; }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n0; j++)
        {
            if (m[j] > m[j + 1]) { h = m[j]; m[j] = m[j + 1]; m[j + 1] = h; }
        }
        n0--;
    }
    for (int j = 0; j < n; j++)
    {
        cout << m[j] << " ";
        if (j == n - 1)cout << endl;
    }

    return 0;
}