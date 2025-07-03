/*
谓词实例1(一元谓词)

题目描述
已知客体域A={x|x∈N, 100≤x≤200}，其中N为自然数的集合，谓词P(x)表示“x是素数”。
求使得该谓词取值为T的x取值。

输入描述
本题无输入。

输出描述
输出使得谓词P(x)取值为T的x取值，用空格隔开。
*/
#include <iostream>
using namespace std;
int main()
{
    int k = 0, u = 0;
    for (int i = 100; i <= 200; i++)
    {
        u = 1;
        for (int j = 2; j * j <= i; j++)
            if (i % j == 0)
            {
                u = 0;
                break;
            }
        if (u)
        {
            if (k)cout << " ";
            cout << i;
            k = 1;
        }
    }
    return 0;
}