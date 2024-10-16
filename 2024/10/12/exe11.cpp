#include <iostream>
using namespace std;
int main()
{
	int b, c;
	float m;
	char a;
	a = 'a';

	//(1)   m = (3.5 * 3 + 2 * 7 - a);
	//(2)   m = (26 / 3 + 34 % 3 + 2.5);
	//(3)   m = (45 / 2 + (int)3.14159 / 2);
	//(4)   int a = 3;
		  //m=(a = b = (c = a += 6));
	//(5)   m = (a = 3 * 5, a = b = 3 * 2);
	//(6)   int a = 3;
		  //m = ((int)(a + 6.5) % 2 + (a = b = 5));
	//(7)   float x = 2.5, y = 4.7;  int a = 7;
		  //m = (x + a % 3 * (int)(x + y) % 2 / 4);
	//(8)   int a = 2, b = 3;  float x = 3.5, y = 2.5;
	      //m = ((float)(a + b) / 2 + (int)x % (int)y);

	cout << m << endl;

	return 0;
}
