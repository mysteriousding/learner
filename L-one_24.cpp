/*
美丽的2024【算法赛】

问题描述
小蓝刚学习完二进制知识，所以现在他对任何数字的二进制都特别感兴趣。
恰好即将迎来 2024 年，他想知道 2024 的二进制中有几个 1？

请你帮忙解决这个问题

输入格式
本题为填空题，无输入。

输出格式
输出一个整数表示答案。
*/
#include <iostream>
#include <bitset>
#include <string>
using namespace std;
int main()
{
    int num = 0;
    for (char v : bitset<32>(2024).to_string())
        if (v == '1')
            num++;
    cout << num << endl;

    return 0;


    
}

