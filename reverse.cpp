#include<iostream>
using namespace std;
/*第一代
int main()
{
	int num, num0, a, b, c, d, e, f, g, h, i, j;
	cout << "请输入一个数字，让我为你将它颠倒" << endl;
	cin >> num;
	num0 = num;

	a = num % 10;
	num = num / 10;
	b = num % 10;
	num = num / 10;
	c = num % 10;
	num = num / 10;
	d = num % 10;
	num = num / 10;
	e = num % 10;
	num = num / 10;
	f = num % 10;
	num = num / 10;
	g = num % 10;
	num = num / 10;
	h = num % 10;
	num = num / 10;
	i = num % 10;
	num = num / 10;
	j = num % 10;
	num = num / 10;

	if (2.15e9 > num0 && num0 >= 1e9) { cout << a << b << c << d << e << f << g << h << i << j << endl; }
	else if (1e9 > num0 && num0 >= 1e8) { cout << a << b << c << d << e << f << g << h << i << endl; }
	else if (1e8 > num0 && num0 >= 1e7) { cout << a << b << c << d << e << f << g << h << endl; }
	else if (1e7 > num0 && num0 >= 1e6) { cout << a << b << c << d << e << f << g << endl; }
	else if (1e6 > num0 && num0 >= 1e5) { cout << a << b << c << d << e << f << endl; }
	else if (1e5 > num0 && num0 >= 1e4) { cout << a << b << c << d << e << endl; }
	else if (1e4 > num0 && num0 >= 1e3) { cout << a << b << c << d << endl; }
	else if (1e3 > num0 && num0 >= 1e2) { cout << a << b << c << endl; }
	else if (1e2 > num0 && num0 >= 1e1) { cout << a << b << endl; }
	else { cout << a << endl; }

	return 0;
}
*/

/*第二代
int main()
{
	int num, a;
	cout << "请输入一个数字，让我为你将它颠倒" << endl;
	cin >> num;

	while (true)
	{
		a = num % 10;
		num = num / 10;

		if (num == 0)
		{
			cout << a;
			break;
		}
		else { cout << a; }
	}

	return 0;
}
*/

//第三代
int main()
{
	int n, a, i = 0;
	cin >> n;
	while (true)
	{
		a = n % 10;
		n /= 10;
		if (a == 0 && i == 0) {}
		else
		{
			i++;
			cout << a;
		}
		if (n == 0) { break; }
	}
	return 0;
}