/*】】【
Fibonacci数列

题目描述：
Fibonacci数列：第1、2项均为1，从第3项开始，每一项都是前两项之和。
输入n值，输出Fibonacci数列第n项，该数列前10项为1, 1, 2, 3, 5, 8, 13, 21, 34, 55。

输入描述：
输入占一行，为n的值，1≤n≤40。

输出描述：
输出占一行，为Fibonacci数列第n项的值。

样例输入：
40

样例输出：
102334155
*/
#include <iostream>
using namespace std;
int main()
{
    long long n, a = 0, b = 1, c = 1;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        b = a, a = c;
        c = a + b;
    }
    cout << c << endl;

    return 0;
}
