﻿/*
9. 抓猪拿国一【算法赛】

问题描述
蓝桥杯赛场上，选手小王脑洞大开，跑去问裁判：“裁判，蓝桥杯要是改成‘蓝桥抓猪大赛’，得抓多少头猪才能拿国一啊？”
裁判愣了愣，但为了显摆幽默，淡定答道：“好说！想拿国一，从第一届开始，每届抓的猪数得是这一届的届数加上前面所有届数的总和。
比如，第一届抓 1 头，第二届抓 1+2=3 头，第三届抓 1+2+3=6 头 … 今年是第十六届蓝桥杯，你自己算算吧！”

现在，请你帮小王算算，要拿国一，总共得抓多少头猪？

输入格式
无。

输出格式
输出一个整数，表示答案。
*/
#include <iostream>
using namespace std;
int main()
{
	int num = 0;
	for (int i = 0; i <= 16; i++)
		num += i;
	cout << num << endl;

	return 0;
}
