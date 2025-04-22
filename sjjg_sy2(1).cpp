/*
1.栈的顺序表示和实现编写一个程序实现顺序栈的各种基本运算，并在此基础上设计一个主程序，完成如下功能：
初始化顺序栈；入栈；出栈；取栈顶元素；判断栈是否为空
*/
#include<iostream>
using namespace std;
class stack
{
public:
	int a[100];
	int q = 0;

	bool empty();
	bool push(int x);
	int top();
	bool pop();
};

bool stack::empty()
{
	return !q;
}
bool stack::push(int x)
{
	if (q >= 99)return 0;
	a[q++] = x;
	return 1;
}
int stack::top()
{
	return a[q - 1];
}
bool stack::pop()
{
	if (empty())return 0;
	q--;
	return 1;
}

int main()
{
	stack t;
	int n, m;
	cout << "请输入栈的容量：" << endl;
	cin >> n;
	cout << "请依次输入元素：" << endl;
	while (n--)
	{
		cin >> m;
		t.push(m);
	}
	cout << "元素输出：" << endl;
	while (!t.empty())
	{
		m = t.top();
		cout << m << " ";
		t.pop();
	}

	return 0;
}
