#include <iostream>
#include <string>
#include<cmath>
using namespace std;
int main()
{
    string num16, num;
    char a;
    long long  b = 0, i = 0, j = 0;
    cout << "请输入一个十六进制数(字母大写,且数字末尾加‘*’)，让我为你将他转化为十进制。" << endl;
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
           else { b += (int)(a - 64+9) * pow(16, j); }
        j++;
    }
    
    num16 = num;
    cout << endl << num16 << " 的十进制 = " << b << endl;

    return 0;
}
