#include<iostream>
#include<queue>
using namespace std;

#define MAXSIZE 100
typedef int ElemType;
ElemType r[MAXSIZE] = { 0 };

typedef struct node
{
	ElemType key;
	struct node* lchild, * rchild;
}BstNode, * BsTree;

void Menu()
{
	cout << "\n";
	cout << "******二叉排序树使用菜单******" << '\n';
	cout << "--------------------------------" << '\n';
	cout << "     1.构造二叉排序树          " << '\n';
	cout << "     2.递归算法插入操作" << '\n';
	cout << "     3.非递归算法插入操作" << '\n';
	cout << "     4.递归算法查找操作" << '\n';
	cout << "     5.非递归算法查找操作" << '\n';
	cout << "     6.删除操作" << '\n';
	cout << "     7.层序遍历打印二叉排序树" << '\n';
	cout << "     8.退出" << '\n';
	cout << "--------------------------------" << '\n';
}

int InsertBST1(BsTree& root, BsTree& s);

//1.构造二叉排序树
int BiSortTree(BsTree& root, ElemType r[], int n)
{
	for (int i = 1; i <= n; i++)
	{
		BsTree s;
		s = new BstNode;
		s->key = r[i];
		s->lchild = s->rchild = NULL;
		InsertBST1(root, s);
	}
	return 1;
}

//2.递归算法插入操作
int InsertBST1(BsTree& root, BsTree& s)
{
	if (root == NULL)
	{
		root = s;
	}
	else if (s->key < root->key)
	{
		InsertBST1(root->lchild, s);
	}
	else
	{
		InsertBST1(root->rchild, s);
	}
	return 1;
}
//3.非递归算法插入操作
int InsertBST2(BsTree& root, BsTree& s)
{
	BsTree parent = NULL;
	BsTree p = root;
	if (root == NULL)
	{
		root = s;
		return 1;
	}

	while (p != NULL)
	{
		parent = p;
		if (s->key < p->key) p = p->lchild;
		else p = p->rchild;
	}

	//parent指向s的父亲结点
	if (parent->key > s->key) parent->lchild = s;
	else parent->rchild = s;

	return 1;
}

//4.递归算法查找操作
BsTree* SearchBST1(BsTree& root, ElemType k)
{
	if (root == NULL)
	{
		return NULL;
	}
	else if (k == root->key)
	{
		return &root;
	}
	else if (k < root->key)
	{
		return SearchBST1(root->lchild, k);
	}
	else
	{
		return SearchBST1(root->rchild, k);
	}
}
//5.非递归算法查找操作
BsTree SearchBST2(BsTree& root, ElemType k)
{
	BsTree p;
	p = root;
	while (p != NULL && p->key != k)
	{
		if (k < p->key) p = p->lchild;
		else p = p->rchild;
	}
	//找到了返回该结点，未找到返回NULL
	return p;
}

//6.删除操作
bool Delete(BsTree& s)
{
	BsTree p, q;
	//1.s结点是叶子节点
	if (s->lchild == NULL && s->rchild == NULL)
	{
		delete s;
		s = NULL;
	}

	//2.s结点只有左子树或者只有右子树
	//2.1.s结点只有左子树
	else if (s->rchild == NULL)//s的右子树为空
	{
		p = s;
		s = s->lchild;
		delete p;
	}
	//2.2.s结点只有右子树
	else if (s->lchild == NULL)//s的左子树为空
	{
		p = s;
		s = s->rchild;
		delete p;
	}

	//3.s结点既有左子树也有右子树
	else
	{
		p = s;
		q = s->rchild;//用q指向s中序遍历的直接后继
		//p结点为q结点的父亲结点
		while (q->lchild != NULL)
		{
			p = q;
			q = q->lchild;
		}
		s->key = q->key;

		Delete(q);
	}

	return true;
}

