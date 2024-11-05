#include<iostream>
#include<string>
using namespace std;
string NJJ(int x, int y,int z);
int main()
{
	int n, j, J;
	cout << "你还记得那个日子?输一下？\n";
	cout << "年? :";
	cin >> n;
	cout << "月? :";
	cin >> j;
	cout << "日? :";
	cin >> J;

	cout << NJJ(n, j, J) << endl;

	return 0;
}

string NJJ(int x, int y,int z)
{
	string njj;
	if (x != 2023 || y != 9 || z != 25)
		njj = "无法用语言言语的遗憾啊！";
	else
		njj = "那些美好你还没忘记吗？\n你还没有释怀吗？\n你还承认他们吗？\n\n我永远永远记得，无穷无尽的美好啊！！\n\n谢谢你还记得，谢谢你从不否认!";

	return njj;
}
