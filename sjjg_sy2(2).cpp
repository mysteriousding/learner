/*
2．栈的链式表示和实现编写一个程序实现链栈的各种基本运算，并在此基础上设计一个主程序，完成如下功能：
初始化链栈；入栈；出栈；取栈顶元素；判断栈是否为空。
*/
#include<iostream>
using namespace std;
struct list
{
	int a;
	list* next;
};
class stack
{
public:
	int dx = 0;
	list* L = NULL;

	bool empty();
	bool push(int x);
	int top();
	bool pop();
};

bool stack::empty()
{
	return !L;
}
bool stack::push(int x)
{
	list* q = new list;
	q->a = x;
	q->next = L;
	L = q;
	dx++;
	return 1;
}
int stack::top()
{
	return L->a;
}
bool stack::pop()
{
	if (empty())return 0;
	list* q = L;
	L = L->next;
	delete q;
	dx--;
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