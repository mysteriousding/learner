#include<iostream>
using namespace std;
int main()
{
	int med(int a, int b, int c, int d, int e, int f, int g, int h, int i);
	int l, m, n, o, p, q, r, s, t, xyz;
	cout << "欢迎使用中位数计算器！" << endl;
	cout << "请输入9个数：" << endl;
	cin >> l >> m >> n >> o >> p >> q >> r >> s >> t;
	xyz = med(l, m, n, o, p, q, r, s, t);
	cout << "中位数为：" << xyz << endl;
	cout << "计算完毕，谢谢使用！" << endl;

	return 0;
}
int med(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
	int m0, m1, m2, m3, m4, m5, m6, m7, m8, m9;
	m1 = a;
	m2 = b;
	m3 = c;
	m4 = d;
	m5 = e;
	m6 = f;
	m7 = g;
	m8 = h;
	m9 = i;

	while (true)
	{
		if (m1 > m2, m2 > m3, m3 > m4, m4 > m5, m5 > m6, m6 > m7, m7 > m8, m8 > m9) { break; }

		else
		{
			if (m1 > m2) { m1 = m1; m2 = m2; }
			   else { m0 = m1; m1 = m2; m2 = m0; }
			if (m2 > m3) { m2 = m2; m3 = m3; }
			   else { m0 = m2; m2 = m3; m3 = m0; }
			if (m3 > m4) { m3 = m3; m4 = m4; }
			   else { m0 = m3; m3 = m4; m4 = m0; }
			if (m4 > m5) { m4 = m4; m5 = m5; }
			   else { m0 = m4; m4 = m5; m5 = m0; }
			if (m5 > m6) { m5 = m5; m6 = m6; }
			   else { m0 = m5; m5 = m6; m6 = m0; }
			if (m6 > m7) { m6 = m6; m7 = m7; }
			   else { m0 = m6; m6 = m7; m7 = m0; }
			if (m7 > m8) { m7 = m7; m8 = m8; }
			   else { m0 = m7; m7 = m8; m8 = m0; }
			if (m8 > m9) { m8 = m8; m9 = m9; }
			   else { m0 = m8; m8 = m9; m9 = m0; }
		}
	}

    return(m5);
}