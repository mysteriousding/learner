#include<iostream>
using namespace std;
int main()
{   
	int a, b, T, F, N, M, Q;
	cout << "欢迎使用a,b加减乘除计算机：" << endl << endl;
	cout << "请输入a=";
		cin >> a;
	cout << "请输入b=";
	    cin >> b;

    T = a + b;
	F = a - b;
	N = a * b;
	M = a / b;
	Q = a % b;

	cout << a << "+" << b << "=" << T << endl;
	cout << a << "-" << b << "=" << F << endl;
	cout << a << "*" << b << "=" << N << endl;
	cout << a << "/" << b << "=" << M << "---" << Q << endl << endl;

	cout << "谢谢使用！" << endl;

	return 0;
}