/*
1．队列的顺序表示和实现编写一个程序实现顺序队列的各种基本运算，并在此基础上设计一个主程序，完成如下功能：
初始化顺序队列；入队；出队；判断队列是否为空。
*/
#include<iostream>
using namespace std;
#define N 100
class queue
{
public:
	int a[N];
	int x = 0, y = 0;
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
	a[y % N] = n;
	y++;
	return 1;
}

bool queue::pop()
{
	if (x >= y)return 0;
	x++;
	return 1;
}

int queue::front()
{
	return a[x%N];
}

int queue::back()
{
	return a[(y-1) % N];
}

bool queue::empty()
{
	return x >= y;
}

int queue::size()
{
	return y - x;
}

bool queue::sr()
{
	int n, m;
	cout << "请输入添加元素个数 ：" << endl;
	cin >> n;
	if (y - x + n > N)
	{
		cout << "输入过多！" << endl;
		return 0;
	}
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
	if (y - x <n)
	{
		cout << "输出过多！" << endl;
		return 0;
	}
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
