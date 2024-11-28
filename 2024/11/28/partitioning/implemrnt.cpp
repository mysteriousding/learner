#include"start.h"
void student::SR()
{
	cin >> MZ;
	cin >> XH;
	cin >> NL;
	cin >> XB;
	cin >> DH;
	cin >> DZ;
}

void student::SC()
{
	cout << MZ << endl;
	cout << XH << endl;
	cout << NL << endl;
	cout << XB << endl;
	cout << DH << endl;
	cout << DZ << endl;
}

void V::SJ()
{
	cin >> length;
	cin >> width;
	cin >> height;
}

void V::JS()
{
	TJ = length * width * height;
}

void V::JG()
{
	cout << TJ << endl;
}

void V::KJ()
{
	cout << int(&TJ) << endl;
}
