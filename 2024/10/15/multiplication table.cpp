#include<iostream>
using namespace std;
int main()
{
    int a, b;
    for (a = 1; a <= 9; a++)
    {
        for (b = 1; b <= a; b++)
        {
            cout << a << "*" << b << "=" << a * b << "\t";
            if (b==a) { cout << endl; }
        }
    }

    return 0;
}
