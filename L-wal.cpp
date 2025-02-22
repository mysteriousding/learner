/*
核桃的数量

题目描述
小张是软件项目经理，他带领 3 个开发组。工期紧，今天都在加班呢。为鼓舞士气，小张打算给每个组发一袋核桃（据传言能补脑）。他的要求是：

各组的核桃数量必须相同

各组内必须能平分核桃（当然是不能打碎的）

尽量提供满足 1,2 条件的最小数量（节约闹革命嘛）

输入描述
输入一行 a,b,c，都是正整数，表示每个组正在加班的人数，用空格分开 (a,b,c<30)。

输出描述
输出一个正整数，表示每袋核桃的数量。

输入输出样例
示例

输入
2 4 5

输出
20
*/
#include <iostream>
using namespace std;
int main()
{
    int a, b, c, x, y, h, sum;
    cin >> a >> b >> c;
    x = a, y = b;
    while (y)
    {
        h = y;
        y = x % y;
        x = h;
    }
    x = sum = a * b / x, y = c;
    while (y)
    {
        h = y;
        y = x % y;
        x = h;
    }
    sum = sum * c / x;
    cout << sum << endl;

    return 0;
}