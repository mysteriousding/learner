#include<iostream>
using namespace std;
class ABC           //命名一个类
{
private:            //类中私有部分
	int X;     //定义两个变量
	int Y;
public:             //类中公有部分
	void a()   //定义函数
	{
		cin >> X;                      //输入两个数
		cin >> Y;
	}
	void b()   //定义函数
	{
		cout << "X=" << X << endl;     //输出两句话
		cout << "Y=" << Y << endl;
	};
};
ABC A, B;       //A和B是ABC类中的元素
int main()      //主函数
{  
	A.a();      //元素和函数的乘法分配律       
	B.a();
	A.b();
	B.b();

	return 0;
}
//定义函数，输入数值，输出语句。全部一次性搞好了，后面直接拉出来用。        有点像合并同类项。
