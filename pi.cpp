#include<iostream>
using namespace std;
int main()
{
	double a = 0;
	int j = -1;
	for (int i = 1;; i+=2)
	{
		j *= -1;
		a += (1.0 / i) * j;
		if ((1.0 / i) < 1e-7)break;
	}

	cout << "pi:" << 4 * a << endl;

	return 0;
}