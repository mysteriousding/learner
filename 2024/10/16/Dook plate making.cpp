#include<iostream>
using namespace std;
int main()
{
	int a, b, n = 0, m, i = 1, i0;
	cout << "要为一条街的住户制作门牌号。\n这条街一共有X位住户，门牌号从1到X编号.\n制作门牌的方法是先制作0到9这几个数字字符，最后根据需要将字符粘贴到门牌上.\n例如门牌1017需要依次粘贴字符1、0、1、7，即需要1个字符0，2个字符1，1个字符7。\n请问要制作所有的1到X号门牌，总共需要多少个字符2？" << endl;
	cout << "请输入X为你计算" << endl;
	cin >> m;
	while(i<=m)
	{
		i0 = i;
		while (true)
		{
			b = i % 10;
			i /= 10;
			if (b == 2)
			{
				n += 1;
			}
			if (i == 0)
			{
				break;
			}
		}
		i = i0;
		i++;
	}
	cout << "X=" << n << endl;
	cout << "计算完毕，谢谢使用！" << endl;

	return 0;
}
