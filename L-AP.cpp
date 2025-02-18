/*
等差数列

题目描述
数学老师给小明出了一道等差数列求和的题目。
但是粗心的小明忘记了一 部分的数列，只记得其中 N 个整数。

现在给出这 N 个整数，小明想知道包含这 N 个整数的最短的等差数列有几项？

输入描述
输入的第一行包含一个整数 N。

第二行包含 N 个整数 A1,A2,⋅⋅⋅AN 。(注意 A1 ∼ AN 并不一定是按等差数列中的顺序给出)

其中， 2≤N≤10^5 ，0≤Ai≤10^9 。

输出描述
输出一个整数表示答案。

输入输出样例
示例
输入

5
2 6 4 10 20

输出

10

样例说明：
包含 2、6、4、10、20 的最短的等差数列是 2、4、6、8、10、12、14、16、 18、20。
*/
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n, num, sum;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	sum = a[n - 1];
	for (int i = 0; i < n - 1; i++)
		if (sum > a[i + 1] - a[i])
			sum = a[i + 1] - a[i];
	if (sum)cout << (a[n - 1] - a[0]) / sum + 1 << endl;
	else cout << n << endl;

	return 0;
}
