#include<iostream>
using namespace std;
int main()
{
    //错误：int a,b;                      
    //      c=a+b;
    //      cout>>"a+b=">>a+b;

    //改正：(共四处错误）
    int a, b, c;
    cin >> a >> b;
    c = a + b;
    cout << "a+b=" << c << endl;

    return 0;
}
