#include<iostream>
using namespace std;
int max(int x, int y,int z)
{
	int k;
	if (x > y) k = x;
	   else k = y;
	if (k > z)k = k;
	   else k = z;

	return (k);
}

int main()
{
	int a, b, c, m;
	cin >> a >> b >> c;
	m = max(a, b, c);
	cout << "max=" << m << endl;
	
	return 0;
}
