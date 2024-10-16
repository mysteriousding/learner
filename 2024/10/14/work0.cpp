/*(1)
#include<iostream>
using namespace std;
int main()
{
    long long A, B;
    cin >> A >> B;
    cout << A << "+" << B << "=" << A + B << endl;

    return 0;
}
*/

/*(2)
#include<iostream>
using namespace std;
int main()
{
    int n, a, i = 0;
    cin >> n;
    while (true)
    {
        a = n % 10;
        n /= 10;
        if (a == 0 && i == 0) {}
        else
        {
            i++;
            cout << a;
        }
        if (n == 0) { break; }
    }
    return 0;
}
*/

/*(3)
#include<iostream>
using namespace std;
int main()
{
    long a, b;
    cin >> a >> b;
    cout << "周长 = " << (a + b) * 2 << endl;
    cout << "面积 = " << a * b << endl;

    return 0;
}
*/

/*(4)
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double x, y;
    cin >> x;
    y = 1 / (1 - (1 / x));
    cout << setiosflags(ios::fixed) << setprecision(2) << y << endl;

    return 0;
}
*/

/*(5)
#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    a/=10;
    b/=10;
    cout<<a+b<<endl;

    return 0;
}
*/

/*(6)
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    float c;
    cin >> c;
    cout << "摄氏温度为：" << setiosflags(ios::fixed) << setprecision(2) << (c - 32) / 1.80 << endl;

    return 0;
}
*/

/*(7)
#include<iostream>
using namespace std;
int main()
{
    char a;
    int b;
    cin >> a >> b;
    cout << (int)(a - 64) << endl << (char)(b + 64) << endl;

    return 0;
}
*/


#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
#define pi 3.14
int main()
{
    double a, b, c, v1, v2;
    cin >> a >> b;
    v1 = 4 / 3.0 * pi * pow(a / 2, 3);
    v2 = 4 / 3.0 * pi * pow(b / 2, 3);
    c = cbrt(v1 + v2);
    cout << "Side length of cube:" << setiosflags(ios::fixed) << setprecision(2) << c << endl;

    return 0;
}
