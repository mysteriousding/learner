#include<iostream>
using namespace std;
int main()
{
	int a, b, T, F, M, N, Q;
	cin >> a >> b;
	T = a + b;
	F = a - b;
	M = a * b;
	N = a / b;
	Q = a % b;

	cout << a << "+" << a << "=" << T << endl;
	cout << a << "-" << a << "=" << F << endl;
	cout << a << "*" << a << "=" << M << endl;
	cout << a << "/" << a << "=" << N << "-" << "-" << "-" << Q << endl;


	return 0;
}