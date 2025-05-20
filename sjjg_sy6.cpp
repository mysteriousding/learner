/*
对任意给定的二叉树完成下列操作：
（1）根据输入的序列，建立二叉链表存储结构；
（2）输出该二叉树的先序、中序、后序遍历结果（递归算法）；
（3）先序遍历二叉树（非递归算法）；
（4）借助队列实现二叉树的层次遍历；
（5）求二叉树的高度；
（6）求二叉树叶子结点个数；
（7）将二叉链表视为树或森林的孩子兄弟链表，计算其叶子结点个数。
*/
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct tree
{
	int num,b=0,c=0;
	tree* q = NULL;
	tree* p = NULL;
}*T;

bool cr(int m)
{
	tree* f = T, * node = new tree;
	node->num = m;
	if (!T)
	{
		T = node;
		return 1;
	}
	while (1)
	{
		if (!f->c || !f->b)
		{
			if (!f->c)f->c++, f->p = node;
			else  f->b++, f->q = node;
			
			return 1;
		}
		if (f->c <= f->b)f->c++, f = f->p;
		else f->b++, f = f->q;
	}
	return 0;
}

void jl()
{
	int n,m;
	cout << "请输入数据的个数:" << endl;
	cin >> n;
	cout << "请依次输入数据:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		cr(m);
	}
}

void qsc(tree*f)
{
	if (!f)return;
	cout << f->num << " ";
	qsc(f->q);
	qsc(f->p);
}

void zsc(tree* f)
{
	if (!f)return;
	zsc(f->q);
	cout << f->num << " ";
	zsc(f->p);
}

void hsc(tree* f)
{
	if (!f)return;
	hsc(f->q);
	hsc(f->p);
	cout << f->num << " ";
}

void F_qsc()
{
	stack<tree*>S;
	tree* f;
	S.push(T);
	while (!S.empty())
	{
		f = S.top();
		S.pop();
		cout << f->num << " ";
		if (f->p)S.push(f->p);
		if (f->q)S.push(f->q);
	}
	cout << endl;
}

void C_sc()
{
	queue<tree*>Q;
	tree* f;
	Q.push(T);
	while (!Q.empty())
	{
		f = Q.front();
		Q.pop();
		cout << f->num << " ";
		if (f->q)Q.push(f->q);
		if (f->p)Q.push(f->p);
	}
	cout << endl;
}

int high(tree*f)
{
	if (!f)return 0;
	return max(high(f->q), high(f->p)) + 1;
}

int yz()
{
	stack<tree*>S;
	tree* f;
	int k = 0;
	S.push(T);
	while (!S.empty())
	{
		f = S.top();
		S.pop();
		if (!f->c && !f->b)k++;
		else
		{
			if (f->q)S.push(f->q);
			if (f->p)S.push(f->p);
		}
	}
	return k;
}

int hz_yz()
{
	queue<tree*>Q;
	tree* f;
	int k = 0;
	Q.push(T);
	while (!Q.empty())
	{
		f = Q.front();
		Q.pop();
		if (f->p)Q.push(f->p);
		if (f->q)Q.push(f->q);
		else k++;
	}
	return k;
}

int main()
{
	jl();
	cout << "先序、中序、后序遍历结果（递归算法）: " << endl;
	qsc(T);
	cout <<endl;
	zsc(T);
	cout << endl;
	hsc(T);
	cout << endl;
	cout << "先序遍历（非递归算法）: " << endl;
	F_qsc();
	cout << "层次遍历: " << endl;
	C_sc();
	cout << "高度: " << endl;
	cout << high(T) << endl;
	cout << "结点个数: " << endl;
	cout << yz() << endl;
	cout << "将二叉链表视为树或森林的孩子兄弟链表，其叶子结点个数为: " << endl;
	cout << hz_yz() << endl;


	return 0;
}