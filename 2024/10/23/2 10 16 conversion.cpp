#include <iostream>
#include <string>
#include<cmath>
using namespace std;
int main()
{
	int x, y;
	cout << "欢迎使用进制转换计算机，我可以为你将一个数在2进制、10进制、16进制，之间转换！" << endl;
	cout << "请选择输入的进制：" << endl;
	cin >> x;
	cout << "请选择输出的进制：" << endl;
	cin >> y;

	if (x == 10)
	{
		if (y == 2)
		{
			long long a, b, c, i = 0;
			cout << "请输入要转换的数" << endl;
			cin >> a;
			c = a;
			int arr[10];
			for (i;; i++)
			{
				b = a % 2;
				a /= 2;
				arr[i] = b;

				if (a == 0)break;
			}
			a = c;
			cout << endl << a << " 的二进制 = ";
			for (; i >= 0; i--)
			{
				cout << arr[i];
			}
			cout << endl;
		}
		   else if (y == 16)
		   {
			   long long  a, b, c, i = 0;
			   int arr[20];
			   cout << "请输入要转换的数" << endl;
			   cin >> a;
			   c = a;
			   for (;; i++)
			   {
			  	   b = a % 16;
				   a /= 16;
				   if (b <= 9) { arr[i] = b; }
				      else { arr[i] = (b - 9 + 64); }
				   if (a == 0)break;
			   }
			    a = c;
			   cout << endl << a << " 的十六进制 = ";
			   for (; i >= 0; i--)
			   {
				   if (arr[i] <= 9) { cout << arr[i]; }
				      else{cout << (char)arr[i];}
			   }
			   cout << endl;
		   }
		      else { cout << "请输入 2 或 10 ！" << endl; }
	}
	   else if (x == 2 || x == 16)
	   {
		   if (x == 2)
		   {
			   long long a, b, c = 0, i = 0, a0;
			   cout << "请输入要转换的数" << endl;
			   cin >> a;
			   a0 = a;
			   while (1)
			   {
				   b = a % 10;
				   a /= 10;
				   c += b * pow(2, i);
				   if (a == 0)break;
				   i++;
			   }

			   a = a0;
			   if (y == 10) { cout << endl << a << " 的十进制 = " << c << endl; }
			      else if (y == 16)
			      {
				      long long h, k = 0;
				      int arr[20];
				      cout << "请输入要转换的数" << endl;
				      for (k;; k++)
				      {
					     h = c % 16;
					     c /= 16;
					      if (h <= 9) { arr[k] = h; }
					         else { arr[k] = (h - 9 + 64); }
					      if (c == 0)break;
				      }
				      a = a0;
				      cout << endl << a << " 的十六进制 = ";
				      for (; k >= 0; k--)
				      {
					      if (arr[k] <= 9) { cout << arr[k]; }
					         else { cout << (char)arr[k]; }
				      }
				      cout << endl;
			      }
				     else { cout << "请输入 10 或 16 ！" << endl; }
		   }
		      else 
		      {
			      string num16, num;
			      char a;
			      long long  b = 0, i = 0, j = 0;
			      cout << "请输入一个十六进制数(字母大写,且数字末尾加‘*’)，让我为你将他转化。" << endl;
			      cin >> num16;
			      num = num16;
			      for (i;; i++)
			      {
				      a = num16[i];
				      if (a == '*')break;
			      }
			      for (i = i - 1; i >= 0; i--)
			      {
				      a = num16[i];

				      if (a >= 48 && a <= 57) { b += (a - 48) * pow(16, j); }
				         else { b += (int)(a - 64 + 9) * pow(16, j); }
				      j++;
			      }

			      num16 = num;
				  if (y == 10) { cout << endl << num16 << " 的十进制 = " << b << endl; }
				     else if (y == 2)
				     {
					     long long  h, k = 0;
					     cout << "请输入要转换的数" << endl;
					     int arr[10];
					     for (k;; k++)
					     {
						     h = b % 2;
						     b /= 2;
						     arr[k] = h;

						     if (b == 0)break;
					     }
					     num16 = num;
					     cout << endl << num16 << " 的二进制 = ";
					     for (; k >= 0; k--)
					     {
						    cout << arr[k];
					     }
					     cout << endl;
				     }
					    else { cout << "请输入 2 或 10 ！" << endl; }
		      }
		  


	   }
	      
	      else{ cout << "请输入 2 10 或 16 ！" << endl; }

    cout << endl << "计算完毕，谢谢使用！" << endl;

    return 0;
}
