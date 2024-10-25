#include<iostream>
using namespace std;
int main()
{
	int a, b, c, d, e, x, y, z, m, i;
	cout << "这儿有一组数：1，2，3，5，8，13……" << endl;
	cout << "你知道它们的规律吗？" << endl;
	cout << "请输入1再为这组数延续5个数，或输入其他任意数直接查看数组后续" << endl;
	cin >> m;
	while (m == 1)
	{
		cout << "请输入延续5个数" << endl;
		cin >> a >> b >> c >> d >> e;
		if (a == 21 && b == 34 && c == 55 && d == 89 && e == 144)
		{
			cout << "答对了！！你真是太聪明了！" << endl;
			cout << "输入除1外任意数查看数组后续" << endl;
			cin >> m;
		}
		   else
		   {
			   cout << "很遗憾，可能不太对哦！" << endl;
			   cout << "输入除1外任意数查看数组后续" << endl;
			   cin >> m;
		   }
	}

	x = 1;
	y = 2;
	i = 1;
	while (i <= 10)
	{
		
		z = x + y;
		cout << x << ",";
		cout << y << ",";
		cout << z << ",";

		x = y + z;
		y = z + x;
		
		i++;
	}

	cout << endl << "结束了！你明白数字的规律了吗？" << endl;

	return 0;
}
