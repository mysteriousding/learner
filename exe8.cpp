#include <iostream>
using namespace std;
/*
int main()
{
    int a;
    a = 12;

    //(1)   a += a;
    //(2)   a -= 3;
    //(3)   a *= 2 + 3;
    //(4)   a /= a + a;
    //(5)   int n = 5;
          //a %= (n %= 2);
    a += a -= a *= a;

    cout << a << endl;

    return 0;
}
*/

int main()
{
    int i, j, m, n;
    i = 8;
    j = 10;
    m = ++i + j++;
    n = (++i) + (++j) + m;

    cout << i << '\t' << j << '\t' << m << '\t' << n << endl;

    return 0;
}