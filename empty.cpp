#include<iostream>
using namespace std;
#define ai 9.25
int main()
{
	//cout << "hello world" << endl;

//����
	//���ͣ�
	/*int a1 = 10;
	short a2 = 11;
	long a3 = 12;
	long long a4 = 13;

	cout << a1 << endl;
	cout << a2<< endl;
	cout << a3 << endl;
	cout << a4 << endl;*/



    //������
	/*float b1 = 1.23456544;
	float b2 = 1.23456444f;
	double b3 = 1.23456544;
	double b4 = 1.23456444l;

	cout << b1 << endl;
	cout << b2 << endl;
	cout << b3 << endl;
	cout << b4 << endl;*/



	//�ַ���
	/*char c1, c2, c3;
	c1 = 'A';
	c2 = 'B';
	c3 = 'a';

	cout << c1 << endl;
	cout << c2 << endl;
	cout << c3 << endl << endl;

	cout << (int)c1 << endl;
	cout << (int)c2 << endl;
	cout << (int)c3 << endl << endl;

	c1 = c1 + 42;
	c2 = c2 + 32;
	c3 = c3 - 32;

	cout << c1 << endl;
	cout << c2 << endl;
	cout << c3 << endl;*/



	//�ַ�����
	/*//C���
	char d1[] = "dsq";

	//C++���
	string d2 = "njj";

	cout << d1 << endl;
	cout << d2 << endl;*/



	//������
	/*bool e1 = true;
	bool e2 = false;
	bool e3 = 1;
	bool e4 = 0;
	bool e5 = 2;
	bool e6 = 100;
	bool e7 = 020;
	bool e8 = 0x20;
	bool e9 = 43l;
	bool e10 = 2.13;
	bool e0 = 2e43;

	cout << e1 << endl << e2 << endl << e3 << endl << e4 << endl << e5 << endl << e6 << endl << e7 << endl << e8 << endl << e9 << endl << e10 << endl << e0 << endl;*/




//����
	/*const int f1 = 16;

	//f1 = 17;        ���������޸�
	//ai = 8.21;      ���������޸�

	cout << f1 << endl << ai << endl;*/




//�ڴ�ռ�
/*
	int a1 = 10;
	short a2 = 11;
	long a3 = 12;
	long long a4 = 13;

	float b1 = 1.23456;
	double b2 = 1.23456;

	char c1 = 'a';

	char d1[] = "dsq";
	string d2 = "njj";
	char d3[] = "asdfghjkl";
	string d4 = "zxcvbnmasdfghjklqwertyuiopzxcvbnmasdfghjklqwertyuiop";
	char d5[] = "zxcvbnmasdfghjklqwertyuiopzxcvbnmasdfghjklqwertyuiop";

	bool e1 = false;

	const int f1 = 10;
	const short f2 = 11;
	const long f3 = 12;
	const long long f4 = 13;

	ai;

	cout << "int��ռ�ڴ�ռ�Ϊ��" << sizeof(int) << endl;                 //4 
	cout << "short��ռ�ڴ�ռ�Ϊ��" << sizeof(short) << endl;             //2
	cout << "long��ռ�ڴ�ռ�Ϊ��" <<sizeof(long)  << endl;               //4
	cout << "long long��ռ�ڴ�ռ�Ϊ��" <<sizeof(long long)  << endl;     //8
	cout << "int��ռ�ڴ�ռ�Ϊ��" << sizeof(a1) << endl;                  //4
	cout << "short��ռ�ڴ�ռ�Ϊ��" << sizeof(a2) << endl;                //2
	cout << "long��ռ�ڴ�ռ�Ϊ��" << sizeof(a3) << endl;                 //4
	cout << "long long��ռ�ڴ�ռ�Ϊ��" << sizeof(a4) << endl << endl;    //8

	cout << "float��ռ�ڴ�ռ�Ϊ��" << sizeof(float) << endl;             //4
	cout << "double��ռ�ڴ�ռ�Ϊ��" << sizeof(double) << endl;           //8
	cout << "float��ռ�ڴ�ռ�Ϊ��" << sizeof(b1) << endl;                //4
	cout << "double��ռ�ڴ�ռ�Ϊ��" << sizeof(b2) << endl << endl;       //8

	cout << "char��ռ�ڴ�ռ�Ϊ��" << sizeof(char) << endl;               //1
	cout << "char��ռ�ڴ�ռ�Ϊ��" << sizeof(c1) << endl << endl;         //1

	//cout << "C����ַ�����ռ�ڴ�ռ�Ϊ��" << sizeof(char) << endl;
	cout << "C++����ַ�����ռ�ڴ�ռ�Ϊ��" << sizeof(string) << endl;    //40
	cout << "C����ַ�����ռ�ڴ�ռ�d1Ϊ��" << sizeof(d1) << endl;        //4
	cout << "C++����ַ�����ռ�ڴ�ռ�d2Ϊ��" << sizeof(d2) << endl;      //40
	cout << "C����ַ�����ռ�ڴ�ռ�d3Ϊ��" << sizeof(d3) << endl;        //10
	cout << "C++����ַ�����ռ�ڴ�ռ�d4Ϊ��" << sizeof(d4) << endl;      //40
	cout << "C����ַ�����ռ�ڴ�ռ�d5Ϊ��" << sizeof(d5) << endl;        //53
	cout << "d4=" << d4 << endl;                   //С��40λ��C���,����40λ��C++���
	cout << "d5=" << d5 << endl << endl;           

	cout << "bool��ռ�ڴ�ռ�Ϊ��" << sizeof(bool) << endl;               //1
	cout << "bool��ռ�ڴ�ռ�Ϊ��" << sizeof(e1) << endl << endl;         //1
	
	cout << "������ռ�ڴ�ռ�Ϊ��" << sizeof(const int) << endl;          //4
	cout << "������ռ�ڴ�ռ�Ϊ��" << sizeof(const short) << endl;        //2
	cout << "������ռ�ڴ�ռ�Ϊ��" << sizeof(const long) << endl;         //4
	cout << "������ռ�ڴ�ռ�Ϊ��" << sizeof(const long long) << endl;    //8
	cout << "������ռ�ڴ�ռ�Ϊ��" << sizeof(f1) << endl;                 //4
	cout << "������ռ�ڴ�ռ�Ϊ��" << sizeof(f2) << endl;                 //2
	cout << "������ռ�ڴ�ռ�Ϊ��" << sizeof(f3) << endl;                 //4
	cout << "������ռ�ڴ�ռ�Ϊ��" << sizeof(f4) << endl << endl;         //8

	cout << "�곣����ռ�ڴ�ռ�Ϊ��" << sizeof(ai) << endl;               //8
	*/



//ת���ַ�
/*
    // \n
    cout << "asdfg\nhjkl" << endl;
	// \\ 
	cout << "asdf\\ghjk" << endl;
	//\"
	cout << "asdf\"ghjkl" << endl;
	//\a
    cout << "asdf\aghjk" << endl;
	//\t
	cout << "asdf\tghjkl" << endl;
	cout << "asdfg\thjkl" << endl;
	cout << "asdfgh\tjkl" << endl;
	cout << "asdfghj\tkl" << endl;
	cout << "asdfghjk\tl" << endl << endl;
	//\'
	cout << "asdfg'hjkl'" << endl;
	//\v
	cout << "asdf\vghjkl" << endl;
	//\0
	cout << "asdf\0ghjkl" << endl;
	//\ddd(1-3λ����[8����]��
	cout << "\101" << endl;
	//\xhh(1-2λ[16����]��
	cout << "\x45" << endl;
*/

	system("pause");

	return 0;
}