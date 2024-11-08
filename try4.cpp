#include<iostream>
using namespace std;
int main()
{
	/*比较运算符尝试
	int a = 4, b = 3;

	cout << (a == b) << endl;

	cout << (a != b) << endl;

	cout << (a < b) << endl;

	cout << (a > b) << endl;

	cout << (a <= b) << endl;

	cout << (a >= b) << endl;
	*/

	/*逻辑运算符

	// '&&' -- 与
	int a = 1, b = 0, c = 1;

	cout << (a && b) << endl;   //0
	cout << (a && c) << endl;   //1

	// '||' -- 或
	int a = 1, b = 0, c = 0;

	cout << (a || b) << endl;   //1
	cout << (b || c) << endl;   //0
	 
	// '!' -- 非
	int a = 10;

	cout << !a << endl;   //0
	cout << !!a << endl;  //1

	*/

	/*三目运算符尝试*/
	int a = 10, b = 20, c;
	c = (a > b) ? a : b;
	cout << a << " " << b << " " << c << endl;

	a = 20; b = 10;
	c = (a > b) ? a : b;
	cout << a << " " << b << " " << c << endl;

	a = 10, b = 20;
	(a > b) ? a : b = 100;
	cout << a << " " << b << endl;

	a = 20, b = 10;
	(a > b) ? a : b = 100;
	cout << a << " " << b << endl;

	a = 20, b = 10;
	((a > b) ? a : b) = 100;
	cout << a << " " << b << endl;



	return 0;
}