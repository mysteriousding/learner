/*
回文数

问题描述

1221是一个非常特殊的数，它从左边读和从右边读是一样的，编程求所有这样的四位十进制数。

输出格式

按从小到大的顺序输出满足条件的四位十进制数。
*/
#include <iostream>
using namespace std;
int main()
{
    for (int i = 10; i < 100; i++)
        cout << i * 100 + i % 10 * 10 + i / 10 << endl;

    return 0;
}
