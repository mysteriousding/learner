﻿/*
机器人行走

题目描述
某少年宫引进了一批机器人小车。可以接受预先输入的指令，按指令行动。
小车的基本动作很简单，只有 3 种：左转（记为 L），右转（记为 R），向前走若干厘米（直接记数字）。

例如，我们可以对小车输入如下的指令：

15L10R5LRR10R20

则，小车先直行 15 厘米，左转，再走 10 厘米，再右转，⋯

不难看出，对于此指令串，小车又回到了出发地。

你的任务是：编写程序，由用户输入指令，程序输出每条指令执行后小车位置与指令执行前小车位置的直线距离。

输入描述
用户先输入一个整数 n （n<100），表示接下来将有 n 条指令。

接下来输入 n 条指令。每条指令只由 L、R 和数字组成（数字是 0 ~ 100 之间的整数）

每条指令的长度不超过 256 个字符。

输出描述
程序则输出 n 行结果，每条结果表示小车执行相应的指令前后位置的直线距离。
要求四舍五入到小数后 2 位。

输入输出样例
示例
输入

用户输入：
5
L100R50R10
3LLL5RR4L12
LL
100R
5L5L5L5

输出
102.96
9.06
0.00
100.00
0.00
*/
#include <iostream>
using namespace std;
int main()
{
	// 请在此输入您的代码
	return 0;
}