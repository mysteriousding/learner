/*
约数

题目描述
本题为填空题，只需要算出结果后，在代码中使用输出语句将所填结果输出即可。

如果整数 a 是整数 b 的整数倍，则称 b 是 a 的约数。

请问，有多少个正整数是 2020 的约数。
*/
#include <iostream>
using namespace std;
int main()
{
    int num = 0;
    for (int i = 1; i * i <= 2020; i++)
        if (2020 % i == 0)
        {
            num += 2;
            if (i * i == 2020)
                num--;
        }
    cout << num << endl;

    return 0;

}



