#include<iostream>
using namespace std;
int main()
{
	void sort(int x, int y, int z);
	int x, y, z;
	cin >> x >> y >> z;
	sort(x, y, z);

	return 0;
}
void sort(int x, int y, int z)
{
	int temp;
	if (x > y) { temp = x; x = y, y = temp; }     //{}内3条语句作用是将x和y的值互换
	if (z < x)cout << "中位数为；" << x << endl;
	   else if (z < y)cout << "中位数为；" << z << endl;
	        else cout << "中位数为；" << y << endl;
}