﻿/*
 38红包【算法赛】

问题描述 2025 年 38 妇女节这天，公司里热闹非凡，老板突发奇想，决定给员工们发发节日红包玩。
他召集了全体员工，大手一挥：“咱们公司有 2025 个员工，每人都有个编号，从 1 排到 2025。
今天是 38 节，凡是编号跟 3、8、38 沾点边的同事，都能领一个红包！一人一个，不重复领啊！”

小李一听，赶紧问：“老板，啥叫‘沾点边’啊？”

老板笑眯眯地说：“就是编号要是 3 的倍数，或者 8 的倍数，或者 38 的倍数，明白了吧？”

小张凑过来捣乱：“那我编号是 38 的平方，是不是能多领一个？”

老板翻了个白眼：“想得美！说了不重复，你就是 38 的立方，也就一个红包！”

结果，小王跳出来喊：“老板，我编号是 0 咋办？”

老板愣了下，随即哈哈大笑：“咱们从 1 开始编号，哪儿来的 0 啊？你小子是来蹭红包的吧！”

现在，请你算算，老板总共得发多少个红包？

输入格式
无。

输出格式
输出一个整数，表示答案。
*/
#include <iostream>
using namespace std;
int main()
{
	int j = 0;
	for (int i = 1; i <= 2025; i++)
		if (!(i % 3) || !(i % 8) || !(i % 38))
			j++;
	cout << j << endl;

	return 0;
}
