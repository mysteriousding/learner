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

int min(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j)
{
	int K;
	if (a < b)K = a;
	   else K = b;
	if (K < c)K = K;
	   else K = c;
	if (K < d)K = K;
	   else K = d;
	if (K < e)K = K;
	   else K = e;
	if (K < f)K = K;
	   else K = f;
	if (K < g)K = K;
	   else K = g;
	if (K < h)K = K;
	   else K = h;
	if (K < i)K = K;
	   else K = i;
	if (K < j)K = K;
	   else K = j;

	return(K);
}

int main()
{
	cout << "欢迎使用大小判断计算机：" << endl << endl << "请输入十个数：" << endl;
	
	int l, m, n, o, p, q, r, s, t, u, xyz, XYZ;
	cin >> l >> m >> n >> o >> p >> q >> r >> s >> t >> u;

	xyz = max(l, m, n, o, p, q, r, s, t, u);
	cout << "最大的数为：" << xyz << endl;

	XYZ = min(l, m, n, o, p, q, r, s, t, u);
	cout << "最小的数为：" << XYZ << endl<<endl;

	cout << "判断完毕，谢谢使用！" << endl;
	
	return 0;
}
