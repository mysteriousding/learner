/*
联赛场次

题目描述
通常在足球联赛里，n支球队要分主客场打循环赛，最后根据积分排名。
输入球队数，输出联赛要打多少场比赛。

输入描述
输入占一行，为一个正整数n，n为偶数，6≤n≤20，代表球队数。

输出描述
输出占一行，为一个正整数，为求得的答案。

样例输入
6

样例输出
30
*/
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	cout << n * (n - 1) << endl;

	return 0;

}
