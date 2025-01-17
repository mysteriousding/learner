/*
有 n 个孩子站成一圈，从第一个 孩子开始顺时针方向报数，报到 3 的人出列，
下一个人继续从 1 报数，直到最后剩下一个孩子为止。
问剩下第几个孩子。
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n, i = 0, j = 0;
	cin >> n;
	vector<int>m(n);
	for (int k = 0; k < n; k++)
		m[k] = k + 1;
	bool u = 0;
	while (m.size() != 1)
	{
		i++, j++;
		if (j >= m.size())j -= m.size();
		if (i == 3)
		{
			if (!j)j = m.size();
			//cout << m[j - 1] << endl;
			m.erase(m.begin() + --j);
			i = 0;
		}
		
	}

	cout << m[0] << endl;

	return 0;
}


//验证代码
//#include <iostream>
//using namespace std;
//int main()
//{
//    int n, f = 0, m;
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++) f = (f + m) % i;
//    cout << f + 1 << endl;
//}