#include<iostream>
#include<string>
using namespace std;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;

typedef struct
{
	string name;
	int age;
	int sex;
	int year;
	string ban;
	string jk;
}data0;
typedef struct stu
{
	data0 d;
	stu* next;
}*list;

Status InitLIst(list& L)
{
	L = new stu;
	if (!L)exit(OVERFLOW);
	L->next = NULL;
	cout << "创建成功！" << endl;
	return OK;
}
void sr(data0 &d)
{
	cout << "请输入名字: " << endl;
	cin >> d.name;
	cout << "请输入学号: " << endl;
	cin >> d.age;
	cout << "请输入性别:    0 - 女 , 1 - 男" << endl;
	cin >> d.sex;
	cout << "请输入年龄: " << endl;
	cin >> d.year;
	cout << "请输入班级: " << endl;
	cin >> d.ban;
	cout << "请输入健康状况: " << endl;
	cin >> d.jk;
}
Status listInsert(list& L, int n)
{
	if (!L)
	{
		cout << "请先创建线性表！" << endl;
		return ERROR;
	}
	stu* p = L;
	while (p->next != NULL)
		p = p->next;
	for (int i = 0; i < n; i++)
	{
		stu* node = new stu;
		if (!node)exit(OVERFLOW);
		cout << "\n\n学生 " << i + 1 << " : " << endl;
		sr(node->d);
		/*cout << "请输入名字: " << endl;
		cin >> node->d.name;
		cout << "请输入学号: " << endl;
		cin >> node->d.age;
		cout << "请输入性别:    0 - 女 , 1 - 男" << endl;
		cin >> node->d.sex;
		cout << "请输入年龄: " << endl; 
		cin >> node->d.year;
		cout << "请输入班级: " << endl;
		cin >> node->d.ban;
		cout << "请输入健康状况: " << endl;
		cin >> node->d.jk;*/
		node->next = NULL;
		p->next = node;
		p = p->next;
	}
	cout << "添加成功！" << endl;
	return OK;
}
Status DestroyList(list& L)
{
	stu* p;
	while (L != NULL)
	{
		p = L;
		L = L->next;
		delete p;
	}
	cout << "销毁成功！" << endl;
	return OK;
}
Status ClearList(list& L)
{
	stu* p;
	while (L->next != NULL)
	{
		p = L->next;
		L->next = L->next->next;
		delete p;
	}
	cout << "清空成功！" << endl;
	return OK;
}
Status ListEmpty(list L)
{
	if (!L)
	{
		cout << "请先创建线性表！" << endl;
		return ERROR;
	}
	return !(L->next);
}
Status ListLength(list L)
{
	if (!L)
	{
		cout << "请先创建线性表！" << endl;
		return ERROR;
	}
	int i = 0;
	stu* p = L->next;
	while (p != NULL)
	{
		++i;
		p = p->next;
	}
	return i;
}
Status Getlem(list L, int i, data0& e)
{
	if (!L)
	{
		cout << "请先创建线性表！" << endl;
		return ERROR;
	}
	if (i<1 || i>ListLength(L))
	{
		cout << "位置错误！" << endl;
		return ERROR;
	}
	stu* p = L->next;
	int j = 0;
	while (p != NULL )
	{
		++j;
		if (j == i)
		{
			e = p->d;
			return OK;
		}
		p = p->next;
	}
	
	return ERROR;
}
bool compare(data0 a, data0 b)
{
	return a.name == b.name 
		&& a.age == b.age 
		&& a.sex == b.sex 
		&& a.year == b.year 
		&& a.ban == b.ban 
		&& a.jk == b.jk;
}
Status LocateElem(list L, data0 e, bool(*compare)(data0 a, data0 b))
{
	if (!L)
	{
		cout << "请先创建线性表！" << endl;
		return ERROR;
	}
	stu* p = L->next;
	int i = 0;
	while(p != NULL)
	{
		i++;
		if ((*compare)(e, p->d))return i;
		p = p->next;
	}
	return 0;
}
Status PriorElem(list L, data0 cur_e, data0& pre_e)
{
	if (!L)
	{
		cout << "请先创建线性表！" << endl;
		return ERROR;
	}
	stu* p = L->next;
	int i = 0;
	while (p->next != NULL)
	{
		i++;
		if (compare(p->next->d, cur_e))
		{
			pre_e = p->d;
			return OK;
		}
		p = p->next;
	}
	return ERROR;
}
Status NextElem(list L, data0 cur_e, data0& next_e)
{
	if (!L)
	{
		cout << "请先创建线性表！" << endl;
		return ERROR;
	}
	stu* p = L->next;
	while (p->next != NULL)
	{
		if (compare(cur_e, p->d))
		{
			next_e = p->next->d;
			return OK;
		}
		p = p->next;
	}
	return ERROR;
}
Status ListInsrrt(list& L, int i, data0 e)
{
	if (!L)
	{
		cout << "请先创建线性表！" << endl;
		return ERROR;
	}
	if (i<1 || i>ListLength(L) + 1)
	{
		cout << "位置错误！" << endl;
		return ERROR;
	}
	stu* p = L, * s;
	int j = 0;
	while (p!= NULL)
	{
		if (i == j + 1)
		{
			s = p->next;
			p->next = new stu;
			if (!p->next)exit(OVERFLOW);
			p->next->d = e;
			p->next->next = s;
			cout << "插入成功！" << endl;
			return OK;
		}
		j++;
		p = p->next;
	}
	return ERROR;
}
Status ListDelete(list& L, int i, data0& e)
{
	if (!L)
	{
		cout << "请先创建线性表！" << endl;
		return ERROR;
	}
	if (i<1 || i>ListLength(L))
	{
		cout << "位置错误！" << endl;
		return ERROR;
	}
	stu* p = L, * s;
	int j = 0;
	while (p->next != NULL)
	{
		if (i == j + 1)
		{
			s = p->next;
			e = s->d;
			p->next = p->next->next;
			delete s;
			return OK;
		}
		j++;
		p = p->next;
	}
	return ERROR;
}
bool visit(data0 e)
{
	cout << "名字: " << e.name
		<< "  学号: " << e.age
		<< "  性别: " << (e.sex ? "男" : "女")
		<< "  年龄: " << e.year
		<< "  班级: " << e.ban
		<< "  健康状况: " << e.jk << endl;
	return 1;
}
Status ListTraverse(list L, bool(*visit)(data0 e))
{
	if (!L)
	{
		cout << "请先创建线性表！" << endl;
		return ERROR;
	}
	stu* p = L->next;
	bool u;
	while (p != NULL)
	{
		u=(*visit)(p->d);
		if (!u)return ERROR;
		p = p->next;
	}
	return OK;
}
void jiemian()
{
	cout << "0.退出程序" << endl;
	cout << "1.创建线性表" << endl;
	cout << "2.添加线性表" << endl;
	cout << "3.销毁线性表" << endl;
	cout << "4.清空线性表" << endl;
	cout << "5.判断线性表是否为空" << endl;
	cout << "6.求线性表长度" << endl;
	cout << "7.获取元素" << endl;
	cout << "8.查找元素" << endl;
	cout << "9.获取前驱元素" << endl;
	cout << "10.获取后继元素" << endl;
	cout << "11.插入元素" << endl;
	cout << "12.删除元素" << endl;
	cout << "13.遍历输出线性表" << endl;
}

