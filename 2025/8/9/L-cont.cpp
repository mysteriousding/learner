/*
电扇控制

问题描述
小蓝家的电扇有低、中、高三档，初始时电扇位于低档，当按一下电扇的调节按钮时，电扇变为中档，再按一下电扇变为高档，再按一下变为低档，依次循环。

从低档开始，小蓝连续按了 P 次调档按钮，请问电扇现在是哪一档？

例如，当 P=5 时，最终是高档。

又如，当 P=10 时，最终是中档。

输入格式
输入一行包含一个整数 P 。

输出格式
如果最终是低档，输出小写英文字符串 low ；
如果最终是中档，输出小写英文字符串 mid ；
如果最终是高档，输出小写英文字符串 high 。

样例输入
5

样例输出
high

样例输入
10

样例输出
mid

数据范围
对于所有评测用例，0≤P≤1000。
*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    switch (n % 3)
    {
    case 0:cout << "low" << endl; break;
    case 1:cout << "mid" << endl; break;
    case 2:cout << "high" << endl; break;
    }

    return 0;

}




