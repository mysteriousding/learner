/*
#include<iostream>
using namespace std;
int main()
{
	int a, b, c = 1;
	int n[10];
	cin >> a;
	while (true)
	{
		b = a % 26;
		a /= 26;
		n[c] = b;
		if (a == 0) { break; }
		c++;
	}
	for (c = c; c >= 0; c--)
	{
		cout << (char)(n[c] + 64);
	}
	cout << endl;

	return 0;
}
*/

#include<iostream>
using namespace std;
int main()
{
	int a, b, c = 1;
	int n[10];
	cout << "用字母A对应数字1,B对应2以此类推，用Z对应26。\n对于27以上的数字,用两位或更长位的字符串来对应，例如AA对应27，AB对应28，AZ对应52，LQ对应329。\n请问X对应的字符串是什么？" << endl;
	cout << "请输入X为你计算" << endl;
	cin >> a;
	cout << "X=";
	while (true)
	{
		b = a % 26;
		a /= 26;
		n[c] = b;
		if (a == 0) { break; }
		c++;
	}
	for (c = c; c >= 0; c--)
	{
		cout << (char)(n[c] + 64);
	}
	cout << endl << "计算完毕，谢谢使用！" << endl;

	return 0;
}
