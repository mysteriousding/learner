/*错误一（P11）
* 
* 错误:为了使原来编写的C+＋程序能够运行，仍允许使用原有的带后缀．h的头文件，即二者同时并存，由用户选用。
       例如：#include<iostream.h>
*
* 说明:在 Visual Studio 2022 、Dev-C++ 上均不可行

#include<iostream>
using namespace std;
int main()
{
	cout << "This is a C++ program.";

	return 0;
}
*/

/*错误二（P89）
* 
* 错误:若变量i的值为3，有以下函数调用：
       func(i,++i);
       如果按自左至右顺序求实参的值，则函数调用相当于func(3,4)，若按自右至左顺序求实参的值，则相当于func(3,3)。
	   许多C+＋系统（例如 Visual C+＋和GCC）是按自右至左的顺序求值的。
*
* 说明:若按自右至左顺序求实参的值,在 Visual Studio 2022 、Dev-C++ 上均相当于func(4,4)。

#include<iostream>
using namespace std;

void func(int x, int y)
{
	cout << x << " " << y << endl;
}

int main()
{
	int i = 3;
	func(i, ++i);
	cout << i << endl;



	return 0;
}
*/
