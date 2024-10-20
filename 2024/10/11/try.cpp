#include<iostream>
using namespace std;
/*   尝试一
int main()
{
	int a;
	//a = 234l;     十进制尝试
	//a = 2387L     十进制尝试

	//a = 020;      八进制尝试
	
	//a = 0x20;     十六进制尝试
	a = 0X20;     //十六进制尝试
	cout << a << endl;

	return 0;
}
*/

//尝试二
int main()
{
	int a, b, c, d, e, f, g, x, y;
	x = 2147483646;
	a = 2147483647;
	b = 1;
	c = 2;
	d = 10;

	e = a + b;
	f = a + c;
	g = a + d;
	y = x + b;


	cout << a << "+" << b << "=" << e << endl;
	cout << a << "+" << c << "=" << f << endl;
	cout << a << "+" << d << "=" << g << endl << endl;
	cout << x << "+" << b << "=" << y << endl;

	return 0;
}
