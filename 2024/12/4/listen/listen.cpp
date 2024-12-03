#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;
string DQ(string& name);
void JieM(string& JH, string miyao);
void XR(string& names, string& text);

int main()
{
	string name, names, miyao, t; 
	srand(static_cast<unsigned int>(time(nullptr)));
	cout << "请输入要解密的文件名: " << endl;
	cin >> name;
	t = DQ(name);       //取  
	cout << "请输入解密密钥: " << endl;
	cin >> miyao; 
	JieM(t, miyao);     //密 
	cout << "请输入新建文件名以保存解密结果: " << endl;
	cin >> names;
	XR(names, t);       //填 

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

void JieM(string& JH,string miyao)
{
	for (int i = 0; i < 26; i++)
	{
		int j = 0;
		while (JH[j] != '\0')
		{
			if (JH[j] == miyao[i])JH[j] = char('a' + i); 
			else if (JH[j] == '*' && JH[j + 1] != '\0')
				if (i == 25)JH.erase(j, 1);
				else j++; 
			j++;
		}
	}
}

void XR(string& names, string& text)
{
	ofstream jieguo(names);
	if (!jieguo.is_open())
		cerr << names << "文件打开失败！" << endl;
	else jieguo << text << endl;
	jieguo.close();
}
