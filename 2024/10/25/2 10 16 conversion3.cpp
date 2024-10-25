#include <iostream>
#include <string>
#include<cmath>
using namespace std;
int main()
{
	int x, y;
	string Cc;
	long long C, T;
	cout << "欢迎使用进制转换计算机，我可以为你将一个数在2进制、10进制、16进制，之间转换！" << endl;
start:
	cout << "输入进制时，请输入 2 10 或 16 （输入 0 结束计算程序）。" << endl;
	cout << "请选择输入的进制：" << endl;
	cin >> x;

	if (x == 2)
	{
		int _2to10(string Ci);
		cout << "请输入要转换的数：" << endl;
		cin >> Cc;
		T = _2to10(Cc);
	}
	   else if (x == 16)
	   {
		   int _16to10(string Ci);
		   cout << "请输入一个十六进制数(字母大写,且数字末尾加‘*’)。" << endl;
		   cin >> Cc;
		   T = _16to10(Cc);
	   }
	      else if (x == 10)
	      {
		      cout << "请输入要转换的数：" << endl;
		      cin >> C;
		      T = C;
	      }
	         else if (x == 0) { goto end; }
	            else { goto start; }

	for (int i = 0; 1; i++)
	{
		if (i == 0)cout << "请选择输出的进制：" << endl;
		   else cout << "请选择再次输出的进制：          （或输入 0 结束计算程序，输入 1 重启计算程序）" << endl;
		cin >> y;

		if (y == 2)
		{
			string _10to2(long long Ci);
			string F = _10to2(T);

			if (x == 10) { cout << endl << C << " 的二进制 = " << F << endl; }
			   else { cout << endl << Cc << " 的二进制 = " << F << endl; }
		}
		   else if (y == 16)
		   {
			   string _10to16(long long Ci);
			   string F = _10to16(T);

			   if ( x == 10) { cout << endl << C << " 的十六进制 = " << F << endl; }
			      else { cout << endl << Cc << " 的十六进制 = " << F << endl; }
		   }
		      else if ( y == 10)
		      {
			      int F = T;
			      if ( x == 10) { cout << endl << C << " 的十进制 = " << F << endl; }
			         else { cout << endl << Cc << " 的十进制 = " << F << endl; }
		      }
		         else if (y == 0) { goto end; }
		            else if (y == 1) { goto start; }
		               else
		               {
			               cout << "请输入正确的进制数！" << endl;
			               continue;
		               }
		cout << endl;
	}

end:
	cout << endl << "计算完毕，谢谢使用！" << endl;

	return 0;
}



int _2to10(string Ci)
{

	long long  T = 0;
	char b;
	int  i = 0;
	int n = Ci.size();
	while (1)
	{
		b = Ci[i];
		if (i == n)break;
		T += (int)(b - 48) * pow(2, i);
		i++;
	}

	return(T);
}

int _16to10(string Ci)
{

	char ch;
	long long  T = 0;
	int i = 0, j = 0;
	for (i;; i++)
	{
		ch = Ci[i];
		if (ch == '*')break;
	}
	for (i = i - 1; i >= 0; i--)
	{
		ch = Ci[i];

		if (ch >= 48 && ch <= 57) { T += (ch - 48) * pow(16, j); }
		   else { T += (int)(ch - 64 + 9) * pow(16, j); }
		j++;
	}

	return(T);
}

string _10to2(long long Ci)
{
	string F;
	int b, i = 0;
	int arr[40];
	for (i;; i++)
	{
		b = Ci % 2;
		Ci /= 2;
		arr[i] = b;

		if (Ci == 0)break;
	}
	for (; i >= 0; i--)
	{
		if (arr[i] <= 9) { F = F + (char)(arr[i] + 48); }
	}

	return(F);
}

string _10to16(long long Ci)
{
	int b, i = 0;
	int arr[20];
	string F;
	for (;; i++)
	{
		b = Ci % 16;
		Ci /= 16;
		if (b <= 9) { arr[i] = b; }
		   else { arr[i] = (b - 9 + 64); }
		if (Ci == 0)break;
	}
	for (; i >= 0; i--)
	{
		if (arr[i] <= 9) { F = F + (char)(arr[i] + 48); }
		   else { F = F + (char)arr[i]; }
	}

	return(F);
}
