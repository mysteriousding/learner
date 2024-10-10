#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	int a, b, c, x, i;
	cout << "欢迎试玩猜数字，让我们尽快开始吧！" << endl;
	cout << "请输入1-10000的一个数" << endl;
	srand(time(0));
	a = rand() % 10000 + 1;
	b = 1;
	c = 10000;
	i = 1;

	while (true)
	{
		cin >> x;
		if (x == a) { break; }
		   else if (x > a)
		   {
			   cout << "请输入" << b << "-" << x << "的一个数" << endl;
			   c = x;
		   }
		      else
		      {
			      cout << "请输入" << x << "-" << c << "的一个数" << endl;
			      b = x;
		      }

		i++;
	}

	cout << "恭喜你猜对啦！！" << endl << "就是数字" << a << endl;
	cout << "你只用了" << i << "次，就猜到了数字，不愧是你！" << endl;
	cout << "再来一次吧！期待你更厉害！" << endl;

	return 0;
}