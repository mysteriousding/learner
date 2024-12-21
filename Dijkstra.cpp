#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
struct lj
{
	bool live;
	int jd;
	int jl;
	int sm;
	lj(int sum)
	{
		live = 1;
		jd = sum;
		jl = 3e4;
	}
};
int tu[6][6] =
{
	{ 0, 2, 8, 0, 0, 0},
	{-1, 0, 5, 6, 0, 0},
	{-1,-1, 0, 3, 2, 0},
	{ 0,-1,-1, 0, 1, 9},
	{ 0, 0,-1,-1, 0, 3},
	{ 0, 0, 0,-1,-1, 0}
};
string name[6] = { "v1","v2", "v3", "v4", "v5", "v6", };
int main()
{
	lj* arr[6];
	for (int i = 0; i < 6; i++)
		arr[i] = new lj(i);
	arr[0]->jl = 0;
	arr[0]->sm = -1;
	int k, min;
	for (int i = 0; i < 6; i++)
	{
		min = 3e4+1;
		for(int j=0;j<6;j++)
			if(arr[j]->live)
				if(arr[j]->jl<min)
				{min = arr[j]->jl; k = j;}
		for (int j = 0; j < 6; j++)
			if (tu[i][j] > 0)
				if (arr[i]->jl + tu[i][j]< arr[j]->jl)
				{
					arr[j]->jl = arr[i]->jl + tu[i][j];
					arr[j]->sm = i;
				}
		arr[i]->live = 0;
	}
	string text;
	for (int j = 1; j < 6; j++)
	{
		/*k = j;
		while (k != -1)
		{
			if (k != 0)text = "->" + text;
			text = name[arr[k]->jd] + text;
			k = arr[k]->sm;
		}*/
		text = "";
		k = j;
		while (1)
		{
			text = name[arr[k]->jd] + text;
			if (k != 0)text = "->" + text;
			else break;
			k = arr[k]->sm;
		}
		cout << setiosflags(ios::left);
		cout << "最短距离:" << setw(6) << arr[j]->jl << "最短路径:" << text << endl;
	}
	for (int i = 0; i < 6; i++)
		delete arr[i];

	return 0;
}