#include<iostream>
using namespace std;
int main()
{
	int x = 0, y = 0;
	int a[8];
	for (int i = 0; i < 8; i++)
	{

		cin >> a[i];

		if (a[i] >= 85)
		{
			x += 1;
			y += 1;
		}
		else if (a[i] >= 60)
		{
			y += 1;
		}
	}

		cout << "优秀率:" << (int)(((x / 8.0) * 100) + 0.5) << "%" << endl;
		cout << "及格率:" << (int)(((y / 8.0) * 100) + 0.5) << "%" << endl;

		return 0;
}