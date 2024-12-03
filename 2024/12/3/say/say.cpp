#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
//#include"Pinyin.hpp"
using namespace std;
string DQ(string& name);
string JiaM(string& JH);
void XR(string& names, string& text);

int main()
{
	string name, names, n, m;
	srand(static_cast<unsigned int>(time(nullptr)));
	cout << "请输入要加密的文件名: " << endl;
	cin >> name;
	n = DQ(name);  //取
	m = JiaM(n);     //密 
	cout << "请输入新建文件名以保存加密结果: " << endl;
	cin >> names;
	XR(names, n);  //填
	cout << "密钥为: " << m << endl;

	system("pause");

	return 0;
}

string DQ(string& name)
{
	string JH = "", line;
	ifstream yuanwen(name);
	if (!yuanwen.is_open())
	{
		cerr << name << "文件打开失败！" << endl;
		return "";
	}
	else
	{
		while (getline(yuanwen, line))
			JH += line + '\n';
		yuanwen.close();
		return JH;
	}
}

string JiaM(string& JH)
{
	string cs ="1234567890!@#$%^&+(){}:;<>" /*"abcdefghijklmnopqrstuvwxyz"*/, mm = "";
	for (int i = 0, j = 26; i < 26; i++, j--)
	{
		int k = rand() % (j);
		mm += cs[k];
		cs[k] = cs[j - 1];
	}

	for (long long i = 0; JH[i] != '\0'; i++)
		if (JH[i] >= 'a' && JH[i] <= 'z')JH[i] = mm[JH[i] - 'a'];
		else JH.insert(i++, "*");

	return mm;
}

void XR(string& names, string& text)
{
	ofstream jieguo(names);
	if (!jieguo.is_open())
		cerr << names << "文件打开失败！" << endl;
	else jieguo << text << endl;
	jieguo.close();
}
