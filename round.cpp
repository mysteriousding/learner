#include<iostream>
using namespace std;
int main()
{
	float r, pi, c, s;
	pi = 3.14;
	cout << "欢迎使用圆的周长面积计算机：" << endl;
	cout << "请输入圆的半径R：" ;
	cin >> r;
	c = 2 * pi * r;
	s = pi * r * r;

	cout << "圆的周长为：" << c << endl;
	cout << "圆的面积为：" << s << endl;
	cout << "计算完毕，谢谢使用！";

	return 0;
}