#include<iostream>
#include<string>
using namespace std;
/*字符串
int main()
{
	/*字符数组的输入和覆盖尝试
	char s[100];
	for (int i = 0; i < 5; i++)
	{
		cin >> s;
		cout << s << endl;
	}*


	//string s;
	char s[10];
	cin >> s;
	for (int i = 0; ; i++)
	{
		if(s[i]!='\0')
		cout << s[i] ;
		else { cout << "-----------------" << endl; break; }
	}

	return 0;
}
*/

/*指针疑问
int main()
{
	//a,q,a[i],*(q+i),*(a+i),q[i];
	//a+i可以,a++不行？有q[i]？
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int* p = a;       //如果 int* p = &a[3]; 其实都一样，只不过是从a[3]开头的数组罢了


	cout << a << endl;         //十六进制地址
	cout << p << endl;         //十六进制地址,与上面一模一样
	cout << "--------------------" << endl;

	cout << *a << endl;           //数字 0
	cout << *p << endl;           //数字 0
	
	//p = &a;                     //错误,不能将 "int (*)[10]" 类型的值分配到 "int *" 类型的实体
	                              //错误,无法从“int(*)[10]”转换为“int * ”
	//cout << *p << endl;
	cout << "--------------------" << endl;

	//cout << a++ << endl;      //错误
	cout << p++ << endl;        //正确，十六进制地址
	cout << *(p++) << endl;     //正确，数字 1,因为q++改变了p的值
	p = a;                      //重新初始化

	int i = 1;
	cout << a + i << endl;       //十六进制地址
	cout << p + i << endl;       //十六进制地址,与上面一模一样

	cout << *(a + i) << endl;       //数字 1 
	cout << *(p + i) << endl;       //数字 1
	cout << "--------------------" << endl;
	
	cout << a[i] << endl;      //数字 1 
	cout << p[i] << endl;      //数字 1 



	return 0;
}
*/



//多维数组的指针遍历
//        ---指针赋值时不一样
int main()
{
	//一维数组
	int a1[10];
	int i, * p = a1;
	for (i = 0; i < 10; i++)
		cin >> *(p + i);
	cout << endl;
	for (p = a1; p < (a1 + 10); p++)
		cout << *p << " ";
	cout << endl;

	//二维数组
	int a2[10][10];
	p = &a2[0][0];                                    //有区别，不能以数组名直接使 指针p 指向第一个元素，必须像普通变量一样赋值指针;
	for (i = 0; i < 100; i++)                         //有区别，全部元素个数;
		cin >> *(p + i);
	cout << endl;
	for (p = &a2[0][0]; p < (&a2[0][0] + 100); p++)   //有区别，不能直接使用数组名加减，要用普通变量地址表达方式
	{
		if ((p - &a2[0][0]) % 10 == 0)cout << endl;   //换行
		cout << *p << " ";
	}
	cout << endl;

	//三维数组
	int a3[10][10][10];
	p = &a3[0][0][0];                                        //有区别
	for (i = 0; i < 1000; i++)                               //有区别
		cin >> *(p + i);
	cout << endl;
	for (p = &a3[0][0][0]; p < (&a3[0][0][0] + 1000); p++)   //有区别
	{
		if ((p - &a3[0][0][0]) % 100 == 0)cout << endl;      //换行
		cout << *p << " ";
	}
	cout << endl;



	//另外方法
	//**p

	return 0;
}