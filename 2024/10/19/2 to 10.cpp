#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    int a, b, c = 0, i = 0, a0;
    cout << "请输入一个二进制数，让我为你将他转化为十进制。" << endl;
    cin >> a;
    a0 = a;
    while (1)
    {
        b = a % 10;
        a /= 10;
        c += b * pow(2, i);
        if (a == 0)break;
        i++;
    }

    a = a0;
    cout << endl << a << "的十进制=" << c << endl;

    return 0;
}
