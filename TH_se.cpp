#include<iostream>
#include<vector>
using namespace std;
float mi = 100, num = 0, a[4][4] = {
		{2.48,1.73,-1  ,2.14},
		{2.2 ,-1  ,2.96,1.84},
		{2.17,2.39,2.78,-1  },
		{2.48,1.73,-1  ,2.14}
};
vector<bool>v(4, 0);
vector<int>h(4),u(4);
void dfs(int n)
{
	if (n == 4 && mi > num)
	{
		cout << mi << endl;
		mi = num;
		u = h;
	}
	for (int j = 0; j < 4; j++)
		if (!v[j] && a[n][j] != -1)
		{
			v[j] = 1, h[n] = j + 1, num += a[n][j];
			dfs(n + 1);
			v[j] = 0, num -= a[n][j];
		}
}
int main()
{
	dfs(0);
	cout << mi << endl;
	for (int i = 0; i < 4; i++)
		cout << i + 1 << " " << u[i] << " " << a[i][u[i]-1] << endl;
	
	return 0;


	
}


