#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	int a, i = 100, j, num = 0, n = 0, i0, m, k;
	cout << "欢迎使用‘水仙花数’计算机" << endl;
	cout << "水仙花数:指一个n位数（n≥3），它的每个位上的数字的n次幂之和等于它本身‌。" << endl << endl;
	cout << "请输入  1  试试输入最小的‘水仙花数’，或输入其他任意数直接查看‘水仙花数’数组" << endl;
	cin >> m;

	while (m == 1)
	{
		cout << "请输入最小的‘水仙花数’" << endl;
		cin >> k;
		if (k==153)
		{
			cout << "答对了！！你真是太聪明了！" << endl;
			cout << "输入除1外任意数查看‘水仙花数’数组" << endl;
			cin >> m;
		}
		else
		{
			cout << "很遗憾，可能不太对哦！" << endl;
			cout << "输入除1外任意数查看‘水仙花数’数组" << endl;
			cin >> m;
		}
	}

	cout << "计算机将为你找出0-X的所有‘水仙花数’" << endl;
	cout << "请输入数的上限X：";
	cin >> j;
	cout << "谢谢！100-" << j << "的所有‘水仙花数’为：" << endl;

	while (i <= j)
	{
		i0 = i;
		while (true)          //算出是几位数
		{
			i /= 10;
			n++;
			if (i == 0) { break; }
		}
		i = i0;
		while (true)          //算各位指数运算后相加
		{
			a = i % 10;
			i /= 10;

			num += pow(a, n);
			if (i == 0) { break; }
		}
		i = i0;
		if (num == i) { cout << i << endl; }      //判断是否符合，然后输出
		n = 0;
		num = 0;

		i++;
	}

	cout << "运算完毕，谢谢使用！" << endl;

	return 0;
}