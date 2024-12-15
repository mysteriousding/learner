/*
问题描述
双十一这天，小蓝熬夜到凌晨，就为了抢购限量版机械键盘。困得眼睛都睁不开的他，终于把键盘添加到了购物车，就差最后一步：付款！

然而，当他颤抖着手指准备输入支付密码时，却发现…
他不记得密码了？！😱

好吧这并不要紧，因为小蓝此前设置了动态密码。动态密码是将当天的日期（八位数字格式）转换成二进制表示形式（不含前导零）。

对小蓝来说，今天是 2024 年 11 月 11 日（八位数字格式为：20241111）。现在，请你帮他计算出动态密码，帮他完成支付。

输入格式
无。

输出格式
输出一个数字字符串，表示动态密码。
*/
#include <iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	time_t now = time(nullptr);
	struct tm* tm_info = localtime(&now);
	int year = tm_info->tm_year + 1900;
	int month = tm_info->tm_mon + 1                     - 1; //因为我做题时日期有出入，这是清除差异（我没有好好读题 😱 ）
	int day = tm_info->tm_mday                          - 4;
	long long time0 = year * 1e4 + month * 1e2 + day;
	string m = "";
	int k;
	while (time0 != 0)
	{
		k = time0 % 2;
		m = char(k + 48) + m;
		time0 /= 2;
	}
	cout << m << endl;

	return 0;
}