﻿/*
L1-2 6翻了
分数 15
作者 陈越
单位 浙江大学

https://images.ptausercontent.com/f490fec2-60be-4f14-87fc-a8cd26cb2b33.JPG

“666”是一种网络用语，大概是表示某人很厉害、我们很佩服的意思。
最近又衍生出另一个数字“9”，意思是“6翻了”，实在太厉害的意思。
如果你以为这就是厉害的最高境界，那就错啦 —— 目前的最高境界是数字“27”，因为这是 3 个 “9”！

本题就请你编写程序，将那些过时的、只会用一连串“6666……6”表达仰慕的句子，翻译成最新的高级表达。

输入格式：
输入在一行中给出一句话，即一个非空字符串，由不超过 1000 个英文字母、数字和空格组成，以回车结束。

输出格式：
从左到右扫描输入的句子：
如果句子中有超过 3 个连续的 6，则将这串连续的 6 替换成 9；
但如果有超过 9 个连续的 6，则将这串连续的 6 替换成 27。
其他内容不受影响，原样输出。

输入样例：
it is so 666 really 6666 what else can I say 6666666666
输出样例：
it is so 666 really 9 what else can I say 27
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string n, m = "";
    int i = 0, j = 0;
    getline(cin, n);
    while (n[i] || j)
        if (n[i] != '6')
        {
            if (j)
            {
                if (j <= 3)for (int k = 0; k < j; k++)m += '6';
                else if (j <= 9)m += '9';
                else m += "27";
                j = 0;
            }
            m += n[i], i++;
        }
        else i++, j++;
    cout << m << endl;

    return 0;
}
