/*]
亮了多少】

问题描述
众所周知，电子灯上的数字可以由 7 个电子管组成，如下图。

https://dn-simplecloud.shiyanlou.com/questions/uid1792586-20240115-1705320397552

数字 0∼9 分别由 6,2,5,5,4,5,6,3,7,6 个亮着的电子管组成，现在小蓝看到了一大串数字，他想知道总共有多少个亮着的电子管。

输入格式
一个字符串 S，代表小蓝看见的数字串。

输出格式
一个整数，代表亮着的电子管数量。

样例输入
12

样例输出
7

评测数据范围 1≤∣S∣≤10^4 ，保证只包含数字。
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int m = 0, a[10] = { 6,2,5,5,4,5,6,3,7,6 };
    string s;
    getline(cin, s);
    for (char c : s)
        m += a[c - '0'];
    cout << m << endl;

    return 0;
}
