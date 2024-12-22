#include<iostream>
#include<vector>
using namespace std;
void px(vector<int>& m, int x, int z, int y)
{
	int* p = new int[y - x + 1];
	int k = 0, f = x, g = z+1;
	while (f <= z && g <= y)
	{
		if (m[f] <= m[g])
			p[k++] = m[f++];
		else p[k++] = m[g++];
	}
	while (f <= z)
		p[k++] = m[f++];
	while (g <= y)
		p[k++] = m[g++];
	for (int i = x; i <= y; i++)
		m[i] = p[i - x];
	delete[]p;
}
void sort(vector<int>& m, int x, int y)
{
	if (x >= y)return;
	int k = (x + y) / 2;
	sort(m, x, k);
	sort(m, k + 1, y);
	px(m, x, k, y);
}
int main()
{
	int n;
	cin >> n;
	vector<int>m(n);
	for (int i = 0; i < n; i++)
		cin >> m[i];
	sort(m, 0, n - 1);
	for (int j = 0; j < n; j++)
		cout << m[j] << " ";

	return 0;
}
