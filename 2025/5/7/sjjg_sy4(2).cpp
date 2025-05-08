/*
编程实现一棵二叉排序树，包括插入、删除、查找等功能；
*/
#include<iostream>
using namespace std;
#define N 1000

class tree
{
public:
	tree() : x(0), y(0), q(NULL), p(NULL) {}
	tree(int key) : x(key), y(1), q(NULL), p(NULL) {}   //初始新结点

	void cj();     //创建

private:
	int x, y;      //x是内容，y是高度
	tree* q, * p;  //q是左指针，p是右指针

	int sd();      //返回高度
	void Max();    //计算高度
	tree* Lx();    //左旋
	tree* Rx();    //右旋
	tree* ph();    //调整平衡
	tree* jd(int key);        //生成新结点
	tree* cr(int key);        //插入结点
	tree* sc(int key);        //删除结点
	tree* cz(int key, int& a);//查找结点
	void xg(tree*& T);        //修改结点
	void qsc();    //前遍历
	void zsc();    //中遍历
	void h_Drl();  //后遍历_删除树
	void sy(tree* T);         //使用演示
};

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

tree* tree::ph()
{
	int num = q->sd() - p->sd(), num1;

	if (num > 1)
	{
		num1 = q->q->sd() - q->p->sd();
		if (num1 <= 0)
			q = q->Lx();

		return Rx();
	}
	if (num < -1)
	{
		num1 = p->q->sd() - p->p->sd();
		if (num1 >= 0)
			p = p->Rx();

		return Lx();
	}

	return this;
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
	return ph();
}

tree* tree::sc(int key)
{
	if (this == NULL)
		return NULL;

	else if (key < x)
		q = q->sc(key);

	else if (key > x)
		p = p->sc(key);

	else
	{
		tree* s = NULL;

		if (q && p)
		{
			s = p;
			while (s->q != NULL)
				s = s->q;
			x = s->x;
			p = p->sc(x);
		}
		else
		{
			s = q ? q : p;
			delete this;
			return s;
		}	
	}

	if (this == NULL)
		return NULL;

	Max();
	return ph();
}

tree* tree::cz(int key ,int&a)
{
	tree* l = this;
	while (l && l->x != key)
	{
		a++;
		l = l->x > key ? l->q : l->p;
	}
	if(!l) cout << "未找到该数据！" << endl;

	return l;
}

void tree::xg(tree*& T)
{
	int key;
	cout << "\n请输入要修改的数据:" << endl;
	cin >> key;
	T = T->sc(key);
	cout << "\n请输入修改后的数据:" << endl;
	cin >> key;
	T = T->cr(key);
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
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		/*this=cr(m);*/
		T = T->cr(m);
	}

	sy(T);
}

void tree::sy(tree* T)
{
	int n, m;
	cout << "\n前序遍历：" << endl;
	T->qsc();
	cout << "\n中序遍历：" << endl;
	T->zsc();

	cout << "\n请输入删除数据:" << endl;
	cin >> n;
	T = T->sc(n);

	cout << "\n前序遍历：" << endl;
	T->qsc();
	cout << "\n中序遍历：" << endl;
	T->zsc();

	cout << "\n请输入查找数据:" << endl;
	cin >> n;
	m = 0;
	m += !!T->cz(n, m);
	cout << "共查找" << m << "次。" << endl;

	T->xg(T);
	cout << "\n前序遍历：" << endl;
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
