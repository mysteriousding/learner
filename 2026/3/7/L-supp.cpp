/*
补 0 输出

题目描述
输入一个整数，请在整数前面补 0 补足 8 位后输出。

输入描述
输入一行包含一个整数 n。

输出描述
输出补 0后的整数。

输入输出样例
示例1
输入
2021

输出
00002021

示例2
输入
202110

输出
00202110

评测用例规模与约定
对于所有评测用例，给定的数是不超过 8 位的非负整数。
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string n;
    getline(cin, n);
    for (int i = n.size(); i < 8; i++)
        cout << '0';
    cout << n << endl;

    return 0;

}



