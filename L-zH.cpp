/*
36进制

题目描述
本题为填空题，只需要算出结果后，在代码中使用输出语句将所填结果输出即可。

对于 16 进制，我们使用字母 A−F 来表示 10 及以上的数字。

如法炮制，一直用到字母 Z，就可以表示 36 进制。

36 进制中，A 表示 10，Z 表示 35，AA 表示 370。

你能算出 MANY 表示的数字用 10 进制表示是多少吗?
*/
#include <iostream>
using namespace std;
int main()
{
    string s = "MANY";
    int n = 0;
    for (char i : s)
        n = n * 36 + (i - 'A' + 10);
    cout << n << endl;

    return 0;
}