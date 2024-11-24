#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct TONGXUNLU
{
	string MINGZHI;
	int XINGBIE;
	int NIANLING;
	long long DIANHUA;
	string JIATINGDIZHI;
	TONGXUNLU* next = NULL;
};

void ZHUJIEMIAN();
bool TUICHU(TONGXUNLU*& head);
void TIANJIA(TONGXUNLU*& head);
void XIANSHI(TONGXUNLU* head);
void CHAZHAO(TONGXUNLU* head);
void XIUGAI(TONGXUNLU* head);
void SHANCHU(TONGXUNLU*& head);
void QINGKONG(TONGXUNLU*& head);


int main()
{
	int k;
	TONGXUNLU* head = NULL;
	cout << "欢迎使用通讯录APP! \n制作者:DSQ \n运行通过!开机成功！\n" << endl;
	
	while (1)
	{
		system("pause");
		system("cls");
		ZHUJIEMIAN();
		cin >> k;
		switch (k)
		{
		case 0:
			if(TUICHU(head))
			goto end;
			break;
		case 1:
			TIANJIA(head);
			break;
		case 2:
			XIANSHI(head);
			break;
		case 3:
			CHAZHAO(head);
			break;
		case 4:
			XIUGAI(head);
			break;
		case 5:
			SHANCHU(head);
			break;
		case 6:
			QINGKONG(head);
			break;
		}
	}
end:
	cout << "已成功退出！欢迎下次使用！" << endl << endl;
	system("pause");

	return 0;
}


void ZHUJIEMIAN()
{
	cout << "**********************" << endl;
	cout << "*****" << "1.添加联系人" << "*****" << endl;
	cout << "*****" << "2.显示联系人" << "*****" << endl;
	cout << "*****" << "3.查找联系人" << "*****" << endl;
	cout << "*****" << "4.修改联系人" << "*****" << endl;
	cout << "*****" << "5.删除联系人" << "*****" << endl;
	cout << "*****" << "6.清空联系人" << "*****" << endl;
	cout << "*****" << "0.退出通讯录" << "*****" << endl;
	cout << "**********************" << endl;
}

bool TUICHU(TONGXUNLU*& head)
{
	TONGXUNLU* p = head, * p0 = NULL;
	int m;
	cout << "是否确认要退出通讯录！？\n1 -- 取消, 0 -- 清空！" << endl;

	cin >> m;
	if (m != 0) { cout << "\n已取消！\n" << endl; return 0; }
	else 
	if (head != NULL)
	{
		while (p != NULL)
		{
			p0 = p->next;
			delete p0;
			p = p0;
		}
		head = NULL;

		return 1;
	}
}

void TIANJIA(TONGXUNLU*& head)
{
	TONGXUNLU* p = head, * p0 = NULL;
	TONGXUNLU* node = new TONGXUNLU;
	cout << "新建联系人(将按照首字母顺序添加):\n" << endl;
	cout << "请输入 姓名 :" << endl;
	cin >> node->MINGZHI;
	cout << "请输入 性别 :" << endl;
	cout << "0 -- 男 \n1 -- 女 " << endl;
	cin >> node->XINGBIE;
	cout << "请输入 年龄 :" << endl;
	cin >> node->NIANLING;
	cout << "请输入 联系电话 :" << endl;
	cin >> node->DIANHUA;
	cout << "请输入 家庭地址 :" << endl;
	cin >> node->JIATINGDIZHI;

	if (p == NULL)                                         //空处理  
	{ 
		head = node;
		goto OK;
	}
	if ((node->MINGZHI).compare(p->MINGZHI) < 0)           //头处理   
	{
		p0 = head;
		head = node;
		node->next = p0;
		goto OK;
	}
	while (p->next != NULL)
	{
		if ((node->MINGZHI).compare(p->next->MINGZHI) < 0) //普通操作 
		{
			p0 = p->next;
			p->next = node;
			node->next = p0;
			goto OK;
		}
		p = p->next;
	}
	p->next = node;                                        //尾处理 
OK:
	cout << "\n\n添加成功！" << endl;
}

