/*
3．栈的应用（可根据实际情况进行调整）利用栈的基本操作实现一个程序，判断算术表达式中的圆括号、方括号是否正确配对。
*/
#include<iostream>
#include<string>
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
}t;

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

bool pd(char x)
{
	char y = '0';
	while (y != x && !t.empty())
	{
		y = t.top();
		t.pop();
	}
	return y == x;
}

int main()
{
	bool u = 1;
	string n;
	char m;
	cout << "请输入算术表达式：" << endl;
	getline(cin, n);
	for (int i = 0; i < n.size(); i++)
	{
		if (n[i] == '&')break;
		else if (n[i] == '}')u = pd('{');
		else if (n[i] == ']')u = pd('[');
		else if (n[i] == ')') u = pd('(');
		else t.push(n[i]);
		if (!u)break;
	}
	if (u)
		while (!t.empty())
		{
			m = t.top();
			t.pop();
			if (m == '[' || m == '(')
			{
				u = 0;
				break;
			}
		}
	cout << (u ? "Yes" : "NO") << endl;

	return 0;
}