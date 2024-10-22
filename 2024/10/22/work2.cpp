/*(6)
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << a + b + c << ",";
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << (a + b + c) / 3.0 << endl;

    return 0;
}
*/

/*(7)
#include<iostream>
using namespace std;
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b <= d)
    {
        a = c - a;
        b = d - b;
    }
    else
    {
        a = c - a - 1;
        b = d + 60 - b;
    }

    cout << a << ":" << b << endl;

    return 0;
}
*/

/*(8)
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    float a, b, c;
    cin >> a >> b;
    c = pow(pow(a, 2) + pow(b, 2), 1.0 / 2);

    cout << setiosflags(ios::fixed) << setprecision(1);
    cout << "The diagonal legnth is: " << c << " cm." << endl;

    return 0;
}
*/

/*(9)
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;

    cout << "2 ^ " << n << " = " << (long long)pow(2, n) << endl;

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
    int x = 0, y = 0;
    cin >> n;
    for (int i = 0;; i ++)
    {
        m = n[i];
        if (m =='0') { x += 1; }
           else if (m == '1') { y += 1; }
              else { break; }
    }

    cout << "card(0)=" << x << endl;
    cout << "card(1)=" << y << endl;

    return 0;
}
