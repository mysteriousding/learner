/*
3．队列的应用（可根据实际情况进行调整）二项式(a+b)n展开后，其系数构成杨辉三角形，利用队列写出打印杨辉三角形的前n行的程序。
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
	void qk();
};

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

void queue::qk()
{
	while (!empty())
		pop();
}

void yh(int n)
{
	int front, sum, f;
	queue q[2];
	q[0].push(1);
	for (int i = 0; i < n; ++i)
	{
		q[(i + 1) % 2].qk();
		for (int j = 0; j <= i; ++j)
		{
			front = q[i % 2].front();
			q[i % 2].pop();
			cout << front << " ";
			sum = front + (j == 0 ? 0 : f);
			q[(i + 1) % 2].push(sum);
			f = front;
		}
		q[(i + 1) % 2].push(1);
		cout << endl;
	}
}

int main()
{
	int n,m;
	cout << "请输入杨辉三角形层数 ：" << endl;
	cin >> n;
	yh(n);


	return 0;
}
