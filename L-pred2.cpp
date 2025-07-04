/*
谓词实例2(二元谓词)

题目描述
已知客体域A={x|x∈N, 100≤x≤120}，其中N为自然数的集合，谓词P(x, y)表示“x和y互质”。
求使得该谓词取值为T的x, y的取值。

输入描述
本题无输入。

输出描述
输出使得谓词P(x, y)取值为T的x, y的取值，用空格隔开。
如果有多个取值组合符合要求，则每个取值组合占一行，且首先输出x取值最小的组合，对x取值相同的组合，则先输出y取值最小的组合，以此类推。
注意，在本题中，诸如“100 101”和“101 100”，视为相同的取值组合。
*/
#include <iostream>
using namespace std;
int main()
{
    int n, m, h;
    for (int i = 100; i <= 120; i++)
        for (int j = i + 1; j <= 120; j++)
        {
            m = j, h = i;
            while (1)
            {
                n = m;
                m = h;
                h = n % m;
                if (!h)break;
            }
            if (m == 1)cout << i << " " << j << endl;
        }

    return 0;
}