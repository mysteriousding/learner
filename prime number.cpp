#include<iostream>
using namespace std;
int main()
{
	int i = 0, j = 1, n = 0, a, b;
	cout << "欢迎使用质（素）数计算机" << endl;
	cout << "它将为你找出0-X的所有质（素）数" << endl;
	cout << "请输入数的上限X：";
	cin >> a;
	cout << "谢谢！0-" << a << "的所有质（素）数为：" << endl;

	while (i <= a)
	{
		while (j <= i)
		{
			b = i % j;
			if (b == 0) { n += 1; }

			j++;
		}
		if (n == 2) { cout << i << endl; }

		n = 0;
		j = 1;
		i++;
	}

	cout << "运算完毕，谢谢使用！" << endl;

	return 0;
}
