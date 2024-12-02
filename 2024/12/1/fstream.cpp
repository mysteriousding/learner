#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	string k;
	cin >> k;   //直接输入 ，如“ABC.txt” 
	ofstream XY(k/*"xiangyu.txt"*//*,ios::app*/);       //有 xiangyu.txt 就修改，没有就新建           //有 ios::app 是添加，没有是覆盖      //不只是 .txt 可以创建,如： .exe, .jpg
	if (XY.is_open())
		XY << "你好啊！"<< endl;
	else
	{
		cerr << "错误！" << endl;
		return 1;
	}
	XY.close();

	string ai = "\0";
	ifstream LB("xiangyu.txt");
	if (LB.is_open())
		LB >> ai;
	else
	{
		cerr << "遗憾！" << endl;
		return 1;
	}
	LB.close();
	cout << ai << endl;


	/*ifstream LB("fstream.cpp");

	if (LB.is_open())
		while (getline(LB, ai))
			cout << ai << endl;
	else
	{
		cerr << "Error!" << endl;
		return 1;
	}
	LB.close();*/

	return 0;
}
