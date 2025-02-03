/*
次数差

题目描述
x 星球有 26 只球队，分别用 a ~ z 的 26 个字母代表。他们总是不停地比赛。

在某一赛段，哪个球队获胜了，就记录下代表它的字母，这样就形成一个长长的串。

国王总是询问：获胜次数最多的和获胜次数最少的有多大差距？（当然，他不关心那些一次也没获胜的，认为他们在怠工罢了）

输入描述
输入，一个串，表示球队获胜情况（保证串的长度 < 1000）。

输出描述
要求输出一个数字，表示出现次数最多的字母比出现次数最少的字母多了多少次。

输入输出样例
示例
输入

abaabcaa

输出

4
*/
#include <iostream>
#include<string>
using namespace std;
int a[26] = { 0 };
int main()
{
    int k = 0, min = 1000, max = 0;
    string m;
    cin >> m;
    while (m[k])
        a[m[k++] - 'a']++;
    for (int i = 0; i < 26; i++)
    {
        if (max < a[i])max = a[i];
        if (a[i] && min > a[i])min = a[i];
    }
    cout << max - min << endl;

    return 0;
}