void XIANSHI(TONGXUNLU* head)
{
	TONGXUNLU* p = head;
	int i = 1;
	cout << "所有联系人:" << endl;
	while (p != NULL)
	{
		cout << setiosflags(ios::left) << endl;
		cout << "联系人" << i << " :\n"
			<< setw(10) << p->MINGZHI
			<< setw(4) << ((p->XINGBIE == 0) ? "男" : "女")
			<< setw(4) << p->NIANLING
			<< setw(14) << p->DIANHUA
			<< p->JIATINGDIZHI << endl;

		p = p->next;
		i++;
	}
	cout << endl;
	if (i == 1)cout << "-----暂无联系人-----" << endl << endl;
}

void CHAZHAO(TONGXUNLU* head)
{
	TONGXUNLU* p = head;
	string n;
	int m = 0;
	cout << "请输入你要查找联系人的名字:" << endl;
	cin >> n;

	while (p != NULL)
	{
		if (p->MINGZHI == n)
		{
			cout << setw(10) << p->MINGZHI
				<< setw(4) << ((p->XINGBIE == 0) ? "男" : "女")
				<< setw(4) << p->NIANLING
				<< setw(14) << p->DIANHUA
				<< p->JIATINGDIZHI << endl;

			m = 1;
		}
		p = p->next;
	}
	if (m == 0)cout << "未找到该联系人！" << endl;
	cout << endl;
}

void XIUGAI(TONGXUNLU* head)
{
	TONGXUNLU* p = head;
	string n;
	int m;
	cout << "请输入你要修改联系人的名字:" << endl;
	cin >> n;
	while (p != NULL)if (p->MINGZHI == n)break;

	if(p == NULL)cout << "未找到该联系人！" << endl;
	else
		while (1)
		{
			cout << "\n请输入你要修改的项 \n1 -- 姓名, 2 -- 性别，3 -- 年龄，4 -- 联系电话，5 -- 家庭地址,0 -- 修改完成（确定）。" << endl;
			cin >> m;
			if (m == 0) { cout << "修改成功！" << endl; break; }
			switch (m)
			{
			case 1:
				cout << "请修改姓名 :" << endl;
				cin >> p->MINGZHI;
				break;
			case 2:
				cout << "请修改性别 :" << endl;
				cin >> p->XINGBIE;
				break;
			case 3:
				cout << "请修改年龄 :" << endl;
				cin >> p->NIANLING;
				break;
			case 4:
				cout << "请修改联系电话 :" << endl;
				cin >> p->DIANHUA;
				break;
			case 5:
				cout << "请修改家庭地址 :" << endl;
				cin >> p->JIATINGDIZHI;
				break;
			}
		}
	cout << endl;
}

void SHANCHU(TONGXUNLU*& head)
{
	TONGXUNLU* p = head, * p0 = NULL;
	string n;
	int m = 0;
	cout << "请输入你要删除联系人的名字:" << endl;
	cin >> n;
	if (head != NULL)
	{
		if (p->MINGZHI == n)
		{
			head = p->next;
			delete p;
			goto ok;
		}
		while (p->next != NULL)
		{
			if (p->next->MINGZHI == n)
			{
				p0 = p->next;
				p->next = p->next->next;
				delete p0;
				goto ok;

			}
			p = p->next;
		}
	}
	cout << "未找到该联系人！\n" << endl;
	return;
ok:
	cout << "\n删除成功！" << endl;
}

void QINGKONG(TONGXUNLU*& head)
{
	TONGXUNLU* p = head, * p0 = NULL;
	int m;
	cout << "是否确认要清空通讯录！？\n1 -- 取消, 0 -- 清空！" << endl;

	cin >> m;
	if (m != 0) { cout << "\n已取消！\n" << endl; return; }
	else
	{
		if (head != NULL)
		{
			while (p != NULL)
			{
				p0 = p->next;
				delete p0;
				p = p0;
			}
			head = NULL;
		}
		cout << "\n联系人已清空！\n" << endl;
	}
}