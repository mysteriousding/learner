#include<iostream>            //正方形
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i <= n ; i++)
	{
		for (int j = 0; j <= n * 2+ 5; j++)
		{
			if (j < 5) { cout << " "; }
			   else {cout << "*";}
		}
		cout << endl;
	}

	return 0;
}
