/*
大厨小新的美食烹饪

问题描述
小新是一个热爱烹饪的大厨，他喜欢从厨房的食材中挑选出他需要的食材，进行混合烹饪。
有一天，小新决定烹饪他的招牌菜品“lanqiao”。
为了制作这道菜，小新会将 N 种食材放入大锅中混合，每种食材都可以用一个字符串 S1,S2,...,SN 表示。

在大锅中，食材的字符会彻底混合，每个字符出现的次数等于所有食材字符串中该字符出现的总次数。
现在，小新可以任意次从大锅中取出一个字符（如果这个字符在锅中出现多次，那么他就可以取出多次）并用它来制作菜品。
一个完整的“lanqiao”菜品需要的字符有 'l'，'a'，'n',，'q'， 'i'， 'a'， 'o'。
请你帮助小新计算他最多能制作多少个完整的“lanqiao”菜品！

输入格式
第一行包含一个整数 N。

接下来的 N 行，每行包含一个字符串 Si ，代表一种食材。

数据范围保证：
1≤N≤100，1≤∣Si∣≤1000，Si只包含小写英文字符。

输出格式
输出一行，包含一个整数，表示小新最多能制作的“lanqiao”菜品的数量。

样例输入
5
nncqcnblla
clqonbanla
cabqcliqic
booiblolcl
ailianboac

样例输出
3
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, a[6] = { 0 };
    string s;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        for (char c : s)
            switch (c)
            {
            case 'a':a[0]++; break;
            case 'l':a[1]++; break;
            case 'n':a[2]++; break;
            case 'q':a[3]++; break;
            case 'i':a[4]++; break;
            case 'o':a[5]++; break;
            }
    }
    a[0] /= 2, n = a[0];
    for (int i = 1; i < 6; i++)
        if (n > a[i])
            n = a[i];
    cout << n << endl;

    return 0;

}



