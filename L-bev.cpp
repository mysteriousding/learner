/*
啤酒和饮料

题目描述
本题为填空题，只需要算出结果后，在代码中使用输出语句将所填结果输出即可。

啤酒每罐 2.3 元，饮料每罐 1.9 元。
小明买了若干啤酒和饮料，一共花了 82.3 元。

我们还知道他买的啤酒比饮料的数量少，请你计算他买了几罐啤酒。
*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int i = 0;
    float a;
    while (1)
    {
        a = (82.3 - i * 2.3) / 1.9;
        if (fabs(a - int(a)) < 10e-9)
        {
            cout << i << endl;
            break;
        }
        i++;
    }

    return 0;

}

