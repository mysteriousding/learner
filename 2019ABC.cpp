#include<iostream>
using namespace std;
int main()
{
	int a, b, c = 1;
	int n[10];
	cin >> a;
	while (true)
	{
		b = a % 26;
		a /= 26;
		n[c] = b;
		if (a == 0) { break; }
		c++;
	}
	for (c = c; c >= 0; c--)
	{
		cout << (char)(n[c] + 64);
	}
	cout << endl;

	return 0;
}