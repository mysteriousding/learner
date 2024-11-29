#include<iostream>
using namespace std;

class tool
{
public:
	/*tool()
	{
		height = 10;							 
		width = 10;								 
		length = 10;							 
		for (int i = 0; i < 26; i++)			 
			n[i] = 'a' + i;						 
	}*/											 

	//tool(int a, int b, int c, const char d[]) :height(a), width(b), length(c) { strcpy_s(n, d); }       //必须 const char ！！！
	//tool(int , int , int ) :height(), width(), length() {}    // 错误。0，0，0；

	/*tool()
	{
		height = 10;
		width = 10;
		length = 10;
		for (int i = 0; i < 26; i++)
			n[i] = 'a' + i;
	}
	tool(int a) :height(a), width(12121), length(110) {}
	tool(int a, int b) :height(a), width(b), length(110) {}
	tool(int a, int b, int c) :height(a), width(b), length(c) {}
	tool(int a, int b, int c, const char d[]) :height(a), width(b), length(c) { strcpy_s(n, d); }*/

	//tool(int a, int b = 16, int c = 17,const char n[]="asdhghasgy") :height(a), width(b), length(c) {}     //这样不可以！！上下字符串都无法输入，是乱码
	tool(int a, int b = 16, int c = 17, const char d[] = "asdhghasgy") :height(a), width(b), length(c) { strcpy_s(n, d); }

	~tool() { cout << "Destructor called." << endl; }
	//同一个类的对象的析构函数若同时调用，先调用构造函数的后调用析构函数

	void SC();
	void XG();
private:
	int height;
	int width;
	int length;
	char n[50];
};

int main()
{
	tool t1(23, 45, 2765,"wertyui");
	t1.SC();
	t1.XG(); 
	t1.SC(); 
	system("pause");

	return 0;
}

void tool::SC()
{
	cout << height << endl;
	cout << width << endl;
	cout << length << endl;
	cout << n << endl;
}

void tool::XG()
{
	cin >> height;
	cin >> width;
	cin >> length;
	cin >> n;
}

/*武鑫鑫代码
#include<iostream>
using namespace std;
class preson
{
public:
    //1.构造函数
    preson()
    {
        cout << "preson构造函数的调用" << endl;
    }
    //2.析构函数
    ~preson()
    {
        cout << "~preson的函数调用" << endl;
    }
};

void test01()
{
    preson p;
}
int main()
{
    test01();
    preson p;
    system("pause");

    return 0;
}
*/