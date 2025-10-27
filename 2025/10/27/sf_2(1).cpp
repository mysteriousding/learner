/*
输出一个数组n个元素的全排列，描述算法基本思想，并给出程序。
*/
#include<iostream>
#include<string>
using namespace std;
string n;
int m;
void dg(int k)
{
	if (k == m)
	{
		cout << n << endl;
		return;
	}
	char h;
	for (int i = k; i < m; i++)
		if (i == k || n[i] != n[k])
		{
			h = n[i], n[i] = n[k], n[k] = h;
			dg(k + 1);
			h = n[i], n[i] = n[k], n[k] = h;
		}
}
int main()
{
	getline(cin, n, '\n');
	m = n.size();
	dg(0);

	return 0;

}


