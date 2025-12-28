/*
求和

【问题描述】
给定一个长度为n的数列，求数列中所有数的和
【输入格式】
第一行包含一个正整数n，表示数列长度

第二行包含n个正整数，依次表示数列中的每个数
【输出格式】
仅一个整数，表示求和的结果
【样例输入】
5

2 4 3 6 5
【样例输出】
20
【数据规模和约定】
n<=1000，数列中的数不超过1000
*/
#include <iostream>
using namespace std;
int main()
{
    int n, h, m = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h, m += h;
    cout << m << endl;

    return 0;

}