int main()
{
	int n, m;
	list head = NULL;
	data0 d;
	while (1)
	{
		system("cls");
		jiemian();
		cin >> n;
		switch (n)
		{
		case 0:
			cout << "是否确定退出程序？将丢失所有内容！  0 - 取消 ，1 - 确定" << endl;
			cin >> m;
			if (m)
			{
				DestroyList(head);
				cout << "已退出！" << endl;
				system("pause");
				return 0;
			}
			cout << "已取消！" << endl;
			break;
		case 1:
			InitLIst(head);
			break;
		case 2:
			cout << "请输入添加个数:" << endl;
			cin >> m;
			listInsert(head, m);
			break;
		case 3:
			cout << "是否确定销毁线性表:   0 - 取消 ，1 - 确定" << endl;
			cin >> m;
			if(m)DestroyList(head);
			cout << "已取消！" << endl;
			break;
		case 4:
			cout << "是否确定清空线性表:   0 - 取消 ，1 - 确定" << endl;
			cin >> m;
			if (m)ClearList(head);
			cout << "已取消！" << endl;
			break;
		case 5:
			m = ListEmpty(head);
			cout << (m ? "是" : "否") << endl;
			break;
		case 6:
			m = ListLength(head);
			if (m) cout << "长度为: " << m << endl;
			else cout << "error" << endl;
			break;
		case 7:
			cout << "请输入要获取的元素位置: " << endl;
			cin >> m;
			Getlem(head, m, d);
			visit(d);
			break;
		case 8:
			cout << "请输入要查找的元素: " << endl;
			sr(d);
			m = LocateElem(head, d, *compare);
			if (m) cout << "位置为: " << m << endl;
			else cout << "未找到" << endl;
			break;
		case 9:
			cout << "请输入要获取前驱元素的元素: " << endl;
			sr(d);
			m = PriorElem(head, d, d);
			if (m)
			{
				cout << "前驱元素为: " << endl;
				visit(d);
			}
			else cout << "error" << endl;
			break;
		case 10:
			cout << "请输入要获取后继元素的元素: " << endl;
			sr(d);
			m = NextElem(head, d, d);
			if (m)
			{
				cout << "后继元素为: " << endl;
				visit(d);
			}
			else cout << "error" << endl;
			break;
		case 11:
			cout << "请输入要插入的位置: " << endl;
			cin >> m;
			cout << "请输入要插入的元素: " << endl;
			sr(d);
			ListInsrrt(head, m, d);
			break;
		case 12:
			cout << "请输入要删除的位置: " << endl;
			cin >> m;
			m = ListDelete(head, m, d);
			if (m)
			{
				cout << "已删除: " << endl;
				visit(d);
			}
			else cout << "error" << endl;
			break;
		case 13:
			cout << "线性表为: " << endl;
			ListTraverse(head, *visit);
			break;
		default:;
		}
		cout << "\n\n\n";
		system("pause");
	}

	return 0;
}
