#include<iostream>
#include<string>
using namespace std;
int main()
{
	/*字符串型尝试
	
	//char str[];     错误了，不可以这么定义

	char str[]="string";   //应该这么定义


	//str = "string";   错误了，不可以这么赋值

	//str[] = "string";    还是错误了，不可以这么赋值

	//试过了，没办法赋值……

	cin >> str;       //但是可以这么输入


	//cout << str[];     错误了，不可以这么输出

	cout << str << endl;       //应该这么定义赋值



	string str1;

	str1 = "string1";

	cin >> str1;

	cout << str1 << endl;
	*/

	/*整型尝试
	int a = 20L;

	cout << a << endl;

	int b = 020;

	cout << b << endl;   //输出为16

	int c = 0x20;

	cout << c << endl;
	*/

	/*递增递减尝试*/
	int a = 2, b = ++a;
	cout << "前置递增:   a = 2; b = ++a;        " << "a = " << a << "; b = " << b << "; " << endl;

	a = 2; b = a++;
	cout << "后置递增:   a = 2; b = a++;        " << "a = " << a << "; b = " << b << "; " << endl;

	a = 2; b = --a;
	cout << "前置递减:   a = 2; b = --a;        " << "a = " << a << "; b = " << b << "; " << endl;

	a = 2; b = a--;
	cout << "后置递减:   a = 2; b = a--;        " << "a = " << a << "; b = " << b << "; " << endl;



	return 0;
}