//7.层序遍历打印二叉排序树
void Print(BsTree& root)
{
	cout << "层序遍历二叉排序树的结果为：" << '\n';
	queue< BsTree> node;

	if (root != NULL)
	{
		node.push(root);
	}

	while (!node.empty())
	{
		BsTree p = node.front();
		node.pop();
		if (p != NULL)
		{
			cout << p->key << " ";
			if (p->lchild != NULL)
			{
				node.push(p->lchild);
			}
			if (p->rchild != NULL)
			{
				node.push(p->rchild);
			}
		}
	}
	cout << '\n';
}

int main()
{
	BsTree root;
	root = NULL;
	ElemType k;//查找用
	BsTree s, t, * t0;//s插入用，t查找用
	int n;

	while (1)
	{
		Menu();
		cout << "请输入需要使用的功能（1~8）：";
		int m;
		cin >> m;
		switch (m)
		{
		case 1:cout << "欢迎进入构造二叉排序树" << '\n';
			cout << "请输入您要构造的二叉排序树的结点个数：";
			cin >> n;
			cout << "请输入各结点元素的值：";
			for (int i = 1; i <= n; i++)
			{
				cin >> r[i];
			}
			if (BiSortTree(root, r, n))
			{
				cout << "二叉排序树构造完毕" << '\n';
			}
			Print(root);
			break;
		case 2:cout << "欢迎进入递归算法插入操作" << '\n';
			cout << "请输入您要插入的结点元素的值：";
			s = new BstNode;
			s->lchild = s->rchild = NULL;
			cin >> s->key;
			if (InsertBST1(root, s))
			{
				cout << "插入操作已完成" << '\n';
			}
			Print(root);
			break;
		case 3:cout << "欢迎进入非递归算法插入操作" << '\n';
			cout << "请输入您要插入的结点元素的值：";
			s = new BstNode;
			s->lchild = s->rchild = NULL;
			cin >> s->key;
			if (InsertBST2(root, s))
			{
				cout << "插入操作已完成" << '\n';
			}
			Print(root);
			break;
		case 4:cout << "欢迎进入递归算法查找操作" << '\n';
			cout << "请输入您要查找的结点元素的值：";
			cin >> k;
			t0 = SearchBST1(root, k);
			if (t0 && *t0)
			{
				cout << "该节点在二叉排序树中" << '\n';
				cout << "该节点的左孩子为：";
				if ((*t0)->lchild == NULL)
				{
					cout << "空" << '\n';
				}
				else
				{
					cout << (*t0)->lchild->key << '\n';
				}
				cout << "该节点的右孩子为：";
				if ((*t0)->rchild == NULL)
				{
					cout << "空" << '\n';
				}
				else
				{
					cout << (*t0)->rchild->key << '\n';
				}
			}
			else
			{
				cout << "该节点不在二叉排序树中" << '\n';
			}
			break;
		case 5:cout << "欢迎进入非递归算法查找操作" << '\n';
			cout << "请输入您要查找的结点元素的值：";
			cin >> k;
			t = SearchBST2(root, k);
			if (t)
			{
				cout << "该节点在二叉排序树中" << '\n';
				cout << "该节点的左孩子为：";
				if (t->lchild == NULL)
				{
					cout << "空" << '\n';
				}
				else
				{
					cout << t->lchild->key << '\n';
				}
				cout << "该节点的右孩子为：";
				if (t->rchild == NULL)
				{
					cout << "空" << '\n';
				}
				else
				{
					cout << t->rchild->key << '\n';
				}
			}
			else
			{
				cout << "该节点不在二叉排序树中" << '\n';
			}
			break;
		case 6:cout << "欢迎进入删除操作" << '\n';
			cout << "请输入您要删除的结点元素的值：";
			cin >> k;
			t0 = SearchBST1(root, k);
			if (t0 && *t0)
			{
				if (Delete(*t0))
				{
					cout << "删除操作已完成" << '\n';
					Print(root);
				}
			}
			else
			{
				cout << "该节点不在二叉排序树中" << '\n';
			}
			break;
		case 7:cout << "欢迎进入层序遍历打印二叉排序树" << '\n';
			Print(root);
			break;
		case 8:cout << "谢谢使用程序，再见！";
			return 0;
		}
	}
	return 0;
}


/*
63 90 70 55 42 10 45 58 83 67
*/
