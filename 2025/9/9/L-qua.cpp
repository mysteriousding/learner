/*
平行四边形面积

题目描述
给定一个平行四边形的底边长度 l 和高度 h，求平行四边形的面积。

输入描述
输入的第一行包含一个整数 l，表示平行四边形的底边长度。

第二行包含一个整数 h，表示平行四边形的高。

其中，1≤l,h≤100

输出描述
输出一个数，表示平行四边形的面积。
如果面积为整数，请直接输出这个整数，不带小数点。
如果面积不是整数，请四舍五入保留正好一位小数。

输入输出样例
示例 1
输入

5
6

输出

30
*/
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    float a, b;
    cin >> a >> b;
    a *= b;
    b = int(a);
    if (a == b)
        printf("%.f", b);
    else
        printf("%.1f", a);

    return 0;

}




