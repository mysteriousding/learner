/*
3．散列表的应用（可根据实际情况进行调整）选择合适散列函数和冲突处理方法，编程实现QQ账户的申请与登录。
*/
#include<iostream>
#include<string>
using namespace std;
#define N 1000

typedef struct
{
	int n;
	string m;
	string name;
}ys;

class slb
{
public:
	slb();

	bool dl();

private:
	ys a[N];
	int zs;

	int hx(int x);
	void ql();
	int cz(int x);
	bool zc();
	bool zx(int x);
	bool xg(int x);
	bool xg_new(int x,string y, string z);
};

slb::slb()
{
	for (int i = 0; i < N; i++)
		a[i].n = -1;

	bool u;
	for (int i = N; i > 1; i--)
	{
		u = 1;
		if ((i % 2 == 0 && i > 2) || (i % 3 == 0 && i > 3))u = 0;
		if (u)
			for (int j = 5; j * j <= i; j += 2)
				if (i % j == 0)
				{
					u = 0;
					break;
				}
		if (u)
		{
			zs = i;
			break;
		}
	}
}

int slb::hx(int x)
{
	return x % zs;
}

void slb::ql()
{
	cin.clear();
	cin.ignore();
}

int slb::cz(int x)
{
	int y0 = hx(x),y=y0;
	for (int i = 0; a[y].n != x && a[y].n != -1; i++)
		y = (y0 + N + (i * i) % N * (i % 2 ? 1 : -1)) % N;
	return y;
}

bool slb::zc()
{
	int x,x0;
	string y;
	bool z = 1;
	cout << "QQ注册:" << endl;
	cout << "请输入账号( 3 - 9 位数字):" << endl;
	getline(cin, y, '\n');
	for(int i=0;i<y.size();i++)
		if (y[i] < 48 || y[i]>57)
		{
			z = 0;
			break;
		}
	if (z)
	{
		x0 = stoi(y);
		x = cz(x0);
		a[x].n = x0;
		cout << "请输入密码:" << endl;
		getline(cin, y, '\n');
		a[x].m = y;
		cout << "请输入昵称:" << endl;
		getline(cin, y, '\n');
		a[x].name = y;
		cout << "\n\n注册成功！" << endl;
	}
	else cout << "账号非法！" << endl;

	return z;
}

bool slb::zx(int x)
{
	bool y;
	cout << "是否注销账号？( 0 - 否 , 1 - 是 )" << endl;
	cin >> y;
	ql();
	if (y)
	{
		a[x].n = -1;
		cout << "\n\n注销成功！" << endl;
	}
	else cout << "\n\n注销失败！" << endl;

	return y;
}

bool slb::xg(int x)
{
	string y;
	int z;
	cout << "( 0 - 退出修改 , 1 - 修改账号 , 2 - 修改密码 , 3 - 修改昵称  )" << endl;
	cin >> z;
	ql();
	switch (z)
	{
	case 0:
		cout << "\n\n修改失败！" << endl;
		break;
	case 1:
		cout << "请输入新账号:" << endl;
		cin >> z;
		ql();
		a[x].n = -1;
		xg_new(z, a[x].m, a[x].name);
		cout << "\n\n修改成功！" << endl;
		break;
	case 2:
		cout << "请输入新密码:" << endl;
		getline(cin, y, '\n');
		a[x].m = y;
		cout << "\n\n修改成功！" << endl;
		break;
	case 3:
		cout << "请输入新昵称:" << endl;
		getline(cin, y, '\n');
		a[x].name = y;
		cout << "\n\n修改成功！" << endl;
		break;
	}

	return z;
}

bool slb::xg_new(int x, string y, string z)
{
	int x0 = cz(x);
	a[x0].n = x;
	a[x0].m = y;
	a[x0].name = z;

	return 1;
}

bool slb::dl()
{
	int x;
	string y;
	int z = 1;
	cout << "QQ登录:" << endl;
	cout << "请输入账号:" << endl;
	getline(cin, y, '\n');
	for (int i = 0; i < y.size(); i++)
		if (y[i] < 48 || y[i]>57)
		{
			z = 0;
			break;
		}
	if (z)
	{
		z = 0;
		x = stoi(y);
		x = cz(x);
		if (a[x].n != -1)
		{
			cout << "请输入密码:" << endl;
			getline(cin, y, '\n');
			if (a[x].m == y)
			{
				z = 1;
				cout << "\n\n登录成功！" << endl;
				cout << a[x].name << "，欢迎回家！\n\n" << endl;
			}
			else cout << "\n密码错误！" << endl;
		}
		else
		{
			cout << "账号不存在！是否注册账号？( 0 - 否 , 1 - 是 )" << endl;
			cin >> z;
			ql();
			if (z)zc();
			else 
				cout << "即将返回" << endl;

			system("pause");
			system("cls");

			return 0;
		}
	}
	else cout << "账号非法！" << endl;

	if (z)
	{
		cout << "操作:  ( 0 - 退出登录 , 1 - 修改账号信息 , 2 - 注销账号 )" << endl;
		cin >> z;
		ql();
		switch (z)
		{
		case 0:
			cout << "即将退出！" << endl;
			break;
		case 1:
			xg(x);
			break;
		case 2:
			zx(x);
			break;
		}
	}
	system("pause");
	system("cls");

	return z;
}

int main()
{
	int n = 25;
	slb a;
	while(n--)
		a.dl();

	return 0;
}
