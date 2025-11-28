/*
区间计数【省模拟赛】

问题描述
请问有多少组整数对 l,r 满足：

l 和 r 都介于 0 （含）到 100 （含）之间；
r−l≥10。
答案提交
这是一道结果填空的题，你只需要算出结果后提交即可。
本题的结果为一个整数，在提交答案时只填写这个整数，填写多余的内容将无法得分。
*/
#include <iostream>
using namespace std;
int main()
{
    int n = 5050;
    for (int i = 0; i < 9; i++)
        n -= 100 - i;
    cout << n << endl;

    return 0;
}