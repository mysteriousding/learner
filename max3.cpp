#include<iostream>
using namespace std;
int max(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j)
{
	int k;
	if (a > b)k = a;
	   else k = b;
	if (k > c)k = k;
	   else k = c;
	if (k > d)k = k;
	   else k = d;
	if (k > e)k = k;
	   else k = e;
	if (k > f)k = k;
	   else k = f;
	if (k > g)k = k;
	   else k = g;
	if (k > h)k = k;
	   else k = h;
	if (k > i)k = k;
	   else k = i;
	if (k > j)k = k;
	   else k = j;

	return(k);
}

int main()
{
	int l, m, n, o, p, q, r, s, t, u, xyz;
	cin >> l >> m >> n >> o >> p >> q >> r >> s >> t >> u;
	xyz = max(l, m, n, o, p, q, r, s, t, u);
	cout << "max=" << xyz << endl;

	return 0;
}