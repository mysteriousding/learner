/*
2．队列的链式表示和实现   编写一个程序实现链队列的各种基本运算，并在此基础上设计一个主程序，完成如下功能：
初始化链队列；入队；出队；判断队列是否为空。
*/
#include<iostream>
using namespace std;
struct list
{
	int k;
	list* next = NULL;
};
class queue
{
public:
	int dx = 0;
	list* q = NULL;
	list* p = NULL;
	bool push(int n);
	bool pop();
	int front();
	int back();
	bool empty();
	int size();
	bool sr();
	bool sc();
	void sw();
}t;

bool queue::push(int n)
{
	if (!dx)q = p = new list;
	else
	{
		p->next = new list;
		p = p->next;
	}
	p->k = n;
	dx++;
	return p;
}

bool queue::pop()
{
	if (!dx)return 0;
	list* l = q;
	q = q->next;
	delete l;
	if (q == NULL)p = NULL;
	dx--;
	return 1;
}

int queue::front()
{
	if (!dx)return -1;
	return q->k;
}

int queue::back()
{
	if (!dx)return -1;
	return p->k;
}

bool queue::empty()
{
	return q == NULL;
}

int queue::size()
{
	return dx;
}

bool queue::sr()
{
	int n, m;
	cout << "请输入添加元素个数 ：" << endl;
	cin >> n;
	cout << "请依次输入元素 ：" << endl;
	while (n--)
	{
		cin >> m;
		t.push(m);
	}
	return 1;
}
bool queue::sc()
{
	int n, m;
	cout << "请输入输出元素个数 ：" << endl;
	cin >> n;
	while (n--)
	{
		m = t.front();
		cout << m << " ";
		t.pop();
	}
	cout << endl;
	return 1;
}

void queue::sw()
{
	int m;
	cout << "剩余元素 ：" << endl;
	while (!t.empty())
	{
		m = t.front();
		cout << m << " ";
		t.pop();
	}
	cout << endl;
}

int main()
{

	t.sr();
	t.sc();
	t.sw();

	return 0;
}
