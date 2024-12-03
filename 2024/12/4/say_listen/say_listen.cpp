#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;
string DQ(string& name);
string JiaM(string& JH);
void JieM(string& JH, string miyao); 
void XR(string& names, string& text);

int main()
{
	int p;
	string name, names, n, m;
	srand(static_cast<unsigned int>(time(nullptr)));
	cout << "请输入你要进行的操作: " << endl;
	cout << "0--加密,1--解密 " << endl;
	cin >> p;
	if (!p)
	{
		cout << "请输入要加密的文件名: " << endl;
		cin >> name;
		n = DQ(name);    //取
		m = JiaM(n);     //密 
		cout << "请输入新建文件名以保存加密结果: " << endl;
		cin >> names;
		XR(names, n);    //填
		cout << "密钥为: " << m << endl;
	}
	else
	{
		cout << "请输入要解密的文件名: " << endl;
		cin >> name;
		n = DQ(name);       //取
		cout << "请输入解密密钥: " << endl;
		cin >> m; 
		JieM(n, m);         //密
		cout << "请输入新建文件名以保存解密结果: " << endl;
		cin >> names;
		XR(names, n);       //填
	}

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
	string cs = "1234567890!@#$%^&+(){}:;<>", mm = "";
	for (int i = 0, j = 26; i < 26; i++, j--)
	{
		int k = rand() % (j);
		mm += cs[k];
		cs[k] = cs[j - 1];
	}

	for (long long i = 0; JH[i] != '\0'; i++)
		if (JH[i] >= 'a' && JH[i] <= 'z')JH[i] = mm[JH[i] - 'a'];
		else if (JH[i] >= 'A' && JH[i] <= 'Z') { JH.insert(i++, "/"); JH[i] = mm[JH[i] - 'A']; }
		else if (JH[i] != ' ')JH.insert(i++, "*");

	return mm;
}

void JieM(string& JH, string miyao)
{
	for (int i = 0; i <= 26; i++)
	{
		int j = 0;
		while (JH[j] != '\0')
		{
			if (JH[j] == miyao[i])JH[j] = char('a' + i);
			else if (JH[j] == '/' && JH[j + 1] != '\0'&&i == 26) { JH.erase(j, 1); JH[j] -= 32; }
			else if (JH[j] == '*' && JH[j + 1] != '\0')
				if (i == 26)JH.erase(j, 1);
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
