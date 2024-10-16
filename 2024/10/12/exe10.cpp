#include <iostream>
using namespace std;
int main()
{
    float r, pi, c, s, v;
    pi = 3.1415;
    cout << "请输入半径以计算圆的周长面积及球的体积：" << endl;
    cin >> r;

    c = 2 * pi * r;
    s = pi * r * r;
    v = 4.0 / 3 * pi * r * r * r;

    cout << "圆的周长为：" << c << endl;
    cout << "圆的面积为：" << s << endl;
    cout << "球的体积为：" << v << endl;

    return 0;
}
