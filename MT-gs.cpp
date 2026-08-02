/*
1、燕丹归国谋策
*
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	int n = s.size(), m = 0, x = 0;
	for (int i = 0; i < n; i++)
		if (s[i] >= 'a' && s[i] <= 'z')
			m++;
		else if (s[i] >= 'A' && s[i] <= 'Z')
			x++;

	cout << (x == 0 || m == 0 ? "Yes" : "No") << endl;

	return 0;
}
*/

/*
2、田光荐轲刎志
*
#include<iostream>
#include<string>
using namespace std;
int main()
{
	

	return 0;
}
*/

/*
3、荆轲受命陈策
*?
//输入：
//5
//1 2 3 4
//1 1 2 2
//3 3 4 4
//3 2 6 7
//3 7 9 10

//输出：
//3 1 2 3 1 
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
struct v
{
	long long x, y, z, k, m, u, v;
};
int main()
{
	int n;
	cin >> n;
	vector<v>a(n);
	vector<int>b(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].x >> a[i].y >> a[i].z >> a[i].k;
		//a[i].u = a[i].k - a[i].y, a[i].v = a[i].z - a[i].x;
		//a[i].m = a[i].u * a[i].v;
	}
	//for (int i = 0; i < n; i++)
	//	for (int j = i + 1; j < n; j++)
	//		if (a[i].m + a[j].m + a[i].u * a[j].v + a[i].v * a[j].u >=
	//			(max(a[i].z, a[j].z) - min(a[i].x, a[j].x)) * (max(a[i].k, a[j].k) - min(a[i].y, a[j].y)))
	//			b[i]++, b[j]++;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (max(a[i].x, a[j].x) <= min(a[i].z, a[j].z) && max(a[i].y, a[j].y) <= min(a[i].k, a[j].k))
				b[i]++, b[j]++;
	for (int i = 0; i < n; i++)
		cout << b[i] << ' ';

	return 0;
}
*/

/*
4、督亢樊首成礼
*
//输入：
//4
//3
//4
//5
//6
//复制
//输出：
//1
//4
//10
//8
#include<iostream>
using namespace std;
int main()
{
	long long t, n, m;
	cin >> t;
	while (t--)
	{
		cin >> n;
		m = (n - 1) / 2 * n;
		if (n % 3 == 0)
			m -= n / 3 * 2;
		cout << m << endl;;
	}

	return 0;
}
*/

/*
5、樊期自刎献计
*?
//样例 1
//输入：
//1
//5
//aabba
//1 1 2 -10 3
//复制
//输出：
//3
//复制
//样例 2
//输入：
//1
//10
//caaabaacba
//1 1 -1 2 1 -3 -3 2 2 2
//复制
//输出：
//6
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
string s;
vector<int>a;
long long cl(int x, int y)
{
	long long z = 0;
	if (s[x] != 'a')
		for (int i = x; i < y; i++)
			z += a[i];
	else
	{
		int w;
		for (w = x; w < y; w++)
			if (s[w] != 'a')
				break;
		if (w == y)
			for (int i = x; i < y; i++)
				z += a[i];
		else
		{
			long long m = 0, mi = 0;
			int  l = w, r = w-1;
			for (int u = w - 1, v = w; u >= x && v < y; u--, v++)
			{
				m += a[u] + a[v];
				if (m < mi)
					mi = m, l = u, r = v;
			}
			for (int i = x; i < l; i++)
				z += a[i];
			for (int i = r + 1; i < y; i++)
				z += a[i];
		}
	}
	return z;
}
int main()
{
	long long  m;
	int t, n, f;
	queue<int>q;
	cin >> t;
	while (t--)
	{
		cin >> n >> s;
		a.resize(n);
		m = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (i && s[i - 1] != 'a' && s[i] == 'a')
				q.push(i);
		}
		q.push(n);
		int i = 0;
		while (!q.empty())
		{
			f = q.front();
			q.pop();
			m += cl(i, f);
			i = f;
		}
		cout << m << endl;
	}

	return 0;
}
*/
 
/*
7、易水送别绝唱
*
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int t, n, k;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		cout << n - (k - 1) / 2 << endl;
		for (int i = (k + 1) / 2; i <= n; i++)
			cout << i << ' ';
		cout << endl;
	}

	return 0;
}
*/

/*
9、舞阳失色退场
*?
//样例 1
//输入：
//1
//5
//14 2 7 7 7
//复制
//输出：
//14
//复制
//样例 2
//输入：
//1
//5
//1 2 3 4 5
//复制
//输出：
//-1
#include<iostream>
#include<vector>
using namespace std;
vector<int>c;
int bc(int x)
{
	if (x == c[x])
		return x;
	else return c[x] = bc(c[x]);
}
int main()
{
	long long t, n, ma, mx, k, h;
	bool u, v;
	vector<int>a;
	cin >> t;
	while (t--)
	{
		cin >> n;
		a.resize(n);
		c.resize(n);
		ma = mx = 0;
		v = 1;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			c[i] = i;
			if (a[i] > ma)
				ma = a[i];
		}
		for (int i = 1; v && i <= ma; i += 2)
		{
			k = i == 1 ? 2 : i;
			u = 1;
			for (int j = 2; j * j <= k; j++)
				if (k % j == 0)
				{
					u = 0;
					break;
				}
			if (u)
			{
				for (int l = 1; l < n; l++)
					for (int r = n-1-l; r>=0; r--)
						if (a[r] % k == 0 && a[r+l] % k == 0 && bc(l) != bc(r))
						{
							c[bc(r + l)] = bc(r);
							h = l * k;
							if (h > mx)
								mx = h;
						};
				v = 0;
				for (int j = 0; j < n; j++)
					if (c[j])
						v = 1;
			}
		}

		cout << (v ? -1 : mx) << endl;
	}

	return 0;
}
*/

/*
12、燕献太子亡国
*/
#include<iostream>
using namespace std;
int main()
{
	long long n, k, m = 0, h;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> h;
		if (i % k == 0)
			m += h;
	}
	cout << m << endl;

	return 0;
}
