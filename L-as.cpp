/*
乐乐的加和除

问题描述
乐乐有一个整数 N。
如果它是奇数，就加 1，否则就除以 2。
重复这个过程，直到数字变成 1。
乐乐想知道进行了多少步。

输入格式
第一行包含一个整数 N。

输出格式
输出一个整数，表示执行的步数。

样例输入
13

样例输出
6

评测数据规模
1≤N≤10^9 。
*/
#include <iostream>
using namespace std;
int main()
{
    int n, i = 0;
    cin >> n;
    while (n != 1)
    {
        if (n % 2)
            n++;
        else
            n /= 2;
        i++;
    }
    cout << i << endl;

    return 0;

}
