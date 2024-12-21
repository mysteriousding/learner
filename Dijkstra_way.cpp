#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;
struct lj
{
	bool live;
	int jd;
	float jl;
	int sm;
	lj() :live(1), jl(3e4){}
};
int main()
{
	int n;
	cout << "请输入结点个: " << endl;
	cin >> n;
	vector<string>name(n);
	cout << "请输入所有结点:" << endl;
	for (int i = 0; i < n; i++)
		cin >> name[i];
	cout << endl;
	vector<vector<int>>tu(n, vector<int>(n,-1));
	for (int j = 0; j < n; j++)
		cout << j + 1 << " - " << name[j] << " , ";
	cout << "0 0 0 - " << "退出" << endl;
	cout << "请输入所有路线: (出结点 入结点 距离)" << endl << endl;
	
	/*for (int i = 0; i < n; i++)
	{
		cout << i + 1 << "的关联结点:" << endl;
		int k = 1;
		while (1)
		{
			int m, v;
			cout << "关联结点"<<k++<<":";
			cin >> m;
			if (m == 0)break;
			else
			{
				cout << "关联距离:"; 
				cin >> v; 
				tu[i][--m] = v;
			}
		}
		cout << endl;
	}*/

	int l = 0, x, y;
	float v;
	while (1)
	{
		cout << "路线" << ++l << ":";
		cin >> x >> y >> v;
		if (x == 0 || y == 0 || v == 0) { cout << endl; break; }
		else tu[--x][--y] = v;
	}
	vector<lj>arr(n);
	for (int j = 0; j < n; j++)
		arr[j].jd = j;
	arr[0].jl = 0;
	float k, min;
	for (int i = 0; i < n; i++)
	{
		min = 3e4 + 1;
		for (int j = 0; j < n; j++)
			if (arr[j].live)
				if (arr[j].jl < min)
				{min = arr[j].jl; k = j;}
		for (int j = 0; j < n; j++)
			if (tu[i][j] > 0)
				if (arr[i].jl + tu[i][j] < arr[j].jl)
				{
					arr[j].jl = arr[i].jl + tu[i][j];
					arr[j].sm = i;
				}
		arr[i].live = 0;
	}
	string text;
	for (int j = 1; j < n; j++)
	{
		text = "";
		k = j;
		while (1)
		{
			text = name[arr[k].jd] + text;
			if (k != 0)text = "->" + text;
			else break;
			k = arr[k].sm;
		}
		cout << setiosflags(ios::left);
		cout << "最短距离:" << setw(6) << arr[j].jl << "最短路径:" << text << endl;
	}
	
	return 0;
}