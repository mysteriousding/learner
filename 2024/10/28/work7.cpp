/*(11)
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int m, n;
    float x, y, z;
    cin >> m >> n;
    x = n * m * 2.0 / (n - m);
    y = (6.0 * n - 8.0 * m) / (n - m);
    z = x / (10.0 - y);

    cout << setiosflags(ios::fixed) << setprecision(1);
    cout << "Original number of visitors: " << x << endl;
    cout << "New arriavlas per minute: " << y << endl;
    cout << "Check time when 10 gates are opened: " << z;

    return 0;
}
*/

/*(12)
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    float x, y, z, p, s;
    cin >> x >> y >> z;
    if (x + y > z && x + z > y && y + z > x)
    {
        p = (x + y + z) / 2.0;
        s = pow(p * (p - x) * (p - y) * (p - z), 1.0 / 2);
        cout << setiosflags(ios::fixed) << setprecision(2) << s << endl;
    }
    else { cout << "Error Input." << endl; }

    return 0;
}
*/

/*(13)
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    float YD(float x, float y);
    float v, a, L;
    cin >> v >> a;
    L = YD(v, a);

    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << "The shortest length of run  way: " << L << endl;

    return 0;
}

float YD(float x, float y)
{
    float z;
    z = pow(x, 2) / (2.0 * y);
    return(z);
}
*/

/*(14)
#include<iostream>
#include<iomanip>
#include<cmath>
#define pi 3.14
using namespace std;
int main()
{
    float v1, v2, l;
    cin >> v1 >> v2;
    v1 = 4.0 / 3 * pi * pow(v1 / 2.0, 3);
    v2 = 4.0 / 3 * pi * pow(v2 / 2.0, 3);
    l = pow(v1 + v2, 1.0 / 3);

    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << "Side length of cube: " << l << endl;

    return 0;
}
*/

#include<iostream>
#include<cmath>
#define pi 3.1415926
using namespace std;
int main()
{
    float r;
    cin >> r;
    r = pi * pow(r, 2);

    cout << r << endl;

    return 0;
}
