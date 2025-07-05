/*
谓词实例3(三元谓词)

题目描述
已知客体域A={3.46, 3.90, 4.63, 5.75, 5.83, 6.29, 7.21, 9.11, 9.37, 9.99}，谓词P(x, y, z)表示“x+y>z、x+z>y且y+z>x (x, y, z互不相同)”。
求使得该谓词取值为T的x, y, z取值。

输入描述
本题无输入。

输出描述
输出使得谓词P(x, y, z)取值为T的x, y, z取值，用空格隔开，保留小数点后面2位有效数字。
如果有多个取值组合符合要求，则每个取值组合占一行，且首先输出x取值最小的组合，对x取值相同的组合，则先输出y取值最小的组合，以此类推。

注意，互换两个或三个值，如“3.46 3.90 4.63”和“3.90 3.46 4.63”，视为同一个组合，不能重复输出。
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	float a[] = { 3.46, 3.90, 4.63, 5.75, 5.83, 6.29, 7.21, 9.11, 9.37, 9.99 };
	int n = 10;
	cout << setiosflags(ios::fixed) << setprecision(2);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)
				if (a[i] + a[j] > a[k] && a[i] + a[k] > a[j] && a[k] + a[j] > a[i])
					cout << a[i] << " " << a[j] << " " << a[k] << endl;

	return 0;
}