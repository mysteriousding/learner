#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
struct TXL
{
	string MZ;
	int XB;
	int NL;
	long long DH;
	string DZ;
};
int N[1000] = { 0 };
TXL* p[1000];

void SCD();
void TJ();
void XS();
void SC(int n);
void CZ(string m);
void XG(string m);
void QK();


int main()
{
	int J, n;
	string m;
	cout << "欢迎使用通讯录APP! \n制作者:DSQ \n运行通过!开机成功！\n" << endl;
	system("pause");
	system("cls");
	while (1)
	{
		SCD();
		cin >> J;
		if (J == 0)break;
		switch (J)
		{
		case 1:TJ(); break;

		case 2:XS(); break;

		case 3:cout << "请输入你要删除联系人的序号 :" << endl; cin >> n; SC(n); break;

		case 4:cout << "请输入你要查找联系人的名字 :" << endl; cin >> m; CZ(m); break;

		case 5:cout << "请输入你要修改联系人的名字 :" << endl; cin >> m; XG(m); break;

		case 6:QK(); break;

		default:cout << "请正确输入！" << endl; system("pause");
		}
		system("cls");
	}
	cout << "已成功退出！欢迎下次使用！" << endl << endl;
	system("pause");

	return 0;
}


void SCD()
{
	cout << "**********************" << endl;
	cout << "*****" << "1.添加联系人" << "*****" << endl;
	cout << "*****" << "2.显示联系人" << "*****" << endl;
	cout << "*****" << "3.删除联系人" << "*****" << endl;
	cout << "*****" << "4.查找联系人" << "*****" << endl;
	cout << "*****" << "5.修改联系人" << "*****" << endl;
	cout << "*****" << "6.清空联系人" << "*****" << endl;
	cout << "*****" << "0.退出通讯录" << "*****" << endl;
	cout << "**********************" << endl;
}

void TJ()
{
	int i = 0;
	while (N[i] != 0)i++;
	p[i] = new TXL;
	N[i] = 1;
	cout << "新建联系人:" << endl;
	cout << "请输入 姓名 :" << endl;
	cin >> p[i]->MZ;
	cout << "请输入 性别 :" << endl;
	cout << "0 -- 男 \n1 -- 女 " << endl;
	cin >> p[i]->XB;
	cout << "请输入 年龄 :" << endl;
	cin >> p[i]->NL;
	cout << "请输入 联系电话 :" << endl;
	cin >> p[i]->DH;
	cout << "请输入 家庭地址 :" << endl;
	cin >> p[i]->DZ;
	cout << "\n\n添加成功！" << endl;
	system("pause");
}

void XS()
{
	int i = 0;
	cout << "所有联系人:" << endl;
	while (N[i] != 0)
	{
		cout<<setiosflags(ios::left)<< endl;
		cout << "联系人" << i + 1 << " :\n" << setw(10) << p[i]->MZ << setw(4) << ((p[i]->XB == 0) ? "男" : "女") << setw(4) << p[i]->NL << setw(14) << p[i]->DH << p[i]->DZ << endl;
		i++;
	}
	if (i == 0)cout << "-----暂无联系人-----" << endl << endl;
	system("pause");
}

void SC(int n)
{
	if (n < 1 || N[n-1] == 0) { cout << "错误输入请重试！" << endl << endl; system("pause"); return; }
	int i = n-1;
	for (; N[i + 1] != 0; i++)*p[i] = *p[i + 1];
	delete  p[i];
	N[i] = 0;
	cout << "\n\n删除成功！" << endl;
	system("pause");
}

void CZ(string m)
{
	int i = 0,l,k=0;
	for (; N[i] != 0; i++)
	{
		l = 0;
		if (m == p[i]->MZ) { l = 1; k = 1; }
		if (l == 1)cout << "联系人 :\n" << setw(10) << p[i]->MZ << setw(4) << ((p[i]->XB == 0) ? "男" : "女") << setw(4) << p[i]->NL << setw(14) << p[i]->DH << p[i]->DZ << endl;
	}
	if (k == 0)cout << "\n查无此人！" << endl << endl;
	system("pause");
}

void XG(string m)
{
	int i = 0, l;
	for (; N[i] != 0; i++)
	{
		l = 0;
		if (m == p[i]->MZ) { l = 1; break; }
	}
	if (l == 0)cout << "\n查无此人！" << endl;
	else
	{
		cout << "请输入你要修改的项 \n1 -- 姓名, 2 -- 性别，3 -- 年龄，4 -- 联系电话，5 -- 家庭地址,0 -- 修改完成（确定）。" << endl;
		int n;
		while (1)
		{
			cout << "请输入选项 : ";
			cin >> n;
			if (n == 0)break;
			switch (n)
			{
			case 1:
				cout << "请修改 姓名 :\n"; cin >> p[i]->MZ; break;

			case 2:
				cout << "请修改 性别 :\n0 -- 男 \n1 -- 女\n"; cin >> p[i]->XB; break;

			case 3:
				cout << "请修改 年龄 :\n"; cin >> p[i]->NL; break;

			case 4:
				cout << "请修改 联系电话 :\n"; cin >> p[i]->DH; break;

			case 5:
				cout << "请修改 家庭地址 :\n"; cin >> p[i]->DZ; break;

			default:cout << "请正确输入！" << endl;
			}
			cout << endl;
		}
	}
	cout << "\n\n修改成功！" << endl;
	system("pause");
}

void QK()
{
	cout << "是否再次确定清除？\n 0 -- 取消\n 1 -- 确定\n" << endl;
	int i = 0, n;
	cin >> n;
	if (n != 1)return;
	while (N[i] != 0)
	{
		delete  p[i];
		N[i] = 0;
		i++;
	}
	cout << "\n\n已清空！" << endl;
	system("pause");
}
