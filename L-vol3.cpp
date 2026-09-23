/*]]】
直角三角形

题目描述
给定一个三角形的三条边的长度 a,b,c，请问这个三角形是不是一个直角三角形。

输入描述
输入一行包含三个整数 a,b,c，表示三角形三边的长度，相邻整数之间用一个空格分隔。

输出描述
如果是直角三角形，输出“YES”（全大写），否则输出“NO”（全大写）。

输入输出样例
示例1
输入
3 4 5

输出
YES

示例2
输入
4 5 4

输出
NO

评测用例规模与约定
对于所有评测用例，1≤a,b,c≤1000。
*/
#include <iostream>
using namespace std;
int main()
{
	long long a, b, c;
	cin >> a >> b >> c;
	a *= a, b *= b, c *= c;
	cout << (a == b + c || b == c + a || c == a + b ? "YES" : "NO") << endl;

	return 0;
}
