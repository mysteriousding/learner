/*(26)
#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;

    cout<<n+m;

    return 0;
}
*/


#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, k = 0;
    cin >> n;
    vector<int>m(n);
    if (n < 1 || n>500)goto end;
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
        if (m[i] > 1000 || m[i] < -1000)goto end;
    }
    for (int j = 0; j < n; j++)
    {
        for (int l = 0; l < n; l++)
        {
            if (m[j] == -m[l])k++;
            if (j == l)break;
        }
    }

    cout << k;
end:

    return 0;
}


/*(28)
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int min(int a[], int n);
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++) { cin >> a[i]; }
    int m = min(a.data(), n);

    cout << m;

    return 0;
}

int min(int x[], int y)
{
    int h;
    for (int i = 0; i < y - 1; i++)
    {
        if (x[i] < x[i + 1]) { h = x[i]; x[i] = x[i + 1]; x[i + 1] = h; }
    }
    return(x[y - 1]);
}
*/

/*(29)
#include<iostream>
using namespace std;
int main()
{
    int n, m = 2;
    int a = 1, b = 1;
    cin >> n;
    if (n == 1 || n == 2) { cout << 1; }
       else
       {
           for (;;)
           {
               a = a + b;
               m++;
               if (m == n) { cout << a; break; }
               b = b + a;
               m++;
               if (m == n) { cout << b; break; }
           }
       }

    return 0;
*/


//#include<iostream>
//#include<cmath>
//using namespace std;
//int main()
//{
//    float a, b, c, p;
//    cin >> a >> b >> c;
//    if (a + b > c && b + c > a && a + c > b)
//    {
//        p = (a + b + c) / 2;
//        p = pow(p * (p - a) * (p - b) * (p - c), 1.0 / 2);
//        cout << p << endl;
//    }
//    else cout << "No";
//
//    return 0;
//}