#include<iostream>
using namespace std;
int main()
{
	int i = 1, i0, j, n, m = 0, a;
	cout << "欢迎进入逢7跳过计算机" << endl;
	cout << "它将为你找出0-X的所有游戏规避数" << endl;
	cout << "请输入数的上限X：";
	cin >> j;
	cout << "谢谢！0-" << j << "的所有游戏规避数为：" << endl;
	while (i <= j)
	{
		i0 = i;
		n = i % 7;
		while (true)
		{
			a = i % 10;
			i /= 10;
			if (a == 7) { m += 1; }
			if (i == 0) { break; }
		}
		i = i0;
		if(n==0||m!=0)
		{
			cout << i << endl;
		}
		m = 0; 
		i++;
	}
	cout << "运算完毕，谢谢使用！快去玩游戏试试吧！" << endl;

	return 0;
}