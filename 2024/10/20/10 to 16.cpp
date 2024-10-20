#include<iostream>
using namespace std;
int main()
{
	int a, b, c, d, i = 0;
	int arr[20];
	cout << "请输入一个十进制数，让我为你将他转化为十六进制。" << endl;
	cin >> a;
	c = a;
	for (;; i++)
	{
		b = a % 16;
		a /= 16;
		if ( b <= 9) { arr[i] = b; }
		   else {arr[i] = (b - 9 + 64);}
		if (a == 0)break;
	}
	a = c;
	cout << endl << a << " 的十六进制 =  ";
	for (; i >= 0; i--)
	{
		d = arr[i];
		if (b <= 9) { cout << d; }
		   else { cout << (char)d; }
	}
	cout << endl;

	/*for (int i=0; i <= 2; i++)
	{
		cin >> arr[i];
	}

	for (int i=2; i >=0 ; i--)
	{
		cout << arr[i];	
	}*/



	return 0;
}
