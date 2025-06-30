/*
18. 统计指定前缀的单词数

问题描述
英文里很多单词具有相同的前缀。给定一部字典，再指定一个单词 A（一个较短的字符串），统计字典中以 A 为前缀的单词数（包括 A 本身）。

输入格式
输入数据第 1 行为正整数 N，N≤1.2×10^5 ，表示字典中的单词数。

接下来有 N 行，每行为一个由小写字母组成的单词，单词按字典序排列，单词没有重复，每个单词不超过 20 个字母。

字典之后还有一行，是单词 A。

输出格式
输出字典中以单词 A 为前缀的单词数，如果没有，则输出 0。

样例输入
10
a
alien
born
less
lien
never
nevertheless
new
newborn
zebra
ne

样例输出
4
*/
#include <iostream>
#include<string>
using namespace std;
int main()
{
    int n, m = 0;
    char c;
    string h;
    cin >> n;
    cin.ignore();
    cin >> c;
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        getline(cin, h);
        if (h[0] == c)m++;
    }
    cout << h << m << endl;

    return 0;
}