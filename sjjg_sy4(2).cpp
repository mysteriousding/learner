/*
编程实现一棵二叉排序树，包括插入、删除、查找等功能；
*/
#include<iostream>
using namespace std;
#define N 1000

class tree
{
public:
	int x, y;
	tree* q, * p;
	tree() : x(0), y(0), q(NULL), p(NULL) {}
	tree(int key) : x(key), y(0), q(NULL), p(NULL) {}

	bool cj0();
	void dg0(int a[],int x,int y);

	int sd();
	void Max();
	tree* Lx();
	tree* Rx();
	tree* jd(int key);
	tree* cr(int key);
	void qsc();
	void zsc();
	void h_Drl();
	void cj();
};


/*折半查找判定树实现平衡二叉树构构建 start*/
bool tree::cj0()
{
	int a[N], n, k;
	cout << "请输入数据个数:" << endl;
	cin >> n;
	cout << "请依次输入数据,构建平衡二叉树:" << endl;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++)
	{
		a[0] = a[i], k = i;
		for (int j = i + 1; j <= n; j++)
			if (a[0] > a[j])
				a[0] = a[j], k = j;
		a[k] = a[i], a[i] = a[0];
	}
	this->dg0(a, 1, n);

	return 1;
}

void tree::dg0(int a[], int b1, int b2)
{
	int c = (b1 + b2) / 2;
	x = c;
	if (b1 <= c - 1)
	{
		q = new tree;
		q->dg0(a, b1, c - 1);
	}
	if (c + 1 <= b2)
	{
		p = new tree;
		p->dg0(a, c + 1, b2);
	}
}
/*折半查找判定树实现平衡二叉树构构建 end*/

int tree::sd()
{
	return this ? y : 0;
}

void tree::Max()
{
	y = max(q->sd(), p->sd()) + 1;
}

tree* tree::Lx()
{
	tree* newt = p;
	p = p->q;
	newt->q = this;
	Max();
	newt->Max();

	return newt;
}

tree* tree::Rx()
{
	tree* newt = q;
	q = q->p;
	newt->p = this;
	Max();
	newt->Max();

	return newt;
}

tree* tree::jd(int key)
{
	tree* node = new tree(key);

	return node;
}

tree* tree::cr(int key)
{
	if (this == NULL)
		return jd(key);

	else if (key < x)
		q = q->cr(key);

	else if (key > x)
		p = p->cr(key);

	else return this;

	Max();
	int num = q->sd() - p->sd(), num1;
	if (num > 1)
	{
		num1 = q->q->sd() - q->p->sd();
		if (num1 < 0)
			p->Lx();

		return Rx();
	}
	if (num < -1)
	{
		num1 = p->q->sd() - p->p->sd();
		if (num1 > 0)
			q->Rx();

		return Lx();
	}

	return this;
}

void tree::qsc()
{
	if (this == NULL)
		return;
	cout << x << " ";
	q->qsc();
	p->qsc();
}

void tree::zsc()
{
	if (this == NULL)
		return;
	q->zsc();
	cout << x << " ";
	p->zsc();
}

void tree::h_Drl()
{
	if (this == NULL)
		return;
	q->h_Drl();
	p->h_Drl();
	delete this;
}

void tree::cj()
{
	tree* T = NULL;
	int  n, m;
	cout << "请输入数据个数:" << endl;
	cin >> n;
	cout << "请依次输入数据,构建平衡二叉树:" << endl;
	for (int i = 1; i <= n; i++)
	{
		cin >> m;
		/*this=cr(m);*/
		T = T->cr(m);
	}
	cout << "前序遍历：" << endl;
	T->qsc();
	cout << "\n中序遍历：" << endl;
	T->zsc();
	T->h_Drl();
}

int main()
{
	tree* T = NULL;
	T->cj();

	return 0;
}

/*
9 8 7 6 5 4 3 2 1
*/
