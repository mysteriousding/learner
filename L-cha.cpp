/*
确定字符串是否包含唯一字符

题目描述
实现一个算法来识别一个字符串的字符是否是唯一的（忽略字母大小写）。

若唯一，则输出YES，否则输出NO。

输入描述
输入一行字符串，长度不超过 100。

输出描述
输出一行，若字符串的字符是唯一的，则输出YES，否则输出NO。

输入输出样例
示例
输入
abd25+

输出
YES
*/
#include <iostream>
#include<string>
using namespace std;
int main()
{
    int arr[128] = { 0 };
    string n;
    getline(cin, n);
    for (int i = 0; n[i]; i++)
    {
        if (n[i] >= 'a' && n[i] <= 'z')n[i] -= 32;
        if (arr[n[i]])
        {
            cout << "NO" << endl;
            return 0;
        }
        else arr[n[i]]++;
    }
    cout << "YES" << endl;

    return 0;
}
