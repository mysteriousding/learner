/*
求最大公约数

题目描述：
设a, b是两个整数，如果d能整除a且d能整除b，那么，d就称为是a和b的公约数。
a和b的公约数中最大的整数称为a和b的最大公约数。

输入两个正整数a和b，求它们的最大公约数。

输入描述：
输入占一行，为两个正整数a和b，不超过int型范围。

输出描述：
输出占一行，为a和b的最大公约数。

样例输入：
33 18

样例输出：
3
*/
#include <iostream>
using namespace std;
int main()
{
    int a, b, c = 1;
    cin >> a >> b;
    while (c)
        c = a % b, a = b, b = c;
    cout << a << endl;

    return 0;

}

