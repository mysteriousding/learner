/*
有趣的平方数 
625 这个数字很特别，625 的平方等于 390625，刚好其末 3 位是 625 本身。除了 625，
还有其它的 3 位数有这个特征吗？还有一个！该数是：_____________
【参考答案】
376
*/
#include<iostream>
using namespace std;
int main()
{
	for (int i = 100; i < 1000; i++)
		if (i * i % 1000 == i)
			cout << i << endl;

	return 0;
}
