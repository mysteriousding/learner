#include <iostream>】】
#include <cstdlib>
#include <ctime>
#include <vector>
#include <queue>
using namespace std;
int cd(int x)
{
	int y = 0;
	while (x)
		x /= 10, y++;
	return y;
}
int main()
{
	srand((unsigned)time(NULL));
	int n, m = 0, k = 1;
	cin >> n;
	vector<int>nl(n), wc(n), cc(n, 1), shu(n, 0), yin(n, 0), pm(n);
	vector<queue<int>>q(n + 1);
	for (int i = 0, h; i < n; i++)
	{
		h = rand() % n + 1;
		nl[i] = h;
		if (n / 2 < h)
			h = n - h;
		h++;
		wc[i] = rand() % h;
		q[1].push(i);
	}
	int  a, b, x, y;
	while (k < n)
		for (int i = k; i > 0; i--)
		{
			if (q[i].size() < 2)
				continue;
			a = q[i].front();
			q[i].pop();
			b = q[i].front();
			q[i].pop();

			x = rand() % (wc[a] * 2 + 1) - wc[a] + nl[a];
			y = rand() % (wc[b] * 2 + 1) - wc[b] + nl[b];
			if (x > y)
				a += b, b = a - b, a -= b;

			shu[a]++, yin[b]++;
			cc[b]++;
			if (k < cc[b])
				k = cc[b];
			if (cc[a] > 1)
				cc[a]--;

			q[cc[a]].push(a);
			q[cc[b]].push(b);
			m++;
		}

	int n_w = cd(n), y_w = 0, s_w = 0, h;
	for (int i = 0; i < n; i++)
	{
		if (y_w < yin[i])
			y_w = yin[i];
		if (s_w < shu[i])
			s_w = shu[i];
		pm[cc[i] - 1] = i;
	}
	y_w = cd(y_w), s_w = cd(s_w);

	for (int i = 1; i <= n; i++)
	{
		h = pm[n - i];
		printf("序号%0*d:   层次-%*d   能力-%*d   误差-%*d   胜-%*d   负-%*d \n", n_w, h, n_w, cc[h], n_w, nl[h], n_w, wc[h], y_w, yin[h], s_w, shu[h]);
	}
	cout << m << endl;// m = n*(n^2-1)/6   三角金字塔   n(n-1)(n-2)/6

	return 0;
}
