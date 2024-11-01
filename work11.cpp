/*(31)
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string n;
    int n1, n2, n3, n4, n5, a, b;
    n1 = n2 = n3 = n4 = n5 = 0;
    getline(cin, n);
    a = n.size();
    for (int i = 0; i < a; i++)
    {
        b = (int)n[i];
        if (b >= 48 && b <= 57) { n1++; }
        else if (b >= 65 && b <= 90) { n2++; }
        else if (b >= 97 && b <= 122) { n3++; }
        else if (b == 32) { n4++; }
        else { n5++; }
    }

    cout << "n1=" << n1 << "  n2=" << n2 << "  n3=" << n3 << "  n4=" << n4 << "  n5=" << n5 << endl;

    return 0;
}
*/

/*(32)
#include<iostream>
using namespace std;
int main()
{
    int x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;

    cout << "t1 is:" << endl << x << ":" << y << ":" << z << endl;
    cout << "t2 is:" << endl << a << ":" << b << ":" << c << endl;

    return 0;
}
*/

/*(34)
#include<iostream>
#include<string>
using namespace std;
int print(int num);
int print(int num0, int a);
int print(string str);
int print(char a);
int main()
{
    int a[10][4];
    string b[10];
    int i0 = 0;
    while (cin >> a[i0][0])
    {
        cin >> b[i0];
        for (int j = 1; j <= 3; j++)cin >> a[i0][j];
        i0++;
    }

    for (int i = 0; i < i0; i++)
    {
        print(a[i][0]);
        print(b[i]);
        for (int j = 1; j <= 2; j++)print(a[i][j]);
        print(a[i][3], 1);
        if (i != i0)print('\n');
    }

    return 0;
}
int print(int num)
{
    cout << num << " ";
    return 1;
}
int print(int num0, int a)
{
    cout << num0;
    return 1;
}
int print(string str)
{
    cout << str << " ";
    return 1;
}
int print(char a)
{
    cout << endl;
    return 1;
}
*/