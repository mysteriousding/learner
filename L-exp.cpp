/*]
小蓝的括号串1

问题描述
小蓝有一个长度为 n 的括号串，括号串仅由字符 ( 、 ) 构成，请你帮他判断一下该括号串是否合法，合法请输出 Yes ，反之输出 No 。

合法括号序列：

	空串是合法括号序列。

	若 s 是合法括号序列，则 ( s ) 也是合法括号序列。

	若 s,t 都是合法括号序列，则 st 也是合法括号序列。

例如 ()() ， (()) ， (())() 均为合法括号序列。

输入格式
第一行包含一个正整数 n ，表示括号串的长度。

第二行包含一个长度为 n 的括号串。

输出格式
输出共 1 行，若括号串合法请输出 Yes ，反之输出 No 。

样例输入1
10
(()(()))()

样例输出1
Yes

样例输入2
5
()()(

样例输出2
No

评测数据规模
对于所有评测数据，1≤n≤1×10^2 ，括号串仅包含两种字符 ( ， ) 。
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    int n, a = 0, b = 0;
    bool bl;
    cin >> n;
    cin.ignore();
    getline(cin, s);
    bl = n % 2;
    for (int i = 0; !bl && i < n; i++)
    {
        if (s[i] == '(')
            a++;
        else b++;
        bl = a < b;
    }

    cout << (bl || a != b ? "No" : "Yes") << endl;

    return 0;
}
