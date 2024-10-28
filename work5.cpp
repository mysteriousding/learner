/*(1)
#include<iostream>
using namespace std;
int main()
{
    char n;
    int m;
    cin >> n >> m;
    n = n - 64;
    m = m + 64;

    cout << (int)n << endl << (char)m;

    return 0;
}
*/

/*(2)
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    float n;
    cin >> n;
    n = 5.0 / 9 * (n - 32);

    cout << setiosflags(ios::fixed) << setprecision(1) << n << endl;

    return 0;
}
*/

/*(3)
#include<iostream>
using namespace std;
int main()
{
    int n, x, y, z;
    cin >> n;
    z = n % 5;
    y = n - z;
    x = n / 5;

    cout << "Everyone have " << x << " apples." << endl;
    cout << y << " apples have been taken in total." << endl;
    cout << "returned " << z << " apples to the teacher.";

    return 0;
}
*/

/*(4)
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n, m;
    int a[10];
    float x = 0, y = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> n >> m;
        a[i] = n;
        a[i + 5] = m;
        x += m;
    }
    for (int j = 0; j < 5; j++)
    {
        if (a[j] >= 90) { y += 4.0 * a[j + 5] / x; }
        else { y += 4.0 * a[j] / 90.0 * a[j + 5] / x; }
    }

    cout << "GPA:" << setiosflags(ios::fixed) << setprecision(2) << y << endl;

    return 0;
}
*/

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int x,y,z;
    cin>>x>>y>>z;
    x=x+y+z;

    cout<<x<<","<<setiosflags(ios::fixed)<<setprecision(2)<<x/3.0<<endl;

    return 0;
}