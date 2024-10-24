#include <iostream>
#include <string>
#include<cmath>
using namespace std;
int main()
{
    string a;
    char b;
    int c = 0, i = 0;
    cout << "请输入一个二进制数，让我为你将他转化为十进制。" << endl;
    cin >> a;
    int n = a.size();
    while (1)
    {
        b = a[i];
        if (i == n)break;
        c += (int)(b -48) * pow(2, i);
        i++;
    }

    cout << endl << a << " 的十进制 = " << c << endl;

    return 0;
}
