/*
不敢惹

问题描述
小蓝是个直男，他老是不懂女朋友的心思，甚至不知道女朋友有没有生气。

后来他逐渐发现，如果女朋友给他发的消息的字符个数小于等于 10 个，那么就是生气了，否则就是没有生气。

现在收到一条女朋友发来的消息，请你帮他判断一下，女友有没有生气。

输入格式
输入一串字符串 S，仅包含小写字母。

输出格式
输出一个字符，如果女友生气了，输出 YES，否则输出 NO。

样例输入
hhh

样例输出
YES

评测数据范围
1≤∣S∣≤10^3。
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	cout << (s.size() > 10 ? "NO" : "YES") << endl;

	return 0;
}