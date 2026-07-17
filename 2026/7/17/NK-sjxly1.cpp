/*
在蓝色星球的2090年，一种表情包病毒已经席卷全球。
每一个感染这种病毒的人只能说“表情包语言”。
一句话表示为一个仅由小写英文字母组成的字符串 s。
它被归类为表情包语言的条件是满足以下所有要求：
字符串 s的长度恰好为 8。
位置1、3、5和7的字符是辅音（即它们不是`a`、`e`、`i`、`o`或`u`）。
位置2、4、6和8的字符是元音（`a`、`e`、`i`、`o`或`u`）。

例如，“bababoyi”和“bibilabu”是有效的表情包语言字符串。
然而，“wodedaodun”不是（长度不是 8），“aiyogama”不是（第1个字符`a`不是辅音），而“ruheneng”也不是（第8个字符`g`不是元音）。

你是蓝色星球上一个避难所的负责人，负责识别未被感染的幸存者。
为了确定感染状况，你会询问每个人要判断感染状态，你让每个人说一句话。
如果这句话不是“梗语”，那么这个人被确认未感染（幸存者）。
否则，这个人被认为已感染。给定𝑛个人说的话，判断每个人是否是幸存者。

输入描述：
第一行包含一个整数𝑛（1 ≤ 𝑛 ≤ 10^5），表示要检查的人数。接下来的𝑛行，每行包含一个仅由小写英文字母组成的字符串𝑠，表示某人说的话。
保证所有字符串𝑠的总长度不超过10^6。

输出描述：
输出𝑛行。对于第𝑖行，如果第𝑖个人的话是梗语，输出“Suspected Virus”（不带引号）；否则，输出“Well-Being”（不带引号）。
*/
#include<iostream>
#include<string>
#include<set>
using namespace std;
int main()
{
    int t;
    string s;
    bool u, v;
    set<char>y = { 'a','e','i','o','u' };
    cin >> t;
    cin.ignore();
    while (t--)
    {
        u = 1,v = 0;
        getline(cin, s);
        u = (s.size() == 8);
        if (u)
            for (int i = 0; i < 8; i++, v = !v)
                if (y.count(s[i]) ^ v)
                {
                    u = 0;
                    break;
                }
        cout << (u ? "Suspected Virus" : "Well-Being") << endl;
    }

    return 0;
}
