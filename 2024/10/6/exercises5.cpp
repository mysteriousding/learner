﻿#include<iostream>
using namespace std;
//错误：
//int main();
//{
//   int a,b;
//   c=add(a,b)
//   cout<<"a+b="<<c<<endl;
//   return 0;
//}
//int add(int x,int y);
//{
//   z=x+y;
//   return(z）;
// }
//改正：                 （共五处错误）
int main()
{
	int add(int x, int y);
	int a, b, c;
	cin >> a >> b;
	c = add(a, b);
	cout << "a+b=" << c << endl;

	return 0;
}
int add(int x, int y)
{
	int z;
	z = x + y;

	return(z);
}
