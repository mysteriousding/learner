/*
有奖猜谜

题目描述
本题为填空题，只需要算出结果后，在代码中使用输出语句将所填结果输出即可。

小明很喜欢猜谜语。 最近，他被邀请参加了 X 星球的猜谜活动。

每位选手开始的时候都被发给 777 个电子币。 
规则是：猜对了，手里的电子币数目翻倍， 猜错了，扣除 555 个电子币, 扣完为止。

小明一共猜了 15 条谜语。
战果为： vxvxvxvxvxvxvvx 其中 v 表示猜对了，x 表示猜错了。

请你计算一下，小明最后手里的电子币数目是多少。
*/
#include <iostream>
#include<string>
using namespace std;
int main()
{
	string s = "vxvxvxvxvxvxvvx";
	int num = 777;
	for (char i : s)
		if (i == 'v')
			num *= 2;
		else
			num -= 555;
	cout << num << endl;

	return 0;

}

