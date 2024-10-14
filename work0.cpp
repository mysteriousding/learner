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

/*(1)
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
