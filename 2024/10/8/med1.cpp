#include<iostream>
using namespace std;
int main()
{
	int med(int x, int y, int z);
	int a, b, c, m;
	cin >> a >> b >> c;
	m = med(a, b, c);
	cout << "med=" << m << endl;

	return 0;
}
int med(int x, int y, int z)
{
	int m0, m1, m2, m3;
	m1 = x;
	m2 = y;
	m3 = z;

	if (m1 > m2) { m1 = m1; m2 = m2; }
	   else { m0 = m1; m1 = m2; m2 = m0; }
	if (m2 > m3) { m2 = m2; m3 = m3; }
	   else { m0 = m2; m2 = m3; m3 = m0; }
	if (m1 > m2) { m1 = m1; m2 = m2; }
	   else { m0 = m1; m1 = m2; m2 = m0; }
	if (m2 > m3) { m2 = m2; m3 = m3; }
	   else { m0 = m2; m2 = m3; m3 = m0; }
	if (m1 > m2) { m1 = m1; m2 = m2; }
	   else { m0 = m1; m1 = m2; m2 = m0; }
	if (m2 > m3) { m2 = m2; m3 = m3; }
	   else { m0 = m2; m2 = m3; m3 = m0; }

	return(m2);
}
