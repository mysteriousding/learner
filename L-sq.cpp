﻿/*
生物芯片

题目描述
X 博士正在研究一种生物芯片，其逻辑密集度、容量都远远高于普通的半导体芯片。

博士在芯片中设计了 n 个微型光源，每个光源操作一次就会改变其状态，即：点亮转为关闭，或关闭转为点亮。

这些光源的编号从 1 到 n，开始的时候所有光源都是关闭的。

博士计划在芯片上执行如下动作：

所有编号为 2 的倍数的光源操作一次，也就是把 2 4 6 8 ⋯ 等序号光源打开;

所有编号为 3 的倍数的光源操作一次, 也就是对 3 6 9 ⋯ 等序号光源操作，注意此时 6 号光源又关闭了。

所有编号为 4 的倍数的光源操作一次。

⋯ 

直到编号为 n 的倍数的光源操作一次。

X 博士想知道：经过这些操作后，某个区间中的哪些光源是点亮的。

输入描述
输入 3 个用空格分开的整数： N L R(L<R<N<10^ )， N 表示光源数， L 表示区间的左边界， R 表示区间的右边界。

输出描述
输出 1 个整数，表示经过所有操作后， [L,R] 区间中有多少个光源是点亮的。

输入输出样例
示例

输入
5 2 3

输出
2
*/
#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	long long n, l, r, sum;
	cin >> n >> l >> r;
	int num, ll = (int)sqrt(l), rr = (int)sqrt(r);
	sum = r - l + 1 - rr + ll;
	if (l == 1)sum++;
	cout << sum << endl;

	return 0;
}
